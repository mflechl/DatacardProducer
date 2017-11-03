#include "interface/NameStrings.h"

using namespace std;

//WHAT CURRENTLY DOES NOT WORK:
//- any variable with type other than int or float

/*
const vector<TString> variables={
  s_dm2+s_join2d+s_mvis,
  s_pttt+s_join2d+s_mvis,
  s_mvis
};
const vector<TString> vartypes={
  "int"+s_join2d+"float",
  "float"+s_join2d+"float",
  "float"
};
*/

//"default" is substitutes according to config/Analysis.json
const vector<TString> variables={
  "default",
  s_mvis
};
const vector<TString> vartypes={
  "default",
  "float"
};


//negative bins in histograms will be set to zero
const int resetZero=0;
//create the templates specified in SelectionAnalyzer::init*Selections() before running
const int doInitialize=1;
// calculate Fake Factor templates 
const int calcFF=1;

// Used for Debugging. Keep histograms in final root file
const int keepDebugHistos=0;
const int keepFFDebugHistos=0;
const int keepZGenJetsSplitting=0;

// Deprecated in MSSM
const int jecShift=0;
const int useMVAMET=0;
const TString doSvfit="woSVFIT";

const int DEBUG=0;
