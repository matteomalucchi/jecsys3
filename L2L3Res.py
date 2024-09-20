import os
import argparse

parser = argparse.ArgumentParser(description="Move files")
parser.add_argument("-v", "--version", required=True)
parser.add_argument("-c", "--closure", default=False, action="store_true")
args = parser.parse_args()

os.system(f"python copy_files_to_workdir.py -v {args.version}")
os.system(f"make clean")
os.system(f"make")
os.system(f"python minitools/runAllIOVs.py -v {args.version} {'-c' if args.closure else ''}")


for file_name in ["L2Res", "createL2L3ResTextFile"]:
    with open(f"{file_name}.C") as file:
        filedata = file.read()

    # find line that starts with string version =
    for line in filedata.split("\n"):
        if line.startswith("string version"):
            line_new = f"string version = \"{args.version}\";"
            break
    # modify line
    filedata = filedata.replace(line, line_new)
    # print(filedata[:1000])

    with open(f"{file_name}.C", "w") as file:
        file.write(filedata)

    os.system(f"root -l -b {file_name}.C")