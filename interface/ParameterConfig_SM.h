#include "Settings.h"

const struct Parameter{

  struct dataset{

    TString inputfolder ="/data/higgs/data_2016/ntuples_"+version+"/"+channel+"/ntuples_"+doSvfit+"_merged/";
    TString appendix = channel+"_"+version+"_TES"+reduced+".root";

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
  struct variable{
    
    struct m_vis{
      int nbins = 20;
      double nmin = 0;
      double nmax = 200;
      int doVarBins = 1;
      std::map<TString, vector<double> > varBins = {
        {"default", {10,25,40,55,70,85,100,115,130,145,160,175,190,205,220,235,250} },
        {"btag", {10,30,50,70,90,110,130,150,170,190,210,230,250} },
        {"nobtag", {10,25,40,55,70,85,100,115,130,145,160,175,190,205,220,235,250} } 
      };
    } m_vis;
    struct m_sv{
      int nbins = 25;
      double nmin = 0;
      double nmax = 250;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } m_sv;
    struct pt_sv{
      int nbins = 20;
      double nmin = 0;
      double nmax = 200;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } pt_sv;
    struct jpt{
      int nbins = 70;
      double nmin = 0;
      double nmax = 350;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } jpt;
    struct pt{
      int nbins = 14;
      double nmin = 30;
      double nmax = 100;
      int doVarBins = 1;
      std::map<TString, vector<double> > varBins = {
        {"default", {30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,120,140,160,180,200,250,300,350,400,500} },
        {"mt", {30,35,40,45,50,55,60,65,70,75,80,85,90,95,100} },
        {"et", {30,35,40,45,50,55,60,65,70,75,80,85,90,95,100} },
        {"tt", {40,45,50,55,60,65,70,75,80,85,90,95,100} } 
      };
    } pt;
    struct eta{
      int nbins = 25;
      double nmin = -2.5;
      double nmax = 2.5;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } eta;
    struct njet{
      int nbins = 10;
      double nmin = -0.5;
      double nmax = 9.5;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } njet;
    struct nbtag{
      int nbins = 5;
      double nmin = -0.5;
      double nmax = 4.5;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } nbtag;
    struct jeta{
      int nbins = 40;
      double nmin = -5;
      double nmax = 5;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } jeta;
    struct jdeta{
      int nbins = 40;
      double nmin = 0;
      double nmax = 10;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } jdeta;
    struct mt_1{
      int nbins = 14;
      double nmin = 0;
      double nmax = 70;
      int doVarBins = 1;
      std::map<TString, vector<double> > varBins = { {"default", {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,500}} };
    } mt_1;
    struct mt_2{
      int nbins = 20;
      double nmin = 0;
      double nmax = 100;
      int doVarBins = 1;
      std::map<TString, vector<double> > varBins = { {"default", {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,110,120,130,140,150,160,170,180,190,200}} };
    } mt_2;
    struct met{
      int nbins = 20;
      double nmin = 0;
      double nmax = 200;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } met;
    struct mttot{
      int nbins = 50;
      double nmin = 0;
      double nmax = 500;
      int doVarBins = 1;
      std::map<TString, vector<double> > varBins =  
      { {"default", {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,225,250,275,300,325,350,400,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3500,3700,3900} },
        {"mt_nobtag", {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,225,250,275,300,325,350,400,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3500,3700,3900} },
        //{"mt_btag", {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,225,250,275,300,325,350,400,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3500,3700,3900} },
        {"et_nobtag", {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,225,250,275,300,325,350,400,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3500,3700,3900} },
        //{"et_btag", {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,225,250,275,300,325,350,400,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3500,3700,3900} },
        {"tt_nobtag", {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,225,250,275,300,325,350,400,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3500,3700,3900} },
        {"tt_btag", {0,20,40,60,80,100,120,140,160,180,200,250,300,350,400,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3500,3700,3900} },
        {"et_btag", {0,20,40,60,80,100,120,140,160,180,200,250,300,350,400,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3500,3700,3900} },
        {"mt_btag", {0,20,40,60,80,100,120,140,160,180,200,250,300,350,400,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3500,3700,3900} },       
        //{"tt_btag", {0,20,40,60,80,100,120,140,160,180,200,250,300,350,400,500,700,900,1100,1300,1500,1700,1900,2100,2300,2500,2700,2900,3100,3300,3500,3700,3900} }
      };

    } mttot;
    struct Hpt{
      int nbins = 20;
      double nmin = 0;
      double nmax = 200;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } Hpt;
    struct Low_mt_1{
      int nbins = 25;
      double nmin = 0;
      double nmax = 50;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } Low_mt_1;
    struct High_mt_1{
      int nbins = 40;
      double nmin = 80;
      double nmax = 1000;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } High_mt_1;
    struct iso_1{
      int nbins = 25;
      double nmin = 0;
      double nmax = 0.5;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } iso_1;
    struct mjj{
      int nbins = 70;
      double nmin = 0;
      double nmax = 1400;
      int doVarBins = 1;
      std::map<TString, vector<double> > varBins = { {"default",  {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500,520,540,560,580,600,625,650,675,700,725,750,775,800,850,900,950,1000,1100,1200,1400} } };
    } mjj;
    struct jeta1eta2{
      int nbins = 40;
      double nmin = -10;
      double nmax = 10;
      int doVarBins = 0;
      std::map<TString, vector<double> > varBins = { {"default", {50,55,60,65,80}} };
    } jeta1eta2;

  } variable;

  struct variable2D{
    struct D2_0Jet{
      TString name = s_0jet;
      vector<double> binsX = {30,35,40,45,50,55,300}; //pt_2
      vector<double> binsY = {0,60,65,70,75,80,85,90,95,100,105,110,400}; //m_vis
    } D2_0Jet;
    struct D2_boosted{
      TString name = s_boosted;
      vector<double> binsX = {0,100,150,200,250,300,5000}; //Higgs_pt
      vector<double> binsY_svfit = {0,80,90,100,110,120,130,140,150,160,300}; //svfit_mass
      vector<double> binsY_mvis = {0,60,70,80,90,100,110,120,130,140,300}; //m_vis instead of svfit_mass
      //binsY_mvis must have same number of bins
    } D2_boosted;
    struct D2_vbf{
      TString name = s_vbf;
      vector<double> binsX = {300,700,1100,1500,10000}; //m_jj
      vector<double> binsY_svfit = {0,95,115,135,155,400}; //svfit_mass
      vector<double> binsY_mvis = {0,75,95,115,135,400}; //m_vis instead of svfit_mass
      //binsY_mvis must have same number of bins
    } D2_vbf;
    struct antiiso{
      vector<double> binsX = {40,80,120,160,200};
    } antiiso;
  } variable2D;
  struct variable2D_tt{
    struct D2_0Jet{
      TString name = s_0jet;
      vector<double> binsX = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300}; //svfit_mass of m_vis
    } D2_0Jet;
    struct D2_boosted{
      TString name = s_boosted;
      vector<double> binsX = {0,100,170,300,1000}; //Higgs_pt
      vector<double> binsY_svfit = {0,40,60,70,80,90,100,110,120,130,150,200,250}; //svfit_mass
      vector<double> binsY_mvis = {0,30,50,60,70,80,90,100,110,120,140,200,250}; //m_vis instead of svfit_mass
      //binsY_mvis must have same number of bins
    } D2_boosted;
    struct D2_vbf{
      TString name = s_vbf;
      vector<double> binsX = {300,500,800,10000}; //m_jj
      vector<double> binsY_svfit = {0,40,60,70,80,90,100,110,120,130,150,200,250}; //svfit_mass
      vector<double> binsY_mvis = {0,30,50,60,70,80,90,100,110,120,140,200,250}; //m_vis instead of svfit_mass
      //binsY_mvis must have same number of bins
    } D2_vbf;
  } variable2D_tt;  

  struct analysisCut{
    double mTHigh = 70;
    double mTLow  = 40;
    double muIso_base = 0.15;
    double muIso_relaxed = 0.3;
    double muIso_antiIsoLow = 0.15;
    double muIso_antiIsoHigh = 0.3;
    double elIso_base = 0.1;
    double elIso_relaxed = 0.3;
    double elIso_antiIsoLow = 0.1;
    double elIso_antiIsoHigh = 0.3;
  } analysisCut;

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

  struct QCD_OSSS
  {
    struct mt
    {
      double ZeroJet = 1.00;
      double Boosted = 1.15;
      double VBF = 1.20;
    }mt;
    struct et
    {
      double ZeroJet = 1.00;
      double Boosted = 1.15;
      double VBF = 1.20;
      
    }et;
  } QCD_OSSS ;
  
} Parameter;

 
