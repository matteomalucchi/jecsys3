void mk_reprocess_RunEpoch(std::string inepoch="", std::string version="", std::string closure="") {
  #define epochname

  gROOT->ProcessLine(Form("string inputepoch(\"%s\");",inepoch.c_str()));
  gROOT->ProcessLine(Form("string version(\"%s\");",version.c_str()));
  gROOT->ProcessLine(Form("string closure(\"%s\");",closure.c_str()));
  gROOT->ProcessLine(".x mk_reprocess.C");
}
