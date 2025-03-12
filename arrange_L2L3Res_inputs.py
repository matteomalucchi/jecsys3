import os
import argparse


parser = argparse.ArgumentParser(description="Copy files to a common directory")
parser.add_argument("-v", "--version", required=True)
parser.add_argument("-d", "--directory", default="/work/mmalucch/L2L3Res_inputs")
parser.add_argument("-o", "--option", default="work", help="What to do with the files (work, storage, rm)")

args = parser.parse_args()

if args.option == "work":
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

elif  args.option == "storage":
    storage_dir="/pnfs/psi.ch/cms/trivcat/store/user/mmalucch/L2L3_all_inputs/"

    os.system(f"rsync -ravzP --ignore-existing ~/dijet/rootfiles/{args.version} {storage_dir}/dijet_rootfiles/")
    os.system(f"rsync -ravzP --ignore-existing ~/gamjet-analysis/rootfiles/{args.version} {storage_dir}/gam_jet_rootfiles/")
    os.system(f"rsync -ravzP --ignore-existing ~/ZbAnalysis/rootfiles/{args.version}_* {storage_dir}/zb_rootfiles/")
    os.system(f"rsync -ravzP --ignore-existing ~/ZbAnalysis/figures/{args.version}_* {storage_dir}/zb_rootfiles/figures/")

elif args.option == "rm":
    print("Are you sure you want to remove the files? [y/n]")
    answer = input()
    if answer == "y":
        os.system(f"rm -r ~/dijet/rootfiles/{args.version}")
        os.system(f"rm -r ~/gamjet-analysis/rootfiles/{args.version}")
        os.system(f"rm -r ~/ZbAnalysis/rootfiles/{args.version}_*")
        os.system(f"rm -r ~/ZbAnalysis/figures/{args.version}_*")
        print("Files removed")
    else:
        print("Nothing removed")