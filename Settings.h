#include "interface/NameStrings.h"

using namespace std;

const TString channel="et";const TString FFiso = "tight";const vector<TString> categories={s_nobtag_tight,s_btag_tight,s_nobtag_loosemt,s_btag_loosemt};const int applyMTCut=1;
//const TString channel="et";const TString FFiso = "tight";const int applyMTCut=0;

//const TString channel="mt";const TString FFiso = "tight";const vector<TString> categories={s_nobtag_tight,s_btag_tight,s_nobtag_loosemt,s_btag_loosemt};const int applyMTCut=1;
//const TString channel="tt";const TString FFiso = "medium";const vector<TString> categories={s_btag,s_nobtag};const int applyMTCut=0;
const TString version="v16";
const TString production = "MCSummer16";
const int doMC=0;
const double usedLuminosity=35.9; 
const TString doSvfit="woSVFIT";
const TString reduced="";//"";//"_reduced";
const TString FFversion="fakeFactors_20170628_"+FFiso+".root";
const TString UseIso = "tight";
//const vector<TString> categories={s_inclusive};
//const vector<TString> variables={s_mttot,s_pt1,s_pt2,s_eta1,s_eta2,s_njet,s_nbtag,s_mvis,s_met}; //s_mvis,s_met,s_pt1,s_pt2
//const vector<TString> variables={s_pt1,s_pt2,s_eta1,s_eta2,s_njet,s_nbtag};
const vector<TString> variables={s_mttot};
///////////////////////////////////////////////////////////////////////////
//const int applyMTCut=0;//MTcut in inclusive selection, default==1 for mt&et, default==0 for tt
const int resetZero=0;
const int ptShift=1;
const int jecShift=0;
const int doInitialize=1;
const int useMVAMET=0;
const int calcFF=1;
const int keepDebugHistos=0;
const int keepFFDebugHistos=0;
const int keepZGenJetsSplitting=0;


