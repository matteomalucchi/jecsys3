import numpy as np
import matplotlib.pyplot as plt
import mplhep as hep
import sys
import argparse
import awkward as ak
import scipy.ndimage
import ROOT
import ctypes
import json

hep.style.use("CMS")


eta_bins_edges = np.array(
    [
        0.0,
        0.261,
        0.522,
        0.783,
        1.044,
        1.305,
        1.479,
        1.653,
        1.93,
        2.172,
        2.322,
        2.5,
        2.65,
        2.853,
        2.964,
        3.139,
        3.314,
        3.489,
        3.839,
        4.013,
        4.583,
        # 5.191,
    ]
)

pt_bins_edges = np.array(
    [
        # 15,
        # 21,
        # 28,
        # 37,
        49,
        59,
        86,
        110,
        132,
        170,
        204,
        236,
        279,
        302,
        373,
        460,
        575,
        638,
        737,
        846,
        967,
        1101,
        1248,
        1410,
        1588,
        1784,
        2000,
        2238,
        2500,
        2787,
        3103,
    ]
)

parser = argparse.ArgumentParser(description="Run the jme analysis")
parser.add_argument(
    "-v",
    "--version",
    type=str,
    help="Version of the analysis",
)
parser.add_argument(
    "-e",
    "--era",
    type=str,
    help="Era of the analysis",
)
args = parser.parse_args()

era_dict={
    "2023Cv123":"2023 Era C (early)"
}

def plot_2d_hist(histo_2d, fig_name):
    fig, ax = plt.subplots()
    ax.set_yscale("log")
    hep.hist2dplot(histo_2d, cbar=True, ax=ax, cmin=0.0, cmax=0.205)

    hep.cms.lumitext(
        f"{era_dict[args.era]} (13.6 TeV)",
        # fontsize=24,
    )
    hep.cms.text(
        text="Preliminary",
        loc=0,
        # fontsize=24,
    )
    ax.set_ylabel(r"$p_{T}^{reco}$ (GeV)", loc="top")
    ax.set_xlabel(r"|$\eta^{reco}$|", loc="right")
    ax.text(
        0.95,
        0.95,
        (
            r"anti-$k_{T}$ R=0.4 (PUPPI)"
            + ("\nPNet incl. neutrinos" if "neutrino" in args.version else "\nPNet")
            + "\n"
            + (
                r"$\sigma_{Rel}$"
                #r"$\sigma_{L2Res}$"
                if "Unc" not in fig_name
                else r"$\sigma_{Rel}  \oplus  \sigma_{Abs}$"
                #r"$\sigma_{L2Res}  \oplus  \sigma_{L3Res}$"
            )
        ),
        horizontalalignment="right",
        verticalalignment="top",
        transform=ax.transAxes,
    )

    plt.savefig(
        f"textfiles/L2Res_{args.version}/{fig_name}_{args.version}.png",
        bbox_inches="tight",
        dpi=300,
    )
    plt.savefig(
        f"textfiles/L2Res_{args.version}/{fig_name}_{args.version}.pdf",
        bbox_inches="tight",
        dpi=300,
    )

    if False:
        # convert the numpy array in a c array
        eta_bins=histo_2d[1].ctypes.data_as(ctypes.POINTER(ctypes.c_double))
        pt_bins=histo_2d[2].ctypes.data_as(ctypes.POINTER(ctypes.c_double))

        # dump histo in TH2D
        hist_root = ROOT.TH2D(
            f"{fig_name}_{args.version}",
            f"{fig_name}_{args.version}",
            len(histo_2d[1]) - 1,
            eta_bins,
            len(histo_2d[2]) - 1,
            pt_bins,
        )
        for i in range(len(histo_2d[1]) - 1):
            for j in range(len(histo_2d[2]) - 1):
                hist_root.SetBinContent(i + 1, j + 1, histo_2d[0][i][j])

        c = ROOT.TCanvas()
        c.cd()
        hist_root.Draw("colz")
        c.Update()
        c.Print(f"textfiles/L2Res_{args.version}/root_{fig_name}_{args.version}.png")
        # save the histogram in a root file
        file = ROOT.TFile(
            f"textfiles/L2Res_{args.version}/{fig_name}_{args.version}.root", "RECREATE"
        )
        c.Write()
        hist_root.Write()
        file.Close()


# load txt file
data = np.loadtxt(
    f"textfiles/L2Res_{args.version}/L2Res_summary_max_{args.era}.txt",
    unpack=True,
)

eta_bins_low = data[0, :]
pt_bins_low = data[1, :]

eta_unique = np.unique(eta_bins_low)

# get the index where pt_bins is 15
eta_bin_index = list(np.squeeze(np.argwhere(pt_bins_low == 15))) + [len(pt_bins_low)]

# get difference of the index
eta_bin_lenght = np.diff(eta_bin_index)


# extend dimension of jes to 2D with lenght given by eta_bin_lenght
jes = ak.unflatten(data[2, :], eta_bin_lenght)
eta_bins_low = ak.unflatten(eta_bins_low, eta_bin_lenght)
pt_bins_low = ak.unflatten(pt_bins_low, eta_bin_lenght)


# pad the arrays with zeros to have the same lenght
max_lenght = max(eta_bin_lenght)
jes = ak.fill_none(ak.pad_none(jes, max_lenght, clip=True), 0) - 1
print(len(jes), len(jes[0]))
jes = jes[:, 4:]
print(len(jes), len(jes[0]))
jes = ak.to_numpy(abs(np.where(jes == -1, np.nan, jes))[:-1])

print(len(jes), len(jes[0]), type(jes))
print(len(eta_bins_edges))
print(len(pt_bins_edges))

histo_2d = (jes, eta_bins_edges, pt_bins_edges)
plot_2d_hist(histo_2d, f"L2Res_summary_{args.era}")


unc_dict = {
    # get the index of pt_bin_edges where it is over 200 for the first time
    np.squeeze(np.argwhere(pt_bins_edges > 200))[0]: 0.02,
    len(pt_bins_edges): 0.01,
}
unc_dict_neutrino = {
    # get the index of pt_bin_edges where it is over 200 for the first time
    np.squeeze(np.argwhere(pt_bins_edges > 200))[0]: 0.03,
    np.squeeze(np.argwhere(pt_bins_edges > 300))[0]: 0.05,
    len(pt_bins_edges): 0.01,
}

for i in range(len(jes)):
    for j in range(len(jes[0])):
        if "neutrino" not in args.version:
            for key in unc_dict.keys():
                if j < key:
                    jes[i][j] = np.sqrt(jes[i][j] ** 2 + unc_dict[key] ** 2)
                    break
        else:
            for key in unc_dict_neutrino.keys():
                if j < key:
                    jes[i][j] = np.sqrt(jes[i][j] ** 2 + unc_dict_neutrino[key] ** 2)
                    break


histo_2d = (jes, eta_bins_edges, pt_bins_edges)
# print(histo_2d)

histo_dict={}
for i in range(len(jes)):
    histo_dict[f"({eta_bins_edges[i]} {eta_bins_edges[i+1]})"]={}
    for j in range(len(jes[0])):
        histo_dict[f"({eta_bins_edges[i]} {eta_bins_edges[i+1]})"][f"({pt_bins_edges[j]} {pt_bins_edges[j+1]})"]=jes[i][j] if not np.isnan(jes[i][j]) else -1
#save the histo to json
with open(f"textfiles/L2Res_{args.version}/L2Res_summary_{args.era}.json", "w") as f:
    json.dump(histo_dict, f, indent=4)


plot_2d_hist(histo_2d, f"L2Res_summary_{args.era}_SumUnc")
