// Purpose: common file listings for L2Res.C, L3Res.C/globalFit, JERSF.C
#ifndef __CONFIGFILES_C__
#define __CONFIGFILES_C__

#include <map>
#include <string>
std::map<std::string, map<std::string, map<std::string, std::string> > > mf;

// 2024 partial re-reco + Summer24
string t = "24V9M";

// Options for Zmm: v100. v100pu. v100noPU_smear. v100pu_smear.root
// Use find-and-replace to switch
// v100*smear.root are corrupt, bad JRV9M file
mf[t]["Zmm"]["2024C_nib1"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024CDEReprocessing_v1_2024C_nib1_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024D_nib1"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024CDEReprocessing_v1_2024D_nib1_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024E_nib1"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024CDEReprocessing_v1_2024E_nib1_Zmm_V9M_v100pu.root";
//mf[t]["Zmm"]["2024Ev1_nib1"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024CDEReprocessing_v1_2024Ev1_nib1_Zmm_V9M_v100pu.root";
//mf[t]["Zmm"]["2024Ev2_nib1"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024CDEReprocessing_v1_2024Ev2_nib1_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024F_nib1"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024F_nib1_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024F_nib2"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024F_nib2_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024F_nib3"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024F_nib3_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024G_nib1"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024G_nib1_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024G_nib2"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024G_nib2_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024H_nib1"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024H_nib1_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024I_nib1"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024I_nib1_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024CDE_nib"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024CDE_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024FGHI_nib"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024FGHI_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["2024_nib"] = "rootfiles/Prompt2024/Zmm_v100/jme_Zj_2024_Zmm_V9M_v100pu.root";
mf[t]["Zmm"]["MC"] = ""; // 'mc' directory in input files

mf[t]["Gam"]["2024C_nib1"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024C-rereco_w56.root";
mf[t]["Gam"]["2024D_nib1"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024D-rereco_w56.root";
mf[t]["Gam"]["2024E_nib1"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024E-rereco_w56.root";
mf[t]["Gam"]["2024F_nib1"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024Fnib1_w56.root";
mf[t]["Gam"]["2024F_nib2"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024Fnib2_w56.root";
mf[t]["Gam"]["2024F_nib3"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024Fnib3_w56.root";
mf[t]["Gam"]["2024G_nib1"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024Gnib1_w56.root";
mf[t]["Gam"]["2024G_nib2"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024Gnib2_w56.root";
mf[t]["Gam"]["2024H_nib1"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024Hnib1_w56.root";
mf[t]["Gam"]["2024I_nib1"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024Inib1_w56.root";
mf[t]["Gam"]["2024CDE_nib"]  = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024CDE_V9M_w56.root";
mf[t]["Gam"]["2024FGHI_nib"] = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024FGHI_V9M_w56.root";
mf[t]["Gam"]["2024_nib"]   = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_data_2024_V9M_w56.root";
mf[t]["Gam"]["MC"]         = "rootfiles/Prompt2024/w48_Gam/GamHistosFill_mc_summer2024P8_pu-2024CDEFGHI_w48.root";
//mf[t]["Gam"]["MC"]         = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_mc_summer2024P8_no-pu_w56.root"; // no QCD, no PU RW
//mf[t]["Gam"]["MC"]         = "rootfiles/Prompt2024/Gam_w56/GamHistosFill_mc_summer2024QCD_no-pu_w56.root"; // QCD, no PU RW; unstable stats, revert

mf[t]["Jet"]["2024C_nib1"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024C_Rp_JME_v134.root";
mf[t]["Jet"]["2024D_nib1"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024D_Rp_JME_v134.root";
mf[t]["Jet"]["2024E_nib1"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024E_Rp_JME_v134.root";
mf[t]["Jet"]["2024F_nib1"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024F_nib1_JME_v134.root";
mf[t]["Jet"]["2024F_nib2"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024F_nib2_JME_v134.root";
mf[t]["Jet"]["2024F_nib3"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024F_nib3_JME_v134.root";
mf[t]["Jet"]["2024G_nib1"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024G_nib1_JME_v134.root";
mf[t]["Jet"]["2024G_nib2"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024G_nib2_JME_v134.root";
mf[t]["Jet"]["2024H_nib1"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024H_nib1_JME_v134.root";
mf[t]["Jet"]["2024I_nib1"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024I_nib1_JME_v134.root";
//mf[t]["Jet"]["2024Iv1_nib1"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024Iv1_nib1_JME_v134.root";
//mf[t]["Jet"]["2024Iv2_nib1"] = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024Iv2_nib1_JME_v134.root";
mf[t]["Jet"]["2024CDE_nib"]   = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024CDE_JME_v134.root";
mf[t]["Jet"]["2024FGHI_nib"]   = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024FGHI_JME_v134.root";
mf[t]["Jet"]["2024_nib"]   = "rootfiles/Prompt2024/Jet_v134/jmenano_data_cmb_2024CDEFGHI_JME_v134.root";
//mf[t]["Jet"]["MC"] = "rootfiles/Prompt2024/Jet_v132/jmenano_mc_out_Summer24MG_v132.root"; // no JER SF? no PU RW?
//mf[t]["Jet"]["MC"] = "rootfiles/Prompt2024/Jet_v134/jmenano_mc_out_Summer24MG_v134.root"; // no JER SF, no PU RW
mf[t]["Jet"]["MC"] = "rootfiles/Prompt2024/Jet_v134/jmenano_mc_out_Summer24MG_PU69_v134.root"; // no JER SF, with PU RW
//mf[t]["Jet"]["MC"] = "rootfiles/Prompt2024/Jet_v134/jmenano_mc_out_Summer24MG_JERSF_v134.root"; // with JER SF, no PU RW

////////////////////////////  For PNET and UparT regressions ///////////////////////////

// Dijet Data files for PNET regression
mf["pnetreg_v1"]["Jet"]["2024C"] = "L2L3Res_inputs/pnetreg_v1/dijet/jmenano_data_cmb_2024C_JME_pnetreg_v1.root";
mf["pnetreg_v1"]["Jet"]["2024D"] = "L2L3Res_inputs/pnetreg_v1/dijet/jmenano_data_cmb_2024D_JME_pnetreg_v1.root";
mf["pnetreg_v1"]["Jet"]["2024E"] = "L2L3Res_inputs/pnetreg_v1/dijet/jmenano_data_cmb_2024E_JME_pnetreg_v1.root";
mf["pnetreg_v1"]["Jet"]["2024F"] = "L2L3Res_inputs/pnetreg_v1/dijet/jmenano_data_cmb_2024F_JME_pnetreg_v1.root";
mf["pnetreg_v1"]["Jet"]["2024G"] = "L2L3Res_inputs/pnetreg_v1/dijet/jmenano_data_cmb_2024G_JME_pnetreg_v1.root";
mf["pnetreg_v1"]["Jet"]["2024H"] = "L2L3Res_inputs/pnetreg_v1/dijet/jmenano_data_cmb_2024H_JME_pnetreg_v1.root";
mf["pnetreg_v1"]["Jet"]["2024I"] = "L2L3Res_inputs/pnetreg_v1/dijet/jmenano_data_cmb_2024I_JME_pnetreg_v1.root";
// Dijet MC file for PNET regression
mf["pnetreg_v1"]["Jet"]["MC"] = "L2L3Res_inputs/pnetreg_v1/dijet/jmenano_mc_out_2024QCD_pnetreg_v1.root";

// Dijet Data files for PNET regression Closure
mf["pnetreg_v1_closure"]["Jet"]["2024C"] = "L2L3Res_inputs/pnetreg_v1_closure/dijet/jmenano_data_cmb_2024C_JME_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Jet"]["2024D"] = "L2L3Res_inputs/pnetreg_v1_closure/dijet/jmenano_data_cmb_2024D_JME_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Jet"]["2024E"] = "L2L3Res_inputs/pnetreg_v1_closure/dijet/jmenano_data_cmb_2024E_JME_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Jet"]["2024F"] = "L2L3Res_inputs/pnetreg_v1_closure/dijet/jmenano_data_cmb_2024F_JME_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Jet"]["2024G"] = "L2L3Res_inputs/pnetreg_v1_closure/dijet/jmenano_data_cmb_2024G_JME_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Jet"]["2024H"] = "L2L3Res_inputs/pnetreg_v1_closure/dijet/jmenano_data_cmb_2024H_JME_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Jet"]["2024I"] = "L2L3Res_inputs/pnetreg_v1_closure/dijet/jmenano_data_cmb_2024I_JME_pnetreg_v1_closure.root";
// Dijet MC file for PNET regression Closure
mf["pnetreg_v1_closure"]["Jet"]["MC"] = "L2L3Res_inputs/pnetreg_v1_closure/dijet/jmenano_mc_out_2024QCD_pnetreg_v1_closure.root";


// Dijet Data files for PNET regression with neutrinos
mf["pnetreg_neutrino_v1"]["Jet"]["2024C"] = "L2L3Res_inputs/pnetreg_neutrino_v1/dijet/jmenano_data_cmb_2024C_JME_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Jet"]["2024D"] = "L2L3Res_inputs/pnetreg_neutrino_v1/dijet/jmenano_data_cmb_2024D_JME_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Jet"]["2024E"] = "L2L3Res_inputs/pnetreg_neutrino_v1/dijet/jmenano_data_cmb_2024E_JME_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Jet"]["2024F"] = "L2L3Res_inputs/pnetreg_neutrino_v1/dijet/jmenano_data_cmb_2024F_JME_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Jet"]["2024G"] = "L2L3Res_inputs/pnetreg_neutrino_v1/dijet/jmenano_data_cmb_2024G_JME_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Jet"]["2024H"] = "L2L3Res_inputs/pnetreg_neutrino_v1/dijet/jmenano_data_cmb_2024H_JME_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Jet"]["2024I"] = "L2L3Res_inputs/pnetreg_neutrino_v1/dijet/jmenano_data_cmb_2024I_JME_pnetreg_neutrino_v1.root";
// Dijet MC file for PNET regression with neutrinos
mf["pnetreg_neutrino_v1"]["Jet"]["MC"] = "L2L3Res_inputs/pnetreg_neutrino_v1/dijet/jmenano_mc_out_2024QCD_pnetreg_neutrino_v1.root";

// Dijet Data files for PNET regression with neutrinos Closure
mf["pnetreg_neutrino_v1_closure"]["Jet"]["2024C"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024C_JME_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Jet"]["2024D"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024D_JME_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Jet"]["2024E"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024E_JME_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Jet"]["2024F"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024F_JME_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Jet"]["2024G"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024G_JME_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Jet"]["2024H"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024H_JME_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Jet"]["2024I"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024I_JME_pnetreg_neutrino_v1_closure.root";
// Dijet MC file for PNET regression with neutrinos Closure
mf["pnetreg_neutrino_v1_closure"]["Jet"]["MC"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/dijet/jmenano_mc_out_2024QCD_pnetreg_neutrino_v1_closure.root";

// Dijet Data files for UPART regression
mf["upartreg_v1"]["Jet"]["2024C"] = "L2L3Res_inputs/upartreg_v1/dijet/jmenano_data_cmb_2024C_JME_upartreg_v1.root";
mf["upartreg_v1"]["Jet"]["2024D"] = "L2L3Res_inputs/upartreg_v1/dijet/jmenano_data_cmb_2024D_JME_upartreg_v1.root";
mf["upartreg_v1"]["Jet"]["2024E"] = "L2L3Res_inputs/upartreg_v1/dijet/jmenano_data_cmb_2024E_JME_upartreg_v1.root";
mf["upartreg_v1"]["Jet"]["2024F"] = "L2L3Res_inputs/upartreg_v1/dijet/jmenano_data_cmb_2024F_JME_upartreg_v1.root";
mf["upartreg_v1"]["Jet"]["2024G"] = "L2L3Res_inputs/upartreg_v1/dijet/jmenano_data_cmb_2024G_JME_upartreg_v1.root";
mf["upartreg_v1"]["Jet"]["2024H"] = "L2L3Res_inputs/upartreg_v1/dijet/jmenano_data_cmb_2024H_JME_upartreg_v1.root";
mf["upartreg_v1"]["Jet"]["2024I"] = "L2L3Res_inputs/upartreg_v1/dijet/jmenano_data_cmb_2024I_JME_upartreg_v1.root";
// Dijet MC file for UPART regression
mf["upartreg_v1"]["Jet"]["MC"] = "L2L3Res_inputs/upartreg_v1/dijet/jmenano_mc_out_2024QCD_upartreg_v1.root";

// Dijet Data files for UPART regression Closure
mf["upartreg_v1_closure"]["Jet"]["2024C"] = "L2L3Res_inputs/upartreg_v1_closure/dijet/jmenano_data_cmb_2024C_JME_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Jet"]["2024D"] = "L2L3Res_inputs/upartreg_v1_closure/dijet/jmenano_data_cmb_2024D_JME_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Jet"]["2024E"] = "L2L3Res_inputs/upartreg_v1_closure/dijet/jmenano_data_cmb_2024E_JME_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Jet"]["2024F"] = "L2L3Res_inputs/upartreg_v1_closure/dijet/jmenano_data_cmb_2024F_JME_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Jet"]["2024G"] = "L2L3Res_inputs/upartreg_v1_closure/dijet/jmenano_data_cmb_2024G_JME_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Jet"]["2024H"] = "L2L3Res_inputs/upartreg_v1_closure/dijet/jmenano_data_cmb_2024H_JME_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Jet"]["2024I"] = "L2L3Res_inputs/upartreg_v1_closure/dijet/jmenano_data_cmb_2024I_JME_upartreg_v1_closure.root";
// Dijet MC file for UPART regression Closure
mf["upartreg_v1_closure"]["Jet"]["MC"] = "L2L3Res_inputs/upartreg_v1_closure/dijet/jmenano_mc_out_2024QCD_upartreg_v1_closure.root";

// Dijet Data files for UPART regression with neutrinos
mf["upartreg_neutrino_v1"]["Jet"]["2024C"] = "L2L3Res_inputs/upartreg_neutrino_v1/dijet/jmenano_data_cmb_2024C_JME_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Jet"]["2024D"] = "L2L3Res_inputs/upartreg_neutrino_v1/dijet/jmenano_data_cmb_2024D_JME_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Jet"]["2024E"] = "L2L3Res_inputs/upartreg_neutrino_v1/dijet/jmenano_data_cmb_2024E_JME_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Jet"]["2024F"] = "L2L3Res_inputs/upartreg_neutrino_v1/dijet/jmenano_data_cmb_2024F_JME_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Jet"]["2024G"] = "L2L3Res_inputs/upartreg_neutrino_v1/dijet/jmenano_data_cmb_2024G_JME_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Jet"]["2024H"] = "L2L3Res_inputs/upartreg_neutrino_v1/dijet/jmenano_data_cmb_2024H_JME_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Jet"]["2024I"] = "L2L3Res_inputs/upartreg_neutrino_v1/dijet/jmenano_data_cmb_2024I_JME_upartreg_neutrino_v1.root";
// Dijet MC file for UPART regression with neutrinos
mf["upartreg_neutrino_v1"]["Jet"]["MC"] = "L2L3Res_inputs/upartreg_neutrino_v1/dijet/jmenano_mc_out_2024QCD_upartreg_neutrino_v1.root";

