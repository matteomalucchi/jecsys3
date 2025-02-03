import os
import argparse


parser = argparse.ArgumentParser(description="Copy files to a common directory")
parser.add_argument("-v", "--version", required=True)
parser.add_argument("-d", "--directory", default="/work/mmalucch/L2L3Res_inputs")
args = parser.parse_args()

work_dir=f"{args.directory}/{args.version}"

#mkdir
os.system(f"mkdir {work_dir}")
os.system(f"mkdir {work_dir}/dijet")
os.system(f"mkdir {work_dir}/gam")
os.system(f"mkdir {work_dir}/zb")

os.system(f"cp ~/dijet/rootfiles/{args.version}/*root {work_dir}/dijet/")
os.system(f"cp ~/gamjet-analysis/rootfiles/{args.version}/*root {work_dir}/gam/")
os.system(f"cp ~/ZbAnalysis/figures/{args.version}_*/jme_bplusZ_merged*.root {work_dir}/zb/")

print(f"Copied output in {work_dir}")