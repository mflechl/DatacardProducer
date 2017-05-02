const TString s_inclusive =              "inclusive";
const TString s_0jet =                   "0jet";
const TString s_boosted =                "boosted";
const TString s_vbf =                    "vbf";
const TString s_wjets_0jet_cr =          "wjets_0jet_cr";
const TString s_wjets_boosted_cr =       "wjets_boosted_cr";
const TString s_wjets_vbf_cr =           "wjets_vbf_cr";
const TString s_antiiso_0jet_cr =        "antiiso_0jet_cr";
const TString s_antiiso_boosted_cr =     "antiiso_boosted_cr";
const TString s_antiiso_vbf_cr =         "antiiso_vbf_cr";

const TString s_nobtag =                 "nobtag";
const TString s_btag =                   "btag";
const TString s_nobtag_tight =           "nobtag_tight";
const TString s_btag_tight =             "btag_tight";
const TString s_nobtag_looseiso =        "nobtag_looseiso";
const TString s_btag_looseiso =          "btag_looseiso";
const TString s_nobtag_loosemt =         "nobtag_loosemt";
const TString s_btag_loosemt =           "btag_loosemt";

const TString s_wjets =                  "wjets";
const TString s_antiiso =                "antiiso";
const TString s_wjets_cr =               "_wjets_cr";
const TString s_qcd_cr =                 "_qcd_cr";

const TString s_nobtag_tight_wjets_cr =   s_nobtag_tight+s_wjets_cr;
const TString s_btag_tight_wjets_cr =     s_btag_tight+s_wjets_cr;
const TString s_nobtag_loosemt_wjets_cr=  s_nobtag_loosemt+s_wjets_cr;
const TString s_btag_loosemt_wjets_cr =   s_btag_loosemt+s_wjets_cr;
const TString s_nobtag_looseiso_wjets_cr= s_nobtag_looseiso+s_wjets_cr;
const TString s_btag_looseiso_wjets_cr =   s_btag_looseiso+s_wjets_cr;

const TString s_mvis =                   "m_vis";
const TString s_msv =                    "m_sv";
const TString s_ptsv =                   "pt_sv";
const TString s_Hpt =                    "Hpt";
const TString s_mjj =                    "mjj";
const TString s_met =                    "met";
const TString s_mttot =                  "mttot";
const TString s_mt1 =                    "mt_1";
const TString s_mt2 =                    "mt_2";
const TString s_pt1 =                    "pt_1";
const TString s_pt2 =                    "pt_2";
const TString s_eta1 =                   "eta_1";
const TString s_eta2 =                   "eta_2";
const TString s_jpt1 =                   "jpt_1";
const TString s_jpt2 =                   "jpt_2";
const TString s_jeta1 =                  "jeta1";
const TString s_jeta2 =                  "jeta2";

const TString s_tau  =                   "tau";
const TString s_jec =                    "jec";  
const TString s_up =                     "Up";
const TString s_down =                   "Down";
const TString s_tauUp =                  s_tau+s_up;
const TString s_tauDown =                s_tau+s_down;
const TString s_jecUp =                  s_jec+s_up;
const TString s_jecDown =                s_jec+s_down;

