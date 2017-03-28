#ifndef __GLOBALCLASS__
#define __GLOBALCLASS__

#include "ntuple.h"
#include "TChain.h"
#include "TFile.h"
#include "TH1D.h"
#include "ParameterConfig_SM.h"


class GlobalClass{
 public:

  GlobalClass();
  ~GlobalClass();

  double get2DVar(TString sub);
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
  int CategorySelection(TString cat, TString iso = "");
  int Btag(TString btag);
  int LowMt(TString iso);
  int LooseMt(TString iso);
  int HighMt(TString iso);

  double getWSFUncertainty( TString cat );
  double getQCDSFUncertainty( TString cat );
  double getRenormScale( TString cat );
  double getZmumuWeight( TString cat );
  double applyZmumuUncertainty( TString cat );
  TString return2DString( TString cat );

  double QCD_OSSS(TString cat);
  int OS_W(TString cat);
  int SS_W(TString cat);
  int relaxed_W(TString cat, TString mt);
  int SS_Low(TString cat);
  int SS_Low_relaxed(TString cat);

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
  vector< vector<TString> > files; 

  ntuple *NtupleView;
  Int_t isJEC=0; //0->no correction; 1->jecUp; -1->jecDown;
};



#endif


