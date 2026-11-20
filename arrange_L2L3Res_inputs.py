import os
import argparse
import subprocess

DIJET=True
GAMJET=True
ZJET=True

L2L3RES_DIR="L2L3Res_inputs"
HOME_DIR = "/afs/cern.ch/user/j/jessy/workspace/private/CMS/PNET_Regression/Residuals/"
#HOME_DIR = os.environ.get("HOME", ".")

parser = argparse.ArgumentParser(description="Copy files to a common directory")
parser.add_argument("-v", "--version", required=True)
parser.add_argument("--vZjet", default=None, help="Version of Zjet to copy (if different from dijet and gamjet)")
parser.add_argument("-o", "--option", default="copy", help="What to do with the files (copy, backup, rm)")

args = parser.parse_args()
vZjet = args.vZjet if args.vZjet else args.version

if args.option == "copy":
    # get workdir
    copy_dir= os.environ.get("copy_dir", ".")
    main_dir=f"{copy_dir}/{L2L3RES_DIR}/{args.version}"
    #mkdir
    subprocess.run(f"mkdir {L2L3RES_DIR}", shell=True)
    subprocess.run(f"mkdir {main_dir}", shell=True)
    #breakpoint()
    if DIJET:
        print("Copying dijet")
        subprocess.run(f"mkdir {main_dir}/dijet", shell=True)
        subprocess.run(f"cp {HOME_DIR}/dijet/rootfiles/{args.version}/*root {main_dir}/dijet/", shell=True)
        
    if GAMJET:
        print("Copying gamjet-analysis")
        subprocess.run(f"mkdir {main_dir}/gam", shell=True)
        subprocess.run(f"cp {HOME_DIR}/gamjet-analysis/rootfiles/{args.version}/*root {main_dir}/gam/", shell=True)
        
    if ZJET:
        print("Copying ZbAnalysis")
        subprocess.run(f"mkdir {main_dir}/zb", shell=True)
        subprocess.run(f"cp {HOME_DIR}/ZbAnalysis/figures/2024_post-Jessy-updates_27Oct26/{vZjet}_*/jme_bplusZ_merged*.root {main_dir}/zb/", shell=True)

    print(f"Copied output in {main_dir}")

elif  args.option == "backup":
    backup_dir=os.environ.get("backup_dir", ".")
    main_dir=f"{backup_dir}/{L2L3RES_DIR}"
    breakpoint()

    if DIJET:
        print("Copying dijet")
        subprocess.run(f"rsync -ravzP --ignore-existing {HOME_DIR}/dijet/rootfiles/{args.version} {main_dir}/dijet_rootfiles/", shell=True)
    if GAMJET:
        print("Copying gamjet-analysis")
        subprocess.run(f"rsync -ravzP --ignore-existing {HOME_DIR}/gamjet-analysis/rootfiles/{args.version} {main_dir}/gam_jet_rootfiles/", shell=True)
    if ZJET:
        print("Copying ZbAnalysis")
        subprocess.run(f"rsync -ravzP --ignore-existing {HOME_DIR}/ZbAnalysis/rootfiles/{args.version}* {main_dir}/zb_rootfiles/", shell=True)
        subprocess.run(f"rsync -ravzP --ignore-existing {HOME_DIR}/ZbAnalysis/figures/{args.version}* {main_dir}/zb_rootfiles/figures/", shell=True)

elif args.option == "rm":
    print("Are you sure you want to remove the files? [y/n]")
    answer = input()
    if answer == "y":
        if DIJET: 
            print("Removing dijet")
            subprocess.run(f"rm -r {HOME_DIR}/dijet/rootfiles/{args.version}", shell=True)
        if GAMJET:
            print("Removing gamjet-analysis")
            subprocess.run(f"rm -r {HOME_DIR}/gamjet-analysis/rootfiles/{args.version}", shell=True)
        if ZJET:
            print("Removing ZbAnalysis")
            subprocess.run(f"rm -r {HOME_DIR}/ZbAnalysis/rootfiles/{args.version}_*", shell=True)
            subprocess.run(f"rm -r {HOME_DIR}/ZbAnalysis/figures/{args.version}_*", shell=True)
        print("Files removed")
    else:
        print("Nothing removed")
else:
    print("Unknown option. Please use 'copy', 'backup' or 'rm'.")
    exit(1)