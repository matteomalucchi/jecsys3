import os
import argparse

parser = argparse.ArgumentParser(description="Move files")
parser.add_argument("-v", "--version", required=True)
args = parser.parse_args()

work_dir=f"/work/mmalucch/L2L3Res_inputs/{args.version}/"

#mkdir
os.system(f"mkdir {work_dir}")
os.system(f"mkdir {work_dir}/dijet")
os.system(f"mkdir {work_dir}/gam")
os.system(f"mkdir {work_dir}/zb")

os.system(f"cp ~/dijet/rootfiles/{args.version}/*root /work/mmalucch/L2L3Res_inputs/{args.version}/dijet/")
os.system(f"cp ~/gamjet-analysis/rootfiles/{args.version}/*root /work/mmalucch/L2L3Res_inputs/{args.version}/gam/")
os.system(f"cp ~/ZbAnalysis/figures/{args.version}*/jme_bplusZ_merged*.root /work/mmalucch/L2L3Res_inputs/{args.version}/zb/")

print(f"find output in {work_dir}")