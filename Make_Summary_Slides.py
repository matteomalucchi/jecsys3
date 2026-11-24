import os
import glob
from matplotlib.backends.backend_pdf import PdfPages
import matplotlib.pyplot as plt
from pdf2image import convert_from_path
from PIL import Image, ImageChops

year = "2024"
list_versions = ["pnetreg_v1","pnetreg_neutrino_v1","upartreg_v1","upartreg_neutrino_v1"]
list_eras = ["24C","24D","24E","24F","24G","24H","24I"]

# Make Summary_plots folder if it does not exist
outputDir = "Summary_plots/"
if not os.path.exists(outputDir):
    os.makedirs(outputDir)

# Déterminer la taille en pouces pour matplotlib (format slide 16:9, résolution 300 DPI)
dpi = 300
fig_width = 12.0 
fig_height = 7.5


def trim_white_borders(img):
    """
    Découpe automatiquement les marges et bordures blanches autour du graphique PDF.
    """
    if img.mode != 'RGB':
        img = img.convert('RGB')
    bg = Image.new('RGB', img.size, (255, 255, 255))
    diff = ImageChops.difference(img, bg)
    bbox = diff.getbbox()
    if bbox:
        margin = 15  # Marge de sécurité de 15px
        left = max(0, bbox[0] - margin)
        top = max(0, bbox[1] - margin)
        right = min(img.size[0], bbox[2] + margin)
        bottom = min(img.size[1], bbox[3] + margin)
        return img.crop((left, top, right, bottom))
    return img


def compute_aspect_fitted_axes(fig, img, max_box):
    """
    Calcule la position optimale [left, bottom, width, height] d'un axe Matplotlib 
    pour qu'une image occupe TOUT l'espace disponible sans déformation.
    """
    left_max, bottom_max, w_max, h_max = max_box
    img_w, img_h = img.size
    img_aspect = img_w / img_h
    
    fig_w_px = fig_width * dpi
    fig_h_px = fig_height * dpi
    
    box_w_px = w_max * fig_w_px
    box_h_px = h_max * fig_h_px
    box_aspect = box_w_px / box_h_px
    
    if img_aspect > box_aspect:
        w_fit = w_max
        h_fit = (w_max * fig_w_px / img_aspect) / fig_h_px
    else:
        h_fit = h_max
        w_fit = (h_max * fig_h_px * img_aspect) / fig_w_px
        
    left_fit = left_max + (w_max - w_fit) / 2.0
    bottom_fit = bottom_max + (h_max - h_fit) / 2.0
    
    return [left_fit, bottom_fit, w_fit, h_fit]


def add_pdf_page_with_overlay(pdf_out, pdf_path, text_overlay=None):
    """
    Rend les pages d'un PDF sous forme d'image HD dans Matplotlib avec rognage et overlay.
    """
    images = convert_from_path(pdf_path, dpi=300)
    for img in images:
        img_trimmed = trim_white_borders(img)
        
        fig = plt.figure(figsize=(fig_width, fig_height), dpi=dpi)
        
        max_box = (0.02, 0.02, 0.96, 0.88)
        axes_rect = compute_aspect_fitted_axes(fig, img_trimmed, max_box)
        
        ax = fig.add_axes(axes_rect)
        ax.imshow(img_trimmed, interpolation='lanczos')
        ax.axis('off')

        if text_overlay:
            ax.text(
                0.5, 1.02, text_overlay,
                transform=ax.transAxes,
                fontsize=22, fontweight='bold', color='darkred',
                ha='center', va='bottom',
                bbox=dict(boxstyle='round,pad=0.4', facecolor='yellow', alpha=0.85, edgecolor='red', linewidth=2)
            )

        pdf_out.savefig(fig, dpi=dpi)
        plt.close(fig)


