#include "interface/NameStrings.h"

using namespace std;

//const vector<TString> variables={s_mttot+s_join2d+s_pt2}; //mt_tot|pt_2
//const vector<TString> variables={s_mvis+s_join2d+s_pt2}; //m_vis|pt_2
const vector<TString> variables={s_dm2+s_join2d+s_mvis};
const vector<TString> vartypes={"int"+s_join2d+"float"};
//const vector<TString> variables={s_mvis};
//const vector<TString> variables={s_pt2};
//const vector<TString> variables={s_mttot};
//const vector<TString> variables={s_mttot,s_pt1,s_pt2,s_met,s_mvis};
//const vector<TString> variables={s_eta1,s_eta2,s_njet,s_nbtag};

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

const int DEBUG=1;




