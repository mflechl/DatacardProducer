#ifndef __GLOBALCLASS__
#define __GLOBALCLASS__

#include "ntuple.h"
#include "TChain.h"
#include "TFile.h"
#include "TH1D.h"
#include "ParameterConfig.h"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;


class GlobalClass{
 public:

  GlobalClass();
  ~GlobalClass();

  int returnBin(vector<double> bins, double value);

  int getNjets();
  float getMjj();
  float getJdeta();
  float getMT();
  float getMT2();
  float CalcHPt();

  int Baseline(TString sign, TString cat);
  int passMTCut();
  int passIso(TString type);
  int Vetos();
  int CategorySelection(TString cat, TString iso);
  int LooseBtagCategory(TString cat, TString iso);
  int Btag(TString btag);
  int TauIso(TString  iso);
  int LooseBtag(TString btag);
  int TightMt(TString iso,TString mt = "SR");
  int LooseMt(TString iso,TString mt = "SR");
  int W_CR(TString sign, TString iso, TString cat, bool mtcut=true );

  TH1D* GetHistbyName(TString name, TString strVar="");
  TH1D* JITHistoCreator(TString name, TString strVar);
  void returnBinning(double*, vector<double> input);
  int returnBins(vector<double> input);
  TH1D* getBinnedHisto(TString name,vector<double> input);
  void resetZeroBins(TString hist, TString var);
  void resetZeroBins(TH1D* hist);

  
  map<TString, TH1D*> histograms;

  vector<TString> cats;
  vector<TString> vars;
  //vector< vector<TString> > files; 
  map<string, pair<string,string> > files;

  //ntuple *NtupleView;
  std::unique_ptr<ntuple> NtupleView;
  Int_t isJEC=0; //0->no correction; 1->jecUp; -1->jecDown;
  TString runOption = "";
  TString folder;
  bool applyMTCut;
  string FFiso;
  string FFbuild;
  TString FFversion;
  TString channel;
  vector<string> categories;
  json Analysis;
  json Binning;
  json Datasets;


};



#endif


