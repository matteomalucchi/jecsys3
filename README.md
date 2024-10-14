# jecsys3
Compute the L2L3Residuals calibration within the JetMET group of CMS as described by the [JERC](https://cms-jerc.web.cern.ch/) sub-group. This is done by combining the outputs from the [photon+jet](https://github.com/matteomalucchi/gamjet-analysis), [dijet](https://github.com/matteomalucchi/dijet) and [Z+jet](https://gitlab.cern.ch/mmalucch/ZbAnalysis) analyses.

## How to run
Copy the outputs of the different analyses to a common directory with
```bash
python copy_files_to_workdir.py -v version
```

Run for 2022+2023 recompiling the libraries

```bash
python L2L3Res.py -y all -v version
```

This script executes the following actions:

- `make clean`
- `make`
- Compute the L3Res doing a global fit and show the different contributions running `python minitools/runAllIOVs.py -v version`
- change version and year in `L2Res.C` and run  `root -l -b L2Res.C+g` to compute the L2Res
- change version and year in `createL2L3ResTextFile.C` and run  `root -l -b createL2L3ResTextFile.C+g` to create the text file containing the L2L3Residuals
