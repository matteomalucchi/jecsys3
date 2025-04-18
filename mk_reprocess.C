{
  // make sure asserts are run
  #undef NDEBUG
  // does not seem to be enough, also need to combile with +g

  // For JEC residual (and pile-up)

  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/Utilities.cc+");
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/JetCorrectorParameters.cc+");
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/SimpleJetCorrector.cc+");
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/FactorizedJetCorrector.cc+");
  //
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/SimpleJetCorrectionUncertainty.cc+");
  gROOT->ProcessLine(".L CondFormats/JetMETObjects/src/JetCorrectionUncertainty.cc+");

  // Compile with +g to make sure asserts are run
  gROOT->ProcessLine(".L tools.C+g");
  gROOT->ProcessLine(".L Flavor.C+g");
  gROOT->ProcessLine(".L reprocess.C+g");
  // gROOT->ProcessLine(".L scaleJES.C+g");
  gROOT->ProcessLine(".L softrad3.C+g");
  //gROOT->ProcessLine(".L globalFitSyst.C+g");
  //gROOT->ProcessLine(".L globalFitRenormPF.C+g");
  gROOT->ProcessLine(".L globalFit.C+g");

  // Merge inputs from separate groups
  // NB: this does not need to be run, if the merged inputs
  //     are already available in 'rootfiles/jecdata.root'
  string epoch = "Run22C";//"Run23B";//"Run3";//"RunCD";
  #ifdef epochname
  // std::cout << epoch.c_str()<< std::endl;
  // std::cout << inputepoch.c_str()<< std::endl;
  epoch = inputepoch;
  std::cout << epoch.c_str()<< std::endl;
  #endif



  // Read in files from different groups and merge them in jecdata[epoch].root
  reprocess(epoch, version, closure); // Comment out if using archived jecdata[epoch].root

  // Code for 19Dec2023 use only!
  // Scale Z+jet, gamma+jet (and multijet) from 22Sep2023 to 19Dec2023
  //if (epoch!="Run3" && epoch!="Run22FG") { // Run3,22FG inputs already scaled
  //scaleJES(epoch, "zjet");
  //}
  //if (epoch!="Run22FG") { // Run22FG inputs already scaled (19Dec)
  //scaleJES(epoch, "gamjet");
  //}
  //scaleJES(epoch, "multijet"); // 19Dec no scaling needed

  // HDM method: use HT decomposition (lead, soft jets, unclustered) for FSR
  softrad3(0.0,1.3,epoch, version); // 3-point FSR

  // Produce central systematic uncertainties for globalFitL3Res
  //globalFitSyst(epoch);     // also for globalFitRun2.C
  //globalFitRenormPF(epoch); // for globalFitRun2.C

  // string gaus_prior_string = (run=="Run23C4" && closure=="False") ? "bool gaus_prior(false);" : "bool gaus_prior(true);";
  // gauss_prior_char = gaus_prior_string.c_str();
  // cout<<gaus_prior_string<<endl;
  // gROOT->ProcessLine(gauss_prior_char);

  // bool gaus_prior(true);
  // if  (epoch=="Run23C4" && closure=="False") {
  //   gaus_prior = false;
  // }
  // cout<<"gaus_prior" << gaus_prior << endl;

  // #define gaus_prior
  // if  (epoch=="Run23C4" && closure=="False") {
  //   #undef gaus_prior
  // }


  // Run global fit
  /////////////////
  //globalFitEtaBin(0.0, 1.3, epoch, "22Sep2023reV3");
  //globalFitEtaBin(0.0, 1.3, epoch, "19Dec2023");
  //globalFitEtaBin(0.0, 1.3, epoch, "Summer23");
  //globalFitEtaBin(0.0, 1.3, epoch, "Summer23_V1test");

  globalFitEtaBin(0.0, 1.3, epoch, version, closure);

  exit(0); // Avoid page full of THastList::Delete errors
}
