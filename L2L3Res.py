import os
import argparse
import time
import sys

parser = argparse.ArgumentParser(description="Move files")
parser.add_argument("-v", "--version", required=True)
parser.add_argument("-y", "--year", default="all")
parser.add_argument("-c", "--closure", default=False, action="store_true")
parser.add_argument("-f", "--fast", default=False, action="store_true")
args = parser.parse_args()

if not args.fast:
    os.system(f"make clean")
    os.system(f"make")


closure = args.closure
if "closure" in args.version:
    closure = True

# print(f"Running for version {args.version} and year {args.year} with closure {closure}")
# os.system(f"python minitools/runAllIOVs.py -v {args.version} {'-c' if closure else ''} -i {args.year}")


for file_name in ["L2Res", "createL2L3ResTextFile"]:
    with open(f"{file_name}.C") as file:
        filedata = file.read()

    # find line that starts with string version
    for line in filedata.split("\n"):
        if line.startswith("string version_string"):
            line_new = f"string version_string = \"{args.version}\";"
            break
    # modify line
    filedata = filedata.replace(line, line_new)

    # find line that starts with string YEAR
    for line in filedata.split("\n"):
        if line.startswith("string YEAR"):
            line_new = f"string YEAR = \"{args.year}\";"
            break
    # modify line
    filedata = filedata.replace(line, line_new)


    # print(filedata[:1000])

    with open(f"{file_name}.C", "w") as file:
        file.write(filedata)

    time.sleep(10)

    os.system(f"root -q -l -b {file_name}.C+g")
    time.sleep(10)