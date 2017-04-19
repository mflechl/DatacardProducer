#include "interface/NameStrings.h"

using namespace std;

const TString channel="tt";
const TString version="v11";
const int doMC=0;
const double usedLuminosity=35.9; 
const TString doSvfit="woSVFIT";
const TString reduced="";//"";//"_reduced";
const TString FFversion="fakeFactors_20170415_tight.root";
const TString FFiso = "tight";
const TString UseIso = "medium";
//const vector<TString> variables={s_mttot}; //s_mvis,s_met,s_pt1,s_pt2
//const vector<TString> categories={s_nobtag_loosemt, s_nobtag_looseiso};
const vector<TString> variables={s_mttot};//,s_mvis,s_met,s_pt1,s_pt2}; //s_mvis,s_met,s_pt1,s_pt2
const vector<TString> categories={s_nobtag,s_btag};
//const vector<TString> categories={s_btag_tight,s_btag_looseiso,s_btag_loosemt,s_nobtag_tight,s_nobtag_looseiso,s_nobtag_loosemt};
///////////////////////////////////////////////////////////////////////////
const int applyMTCut=0;//MTcut in inclusive selection, default==1 for mt&et, default==0 for tt
const int resetZero=1;
const int isSync=1;
const int ptShift=0;
const int jecShift=0;
const int doInitialize=1;
const int useMVAMET=0;
const int calcFF=1;
const int keepDebugHistos=0;
const int keepFFDebugHistos=0;
const int keepZGenJetsSplitting=0;


