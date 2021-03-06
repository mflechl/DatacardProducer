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

const TString s_0jet_low =               "0Jet_low";
const TString s_0jet_high =              "0Jet_high";
const TString s_1jet_low =               "1Jet_low";
const TString s_1jet_high =              "1Jet_high";
const TString s_vbf_low =                "VBF_low";
const TString s_vbf_high =               "VBF_high";

const TString s_wjets =                   "wjets";
const TString s_antiiso =                 "antiiso";

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

const TString s_data =                   "data";
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
const TString s_WSFUncert =              "_WSFUncert_";
const TString s_QCDSFUncert =            "_QCDSFUncert_";
const TString s_13TeVUp    =             "13TeVUp";
const TString s_13TeVDown =              "13TeVDown";
const TString s_norm =                   "norm";




