#include "interface/NameStrings.h"

using namespace std;


//#define APPLY_MT_CUT 0;
//#define CHANNEL "tt"
//#define USE_CONST_CAT 1;
const vector<TString> const_categories={s_btag};
const vector<TString> variables={s_mttot};
//const vector<TString> variables={s_mttot,s_pt1,s_pt2,s_met,s_mvis};
//const vector<TString> variables={s_eta1,s_eta2,s_njet,s_nbtag};

const int resetZero=0;
const int ptShift=1;
const int jecShift=0;
const int doInitialize=1;
const int useMVAMET=0;
const int calcFF=1;
const int keepDebugHistos=0;
const int keepFFDebugHistos=0;
const int keepZGenJetsSplitting=0;



const TString version="v16";
const TString production = "MCSummer16";
const int doMC=0;
const double usedLuminosity=35.9; 
const TString doSvfit="woSVFIT";
const TString reduced="";//"";//"_reduced";
const TString UseIso = "tight";






