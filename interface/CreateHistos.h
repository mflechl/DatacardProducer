#ifndef __CREATEHISTOS__
#define __CREATEHISTOS__

#include "interface/SelectionAnalyzer.h"

class CreateHistos : public SelectionAnalyzer{
 public:

  CreateHistos(TString testEnv_, TString ch);

  ~CreateHistos();
  bool SpecialCuts();
  float getAntiLep_tauscaling();
  TString getFilestring(TString input, TString ES="", TString mass="");
  TString ColorPrompt(TString input, TString color);
  int isZFile(TString fileName);
  int isEWKZFile(TString fileName);
  int isSignalFile(TString fileName);
  int isTTFile(TString fileName);
  int isWFile(TString fileName);
  int isVVFile(TString fileName); 
  int getFiletype(TString fileName);

  double getQCD_osss(TString cat);
  double getW_osss(TString strVar, TString cat);
  double getW_mtHL(TString strVar, TString cat, TString sign);
  double getW_BtagConv(TString strVar, TString cat, TString cr = "");
  void Estimate_W_QCD(TString strVar, TString cat, TString extend="");
  void EstimateW(TString strVar, TString cat);
  void EstimateQCD(TString strVar, TString cat);
  void EstimateFF(TString strVar, TString cat, TString extend="");
  void createInclusive(TString strVar, TString cat);
  float recalcEffweight();

  void loadFile(TString filename);
  void run();
  void clearHistos();
  void writeHistos(TString channel, vector<TString> cats, vector<TString> vars);
  
  TFile *outfile;

  
};



#endif
