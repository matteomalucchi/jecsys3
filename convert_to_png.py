import fitz
import os


# get list of files in the directory pdf and subdirectories
files = []
for (dirpath, dirnames, filenames) in os.walk("pdf"):
    for file in filenames:
        fname=os.path.join(dirpath, file)
        files += fname

        dpi = 300  # choose desired dpi here
        zoom = dpi / 72  # zoom factor, standard: 72 dpi
        magnify = fitz.Matrix(zoom, zoom)  # magnifies in x, resp. y direction
        doc = fitz.open(fname)  # open document
        for page in doc:
            pix = page.get_pixmap(matrix=magnify)  # render page to an image
            pix.save(f"{fname.replace('.pdf', '.png')}")