const TString s_data =                   "data_obs";
const TString s_Z =                      "Z";
const TString s_ZtauUp =                 s_Z+s_tauUp;
const TString s_ZtauDown =               s_Z+s_tauDown;
const TString s_ZjecUp =                 s_Z+s_jecUp;
const TString s_ZjecDown =               s_Z+s_jecDown;
const TString s_ZTT =                    "ZTT";
const TString s_ZTTtauUp =               s_ZTT+s_tauUp;
const TString s_ZTTtauDown =             s_ZTT+s_tauDown;
const TString s_ZTTjecUp =               s_ZTT+s_jecUp;
const TString s_ZTTjecDown =             s_ZTT+s_jecDown;
const TString s_ZLL =                    "ZLL";
const TString s_ZL =                     "ZL";
const TString s_ZLtauUp =                s_ZL+s_tauUp;
const TString s_ZLtauDown =              s_ZL+s_tauDown;
const TString s_ZLjecUp =                s_ZL+s_jecUp;
const TString s_ZLjecDown =              s_ZL+s_jecDown;
const TString s_ZJ =                     "ZJ";
const TString s_ZJtauUp =                s_ZJ+s_tauUp;
const TString s_ZJtauDown =              s_ZJ+s_tauDown;
const TString s_ZJjecUp =                s_ZJ+s_jecUp;
const TString s_ZJjecDown =              s_ZJ+s_jecDown;
const TString s_EWKZ =                   "EWKZ";
const TString s_EWKZtauUp =              s_EWKZ+s_tauUp;
const TString s_EWKZtauDown =            s_EWKZ+s_tauDown;
const TString s_EWKZjecUp =              s_EWKZ+s_jecUp;
const TString s_EWKZjecDown =            s_EWKZ+s_jecDown;
const TString s_EWKZJ =                  "EWKZJ";
const TString s_EWKZJjecUp =             s_EWKZJ+s_jecUp;
const TString s_EWKZJjecDown =           s_EWKZJ+s_jecDown;
const TString s_TT =                     "TT";
const TString s_TTtauUp =                s_TT+s_tauUp;
const TString s_TTtauDown =              s_TT+s_tauDown;
const TString s_TTjecUp =                s_TT+s_jecUp;
const TString s_TTjecDown =              s_TT+s_jecDown;
const TString s_TTT =                    "TTT";
const TString s_TTTtauUp =               s_TTT+s_tauUp;
const TString s_TTTtauDown =             s_TTT+s_tauDown;
const TString s_TTTjecUp =               s_TTT+s_jecUp;
const TString s_TTTjecDown =             s_TTT+s_jecDown;
const TString s_TTJ =                    "TTJ";
const TString s_TTJtauUp =               s_TTJ+s_tauUp;
const TString s_TTJtauDown =             s_TTJ+s_tauDown;
const TString s_TTJjecUp =               s_TTJ+s_jecUp;
const TString s_TTJjecDown =             s_TTJ+s_jecDown;
const TString s_VV =                     "VV";
const TString s_VVtauUp =                s_VV+s_tauUp;
const TString s_VVtauDown =              s_VV+s_tauDown;
const TString s_VVjecUp =                s_VV+s_jecUp;
const TString s_VVjecDown =              s_VV+s_jecDown;
const TString s_VVT =                    "VVT";
const TString s_VVTtauUp =               s_VVT+s_tauUp;
const TString s_VVTtauDown =             s_VVT+s_tauDown;
const TString s_VVTjecUp =               s_VVT+s_jecUp;
const TString s_VVTjecDown =             s_VVT+s_jecDown;
const TString s_VVJ =                    "VVJ";
const TString s_VVJtauUp =               s_VVJ+s_tauUp;
const TString s_VVJtauDown =             s_VVJ+s_tauDown;
const TString s_VVJjecUp =               s_VVJ+s_jecUp;
const TString s_VVJjecDown =             s_VVJ+s_jecDown;
const TString s_ggH =                    "ggH";
const TString s_ggHtauUp =               s_ggH+s_tauUp;
const TString s_ggHtauDown =             s_ggH+s_tauDown;
const TString s_ggHjecUp =               s_ggH+s_jecUp;
const TString s_ggHjecDown =             s_ggH+s_jecDown;
const TString s_qqH =                    "qqH";
const TString s_qqHtauUp =               s_qqH+s_tauUp;
const TString s_qqHtauDown =             s_qqH+s_tauDown;
const TString s_qqHjecUp =               s_qqH+s_jecUp;
const TString s_qqHjecDown =             s_qqH+s_jecDown;
const TString s_bbH =                    "bbH";
const TString s_bbHtauUp =               s_bbH+s_tauUp;
const TString s_bbHtauDown =             s_bbH+s_tauDown;
const TString s_bbHjecUp =               s_bbH+s_jecUp;
const TString s_bbHjecDown =             s_bbH+s_jecDown;
const TString s_SMggH =					 "ggH_SM125";
const TString s_SMggHtauUp =             s_SMggH+s_tauUp;
const TString s_SMggHtauDown =           s_SMggH+s_tauDown;
const TString s_SMggHjecUp =             s_SMggH+s_jecUp;
const TString s_SMggHjecDown =           s_SMggH+s_jecDown;
const TString s_SMvbf =					 "qqH_SM125";
const TString s_SMvbftauUp =             s_SMvbf+s_tauUp;
const TString s_SMvbftauDown =           s_SMvbf+s_tauDown;
const TString s_SMvbfjecUp =             s_SMvbf+s_jecUp;
const TString s_SMvbfjecDown =           s_SMvbf+s_jecDown;
const TString s_SMWminus =				 "WminusH_SM125";
const TString s_SMWminustauUp =          s_SMWminus+s_tauUp;
const TString s_SMWminustauDown =        s_SMWminus+s_tauDown;
const TString s_SMWminusjecUp =          s_SMWminus+s_jecUp;
const TString s_SMWminusjecDown =        s_SMWminus+s_jecDown;
const TString s_SMWplus =				 "WplusH_SM125";
const TString s_SMWplustauUp =           s_SMWplus+s_tauUp;
const TString s_SMWplustauDown =         s_SMWplus+s_tauDown;
const TString s_SMWplusjecUp =           s_SMWplus+s_jecUp;
const TString s_SMWplusjecDown =         s_SMWplus+s_jecDown;
const TString s_SMZH =				 	 "ZH_SM125";
const TString s_SMZHtauUp =             s_SMZH+s_tauUp;
const TString s_SMZHtauDown =           s_SMZH+s_tauDown;
const TString s_SMZHjecUp =             s_SMZH+s_jecUp;
const TString s_SMZHjecDown =           s_SMZH+s_jecDown;

