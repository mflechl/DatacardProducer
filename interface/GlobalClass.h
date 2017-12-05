#ifndef __GLOBALCLASS__
#define __GLOBALCLASS__

#include "ntuple.h"
#include "TChain.h"
#include "TFile.h"
#include "TH1D.h"
#include "FakeFactorConfig.h"
#include <fstream>
#include "json.hpp"

using nlohmann::json;


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

  int Baseline(TString sign, TString cat);
  int passMTCut();
  int passIso(TString type);
  int Vetos();
  int CategorySelection(TString cat, TString sign);
  bool zeroJetCat();
  bool boostedCat();
  bool vbfCat();

  TH1D* GetHistbyName(TString name, TString strVar="");
  TH1D* JITHistoCreator(TString name, TString strVar);
  //  void returnBinning(double*, vector<double> input);
  void returnBinning(double*, vector<double> input1d,vector<double> input2d={});
  int returnBins(vector<double> input1d,vector<double> input2d={});
  //  TH1D* getBinnedHisto(TString name,vector<double> input);
  void splitString(TString str,TString sep,vector<TString>& vec);
  std::vector<TString> splitString(TString str,TString sep);
  TH1D* getBinnedHisto(TString name,vector<double> input1d,vector<double> input2d={}, TString strVar="");
  void resetZeroBins(TString hist, TString var);
  void resetZeroBins(TH1D* hist);
  map<string, int> ExperimentalCategorizer();
  TString Unmask(map<string, int> Catkey);

  
  map<TString, TH1D*> histograms;

  vector<TString> cats;
  vector<TString> vars;
  //vector< vector<TString> > files; 
  map<TString, pair<string,string> > files;

  //ntuple *NtupleView;
  std::unique_ptr<ntuple> NtupleView;
  Int_t isJEC=0; //0->no correction; 1->jecUp; -1->jecDown;
  string runOption = "";
  TString folder;
  bool applyMTCut;
  string FFiso;
  string FFbuild;
  TString FFversion;
  string channel;
  vector<string> categories;
  vector<string> masspoints;
  std::map<TString,string> def_var_name;
  std::map<TString,string> def_var_type;
  json Analysis;
  json Binning;
  json Datasets;

  std::map<TString,std::vector<double>> binning1d; //dynamic arrays would be faster
  std::map<TString,std::vector<double>> binning2d;

};



#endif


