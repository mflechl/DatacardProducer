#include "Settings.h"


const struct Parameter{

  struct dataset{

    TString inputfolder ="/data/higgs/data_2016/ntuples_"+version+"/CHANNEL/ntuples_"+doSvfit+"_merged/";
    TString appendix = "CHANNEL_"+version+"_TES.root";

    vector<TString> tES_shifts = {"T0Up","T1Up","T10Up","T0Down","T1Down","T10Down"};
    vector<TString> eES_shifts = {"E0Up","E0Down","E1Up","E1Down"};
    vector<TString> min_shifts = {"TauPtUp","TauPtDown"};

    vector<TString> masspoints = {"80","90","100","110","120","130","140","160","180","200",
                                  "250","350","400","450","500","600","700","800","900","1000",
                                  "1200","1400","1600","1800","2000","2300","2600","2900","3200"};
    vector<TString> test_masspoints = {"1000"};

    TString data_mt=     inputfolder + "BASIS_ntuple_SingleMuon_"+ appendix;
    TString data_et=     inputfolder + "BASIS_ntuple_SingleElectron_"+ appendix;
    TString data_tt=     inputfolder + "BASIS_ntuple_Tau_"+ appendix;

    TString Z=           inputfolder + "BASIS_ntuple_DYXJetsToLL_lowMass_merged_"+production+"_"+ appendix;
    TString EWKZ=        inputfolder + "BASIS_ntuple_EWK_merged_"+production+"_"+ appendix;
    TString TT=          inputfolder + "BASIS_ntuple_TT_merged_"+production+"_"+ appendix;
    TString W=           inputfolder + "BASIS_ntuple_WXJets_merged_"+production+"_"+ appendix;
    TString VV=          inputfolder + "BASIS_ntuple_VV_"+production+"_"+ appendix;
    TString SMWminus=    inputfolder + "BASIS_ntuple_WminusHToTauTau_M125_powheg_"+production+"_"+ appendix;
    TString SMWplus=     inputfolder + "BASIS_ntuple_WplusHToTauTau_M125_powheg_"+production+"_"+ appendix;
    TString SMZH=        inputfolder + "BASIS_ntuple_ZHToTauTau_M125_powheg_"+production+"_"+ appendix;
    TString SMvbf=       inputfolder + "BASIS_ntuple_VBFHToTauTau_M125_powheg_"+production+"_"+ appendix;
    TString SMggH=       inputfolder + "BASIS_ntuple_GluGluHToTauTau_M125_powheg_"+production+"_"+ appendix;
    TString bbH=         inputfolder + "BASIS_ntuple_SUSYGluGluToBBHToTauTau_M_XXX_pythia8_"+production+"_"+ appendix;
    TString bbHNLO=      inputfolder + "BASIS_ntuple_SUSYGluGluToBBHToTauTau_M_XXX_amcatnloFXFX_nom_"+production+"_"+ appendix;
    TString ggH=         inputfolder + "BASIS_ntuple_SUSYGluGluToHToTauTau_M_XXX_pythia8_"+production+"_"+ appendix;

  } dataset;


   struct category{
    vector<TString> categoriesForQCDest = {s_inclusive, s_nobtag, s_btag, s_nobtag_tight,s_btag_tight,s_nobtag_looseiso,s_btag_looseiso,s_nobtag_loosemt,s_btag_loosemt};
    //vector<TString> D2categories = {s_0jet,s_boosted,s_vbf,s_wjets_0jet_cr,s_wjets_boosted_cr,s_wjets_vbf_cr,s_antiiso_0jet_cr,s_antiiso_boosted_cr,s_antiiso_vbf_cr};
    //FIXME: add PU jet categories
  } category;

  struct FFsystematics{
    struct XSvariation{
      double DYXSvariation = 0.08;
      double TTXSvariation = 0.12;
    }XSvariation;
    struct mt{
      vector<string> syst = {"ff_qcd_syst_up","ff_qcd_syst_down","ff_qcd_dm0_njet0_stat_up","ff_qcd_dm0_njet0_stat_down","ff_qcd_dm0_njet1_stat_up","ff_qcd_dm0_njet1_stat_down","ff_qcd_dm1_njet0_stat_up","ff_qcd_dm1_njet0_stat_down","ff_qcd_dm1_njet1_stat_up","ff_qcd_dm1_njet1_stat_down","ff_w_syst_up","ff_w_syst_down","ff_w_dm0_njet0_stat_up","ff_w_dm0_njet0_stat_down","ff_w_dm0_njet1_stat_up","ff_w_dm0_njet1_stat_down","ff_w_dm1_njet0_stat_up","ff_w_dm1_njet0_stat_down","ff_w_dm1_njet1_stat_up","ff_w_dm1_njet1_stat_down","ff_tt_syst_up","ff_tt_syst_down","ff_tt_dm0_njet0_stat_up","ff_tt_dm0_njet0_stat_down","ff_tt_dm0_njet1_stat_up","ff_tt_dm0_njet1_stat_down","ff_tt_dm1_njet0_stat_up","ff_tt_dm1_njet0_stat_down","ff_tt_dm1_njet1_stat_up","ff_tt_dm1_njet1_stat_down"};
    } mt;
    struct et{
      vector<string> syst = {"ff_qcd_syst_up","ff_qcd_syst_down","ff_qcd_dm0_njet0_stat_up","ff_qcd_dm0_njet0_stat_down","ff_qcd_dm0_njet1_stat_up","ff_qcd_dm0_njet1_stat_down","ff_qcd_dm1_njet0_stat_up","ff_qcd_dm1_njet0_stat_down","ff_qcd_dm1_njet1_stat_up","ff_qcd_dm1_njet1_stat_down","ff_w_syst_up","ff_w_syst_down","ff_w_dm0_njet0_stat_up","ff_w_dm0_njet0_stat_down","ff_w_dm0_njet1_stat_up","ff_w_dm0_njet1_stat_down","ff_w_dm1_njet0_stat_up","ff_w_dm1_njet0_stat_down","ff_w_dm1_njet1_stat_up","ff_w_dm1_njet1_stat_down","ff_tt_syst_up","ff_tt_syst_down","ff_tt_dm0_njet0_stat_up","ff_tt_dm0_njet0_stat_down","ff_tt_dm0_njet1_stat_up","ff_tt_dm0_njet1_stat_down","ff_tt_dm1_njet0_stat_up","ff_tt_dm1_njet0_stat_down","ff_tt_dm1_njet1_stat_up","ff_tt_dm1_njet1_stat_down"};
    } et;
    struct tt{
      vector<string> syst = {"ff_qcd_syst_up","ff_qcd_syst_down","ff_qcd_dm0_njet0_stat_up","ff_qcd_dm0_njet0_stat_down","ff_qcd_dm0_njet1_stat_up","ff_qcd_dm0_njet1_stat_down","ff_qcd_dm1_njet0_stat_up","ff_qcd_dm1_njet0_stat_down","ff_qcd_dm1_njet1_stat_up","ff_qcd_dm1_njet1_stat_down","ff_w_syst_up","ff_w_syst_down","ff_tt_syst_up","ff_tt_syst_down","ff_w_frac_syst_up","ff_dy_frac_syst_up","ff_tt_frac_syst_up","ff_w_frac_syst_down" ,"ff_dy_frac_syst_down","ff_tt_frac_syst_down"};
    } tt;
  } FFsystematics;

} Parameter;

 
