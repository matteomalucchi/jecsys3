#! /usr/bin/python
import os
import argparse
import time

# IOV_list= ['2016ULAPV','2016UL','2018UL','Run2']
# IOV_list= ['Run22C','Run22D','Run22CD','Run22E','Run22F','Run22G','Run22FG',
#           'Run23B','Run23C1','Run23C2','Run23C2','Run23C3','Run23BC123',
#           'Run23C4']
# IOV_list= ['Run22CD','Run22E','Run22FG','Run23BC123','Run23C4D','Run3']
# IOV_list= ['Run22CD','Run22E','Run22FG','Run23C123',
#            'Run23C4','Run23D','Run23C4D']
run23 = ["Run23C123", "Run23C4","Run23D"]
run22 = ['Run22CD','Run22E','Run22F','Run22G','Run22FG']
# run22 = ['Run22FG']


version = "tot_23_pnetreg_ok"

parser = argparse.ArgumentParser(description="Run all IOVs")

# The user can pass the IOV list, version, max number of files as an argument
parser.add_argument("-i", '--IOV_list', default="all")
parser.add_argument("-v", "--version", default=version)
parser.add_argument("-c", "--closure", default=False, action="store_true")
args = parser.parse_args()

version = args.version

if "23" in args.IOV_list :
    IOV_list=run23
elif "22" in args.IOV_list:
    IOV_list=run22
elif "all" in args.IOV_list:
    IOV_list=run23+run22
else:
    raise ValueError("Invalid IOV_list")

# make pdf/globalFit
os.system(f"mkdir pdf/{version}/")
os.system(f"mkdir pdf/{version}/globalFit")
# os.system("mkdir png/globalFit_"+version)
for iov in IOV_list:
    with open("globalFitSettings.h") as file:
        filedata = file.read()
    # find line that starts with string version =
    for line in filedata.split("\n"):
        if line.startswith("bool _gf_penalizeFitPars"):
            line_new = f"bool _gf_penalizeFitPars = {'false' if 'G' in iov and '22' in iov else 'true'};"
            print(line_new)
            break
    # modify line
    filedata = filedata.replace(line, line_new)

    with open("globalFitSettings.h", "w") as file:
        file.write(filedata)

    time.sleep(10)

    os.system(
        "root -l -b -q 'mk_reprocess_RunEpoch.C(\""
        + iov
        + '","'
        + version
        + '","'
        + str(args.closure)
        + "\")'"
    )

# os.system("root -b -q 'recombine.C'")
# os.system("root -b -q 'mk_reprocess_RunEpoch.C(\"Run3\")'")

# mv jecdata*.root
for iov in IOV_list:
    mv = (
        "mv rootfiles/jecdata"
        + iov
        + ".root rootfiles/jecdata_"
        + iov
        + "_"
        + version
        # + ("_closure" if args.closure else "_initial")
        + ".root"
    )
    os.system(mv)

# mv = (
#     "mv rootfiles/jecdataRun3Data.root rootfiles/jecdataRun3Data_"
#     + version
#     + ("_closure" if args.closure else "_initial")
#     + ".root"
# )
# os.system(mv)