const TString s_W =                      "W";
const TString s_West =                   "West";
const TString s_WjecUp =                 s_W+s_jecUp;
const TString s_WjecDown =               s_W+s_jecDown;
const TString s_WestjecUp =              s_West+s_jecUp;
const TString s_WestjecDown =            s_West+s_jecDown;
const TString s_WJ =                     "WJ";
const TString s_WJjecUp =                s_WJ+s_jecUp;
const TString s_WJjecDown =              s_WJ+s_jecDown;
const TString s_QCD =                    "QCD";
const TString s_QCDjecUp =               s_QCD+s_jecUp;
const TString s_QCDjecDown =             s_QCD+s_jecDown;
const TString s_QCDest =                 "QCDest";
const TString s_QCDestjecUp =            s_QCDest+s_jecUp;
const TString s_QCDestjecDown =          s_QCDest+s_jecDown;
const TString s_jetFakes =               "jetFakes";
const TString s_jetFakesjecUp =          s_jetFakes+s_jecUp;
const TString s_jetFakesjecDown =        s_jetFakes+s_jecDown;
const TString s_rest =                   "rest";
const TString s_restjecUp =              s_rest+s_jecUp;
const TString s_restjecDown =            s_rest+s_jecDown;
const TString s_FFrest =                 "FF_rest";
const TString s_FFrestjecUp =            s_FFrest+s_jecUp;
const TString s_FFrestjecDown =          s_FFrest+s_jecDown;
const TString s_jetToTauFake =           "jetToTauFake";
const TString s_jetToTauFakeUp =         s_jetToTauFake+s_up;
const TString s_jetToTauFakeDown =       s_jetToTauFake+s_down;

const TString s_CMStauScale =            "_CMS_scale_t_";
const TString s_CMSjecScale =            "_CMS_scale_j_";
const TString s_CMSdyShape =             "_CMS_htt_dyShape_";
const TString s_CMSttShape =             "_CMS_htt_ttbarShape_";
const TString s_CMSZLShape =             "_CMS_htt_ZLShape_";
const TString s_CMSjetToTauFake =        "_CMS_htt_jetToTauFake_";
const TString s_CMSscalegg =             "_CMS_scale_gg_";
const TString s_CMSzmumu =               "_CMS_htt_zmumuShape_VBF_";
const TString s_CMSmssmHigh =            "_CMS_eff_t_mssmHigh_";
const TString s_WSFUncert =              "_WSFUncert_";
const TString s_QCDSFUncert =            "_QCDSFUncert_";
const TString s_13TeVUp    =             "13TeVUp";
const TString s_13TeVDown =              "13TeVDown";
const TString s_norm =                   "norm";




