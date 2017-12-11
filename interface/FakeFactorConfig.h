#include "Settings.h"


const struct Parameter{

  struct FFsystematics{
    struct XSvariation{
      double DYXSvariation = 0.08;
      double TTXSvariation = 0.12;
    }XSvariation;
    struct mt{
      vector<string> syst = {"ff_qcd_syst_up","ff_qcd_syst_down","ff_qcd_dm0_njet0_stat_up","ff_qcd_dm0_njet0_stat_down","ff_qcd_dm0_njet1_stat_up","ff_qcd_dm0_njet1_stat_down","ff_qcd_dm1_njet0_stat_up","ff_qcd_dm1_njet0_stat_down","ff_qcd_dm1_njet1_stat_up","ff_qcd_dm1_njet1_stat_down","ff_w_syst_up","ff_w_syst_down","ff_w_dm0_njet0_stat_up","ff_w_dm0_njet0_stat_down","ff_w_dm0_njet1_stat_up","ff_w_dm0_njet1_stat_down","ff_w_dm1_njet0_stat_up","ff_w_dm1_njet0_stat_down","ff_w_dm1_njet1_stat_up","ff_w_dm1_njet1_stat_down","ff_tt_syst_up","ff_tt_syst_down","ff_tt_dm0_njet0_stat_up","ff_tt_dm0_njet0_stat_down","ff_tt_dm0_njet1_stat_up","ff_tt_dm0_njet1_stat_down","ff_tt_dm1_njet0_stat_up","ff_tt_dm1_njet0_stat_down","ff_tt_dm1_njet1_stat_up","ff_tt_dm1_njet1_stat_down"};
      vector<string> systMCC = {"ff_w_syst_up","ff_w_syst_down","ff_w_dm0_njet0_stat_up","ff_w_dm0_njet0_stat_down","ff_w_dm0_njet1_stat_up","ff_w_dm0_njet1_stat_down","ff_w_dm1_njet0_stat_up","ff_w_dm1_njet0_stat_down","ff_w_dm1_njet1_stat_up","ff_w_dm1_njet1_stat_down","ff_tt_syst_up","ff_tt_syst_down","ff_tt_dm0_njet0_stat_up","ff_tt_dm0_njet0_stat_down","ff_tt_dm0_njet1_stat_up","ff_tt_dm0_njet1_stat_down","ff_tt_dm1_njet0_stat_up","ff_tt_dm1_njet0_stat_down","ff_tt_dm1_njet1_stat_up","ff_tt_dm1_njet1_stat_down"};
    } mt;
    struct et{
      vector<string> syst = {"ff_qcd_syst_up","ff_qcd_syst_down","ff_qcd_dm0_njet0_stat_up","ff_qcd_dm0_njet0_stat_down","ff_qcd_dm0_njet1_stat_up","ff_qcd_dm0_njet1_stat_down","ff_qcd_dm1_njet0_stat_up","ff_qcd_dm1_njet0_stat_down","ff_qcd_dm1_njet1_stat_up","ff_qcd_dm1_njet1_stat_down","ff_w_syst_up","ff_w_syst_down","ff_w_dm0_njet0_stat_up","ff_w_dm0_njet0_stat_down","ff_w_dm0_njet1_stat_up","ff_w_dm0_njet1_stat_down","ff_w_dm1_njet0_stat_up","ff_w_dm1_njet0_stat_down","ff_w_dm1_njet1_stat_up","ff_w_dm1_njet1_stat_down","ff_tt_syst_up","ff_tt_syst_down","ff_tt_dm0_njet0_stat_up","ff_tt_dm0_njet0_stat_down","ff_tt_dm0_njet1_stat_up","ff_tt_dm0_njet1_stat_down","ff_tt_dm1_njet0_stat_up","ff_tt_dm1_njet0_stat_down","ff_tt_dm1_njet1_stat_up","ff_tt_dm1_njet1_stat_down"};
    } et;
    struct tt{
      vector<string> syst = {"ff_qcd_syst_up","ff_qcd_syst_down","ff_qcd_dm0_njet0_stat_up","ff_qcd_dm0_njet0_stat_down","ff_qcd_dm0_njet1_stat_up","ff_qcd_dm0_njet1_stat_down","ff_qcd_dm1_njet0_stat_up","ff_qcd_dm1_njet0_stat_down","ff_qcd_dm1_njet1_stat_up","ff_qcd_dm1_njet1_stat_down","ff_w_syst_up","ff_w_syst_down","ff_tt_syst_up","ff_tt_syst_down","ff_w_frac_syst_up","ff_dy_frac_syst_up","ff_tt_frac_syst_up","ff_w_frac_syst_down" ,"ff_dy_frac_syst_down","ff_tt_frac_syst_down"};
    } tt;
  } FFsystematics;

} Parameter;

 
