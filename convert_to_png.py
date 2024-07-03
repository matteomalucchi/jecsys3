import fitz
import os
import argparse

parser = argparse.ArgumentParser(description='Convert pdf to png')
parser.add_argument('-i', '--input', type=str, help='input pdf directory')
args = parser.parse_args()

# get list of files in the directory pdf and subdirectories
files = []
for (dirpath, dirnames, filenames) in os.walk(args.input):
    for file in filenames:
        if "vsEta" in file or "vsPt" in file:
            continue
        fname=os.path.join(dirpath, file)
        files += fname

        dpi = 300  # choose desired dpi here
        zoom = dpi / 72  # zoom factor, standard: 72 dpi
        magnify = fitz.Matrix(zoom, zoom)  # magnifies in x, resp. y direction
        doc = fitz.open(fname)  # open document
        for page in doc:
            pix = page.get_pixmap(matrix=magnify)  # render page to an image
            pix.save(f"{fname.replace('.pdf', '.png')}")