def add_two_pdfs_side_by_side(pdf_out, pdf_path_1, pdf_path_2, text_overlay_1=None, text_overlay_2=None):
    """
    Rend deux fichiers PDF côte à côte avec rognage et haute définition.
    """
    images_1 = convert_from_path(pdf_path_1, dpi=100)
    images_2 = convert_from_path(pdf_path_2, dpi=100)

    img1 = trim_white_borders(images_1[0])
    img2 = trim_white_borders(images_2[0])

    fig = plt.figure(figsize=(fig_width, fig_height), dpi=dpi)

    box_left = (0.01, 0.02, 0.48, 0.88)
    rect1 = compute_aspect_fitted_axes(fig, img1, box_left)
    ax1 = fig.add_axes(rect1)
    ax1.imshow(img1, interpolation='lanczos')
    ax1.axis('off')

    box_right = (0.51, 0.02, 0.48, 0.88)
    rect2 = compute_aspect_fitted_axes(fig, img2, box_right)
    ax2 = fig.add_axes(rect2)
    ax2.imshow(img2, interpolation='lanczos')
    ax2.axis('off')

    if text_overlay_1:
        ax1.text(
            0.5, 1.02, text_overlay_1,
            transform=ax1.transAxes,
            fontsize=18, fontweight='bold', color='darkred',
            ha='center', va='bottom',
            bbox=dict(boxstyle='round,pad=0.35', facecolor='yellow', alpha=0.85, edgecolor='red', linewidth=2)
        )
        
    if text_overlay_2:
        ax2.text(
            0.5, 1.02, text_overlay_2,
            transform=ax2.transAxes,
            fontsize=18, fontweight='bold', color='darkred',
            ha='center', va='bottom',
            bbox=dict(boxstyle='round,pad=0.35', facecolor='yellow', alpha=0.85, edgecolor='red', linewidth=2)
        )

    pdf_out.savefig(fig, dpi=dpi)
    plt.close(fig)


# Boucle principale
for version in list_versions:
    root_dir = f"./pdf/{version}/"
    root_dir_closure = f"./pdf/{version}_closure/"

    output_pdf = f"{outputDir}/Summary_{version}_{year}.pdf"
    print(f"Creating PDF: {output_pdf}")

    with PdfPages(output_pdf) as pdf:
        for era in list_eras:
            print(f"  Processing era: {era} for Version: {version}")

            # 1. Page de Garde pour l'ère
            fig = plt.figure(figsize=(fig_width, fig_height), dpi=dpi)
            plt.text(0.5, 0.5, f"Era {era}\nVersion: {version}", fontsize=28, ha='center', va='center', fontweight='bold')
            plt.axis('off')
            pdf.savefig(fig, dpi=dpi)
            plt.close(fig)

            # 2. Premier plot : Plot standard L2Res
            l2res_path = os.path.join(root_dir, "L2Res", f"L2Res_AllEta_20{era}.pdf")
            if not os.path.exists(l2res_path):
                print(f"  --> Plot standard non trouvé : {l2res_path}")
            else:
                add_pdf_page_with_overlay(pdf, l2res_path, text_overlay="L2Res")

            # 3. Second plot : Plot Closure avec texte "Closure" superposé au-dessus
            l2res_closure_path = os.path.join(root_dir_closure, "L2Res", f"L2Res_AllEta_20{era}.pdf")
            if not os.path.exists(l2res_closure_path):
                print(f"  --> Plot closure non trouvé : {l2res_closure_path}")
            else:
                add_pdf_page_with_overlay(pdf, l2res_closure_path, text_overlay="L2Res - L2L3Res Closure")

            # 4. Deux plots supplémentaires côte à côte sur une seule page
            extra_plot_1 = os.path.join(root_dir, "globalFit", f"globalFit_Run{era}_{version}_rjet_initial_complete.pdf")
            extra_plot_2 = os.path.join(root_dir_closure, "globalFit", f"globalFit_Run{era}_{version}_closure_rjet_initial_complete.pdf")

            if os.path.exists(extra_plot_1) and os.path.exists(extra_plot_2):
                add_two_pdfs_side_by_side(
                    pdf,
                    extra_plot_1,
                    extra_plot_2,
                    text_overlay_1="L3 Res",
                    text_overlay_2="L3 Res - L2L3Res Closure"
                )
            else:
                print(f"  --> Plots supplémentaires introuvables : {extra_plot_1} ou {extra_plot_2}")

print("Génération terminée avec succès !")