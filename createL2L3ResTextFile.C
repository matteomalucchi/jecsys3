// Purpose: Create L2L3Res text file with simple parameterization
//          Takes as input previous L2Res and complex 9p global JES fit
//          Outputs same L2Res and "simple" 7p->8p fit
//          ("simple" as in removing main parameter degeneracies)
//          For merging IOVs together at text file level, use
//          [minitools/mergeL2L3ResTextFiles.C]
#include "TString.h"
#include "TF1.h"
#include "TH1D.h"
#include "TFile.h"
#include "TLine.h"

#include "tdrstyle_mod22.C"

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

string version_string = "rescaleMass_removeCorrectEvents_removeNAN_StandardPt_mctruth15_NewRunCrabSkim";
const char * version = version_string.c_str();

string YEAR = "2022";
bool DO_2022FG = false;



const bool debug = true;

void createL2L3ResTextFiles(string set, bool leg2=false);

TLegend *_leg(0), *_leg2(0);
void createL2L3ResTextFile() {

  setTDRStyle();

  double ptmin = 15;
  double ptmax = 4500;
  TH1D *h = tdrHist("h","Absolute response at |#eta| < 1.3",
		    0.75+1e-4,1.20-1e-4,"p_{T} (GeV)",ptmin,ptmax);
		    //0.90+1e-4,1.30-1e-4,"p_{T} (GeV)",ptmin,ptmax);
		    //0.88+1e-4,1.05-1e-4,"p_{T} (GeV)",ptmin,ptmax);
  lumi_136TeV = Form("%s      Run3, 63 fb^{-1}",
    TString(version).Contains("neutrino") ? "PNet incl. neutrinos" : "PNet"); // Not including 23B
 TCanvas *c1 = tdrCanvas("c1",h,8,11,kSquare);
  c1->SetLeftMargin(0.17);
  c1->SetRightMargin(0.03);
  h->SetTitleOffset(1.5,"Y");
  gPad->SetLogx();

  TLine *l = new TLine();
  l->SetLineStyle(kDashed);
  l->DrawLine(ptmin,1,ptmax,1);

  _leg = tdrLeg(0.45,0.90,0.75,0.90);
  _leg2 = tdrLeg(0.20,0.15,0.50,0.15);

  //h->SetMinimum(0.70+1e-4); // Summer22
  /*
  createL2L3ResTextFiles("Run23C123-Prompt",true);
  createL2L3ResTextFiles("Run23C4-Prompt",true);
  createL2L3ResTextFiles("Run23D-Prompt",true);
  //createL2L3ResTextFiles("Run23C4D-Prompt",true);
  createL2L3ResTextFiles("Run3-Combo",true);
  c1->Update();
  c1->SaveAs("pdf/createL2L3ResTextFile_Summer22_reV3_Run22CDE-22Sep2023_22FG-Prompt_23CD-Prompt_Run3-Combo.pdf");
  */
  gROOT->ProcessLine(Form(".! mkdir -p pdf/%s",version));

  if (YEAR == "2023" || YEAR == "all"){
  createL2L3ResTextFiles("Run23C123-Summer23",true);
  createL2L3ResTextFiles("Run23C4-Summer23",true);
  createL2L3ResTextFiles("Run23D-Summer23",true);
  }
  if (YEAR == "2022" || YEAR == "all"){
  createL2L3ResTextFiles("Run22CD-22Sep2023",true);
  createL2L3ResTextFiles("Run22E-22Sep2023",true);
  createL2L3ResTextFiles("Run22F-22Sep2023",true);
  createL2L3ResTextFiles("Run22G-22Sep2023",true);
  if (DO_2022FG) createL2L3ResTextFiles("Run22FG-22Sep2023",true);
  }
  c1->Update();

  string summer_str;
  if (YEAR == "2023") {summer_str = "Summer23";}
  if (YEAR == "2022") {summer_str = "Summer22";}
  if (YEAR == "all") {summer_str = "Run3";}
  const char * summer = summer_str.c_str();

  //c1->SaveAs("pdf/createL2L3ResTextFile_Summer23_V1.pdf");
  c1->SaveAs(Form("pdf/%s/createL2L3ResTextFile_%s_V1_%s.pdf", version,summer, version));


  /*
  // Produce Run2 year-averages for reprocess.C reference (jec, jecold)
  // Use files in jecsys2020 directory, not jecsys3
  h->GetYaxis()->SetRangeUser(0.94+1e-4,1.06-1e-4);
  createL2L3ResTextFiles("2016BCDEF");
  createL2L3ResTextFiles("2016GH");
  createL2L3ResTextFiles("2017BCDEF");
  createL2L3ResTextFiles("2018ABCD");
  c1->Update();
  c1->SaveAs("pdf/createL2L3ResTextFile_Run2UL_JECV7.pdf");
  */
}

