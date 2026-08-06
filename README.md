# jecsys3

Compute the L2L3Residuals calibration within the JetMET group of CMS as described by the [JERC](https://cms-jerc.web.cern.ch/) sub-group. This is done by combining the outputs from the [photon+jet](https://github.com/matteomalucchi/gamjet-analysis), [dijet](https://github.com/matteomalucchi/dijet) and [Z+jet](https://gitlab.cern.ch/mmalucch/ZbAnalysis) analyses.

## What this repository does

The jet energy scale in CMS is corrected in successive steps. This repository takes care of the last, data-driven step: the **L2L3 residual** corrections, which remove the residual data-to-simulation differences in the jet response as a function of pseudorapidity (η, the L2 residual) and transverse momentum (pT, the L3 residual). In addition, it derives the **jet energy resolution scale factors** (JER SF), which scale the simulated jet resolution to match the one observed in data.

The corrections are obtained by combining three independent pT-balance measurements, each provided by a dedicated upstream analysis:

- **photon+jet** ([gamjet-analysis](https://github.com/matteomalucchi/gamjet-analysis))
- **dijet** ([dijet](https://github.com/matteomalucchi/dijet))
- **Z+jet** ([ZbAnalysis](https://gitlab.cern.ch/mmalucch/ZbAnalysis))

The typical workflow is: (1) collect the inputs from the three analyses into a common directory, then (2) run the calibration chain, which performs a global fit of the response as a function of pT (L3Res), derives the η-dependent corrections (L2Res), writes out the final correction text files, and computes the JER scale factors.

## **Dependencies**

An installation of ROOT is required to run the scripts.

## How to run

Copy the outputs of the different analyses to a common directory with

```bash
python arrange_L2L3Res_inputs.py -v version -o work
```

This gathers the photon+jet, dijet and Z+jet outputs (the input histograms for the given `version`) into the `work` directory so that the rest of the chain finds them in a common, expected location.

Run the L2L3Residuals and the JER scale factors, recompiling the libraries, with

```bash
python L2L3Res_JERSF.py -y all -v version
```

This script executes the following actions:

- `make clean` and `make` to recompile the shared libraries used by the ROOT macros
- Compute the L3Res doing a global fit and show the different contributions running `python minitools/runAllIOVs.py -v version`
- change version and year in `L2Res.C` and run `root -l -b L2Res.C+g` to compute the L2Res (the η-dependent residual corrections)
- change version and year in `createL2L3ResTextFile.C` and run `root -l -b createL2L3ResTextFile.C+g` to create the text file containing the L2L3Residuals in the format used by the CMS jet energy corrections
- change version and year in `JERSF.C` and run `root -l -b JERSF.C+g` to compute the jet energy resolution scale factors

The `version` and `year` (`-v` and `-y`) are propagated automatically into `L2Res.C`, `createL2L3ResTextFile.C` and `JERSF.C` before each macro is compiled and executed, so that the whole chain is run consistently for the same configuration. Use `-c` to run the closure test and `-f` to skip the recompilation step (fast mode).
