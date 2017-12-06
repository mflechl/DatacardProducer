#ifndef __CREATEHISTOS__
#define __CREATEHISTOS__

#include "interface/SelectionAnalyzer.h"

class CreateHistos : public SelectionAnalyzer{
 public:

  CreateHistos(TString testEnv_, TString ch);

  ~CreateHistos();

  union u { int i; float f; };

  bool SpecialCuts();
  double getMT3();
  float getAntiLep_tauscaling();
  TString getFilestring(TString input, TString ES="", TString mass="");
  int isZFile(TString fileName);
  int isEWKZFile(TString fileName);
  int isSignalFile(TString fileName);
  int isTTFile(TString fileName);
  int isWFile(TString fileName);
  int isVVFile(TString fileName); 
  int getFiletype(TString fileName);

  float getQCD_osss(TString cat);
  float getW_mtHL(TString strVar, TString cat);
  void Estimate_W_QCD(TString strVar, TString cat, TString extend="");
  void EstimateW(TString strVar, TString cat);
  void EstimateQCD(TString strVar, TString cat);
  void EstimateFF(TString strVar, TString cat, TString extend="");
  void createInclusive(TString strVar, TString cat);
  float recalcEffweight();
  float getVal(TString m_var);
  void loadFile(TString filename, int isData=0);
  void run();
  void clearHistos();
  void writeHistos(TString channel, vector<TString> cats, vector<TString> vars);
  float get2DBin(const TString var, std::vector<float> val);
  float getUnionVal(u var, TString vartype);
  int getBin(float var, std::vector<double> bins);
  TString getVarName(TString strVar, TString cat, int returnType=0);
  TString getVarType(TString strVar, TString cat);


  TFile *outfile;

  
};



#endif