void createL2L3ResTextFiles(string set, bool leg2) {

  //if (debug)
  cout << "****************************************************************\n";
  cout << "Warning: sscanf only works correctly when code is compiled (.C+)\n";
  cout << "****************************************************************\n";

  cout << "** Processing " << set << " **" << endl << flush;
  cout << "******************************\n";

  // Simplify complex sum into an effective formula
  // Need good starting values and/or a few iterations to converge
  // Fit done to hjesfit from each IOV
  TDirectory *curdir = gDirectory;
  TFile *f(0);
  bool isRun3(false);
  //TFile *f = new TFile(Form("rootfiles/jecdata%s.root",set.c_str()),"READ");
  if (set=="Ref") { // reference JEC
    f = new TFile("rootfiles/jecdataRunCD_v6.root","READ");
  }
  else if (set=="2016BCDEF") {
    f = new TFile("../jecsys2020/rootfiles/jecdata2016BCDEF.root","READ");
  }
  else if (set=="2016GH") {
    f = new TFile("../jecsys2020/rootfiles/jecdata2016GH.root","READ");
  }
  else if (set=="2017BCDEF") {
    f = new TFile("../jecsys2020/rootfiles/jecdata2017BCDEF.root","READ");
  }
  else if (set=="2018ABCD") {
    f = new TFile("../jecsys2020/rootfiles/jecdata2018ABCD.root","READ");
  }
  else if (set=="Run22CD-22Sep2023") {
    f = new TFile(Form("rootfiles/jecdata_Run22CD_%s.root", version),"READ"); isRun3=true;
  }
  else if (set=="Run22E-22Sep2023") {
    f = new TFile(Form("rootfiles/jecdata_Run22E_%s.root", version),"READ"); isRun3=true;
  }
  else if (set=="Run22F-22Sep2023") {
    f = new TFile(Form("rootfiles/jecdata_Run22F_%s.root", version),"READ"); isRun3=true;
  }
  else if (set=="Run22G-22Sep2023") {
    f = new TFile(Form("rootfiles/jecdata_Run22G_%s.root", version),"READ"); isRun3=true;
  }
  else if (set=="Run22FG-22Sep2023") {
    f = new TFile(Form("rootfiles/jecdata_Run22FG_%s.root", version),"READ"); isRun3=true;
  }
  //else if (set=="Run23C123-Prompt") {
  else if (set=="Run23C123-Summer23") {
    f = new TFile(Form("rootfiles/jecdata_Run23C123_%s%s.root", version, ""),"READ"); isRun3=true;
  }
  //else if (set=="Run23C4-Prompt") {
  else if (set=="Run23C4-Summer23") {
    f = new TFile(Form("rootfiles/jecdata_Run23C4_%s%s.root", version, ""),"READ"); isRun3=true;
  }
  //else if (set=="Run23D-Prompt") {
  else if (set=="Run23D-Summer23") {
    f = new TFile(Form("rootfiles/jecdata_Run23D_%s%s.root", version, ""),"READ"); isRun3=true;
  }
  //else if (set=="Run23C4D-Prompt") {
  else if (set=="Run23C4D-Summer23") {
    f = new TFile("rootfiles/jecdataRun23C4D.root","READ"); isRun3=true;
  }
  else if (set=="Run3-Combo") {
    // use input to the global fit for pre-fit average JEC
    f = new TFile("rootfiles/jecdataRun3Data.root","READ"); isRun3=true;
  }
  else
    f = new TFile(Form("rootfiles/jecdata%s.root",set.c_str()),"READ");

  assert(f && !f->IsZombie());
  TH1D *h(0);
  //h = (TH1D*)f->Get("ratio/eta00-13/sys/hjesfit2");
  //if (!h) h = (TH1D*)f->Get("ratio/eta00-13/sys/hjesfit");
  if (!h) h = (TH1D*)f->Get("ratio/eta00-13/run3/hFit_Rjet");
  //if (!h) h = (TH1D*)f->Get("ratio/eta00-13/sys/hjesfit2"); // Run2 refit
  if (!h) h = (TH1D*)f->Get("ratio/eta00-13/herr_l2l3res"); // Run2 ref. JES
  assert(h);
  curdir->cd();

  TF1 *f1 = new TF1(Form("f1_%s",set.c_str()),"[0]+[1]/x+[2]*log(x)/x+[3]*(pow(x/[4],[5])-1)/(pow(x/[4],[5])+1)+[6]*pow(x,-0.3051)+[7]*x",15,4500);
  f1->SetParameters(0.98, 0.1,0.01, 0.01,500.,1.3, 0.001, 0);
  if (set=="2017H")
    f1->SetParameters(0.99, 1.5,0.01, 0.01,1000.,1.3, 0.001, 0.);
  if (!isRun3)
    f1->FixParameter(7, 0.);

  // To avoid division by zero errors
  f1->SetParLimits(4,10.,6500.);
  f1->SetParLimits(5,0.,10.);

  map<string,int> color;
  color["2016BCDEF"] = kYellow+2;
  color["2016GH"] = kRed;
  color["2017BCDEF"] = kGreen+2;
  color["2018ABCD"] = kBlue;

  color["Run22CD-22Sep2023"] = kGreen+2;
  color["Run22E-22Sep2023"] = kCyan+2;
  color["Run22F-22Sep2023"] = kRed;
  color["Run22G-22Sep2023"] = kRed+2;
  color["Run22FG-22Sep2023"] = kRed+3;
  color["Run22FG-Prompt"] = kRed;
  color["Run22F-Prompt"] = kRed;
  color["Run22G-Prompt"] = kRed+2;

  color["Run23C123-Prompt"] = kOrange+1;
  //color["Run23C4D-Prompt"] = kMagenta+2;
  color["Run23C4-Prompt"] = kBlue;
  color["Run23D-Prompt"] = kMagenta;
  color["Run3-Combo"] = kYellow+2;

  color["Run23C123-Summer23"] = kOrange+1;
  color["Run23C4-Summer23"] = kBlue;
  color["Run23D-Summer23"] = kMagenta;

  h->Fit(f1,"QRN");
  h->Fit(f1,"QRNM");
  h->Fit(f1,"QRNM");
  tdrDraw(h,"LE3",kNone,color[set],kSolid,-1,1001,color[set]-9);
  h->SetFillColorAlpha(color[set]-9,0.7);
  f1->SetLineColor(color[set]);
  f1->Draw("SAME");

  if (leg2)
    _leg2->SetY2(_leg2->GetY2()+0.05);
  else
    _leg->SetY1(_leg->GetY1()-0.05);
  if (set=="Ref")
    _leg->AddEntry(h,"Old 22C (ref.)","FL");
  else if (leg2)
    _leg2->AddEntry(h,set.c_str(),"FL");
  else
    _leg->AddEntry(h,set.c_str(),"FL");

  const int np = 8;//7;
  double p[np];
  for (int i = 0; i != np; ++i) {
    p[i] = f1->GetParameter(i);
  } // for i


  /////////////////////////////////////////////////////////////
  // Generate input and output file names semi-automatically  //
  //////////////////////////////////////////////////////////////
  const char *run = set.c_str();

  string sin(""), sout("");
  if (set=="2016BCDEF") {
    sin = "CondFormats/JetMETObjects/data/Summer19UL16APV_RunBCDEF_V7_DATA_L2L3Residual_AK4PFchs.txt";
  }
  if (set=="2016GH") {
    sin = "CondFormats/JetMETObjects/data/Summer19UL16_RunFGH_V7_DATA_L2L3Residual_AK4PFchs.txt";
  }
  if (set=="2017BCDEF") {
    sin = "CondFormats/JetMETObjects/data/Summer19UL17_RunE_V6_DATA_L2L3Residual_AK4PFchs.txt";
  }
  if (set=="2018ABCD") {
    sin = "CondFormats/JetMETObjects/data/Summer19UL18_RunD_V5_DATA_L2L3Residual_AK4PFchs.txt";
  }
  //
  if (set=="2016BCDEF" || set=="2016GH" || set=="2017BCDEF" || set=="2018ABCD")
   sout = Form("textfiles/%s_DATA_L2L3Residual_AK4PFchs.txt",run);

  bool isL2Res(false); bool isNewL2Res(false);
  // if (set=="Run22CD-22Sep2023") {
  //   sin = "textFiles/Run3_22Sep2023_v3/Summer22-22Sep2023_Run2022CD_V3_DATA_L2Residual_AK4PFPuppi.txt"; isL2Res = true;
  //   sout = "textFiles/Run3_22Sep2023_reV3/Summer22-22Sep2023_Run2022CD_reV3_DATA_L2L3Residual_AK4PFPuppi.txt";
  // }
  // if (set=="Run22E-22Sep2023") {
  //   sin = "textFiles/Run3_22Sep2023_v3/Summer22EE-22Sep2023_Run2022E_V3_DATA_L2Residual_AK4PFPuppi.txt"; isL2Res = true;
  //   sout = "textFiles/Run3_22Sep2023_reV3/Summer22EE-22Sep2023_Run2022E_reV3_DATA_L2L3Residual_AK4PFPuppi.txt";
  // }
  // if (set=="Run22F-Prompt") {
  //   sin = "textFiles/Run3_22Sep2023_v3/Summer22EEPrompt22_Run2022F_V3_DATA_L2Residual_AK4PFPuppi.txt"; isL2Res = true;
  //   sout = "textFiles/Run3_22Sep2023_reV3/Summer22EEPrompt22_Run2022F_reV3_DATA_L2L3Residual_AK4PFPuppi.txt";
  // }
  // if (set=="Run22G-Prompt") {
  //   sin = "textFiles/Run3_22Sep2023_v3/Summer22EEPrompt22_Run2022G_V3_DATA_L2Residual_AK4PFPuppi.txt";  isL2Res = true;
  //   sout = "textFiles/Run3_22Sep2023_reV3/Summer22EEPrompt22_Run2022G_reV3_DATA_L2L3Residual_AK4PFPuppi.txt";
  // }
  if (set=="Run22CD-22Sep2023") {
    sin = Form("textfiles/%s/Summer22-22Sep2023_Run2022CD_V1_DATA_L2Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ; isNewL2Res = true;
    sout = Form("textfiles/%s/Summer22-22Sep2023_Run2022CD_V1_DATA_L2L3Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ;
  }
  if (set=="Run22E-22Sep2023") {
    sin = Form("textfiles/%s/Summer22EE-22Sep2023_Run2022E_V1_DATA_L2Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ; isNewL2Res = true;
    sout = Form("textfiles/%s/Summer22EE-22Sep2023_Run2022E_V1_DATA_L2L3Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ;
  }
  if (set=="Run22F-22Sep2023") {
    sin = Form("textfiles/%s/Summer22EE-22Sep2023_Run2022F_V1_DATA_L2Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ; isNewL2Res = true;
    sout = Form("textfiles/%s/Summer22EE-22Sep2023_Run2022F_V1_DATA_L2L3Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ;
  }
  if (set=="Run22G-22Sep2023") {
    sin = Form("textfiles/%s/Summer22EE-22Sep2023_Run2022G_V1_DATA_L2Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ; isNewL2Res = true;
    sout = Form("textfiles/%s/Summer22EE-22Sep2023_Run2022G_V1_DATA_L2L3Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ;
  }
  if (set=="Run22FG-22Sep2023") {
    sin = Form("textfiles/%s/Summer22EE-22Sep2023_Run2022FG_V1_DATA_L2Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ; isNewL2Res = true;
    sout = Form("textfiles/%s/Summer22EE-22Sep2023_Run2022FG_V1_DATA_L2L3Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ;
  }
  /*
  if (set=="Run23C123-Prompt") {
    sin = "textFiles/Run3_22Sep2023_v3/Summer22Prompt23_Run2023Cv123_V3_DATA_L2Residual_AK4PFPUPPI.txt"; isL2Res = true;
    sout = "textFiles/Run3_22Sep2023_reV3/Summer22Prompt23_Run2023Cv123_reV3_DATA_L2L3Residual_AK4PFPUPPI.txt";
  }
  if (set=="Run23C4-Prompt") {
    sin = "textFiles/Run3_22Sep2023_v3/Summer22Prompt23_Run2023Cv4_V3_DATA_L2Residual_AK4PFPUPPI.txt"; isL2Res = true;
    sout = "textFiles/Run3_22Sep2023_reV3/Summer22Prompt23_Run2023Cv4_reV3_DATA_L2L3Residual_AK4PFPUPPI.txt";
  }
  if (set=="Run23D-Prompt") {
    sin = "textFiles/Run3_22Sep2023_v3/Summer22Prompt23_Run2023D_V3_DATA_L2Residual_AK4PFPUPPI.txt"; isL2Res = true;
    sout = "textFiles/Run3_22Sep2023_reV3/Summer22Prompt23_Run2023D_reV3_DATA_L2L3Residual_AK4PFPUPPI.txt";
  }
  */
  if (set=="Run23C123-Summer23") {
    sin = Form("textfiles/%s/Summer23-22Sep2023_Run2023Cv123_V1_DATA_L2Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ; isNewL2Res = true;
    sout = Form("textfiles/%s/Summer23-22Sep2023_Run2023Cv123_V1_DATA_L2L3Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ;
  }
  if (set=="Run23C4-Summer23") {
    sin = Form("textfiles/%s/Summer23-22Sep2023_Run2023Cv4_V1_DATA_L2Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ; isNewL2Res = true;
    sout = Form("textfiles/%s/Summer23-22Sep2023_Run2023Cv4_V1_DATA_L2L3Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ;
  }
  if (set=="Run23D-Summer23") {
    sin = Form("textfiles/%s/Summer23BPix-22Sep2023_Run2023D_V1_DATA_L2Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ; isNewL2Res = true;
    sout = Form("textfiles/%s/Summer23BPix-22Sep2023_Run2023D_V1_DATA_L2L3Residual_AK4PFPNet%s.txt", version,
              TString(version).Contains("neutrino") ? "PlusNeutrino" : "") ;
  }

  if (set=="Run3-Combo") {
    sin = "textFiles/Run3_22Sep2023_v3/Summer22Prompt23_Run2023D_V3_DATA_L2Residual_AK4PFPUPPI.txt"; isL2Res = true; // placeholder L2Res
    sout = "textFiles/Run3_22Sep2023_reV3/Summer22Prompt23_Run3_reV3_DATA_L2L3Residual_AK4PFPUPPI.txt";
  }

  assert(sin!="");
  assert(sout!="");
  assert(sout!=sin);

  cout << "Reading in L2Residual file:" << endl
       << "   " << sin << endl << flush;
  ifstream fin(sin.c_str());
  assert(fin.is_open());

  cout << "Writing out L2L3Residual file:" << endl
       << "   " << sout << endl << flush;
  ofstream fout(sout.c_str());

  // 2018: https://twiki.cern.ch/twiki/bin/view/CMSPublic/PixelOfflinePlotsOctober2018

  string header;
  getline(fin, header);
  if (debug) cout << "Old L2L3Residual header:" << endl;
  if (debug) cout << header << endl;

  //header = "{ 1 JetEta 1 JetPt [2]*([3]*([4]+[5]*TMath::Log(max([0],min([1],x))))*1./([6]+[7]/x+[8]*log(x)/x+[9]*(pow(x/[10],[11])-1)/(pow(x/[10],[11])+1)+[12]*pow(x,-0.3051))) Correction L2Relative}";
  if (isRun3 && isNewL2Res) {
    header =
      "{ 1 JetEta 1 JetPt 1./([0]+[1]*log10(0.01*x)+[2]/(x/10.))"
      "*1./([3]+[4]/x+[5]*log(x)/x+[6]*(pow(x/[7],[8])-1)/(pow(x/[7],[8])+1)+[9]*pow(x,-0.3051)+[10]*x)"
      " Correction L2Relative}";
  }
  else if (isRun3) {
    //Old L2Residual header: [2]*([3]*([4]+TMath::Log(max([0],min([1],x)))*([5]+TMath::Log(max([0],min([1],x)))*[6])+[7]/x))
    header = "{ 1 JetEta 1 JetPt [2]*([3]*([4]+TMath::Log(max([0],min([1],x)))*([5]+TMath::Log(max([0],min([1],x)))*[6])+[7]/x))*1./([8]+[9]/x+[10]*log(x)/x+[11]*(pow(x/[12],[13])-1)/(pow(x/[12],[13])+1)+[14]*pow(x,-0.3051)+[15]*x) Correction L2Relative}";
  }
  else {
    header = "{ 1 JetEta 1 JetPt [2]*([3]*([4]+[5]*TMath::Log(max([0],min([1],x))))*1./([6]+[7]/x+[8]*log(x)/x+[9]*(pow(x/[10],[11])-1)/(pow(x/[10],[11])+1)+[12]*pow(x,-0.3051))) Correction L2Relative}";
  }
  //([6]+[7]*100./3.*(TMath::Max(0.,1.03091-0.051154*pow(x,-0.154227))-TMath::Max(0.,1.03091-0.051154*TMath::Power(208.,-0.154227)))+[8]*0.021*(-1.+1./(1.+exp(-(TMath::Log(x)-5.030)/0.395))))) Correction L2Relative}
  if (debug) cout << "New L2L3Residual header:" << endl;
  if (debug) cout << header << endl;
  fout << header << endl;

  string line;
  double etamin(0), etamax(0);
  int npar(0), xmin(0), xmax(0), ptmin0(0), ptmax1(0);
  double p0(0), p1(0); // isNewL2Res
  double p2(0), p3(0), p4(0), p5(0);
  double p6(0), p7(0), p8(0);
  double p9(0), p10(0); // isRun3
  int cnt(0); int cntmax(0);
  while (getline(fin,line)) {
    if (cnt<cntmax && debug) cout << line << endl;
    if (isRun3 && isNewL2Res) {
     cout << line.c_str() << endl;
      assert(sscanf(line.c_str(),"%lf %lf  %d  %d %d  %lf %lf %lf",
		    &etamin, &etamax, &npar, &xmin, &xmax,
		    &p0, &p1, &p2)==8);
    }
    else if (isRun3 && isL2Res) {
      assert(sscanf(line.c_str(),"%lf %lf  %d  %d %d  %d %d  %lf %lf %lf %lf"
		    "  %lf %lff",
		    &etamin, &etamax, &npar, &xmin, &xmax, &ptmin0, &ptmax1,
		    &p2, &p3, &p4, &p5,  &p6, &p7)==13);
    }
    else if (isRun3 && !isL2Res) {
      assert(false);
    }
    else {
      assert(sscanf(line.c_str(),"%lf %lf  %d  %d %d  %d %d  %lf %lf %lf %lf"
		    "  %lf %lf %lf",
		    &etamin, &etamax, &npar, &xmin, &xmax, &ptmin0, &ptmax1,
		    &p2, &p3, &p4, &p5,  &p6, &p7, &p8)==14);
      assert(false); // takin L2Residual only for 22Sep2023
    }
    assert(!(etamin==0 && etamax==0));
    if (fabs(etamin)<0.01 && fabs(etamax)<0.01) {
      cout << "sscanf failed!" << endl << flush;
      exit(1);
    }

    if (isRun3 && isNewL2Res) {

      int nparnew = 2 + 3 + 8; // 13
      string s = Form("  %6.3f %6.3f %2d  %2d %4d   "
		      "%7.4f %7.4f %7.4f   "
		      "%5.4f %5.4f %5.5f %5.5f %5.2f %5.4f %5.5f %5.8f",
		      etamin, etamax, nparnew, xmin, xmax,
		      p0, p1, p2,
		      p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
      if (cnt<cntmax && debug)
	cout << s << endl;
      fout << s << endl;
      ++cnt;
    }
    else if (isRun3) {
      if (isL2Res) {
	// patch L2L3Res files
	if (etamin > etamax) {
	  assert(etamin<=0);
	  assert(etamax<0);
	  cout << "Swap sign of " << etamin << " and " << etamax << endl;
	  etamin *= -1;
	  etamax *= -1;
	}
      }
      int nparnew = 18;//17;
      if (cnt<cntmax && debug)
	cout << Form("  %9.6f %9.6f   %d   %d %d"
		     "   %d   %d"
		     "   %8.6f %8.6f %8.6f %8.6f %8.6f %8.6f"
		     "   %5.4f %5.4f %5.5f %5.5f %5.2f %5.4f %5.5f %5.8f",
		     etamin, etamax, nparnew, xmin, xmax,
		     ptmin0, ptmax1,
		     p2, p3, p4, p5, p6, p7,
		     p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7])
	     << endl;
      fout << Form("  %9.6f %9.6f   %d   %d %d"
		   "   %d   %d"
		   "   %8.6f %8.6f %8.6f %8.6f %8.6f %8.6f"
		   "   %5.4f %5.4f %5.5f %5.5f %5.2f %5.4f %5.5f %5.8f",
		   etamin, etamax, nparnew, xmin, xmax,
		   ptmin0, ptmax1,
		   p2, p3, p4, p5, p6, p7,
		   p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7])
	   << endl;
      ++cnt;
    }
    else {
      int nparnew = 15;
      if (cnt<cntmax && debug)
	cout << Form("  %9.6f %9.6f   %d   %d %d   %d   %d   %8.6f %8.6f"
		     "   %8.6f %8.6f   "
		     "%5.4f %5.4f %5.5f %5.5f %5.2f %5.4f %5.5f",
		     etamin, etamax, nparnew, xmin, xmax, ptmin0, ptmax1,
		     p2, p3, p4, p5,
		     p[0], p[1], p[2], p[3], p[4], p[5], p[6]) << endl;
      fout << Form("  %9.6f %9.6f   %d   %d %d   %d   %d   %8.6f %8.6f"
		   "   %8.6f %8.6f   "
		   "%5.4f %5.4f %5.5f %5.5f %5.2f %5.4f %5.5f",
		   etamin, etamax, nparnew, xmin, xmax, ptmin0, ptmax1,
		   p2, p3, p4, p5,
		   p[0], p[1], p[2], p[3], p[4], p[5], p[6]) << endl;
      ++cnt;
    }

  } // while getline

} // creataL2L3ResTextFile
