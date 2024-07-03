import numpy as np
import matplotlib.pyplot as plt
import mplhep as hep
import sys
import argparse
import awkward as ak
import scipy.ndimage

hep.style.use("CMS")


eta_bins_edges = [
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
    5.191,
]

pt_bins_edges = [
    15,
    21,
    28,
    37,
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


def plot_2d_hist(histo_2d, fig_name):
    fig, ax = plt.subplots()
    ax.set_yscale("log")
    hep.hist2dplot(histo_2d)

    hep.cms.lumitext(
        "2023 (13.6 TeV)",
    )
    hep.cms.text(
        text="SimulationPreliminary",
        loc=0,
    )
    ax.set_ylabel(r"$p_{T}$ (GeV)", loc="top")
    ax.set_xlabel(r"|$\eta$|", loc="right")
    # ax.text(
    #     0.3,
    #     1,
    #     r"anti-$k_{T}$ R=0.4 (PUPPI)",
    #     horizontalalignment="left",
    #     verticalalignment="top",
    #     transform=ax.transAxes,
    # )
    # ax.text(
    #     0.5,
    #     1,
    #     "PNet incl. neutrinos" if "neutrinos" in args.version else "PNet",
    #     horizontalalignment="left",
    #     verticalalignment="top",
    #     transform=ax.transAxes,
    # )

    plt.savefig(
        f"textfiles/L2Res_{args.version}/{fig_name}.png",
        bbox_inches="tight",
        dpi=300,
    )


# load txt file
data = np.loadtxt(
    f"textfiles/L2Res_{args.version}/L2Res_summary_max_{args.era}.txt",
    unpack=True,
)

eta_bins_low = data[0, :]
pt_bins_low = data[1, :]

eta_unique = np.unique(eta_bins_low)

print(type(pt_bins_low))
# get the index where pt_bins is 15
eta_bin_index = list(np.squeeze(np.argwhere(pt_bins_low == 15))) + [len(pt_bins_low)]

# get difference of the index
eta_bin_lenght = np.diff(eta_bin_index)


# extend dimension of jes to 2D with lenght given by eta_bin_lenght
jes = ak.unflatten(data[2, :], eta_bin_lenght)
eta_bins_low = ak.unflatten(eta_bins_low, eta_bin_lenght)
pt_bins_low = ak.unflatten(pt_bins_low, eta_bin_lenght)

for i in range(len(jes)):
    print(eta_bins_low[i])
    print(pt_bins_low[i])
    print(jes[i])


# pad the arrays with zeros to have the same lenght
max_lenght = max(eta_bin_lenght)
jes = ak.fill_none(ak.pad_none(jes, max_lenght, clip=True), 0) - 1
jes = np.where(jes == -1, np.nan, jes)
eta_bin_low = ak.fill_none(ak.pad_none(eta_bins_low, max_lenght, clip=True), 0)
pt_bins_low = ak.fill_none(ak.pad_none(pt_bins_low, max_lenght, clip=True), 0)


histo_2d = (jes, eta_bins_edges, pt_bins_edges)
plot_2d_hist(histo_2d, f"L2Res_summary_{args.era}")


# do the same histogram 2d but smoothing with gaussian filter
jes_smooth = scipy.ndimage.gaussian_filter(jes, sigma=1)
histo_2d_smooth = (jes_smooth, eta_bins_edges, pt_bins_edges)
plot_2d_hist(histo_2d_smooth, f"L2Res_summary_smooth_{args.era}")
