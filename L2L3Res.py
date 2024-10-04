import os
import argparse
import time
import sys

parser = argparse.ArgumentParser(description="Move files")
parser.add_argument("-v", "--version", required=True)
parser.add_argument("-y", "--year", required=True)
parser.add_argument("-c", "--closure", default=False, action="store_true")
args = parser.parse_args()

os.system(f"python copy_files_to_workdir.py -v {args.version}")
os.system(f"make clean")
os.system(f"make")
os.system(f"python minitools/runAllIOVs.py -v {args.version} {'-c' if args.closure else ''} -i {args.year}")


# sys.exit()

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