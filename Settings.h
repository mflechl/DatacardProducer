#include "interface/NameStrings.h"

using namespace std;

const TString channel="mt";
const TString version="v14";
const int doMC=0;
const double usedLuminosity=35.9; 
const TString doSvfit="woSVFIT";
const TString reduced="";//"";//"_reduced";
const TString FFversion="fakeFactors_20170510_tight.root";
//const TString FFversion="fakeFactors_20170502_tight.root";
//const TString FFversion="fakeFactors_20170502_medium.root";
const TString FFiso = "tight";
const TString UseIso = "tight";
//const vector<TString> variables={s_mttot,s_mvis,s_met,s_pt1,s_pt2,s_mt2,s_mt1}; //s_mvis,s_met,s_pt1,s_pt2
//const vector<TString> categories={s_nobtag_tight,s_btag_tight,s_nobtag_loosemt,s_btag_loosemt};
//const vector<TString> categories={s_btag,s_nobtag};
const vector<TString> variables={s_mttot,s_pt2}; //s_mvis,s_met,s_pt1,s_pt2
const vector<TString> categories={s_nobtag_tight,s_nobtag_loosemt};
//const vector<TString> categories={s_inclusive,s_0jet,s_wjets_0jet_cr,s_antiiso_0jet_cr,s_boosted,s_wjets_boosted_cr,s_antiiso_boosted_cr,s_vbf,s_wjets_vbf_cr,s_antiiso_vbf_cr};

///////////////////////////////////////////////////////////////////////////
const int applyMTCut=1;//MTcut in inclusive selection, default==1 for mt&et, default==0 for tt
const int resetZero=0;
const int isSync=1;
const int ptShift=1;
const int jecShift=1;
const int doInitialize=1;
const int useMVAMET=0;
const int calcFF=1;
const int keepDebugHistos=0;
const int keepFFDebugHistos=0;
const int keepZGenJetsSplitting=0;