// Dijet Data files for UPART regression with neutrinos Closure
mf["upartreg_neutrino_v1_closure"]["Jet"]["2024C"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024C_JME_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Jet"]["2024D"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024D_JME_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Jet"]["2024E"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024E_JME_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Jet"]["2024F"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024F_JME_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Jet"]["2024G"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024G_JME_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Jet"]["2024H"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024H_JME_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Jet"]["2024I"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/dijet/jmenano_data_cmb_2024I_JME_upartreg_neutrino_v1_closure.root";
// Dijet MC file for UPART regression with neutrinos Closure
mf["upartreg_neutrino_v1_closure"]["Jet"]["MC"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/dijet/jmenano_mc_out_2024QCD_upartreg_neutrino_v1_closure.root";


// Z+jet Data files for PNET regression
mf["pnetreg_v1"]["Zmm"]["2024C"] = "L2L3Res_inputs/pnetreg_v1/zb/jme_bplusZ_merged_pnetreg_v1_2024C.root";
mf["pnetreg_v1"]["Zmm"]["2024D"] = "L2L3Res_inputs/pnetreg_v1/zb/jme_bplusZ_merged_pnetreg_v1_2024D.root";
mf["pnetreg_v1"]["Zmm"]["2024E"] = "L2L3Res_inputs/pnetreg_v1/zb/jme_bplusZ_merged_pnetreg_v1_2024E.root";
mf["pnetreg_v1"]["Zmm"]["2024F"] = "L2L3Res_inputs/pnetreg_v1/zb/jme_bplusZ_merged_pnetreg_v1_2024F.root";
mf["pnetreg_v1"]["Zmm"]["2024G"] = "L2L3Res_inputs/pnetreg_v1/zb/jme_bplusZ_merged_pnetreg_v1_2024G.root";
mf["pnetreg_v1"]["Zmm"]["2024H"] = "L2L3Res_inputs/pnetreg_v1/zb/jme_bplusZ_merged_pnetreg_v1_2024H.root";
mf["pnetreg_v1"]["Zmm"]["2024I"] = "L2L3Res_inputs/pnetreg_v1/zb/jme_bplusZ_merged_pnetreg_v1_2024I.root";
// Z+jet MC file for PNET regression
mf["pnetreg_v1"]["Zmm"]["MC"] = "";

// Z+jet Data files for PNET regression Closure
mf["pnetreg_v1_closure"]["Zmm"]["2024C"] = "L2L3Res_inputs/pnetreg_v1_closure/zb/jme_bplusZ_merged_pnetreg_v1_closure_2024C.root";
mf["pnetreg_v1_closure"]["Zmm"]["2024D"] = "L2L3Res_inputs/pnetreg_v1_closure/zb/jme_bplusZ_merged_pnetreg_v1_closure_2024D.root";
mf["pnetreg_v1_closure"]["Zmm"]["2024E"] = "L2L3Res_inputs/pnetreg_v1_closure/zb/jme_bplusZ_merged_pnetreg_v1_closure_2024E.root";
mf["pnetreg_v1_closure"]["Zmm"]["2024F"] = "L2L3Res_inputs/pnetreg_v1_closure/zb/jme_bplusZ_merged_pnetreg_v1_closure_2024F.root";
mf["pnetreg_v1_closure"]["Zmm"]["2024G"] = "L2L3Res_inputs/pnetreg_v1_closure/zb/jme_bplusZ_merged_pnetreg_v1_closure_2024G.root";
mf["pnetreg_v1_closure"]["Zmm"]["2024H"] = "L2L3Res_inputs/pnetreg_v1_closure/zb/jme_bplusZ_merged_pnetreg_v1_closure_2024H.root";
mf["pnetreg_v1_closure"]["Zmm"]["2024I"] = "L2L3Res_inputs/pnetreg_v1_closure/zb/jme_bplusZ_merged_pnetreg_v1_closure_2024I.root";
// Z+jet MC file for PNET regression Closure
mf["pnetreg_v1_closure"]["Zmm"]["MC"] = "";

// Z+jet Data files for PNET regression with neutrinos
mf["pnetreg_neutrino_v1"]["Zmm"]["2024C"] = "L2L3Res_inputs/pnetreg_neutrino_v1/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_2024C.root";
mf["pnetreg_neutrino_v1"]["Zmm"]["2024D"] = "L2L3Res_inputs/pnetreg_neutrino_v1/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_2024D.root";
mf["pnetreg_neutrino_v1"]["Zmm"]["2024E"] = "L2L3Res_inputs/pnetreg_neutrino_v1/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_2024E.root";
mf["pnetreg_neutrino_v1"]["Zmm"]["2024F"] = "L2L3Res_inputs/pnetreg_neutrino_v1/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_2024F.root";
mf["pnetreg_neutrino_v1"]["Zmm"]["2024G"] = "L2L3Res_inputs/pnetreg_neutrino_v1/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_2024G.root";
mf["pnetreg_neutrino_v1"]["Zmm"]["2024H"] = "L2L3Res_inputs/pnetreg_neutrino_v1/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_2024H.root";
mf["pnetreg_neutrino_v1"]["Zmm"]["2024I"] = "L2L3Res_inputs/pnetreg_neutrino_v1/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_2024I.root";
// Z+jet MC file for PNET regression with neutrinos
mf["pnetreg_neutrino_v1"]["Zmm"]["MC"] = "";

// Z+jet Data files for PNET regression with neutrinos Closure
mf["pnetreg_neutrino_v1_closure"]["Zmm"]["2024C"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_closure_2024C.root";
mf["pnetreg_neutrino_v1_closure"]["Zmm"]["2024D"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_closure_2024D.root";
mf["pnetreg_neutrino_v1_closure"]["Zmm"]["2024E"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_closure_2024E.root";
mf["pnetreg_neutrino_v1_closure"]["Zmm"]["2024F"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_closure_2024F.root";
mf["pnetreg_neutrino_v1_closure"]["Zmm"]["2024G"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_closure_2024G.root";
mf["pnetreg_neutrino_v1_closure"]["Zmm"]["2024H"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_closure_2024H.root";
mf["pnetreg_neutrino_v1_closure"]["Zmm"]["2024I"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/zb/jme_bplusZ_merged_pnetreg_neutrino_v1_closure_2024I.root";
// Z+jet MC file for PNET regression with neutrinos Closure
mf["pnetreg_neutrino_v1_closure"]["Zmm"]["MC"] = "";

// Z+jet Data files for UPART regression
mf["upartreg_v1"]["Zmm"]["2024C"] = "L2L3Res_inputs/upartreg_v1/zb/jme_bplusZ_merged_upartreg_v1_2024C.root";
mf["upartreg_v1"]["Zmm"]["2024D"] = "L2L3Res_inputs/upartreg_v1/zb/jme_bplusZ_merged_upartreg_v1_2024D.root";
mf["upartreg_v1"]["Zmm"]["2024E"] = "L2L3Res_inputs/upartreg_v1/zb/jme_bplusZ_merged_upartreg_v1_2024E.root";
mf["upartreg_v1"]["Zmm"]["2024F"] = "L2L3Res_inputs/upartreg_v1/zb/jme_bplusZ_merged_upartreg_v1_2024F.root";
mf["upartreg_v1"]["Zmm"]["2024G"] = "L2L3Res_inputs/upartreg_v1/zb/jme_bplusZ_merged_upartreg_v1_2024G.root";
mf["upartreg_v1"]["Zmm"]["2024H"] = "L2L3Res_inputs/upartreg_v1/zb/jme_bplusZ_merged_upartreg_v1_2024H.root";
mf["upartreg_v1"]["Zmm"]["2024I"] = "L2L3Res_inputs/upartreg_v1/zb/jme_bplusZ_merged_upartreg_v1_2024I.root";
// Z+jet MC file for UPART regression
mf["upartreg_v1"]["Zmm"]["MC"] = "";

// Z+jet Data files for UPART regression Closure
mf["upartreg_v1_closure"]["Zmm"]["2024C"] = "L2L3Res_inputs/upartreg_v1_closure/zb/jme_bplusZ_merged_upartreg_v1_closure_2024C.root";
mf["upartreg_v1_closure"]["Zmm"]["2024D"] = "L2L3Res_inputs/upartreg_v1_closure/zb/jme_bplusZ_merged_upartreg_v1_closure_2024D.root";
mf["upartreg_v1_closure"]["Zmm"]["2024E"] = "L2L3Res_inputs/upartreg_v1_closure/zb/jme_bplusZ_merged_upartreg_v1_closure_2024E.root";
mf["upartreg_v1_closure"]["Zmm"]["2024F"] = "L2L3Res_inputs/upartreg_v1_closure/zb/jme_bplusZ_merged_upartreg_v1_closure_2024F.root";
mf["upartreg_v1_closure"]["Zmm"]["2024G"] = "L2L3Res_inputs/upartreg_v1_closure/zb/jme_bplusZ_merged_upartreg_v1_closure_2024G.root";
mf["upartreg_v1_closure"]["Zmm"]["2024H"] = "L2L3Res_inputs/upartreg_v1_closure/zb/jme_bplusZ_merged_upartreg_v1_closure_2024H.root";
mf["upartreg_v1_closure"]["Zmm"]["2024I"] = "L2L3Res_inputs/upartreg_v1_closure/zb/jme_bplusZ_merged_upartreg_v1_closure_2024I.root";
// Z+jet MC file for UPART regression Closure
mf["upartreg_v1_closure"]["Zmm"]["MC"] = "";

// Z+jet Data files for UPART regression with neutrinos
mf["upartreg_neutrino_v1"]["Zmm"]["2024C"] = "L2L3Res_inputs/upartreg_neutrino_v1/zb/jme_bplusZ_merged_upartreg_neutrino_v1_2024C.root";
mf["upartreg_neutrino_v1"]["Zmm"]["2024D"] = "L2L3Res_inputs/upartreg_neutrino_v1/zb/jme_bplusZ_merged_upartreg_neutrino_v1_2024D.root";
mf["upartreg_neutrino_v1"]["Zmm"]["2024E"] = "L2L3Res_inputs/upartreg_neutrino_v1/zb/jme_bplusZ_merged_upartreg_neutrino_v1_2024E.root";
mf["upartreg_neutrino_v1"]["Zmm"]["2024F"] = "L2L3Res_inputs/upartreg_neutrino_v1/zb/jme_bplusZ_merged_upartreg_neutrino_v1_2024F.root";
mf["upartreg_neutrino_v1"]["Zmm"]["2024G"] = "L2L3Res_inputs/upartreg_neutrino_v1/zb/jme_bplusZ_merged_upartreg_neutrino_v1_2024G.root";
mf["upartreg_neutrino_v1"]["Zmm"]["2024H"] = "L2L3Res_inputs/upartreg_neutrino_v1/zb/jme_bplusZ_merged_upartreg_neutrino_v1_2024H.root";
mf["upartreg_neutrino_v1"]["Zmm"]["2024I"] = "L2L3Res_inputs/upartreg_neutrino_v1/zb/jme_bplusZ_merged_upartreg_neutrino_v1_2024I.root";
// Z+jet MC file for UPART regression with neutrinos
mf["upartreg_neutrino_v1"]["Zmm"]["MC"] = "";

// Z+jet Data files for UPART regression with neutrinos CLosure
mf["upartreg_neutrino_v1_closure"]["Zmm"]["2024C"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/zb/jme_bplusZ_merged_upartreg_neutrino_v1_closure_2024C.root";
mf["upartreg_neutrino_v1_closure"]["Zmm"]["2024D"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/zb/jme_bplusZ_merged_upartreg_neutrino_v1_closure_2024D.root";
mf["upartreg_neutrino_v1_closure"]["Zmm"]["2024E"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/zb/jme_bplusZ_merged_upartreg_neutrino_v1_closure_2024E.root";
mf["upartreg_neutrino_v1_closure"]["Zmm"]["2024F"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/zb/jme_bplusZ_merged_upartreg_neutrino_v1_closure_2024F.root";
mf["upartreg_neutrino_v1_closure"]["Zmm"]["2024G"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/zb/jme_bplusZ_merged_upartreg_neutrino_v1_closure_2024G.root";
mf["upartreg_neutrino_v1_closure"]["Zmm"]["2024H"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/zb/jme_bplusZ_merged_upartreg_neutrino_v1_closure_2024H.root";
mf["upartreg_neutrino_v1_closure"]["Zmm"]["2024I"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/zb/jme_bplusZ_merged_upartreg_neutrino_v1_closure_2024I.root";
// Z+jet MC file for UPART regression with neutrinos Closure
mf["upartreg_neutrino_v1_closure"]["Zmm"]["MC"] = "";

// Gam+jet Data files for PNET regression
mf["pnetreg_v1"]["Gam"]["2024C"] = "L2L3Res_inputs/pnetreg_v1/gam/GamHistosFill_data_2024C_pnetreg_v1.root";
mf["pnetreg_v1"]["Gam"]["2024D"] = "L2L3Res_inputs/pnetreg_v1/gam/GamHistosFill_data_2024D_pnetreg_v1.root";
mf["pnetreg_v1"]["Gam"]["2024E"] = "L2L3Res_inputs/pnetreg_v1/gam/GamHistosFill_data_2024E_pnetreg_v1.root";
mf["pnetreg_v1"]["Gam"]["2024F"] = "L2L3Res_inputs/pnetreg_v1/gam/GamHistosFill_data_2024F_pnetreg_v1.root";
mf["pnetreg_v1"]["Gam"]["2024G"] = "L2L3Res_inputs/pnetreg_v1/gam/GamHistosFill_data_2024G_pnetreg_v1.root";
mf["pnetreg_v1"]["Gam"]["2024H"] = "L2L3Res_inputs/pnetreg_v1/gam/GamHistosFill_data_2024H_pnetreg_v1.root";
mf["pnetreg_v1"]["Gam"]["2024I"] = "L2L3Res_inputs/pnetreg_v1/gam/GamHistosFill_data_2024I_pnetreg_v1.root";
// Gam+jet MC file for PNET regression
mf["pnetreg_v1"]["Gam"]["MC"] = "L2L3Res_inputs/pnetreg_v1/gam/GamHistosFill_mc_2024P8_pnetreg_v1.root";

// Gam+jet Data files for PNET regression Closure
mf["pnetreg_v1_closure"]["Gam"]["2024C"] = "L2L3Res_inputs/pnetreg_v1_closure/gam/GamHistosFill_data_2024C_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Gam"]["2024D"] = "L2L3Res_inputs/pnetreg_v1_closure/gam/GamHistosFill_data_2024D_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Gam"]["2024E"] = "L2L3Res_inputs/pnetreg_v1_closure/gam/GamHistosFill_data_2024E_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Gam"]["2024F"] = "L2L3Res_inputs/pnetreg_v1_closure/gam/GamHistosFill_data_2024F_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Gam"]["2024G"] = "L2L3Res_inputs/pnetreg_v1_closure/gam/GamHistosFill_data_2024G_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Gam"]["2024H"] = "L2L3Res_inputs/pnetreg_v1_closure/gam/GamHistosFill_data_2024H_pnetreg_v1_closure.root";
mf["pnetreg_v1_closure"]["Gam"]["2024I"] = "L2L3Res_inputs/pnetreg_v1_closure/gam/GamHistosFill_data_2024I_pnetreg_v1_closure.root";
// Gam+jet MC file for PNET regression Closure
mf["pnetreg_v1_closure"]["Gam"]["MC"] = "L2L3Res_inputs/pnetreg_v1_closure/gam/GamHistosFill_mc_2024P8_pnetreg_v1_closure.root";

// Gam+jet Data files for PNET regression with neutrinos
mf["pnetreg_neutrino_v1"]["Gam"]["2024C"] = "L2L3Res_inputs/pnetreg_neutrino_v1/gam/GamHistosFill_data_2024C_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Gam"]["2024D"] = "L2L3Res_inputs/pnetreg_neutrino_v1/gam/GamHistosFill_data_2024D_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Gam"]["2024E"] = "L2L3Res_inputs/pnetreg_neutrino_v1/gam/GamHistosFill_data_2024E_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Gam"]["2024F"] = "L2L3Res_inputs/pnetreg_neutrino_v1/gam/GamHistosFill_data_2024F_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Gam"]["2024G"] = "L2L3Res_inputs/pnetreg_neutrino_v1/gam/GamHistosFill_data_2024G_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Gam"]["2024H"] = "L2L3Res_inputs/pnetreg_neutrino_v1/gam/GamHistosFill_data_2024H_pnetreg_neutrino_v1.root";
mf["pnetreg_neutrino_v1"]["Gam"]["2024I"] = "L2L3Res_inputs/pnetreg_neutrino_v1/gam/GamHistosFill_data_2024I_pnetreg_neutrino_v1.root";
// Gam+jet MC file for PNET regression with neutrinos
mf["pnetreg_neutrino_v1"]["Gam"]["MC"] = "L2L3Res_inputs/pnetreg_neutrino_v1/gam/GamHistosFill_mc_2024P8_pnetreg_neutrino_v1.root";

// Gam+jet Data files for PNET regression with neutrinos Closure
mf["pnetreg_neutrino_v1_closure"]["Gam"]["2024C"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/gam/GamHistosFill_data_2024C_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Gam"]["2024D"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/gam/GamHistosFill_data_2024D_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Gam"]["2024E"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/gam/GamHistosFill_data_2024E_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Gam"]["2024F"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/gam/GamHistosFill_data_2024F_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Gam"]["2024G"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/gam/GamHistosFill_data_2024G_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Gam"]["2024H"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/gam/GamHistosFill_data_2024H_pnetreg_neutrino_v1_closure.root";
mf["pnetreg_neutrino_v1_closure"]["Gam"]["2024I"] = "L2L3Res_inputs/pnetreg_neutrino_v1_closure/gam/GamHistosFill_data_2024I_pnetreg_neutrino_v1_closure.root";
// Gam+jet MC file for PNET regression with neutrinos Closure
mf["pnetreg_neutrino_v1_closure"]["Gam"]["MC"] = "L2L3Res_inputs/pnetreg_neutrino_v1/gam/GamHistosFill_mc_2024P8_pnetreg_neutrino_v1.root";

// Gam+jet Data files for UPART regression
mf["upartreg_v1"]["Gam"]["2024C"] = "L2L3Res_inputs/upartreg_v1/gam/GamHistosFill_data_2024C_upartreg_v1.root";
mf["upartreg_v1"]["Gam"]["2024D"] = "L2L3Res_inputs/upartreg_v1/gam/GamHistosFill_data_2024D_upartreg_v1.root";
mf["upartreg_v1"]["Gam"]["2024E"] = "L2L3Res_inputs/upartreg_v1/gam/GamHistosFill_data_2024E_upartreg_v1.root";
mf["upartreg_v1"]["Gam"]["2024F"] = "L2L3Res_inputs/upartreg_v1/gam/GamHistosFill_data_2024F_upartreg_v1.root";
mf["upartreg_v1"]["Gam"]["2024G"] = "L2L3Res_inputs/upartreg_v1/gam/GamHistosFill_data_2024G_upartreg_v1.root";
mf["upartreg_v1"]["Gam"]["2024H"] = "L2L3Res_inputs/upartreg_v1/gam/GamHistosFill_data_2024H_upartreg_v1.root";
mf["upartreg_v1"]["Gam"]["2024I"] = "L2L3Res_inputs/upartreg_v1/gam/GamHistosFill_data_2024I_upartreg_v1.root";
// Gam+jet MC file for UPART regression
mf["upartreg_v1"]["Gam"]["MC"] = "L2L3Res_inputs/upartreg_v1/gam/GamHistosFill_mc_2024P8_upartreg_v1.root";

// Gam+jet Data files for UPART regression Closure
mf["upartreg_v1_closure"]["Gam"]["2024C"] = "L2L3Res_inputs/upartreg_v1_closure/gam/GamHistosFill_data_2024C_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Gam"]["2024D"] = "L2L3Res_inputs/upartreg_v1_closure/gam/GamHistosFill_data_2024D_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Gam"]["2024E"] = "L2L3Res_inputs/upartreg_v1_closure/gam/GamHistosFill_data_2024E_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Gam"]["2024F"] = "L2L3Res_inputs/upartreg_v1_closure/gam/GamHistosFill_data_2024F_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Gam"]["2024G"] = "L2L3Res_inputs/upartreg_v1_closure/gam/GamHistosFill_data_2024G_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Gam"]["2024H"] = "L2L3Res_inputs/upartreg_v1_closure/gam/GamHistosFill_data_2024H_upartreg_v1_closure.root";
mf["upartreg_v1_closure"]["Gam"]["2024I"] = "L2L3Res_inputs/upartreg_v1_closure/gam/GamHistosFill_data_2024I_upartreg_v1_closure.root";
// Gam+jet MC file for UPART regression Closure
mf["upartreg_v1_closure"]["Gam"]["MC"] = "L2L3Res_inputs/upartreg_v1_closure/gam/GamHistosFill_mc_2024P8_upartreg_v1_closure.root";

// Gam+jet Data files for UPART regression with neutrinos
mf["upartreg_neutrino_v1"]["Gam"]["2024C"] = "L2L3Res_inputs/upartreg_neutrino_v1/gam/GamHistosFill_data_2024C_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Gam"]["2024D"] = "L2L3Res_inputs/upartreg_neutrino_v1/gam/GamHistosFill_data_2024D_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Gam"]["2024E"] = "L2L3Res_inputs/upartreg_neutrino_v1/gam/GamHistosFill_data_2024E_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Gam"]["2024F"] = "L2L3Res_inputs/upartreg_neutrino_v1/gam/GamHistosFill_data_2024F_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Gam"]["2024G"] = "L2L3Res_inputs/upartreg_neutrino_v1/gam/GamHistosFill_data_2024G_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Gam"]["2024H"] = "L2L3Res_inputs/upartreg_neutrino_v1/gam/GamHistosFill_data_2024H_upartreg_neutrino_v1.root";
mf["upartreg_neutrino_v1"]["Gam"]["2024I"] = "L2L3Res_inputs/upartreg_neutrino_v1/gam/GamHistosFill_data_2024I_upartreg_neutrino_v1.root";
// Gam+jet MC file for UPART regression with neutrinos
mf["upartreg_neutrino_v1"]["Gam"]["MC"] = "L2L3Res_inputs/upartreg_neutrino_v1/gam/GamHistosFill_mc_2024P8_upartreg_neutrino_v1.root";

// Gam+jet Data files for UPART regression with neutrinos Closure
mf["upartreg_neutrino_v1_closure"]["Gam"]["2024C"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/gam/GamHistosFill_data_2024C_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Gam"]["2024D"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/gam/GamHistosFill_data_2024D_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Gam"]["2024E"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/gam/GamHistosFill_data_2024E_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Gam"]["2024F"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/gam/GamHistosFill_data_2024F_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Gam"]["2024G"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/gam/GamHistosFill_data_2024G_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Gam"]["2024H"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/gam/GamHistosFill_data_2024H_upartreg_neutrino_v1_closure.root";
mf["upartreg_neutrino_v1_closure"]["Gam"]["2024I"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/gam/GamHistosFill_data_2024I_upartreg_neutrino_v1_closure.root";
// Gam+jet MC file for UPART regression with neutrinos Closure
mf["upartreg_neutrino_v1_closure"]["Gam"]["MC"] = "L2L3Res_inputs/upartreg_neutrino_v1_closure/gam/GamHistosFill_mc_2024P8_upartreg_neutrino_v1_closure.root";

#endif
