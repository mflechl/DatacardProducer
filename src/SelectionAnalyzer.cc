#include "interface/SelectionAnalyzer.h"

using namespace std;

SelectionAnalyzer::SelectionAnalyzer(){  
}

SelectionAnalyzer::~SelectionAnalyzer(){
}

void SelectionAnalyzer::initDYSelections(TString cat, TString strVar, TString extend){

  TString sub = extend + "+" + strVar +"_" + cat + "+";
  this->GetHistbyName(s_Z+sub,strVar);
  this->GetHistbyName(s_ZL+sub,strVar);
  this->GetHistbyName(s_ZL+s_CMSdyShape+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZL+s_CMSdyShape+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ZL+s_CMSZLShape+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZL+s_CMSZLShape+channel+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ZLjecUp+sub,strVar);
  this->GetHistbyName(s_ZLjecDown+sub,strVar);
  this->GetHistbyName(s_ZL+s_CMSzmumu+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZL+s_CMSzmumu+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ZLL+sub,strVar);
  this->GetHistbyName(s_ZJ+sub,strVar);
  this->GetHistbyName(s_ZJ+s_CMSdyShape+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZJ+s_CMSdyShape+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ZJ+s_CMSjetToTauFake+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZJ+s_CMSjetToTauFake+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ZJ+s_CMSzmumu+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZJ+s_CMSzmumu+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ZJjecUp+sub,strVar);
  this->GetHistbyName(s_ZJjecDown+sub,strVar);    
  this->GetHistbyName(s_ZTT+sub,strVar);
  this->GetHistbyName(s_ZTT+s_CMSdyShape+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZTT+s_CMSdyShape+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ZTT+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZTT+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ZTT+s_CMSzmumu+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZTT+s_CMSzmumu+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ZTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar);  
  this->GetHistbyName(s_ZTTjecUp+sub,strVar);
  this->GetHistbyName(s_ZTTjecDown+sub,strVar);

  this->GetHistbyName(s_ZL+s_CMSefake+s_1p0p0+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZL+s_CMSefake+s_1p0p0+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ZL+s_CMSefake+s_1p1p0+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ZL+s_CMSefake+s_1p1p0+"_"+s_13TeVDown+sub,strVar);
  
}

void SelectionAnalyzer::initEWKZSelections(TString cat, TString strVar, TString extend){
  return;
  TString sub = extend + "+" + strVar +"_" + cat + "+";
  this->GetHistbyName(s_EWKZ+sub,strVar);
  this->GetHistbyName(s_EWKZ+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_EWKZ+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_EWKZjecUp+sub,strVar);
  this->GetHistbyName(s_EWKZjecDown+sub,strVar);
  
}

void SelectionAnalyzer::initTSelections(TString cat, TString strVar, TString extend){

  TString sub = extend + "+" + strVar +"_" + cat + "+";
  this->GetHistbyName(s_TTJ+sub,strVar);
  this->GetHistbyName(s_TTJ+s_CMSttShape+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_TTJ+s_CMSttShape+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_TTJ+s_CMSjetToTauFake+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_TTJ+s_CMSjetToTauFake+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_TTJjecUp+sub,strVar);
  this->GetHistbyName(s_TTJjecDown+sub,strVar);    
  this->GetHistbyName(s_TTT+sub,strVar);
  this->GetHistbyName(s_TTT+s_CMSttShape+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_TTT+s_CMSttShape+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_TTT+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_TTT+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_TTTjecUp+sub,strVar);
  this->GetHistbyName(s_TTTjecDown+sub,strVar);
  this->GetHistbyName(s_TT+sub,strVar);
  this->GetHistbyName(s_TT+s_CMSttShape+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_TT+s_CMSttShape+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_TT+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_TT+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_TTjecUp+sub,strVar);
  this->GetHistbyName(s_TTjecDown+sub,strVar);

}

void SelectionAnalyzer::initVVSelections(TString cat, TString strVar, TString extend){

  TString sub = extend + "+" + strVar +"_" + cat + "+";
  this->GetHistbyName(s_VVJ+sub,strVar);
  this->GetHistbyName(s_VVJjecUp+sub,strVar);
  this->GetHistbyName(s_VVJjecDown+sub,strVar);    
  this->GetHistbyName(s_VVT+sub,strVar);
  this->GetHistbyName(s_VVT+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_VVT+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_VVTjecUp+sub,strVar);
  this->GetHistbyName(s_VVTjecDown+sub,strVar);
  this->GetHistbyName(s_VV+sub,strVar);
  this->GetHistbyName(s_VVjecUp+sub,strVar);
  this->GetHistbyName(s_VVjecDown+sub,strVar);

}

void SelectionAnalyzer::initSignalSelections(TString cat, TString strVar, TString extend){

  TString sub = extend + "+" + strVar +"_" + cat + "+";

  for(auto mass : Parameter.dataset.masspoints){
    for(auto type : {s_ggH, s_bbH} ){

      this->GetHistbyName(type+mass+sub,strVar);
      this->GetHistbyName(type+mass+s_jecUp+sub,strVar);
      this->GetHistbyName(type+mass+s_jecDown+sub,strVar);
      this->GetHistbyName(type+mass+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar);
      this->GetHistbyName(type+mass+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar);
      this->GetHistbyName(type+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar);
      this->GetHistbyName(type+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar);
      this->GetHistbyName(type+mass+s_CMSscalegg+s_13TeVUp+sub,strVar);
      this->GetHistbyName(type+mass+s_CMSscalegg+s_13TeVDown+sub,strVar);
    }
  }

}

void SelectionAnalyzer::DYSelections(float var, float weight, TString cat, TString strVar, TString fname, TString extend){

    TString sub = extend + "+" + strVar +"_" + cat + "+";
    float usedVar=var;
    TString sign = "OS";
    if( cat.Contains("qcd_cr") ) sign = "SS";

    if(fname == s_Z){

      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_Z+sub,strVar)->Fill(usedVar, weight);
        ////////////////////////////////////////////////////////////////
        if( this->LSelection() ){
          /*if( NtupleView->gen_match_2 == 1 ){
            if(NtupleView->decayMode_2 != 0){
              this->GetHistbyName(s_ZL+s_CMSefake+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
              this->GetHistbyName(s_ZL+s_CMSefake+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
            }
            if(NtupleView->decayMode_2 != 1){
              this->GetHistbyName(s_ZL+s_CMSefake+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
              this->GetHistbyName(s_ZL+s_CMSefake+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
            }  
          }
          else{
              this->GetHistbyName(s_ZL+s_CMSefake+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
              this->GetHistbyName(s_ZL+s_CMSefake+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
              this->GetHistbyName(s_ZL+s_CMSefake+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
              this->GetHistbyName(s_ZL+s_CMSefake+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );            
	      }*/

          this->GetHistbyName(s_ZLL+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZL+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZL+s_CMSdyShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * NtupleView->ZWeight );
          this->GetHistbyName(s_ZL+s_CMSdyShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->ZWeight );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_scale+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_esup );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_scale+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_esdown );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt0+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt0up );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt0+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt0down );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt40+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt40up );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt40+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt40down );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt80+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt80up );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt80+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt80down );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_tjXsec+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_ttup );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_tjXsec+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_ttdown );
	  

          this->GetHistbyName(s_ZL+s_CMSzmumu+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * this->applyZmumuUncertainty( cat ) );
          this->GetHistbyName(s_ZL+s_CMSzmumu+s_13TeVDown+sub,strVar)->Fill(usedVar, weight / this->applyZmumuUncertainty( cat ) );
        }
        else if( this->TSelection() ){


          if( this->ShapeSelector(0,"nom") ){
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if( this->ShapeSelector(1,"nom")){
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if( this->ShapeSelector(10,"nom")){
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }

          this->GetHistbyName(s_ZTT+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZTT+s_CMSdyShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * NtupleView->ZWeight );
          this->GetHistbyName(s_ZTT+s_CMSdyShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->ZWeight );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_scale+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_esup );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_scale+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_esdown );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt0+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt0up );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt0+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt0down );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt40+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt40up );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt40+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt40down );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt80+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt80up );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt80+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt80down );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_tjXsec+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_ttup );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_tjXsec+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_ttdown );

          this->GetHistbyName(s_ZTT+s_CMSzmumu+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * this->applyZmumuUncertainty( cat ) );
          this->GetHistbyName(s_ZTT+s_CMSzmumu+s_13TeVDown+sub,strVar)->Fill(usedVar, weight / this->applyZmumuUncertainty( cat ) );
          if(channel != "tt"){


            this->GetHistbyName(s_ZTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_2)/1000 ) );
            this->GetHistbyName(s_ZTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_2)/1000 ) );

          }
          else{


            this->GetHistbyName(s_ZTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + 0.2*NtupleView->genPt_1/1000 )*(1 + 0.2*NtupleView->genPt_2/1000 ) );
            this->GetHistbyName(s_ZTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight *(1 - 0.2*NtupleView->genPt_1/1000 )*(1 - 0.2*NtupleView->genPt_2/1000 ) );
	  }
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_ZLL+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZJ+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZJ+s_CMSdyShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * NtupleView->ZWeight );
          this->GetHistbyName(s_ZJ+s_CMSdyShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->ZWeight );
      	  /*this->GetHistbyName(s_ZJ+s_CMSdyShape_scale+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_esup );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_scale+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_esdown );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt0+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt0up );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt0+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt0down );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt40+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt40up );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt40+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt40down );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt80+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt80up );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt80+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_statpt80down );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_tjXsec+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_ttup );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_tjXsec+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*NtupleView->zpt_weight_ttdown );*/

	  this->GetHistbyName(s_ZJ+s_CMSdyShape_scale+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_scale+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt0+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt0+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt40+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt40+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt80+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt80+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_tjXsec+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_tjXsec+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);

          this->GetHistbyName(s_ZJ+s_CMSjetToTauFake+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*this->getJetToTauFakeUp(NtupleView->pt_2) );
          this->GetHistbyName(s_ZJ+s_CMSjetToTauFake+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*this->getJetToTauFakeDown(NtupleView->pt_2) );
          this->GetHistbyName(s_ZJ+s_CMSzmumu+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * this->applyZmumuUncertainty( cat ) );
          this->GetHistbyName(s_ZJ+s_CMSzmumu+s_13TeVDown+sub,strVar)->Fill(usedVar, weight / this->applyZmumuUncertainty( cat ) );
        }
        ////////////////////////////////////////////////////////////////
        if( this->FFRest() && !this->LSelection() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_ZJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_ZJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);


      
    }
    /*else if(fname == s_ZEUp && NtupleView->gen_match_2 == 1 && this->Baseline(sign,cat) ) {
        if(NtupleView->decayMode_2 == 0){
          this->GetHistbyName(s_ZL+s_CMSefake+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
        }
        if(NtupleView->decayMode_2 == 1){
          this->GetHistbyName(s_ZL+s_CMSefake+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
        }
    }
    else if(fname == s_ZEDown && NtupleView->gen_match_2 == 1 && this->Baseline(sign,cat) ){
        if(NtupleView->decayMode_2 == 0){
          this->GetHistbyName(s_ZL+s_CMSefake+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
        }
        if(NtupleView->decayMode_2 == 1){
          this->GetHistbyName(s_ZL+s_CMSefake+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
        }
	}*/
    else if(fname == s_ZE0Up && this->Baseline(sign,cat) && this->LSelection() ) {
      this->GetHistbyName(s_ZL+s_CMSefake+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
    }
    else if(fname == s_ZE1Up && this->Baseline(sign,cat) && this->LSelection() ) {
      this->GetHistbyName(s_ZL+s_CMSefake+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
    }
    else if(fname == s_ZE0Down && this->Baseline(sign,cat) && this->LSelection() ) {
      this->GetHistbyName(s_ZL+s_CMSefake+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
    }
    else if(fname == s_ZE1Down && this->Baseline(sign,cat) && this->LSelection() ) {
      this->GetHistbyName(s_ZL+s_CMSefake+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
    }
    else if(fname == s_ZtauUp){
      if( this->Baseline(sign,cat) ){
        if( this->TSelection() ){
          if(this->ShapeSelector(0,  "shape")){
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(1,  "shape")){
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(10,  "shape")){
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          }
        }
        else if( this->LSelection() ){
          this->GetHistbyName(s_ZL+s_CMSZLShape+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        }
      }
    }
    else if(fname == s_ZtauDown){
      if( this->Baseline(sign,cat) ){
        if(  this->TSelection() ){
          if(this->ShapeSelector(0,  "shape")){
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(1,  "shape")){
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(10,  "shape")){
            this->GetHistbyName(s_ZTT+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
        }
        else if(  this->LSelection() ){
          this->GetHistbyName(s_ZL+s_CMSZLShape+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        }
      }
    }
    else if(fname == s_ZjecUp){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_ZjecUp+sub,strVar)->Fill(usedVar, weight);
        ////////////////////////////////////////////////////////////////
        if( this->LSelection() ){
          this->GetHistbyName(s_ZLjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->TSelection() ){
          this->GetHistbyName(s_ZTTjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_ZJjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        ////////////////////////////////////////////////////////////////
        if( this->FFRest() && !this->LSelection() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_ZJ+"_"+s_rest+s_jecUp+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_ZJ+"_"+s_rest+s_jecUp+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_ZjecDown){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_ZjecDown+sub,strVar)->Fill(usedVar, weight);
        ////////////////////////////////////////////////////////////////
        if( this->LSelection() ){
          this->GetHistbyName(s_ZLjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->TSelection() ){
          this->GetHistbyName(s_ZTTjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_ZJjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        ////////////////////////////////////////////////////////////////
        if( this->FFRest() && !this->LSelection() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_ZJ+"_+"+s_rest+s_jecDown+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_ZJ+"_+"+s_rest+s_jecDown+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SelectionAnalyzer::EWKZSelections(float var, float weight, TString cat, TString strVar, TString fname, TString extend){

    TString sub = extend + "+" + strVar +"_" + cat + "+";
    float usedVar=var;
    TString sign = "OS";
    if( cat.Contains("qcd_cr") ) sign = "SS";

    if(fname == s_EWKZ){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_EWKZ+sub,strVar)->Fill(usedVar, weight);
        ////////////////////////////////////////////////////////////////
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_EWKZ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_EWKZ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_EWKZtauUp){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_EWKZ+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      }
    }
    else if(fname == s_EWKZtauDown){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_EWKZ+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      }
    }
    else if(fname == s_EWKZjecUp){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_EWKZjecUp+sub,strVar)->Fill(usedVar, weight);
        ////////////////////////////////////////////////////////////////
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_EWKZ+"_"+s_rest+s_jecUp+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_EWKZ+"_"+s_rest+s_jecUp+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);

      
    }
    else if(fname == s_EWKZjecDown){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_EWKZjecDown+sub,strVar)->Fill(usedVar, weight);
        ////////////////////////////////////////////////////////////////
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_EWKZ+"_"+s_rest+s_jecDown+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_EWKZ+"_"+s_rest+s_jecDown+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
     
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SelectionAnalyzer::TSelections(float var, float weight, TString cat, TString strVar, TString fname, TString extend){
    TString sub = extend+ "+" + strVar +"_" + cat + "+";
    float usedVar=var;
    TString sign = "OS";
    if( cat.Contains("qcd_cr") ) sign = "SS";

    if(fname == s_TT){
      if( this->Baseline(sign,cat) ){

        this->GetHistbyName(s_TT+sub,strVar)->Fill(usedVar, weight);
        this->GetHistbyName(s_TT+s_CMSttShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * NtupleView->topWeight_run1);
        this->GetHistbyName(s_TT+s_CMSttShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->topWeight_run1);
        if( this->TSelection() || this->LSelection() ){ // for TT TSelection and L Selection are combined

          this->GetHistbyName(s_TTT+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_TTT+s_CMSttShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*NtupleView->topWeight_run1);
          this->GetHistbyName(s_TTT+s_CMSttShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->topWeight_run1);
        }
        else if(  this->JSelection() ){
          this->GetHistbyName(s_TTJ+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_TTJ+s_CMSttShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*NtupleView->topWeight_run1);
          this->GetHistbyName(s_TTJ+s_CMSttShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->topWeight_run1);
          this->GetHistbyName(s_TTJ+s_CMSjetToTauFake+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*this->getJetToTauFakeUp(NtupleView->pt_2) );
          this->GetHistbyName(s_TTJ+s_CMSjetToTauFake+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*this->getJetToTauFakeDown(NtupleView->pt_2) );
        }

        if( this->TSelection() || this->LSelection() ){

          if(this->ShapeSelector(0,  "nom")){
            this->GetHistbyName(s_TTT+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
            this->GetHistbyName(s_TTT+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(1,  "nom")){
            this->GetHistbyName(s_TTT+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
            this->GetHistbyName(s_TTT+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(10,  "nom")){
            this->GetHistbyName(s_TTT+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
            this->GetHistbyName(s_TTT+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }

          if(channel != "tt"){
      	    if( this->TSelection() ){
      	      this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_2)/1000 ) );
      	      this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_2)/1000 ) );
      	    }
      	    else{
      	      this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
      	      this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
      	    }
          }
          else{
      	    if(this->TSelection() ){

      	      this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + 0.2*NtupleView->genPt_1/1000 )*(1 + 0.2*NtupleView->genPt_2/1000 ) );
      	      this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight *(1 + 0.2*NtupleView->genPt_1/1000 )*(1 + 0.2*NtupleView->genPt_2/1000 ) );
      	    }
	    else if( NtupleView->gen_match_1 == 5 ){
              this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_1)/1000 ) );
              this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_1)/1000 ) );
            }
            else if( NtupleView->gen_match_2 == 5 ){
              this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_2)/1000 ) );
              this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_2)/1000 ) );
	    }
      	    else{
      	      this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
      	      this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
      	    }
          }
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_TTJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_TTJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_TTtauUp){
      if( this->Baseline(sign,cat) ){                
        this->GetHistbyName(s_TT+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);

        if( this->TSelection() || this->LSelection() ){
          if(this->ShapeSelector(0,  "shape")){
            this->GetHistbyName(s_TTT+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(1,  "shape")){
            this->GetHistbyName(s_TTT+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(10,  "shape")){
            this->GetHistbyName(s_TTT+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          }
        }
      }
    }
    else if(fname == s_TTtauDown){
      if( this->Baseline(sign,cat) ){                
        this->GetHistbyName(s_TT+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);

        if(  this->TSelection() || this->LSelection() ){
          if(this->ShapeSelector(0,  "shape")){
            this->GetHistbyName(s_TTT+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(1,  "shape")){
            this->GetHistbyName(s_TTT+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(10,  "shape")){
            this->GetHistbyName(s_TTT+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
        }
      }
    }
    else if(fname == s_TTjecUp){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_TTjecUp+sub,strVar)->Fill(usedVar, weight);

        if(  this->TSelection() || this->LSelection() ){
          this->GetHistbyName(s_TTTjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_TTJjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_TTJ+"_"+s_rest+s_jecUp+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_TTJ+"_"+s_rest+s_jecUp+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_TTjecDown){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_TTjecDown+sub,strVar)->Fill(usedVar, weight);

        if(  this->TSelection() || this->LSelection() ){
          this->GetHistbyName(s_TTTjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        else if ( this->JSelection() ){
          this->GetHistbyName(s_TTJjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_TTJ+"_"+s_rest+s_jecDown+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_TTJ+"_"+s_rest+s_jecDown+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SelectionAnalyzer::WSelections(float var, float weight, TString cat, TString strVar, TString fname, TString extend){

    TString sub = extend + "+" + strVar +"_" + cat + "+";
    float usedVar=var;
    TString sign = "OS";
    if( cat.Contains("qcd_cr") ) sign = "SS";
    
    if(fname == s_W){
      if( this->Baseline(sign,cat) ){

        this->GetHistbyName(s_W+"_MC"+sub,strVar)->Fill(usedVar, weight);
      	if(NtupleView->gen_match_2 == 6){ 
      	  this->GetHistbyName(s_W+"_MC_fakeShapeUp_"+sub,strVar)->Fill(usedVar, weight*(1-0.2*NtupleView->pt_2/100) );
      	  this->GetHistbyName(s_W+"_MC_fakeShapeDown_"+sub,strVar)->Fill(usedVar, weight*(1+0.2*NtupleView->pt_2/100) );
      	}
      	else{
      	  this->GetHistbyName(s_W+"_MC_fakeShapeUp_"+sub,strVar)->Fill(usedVar, weight );
      	  this->GetHistbyName(s_W+"_MC_fakeShapeDown_"+sub,strVar)->Fill(usedVar, weight );
      	}

        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_W+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_W+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
     
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);

      if( cat.Contains("looseiso") &&  cat.Contains("wjets_cr")){

        if( this->W_CR("OS", "loose", cat, 0) )  this->GetHistbyName("OS_incl_"+fname+sub,strVar)->Fill(var, weight);
        if( this->W_CR("SS", "loose", cat, 0) ) this->GetHistbyName("SS_incl_"+fname+sub,strVar)->Fill(var, weight);
      } 
      else if( cat.Contains("wjets_cr") ){
        if( this->W_CR("OS", "tight", cat, 0) ) this->GetHistbyName("OS_incl_"+fname+sub,strVar)->Fill(var, weight);
        if( this->W_CR("SS", "tight", cat, 0) ) this->GetHistbyName("SS_incl_"+fname+sub,strVar)->Fill(var, weight);
      }
      
    }
    else if(fname == s_WjecUp){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_WjecUp+"_MC"+sub,strVar)->Fill(usedVar, weight);

        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_W+"_"+s_rest+s_jecUp+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_W+"_"+s_rest+s_jecUp+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_WjecDown){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_WjecDown+"_MC"+sub,strVar)->Fill(usedVar, weight);

        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_W+"_"+s_rest+s_jecDown+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_W+"_"+s_rest+s_jecDown+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SelectionAnalyzer::VVSelections(float var, float weight, TString cat, TString strVar, TString fname, TString extend){

    TString sub = extend + "+" + strVar +"_" + cat + "+";
    float usedVar=var;
    TString sign = "OS";
    if( cat.Contains("qcd_cr") ) sign = "SS";
    
    if(fname == s_VV){
      if( this->Baseline(sign,cat) ){

        this->GetHistbyName(s_VV+sub,strVar)->Fill(usedVar, weight);

        if(this->TSelection() || this->LSelection() ){ //// for VV TSelection and L Selection are combined
          if( this->ShapeSelector(0, "nom") ){
            this->GetHistbyName(s_VVT+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
            this->GetHistbyName(s_VVT+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if( this->ShapeSelector(1, "nom")){
            this->GetHistbyName(s_VVT+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
            this->GetHistbyName(s_VVT+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if( this->ShapeSelector(10, "nom")){
            this->GetHistbyName(s_VVT+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
            this->GetHistbyName(s_VVT+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          this->GetHistbyName(s_VVT+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_VVJ+sub,strVar)->Fill(usedVar, weight);
        }
        if( this->TSelection() || this->LSelection() ){
          if(channel != "tt"){
      	    if( this->TSelection() ){
      	      this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_2)/1000 ) );
      	      this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_2)/1000 ) );
      	    }
      	    else{
      	      this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
      	      this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
      	    }
          }
          else{
      	    if( this->TSelection() ){
      	      this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + 0.2*NtupleView->genPt_1/1000 )*(1 + 0.2*NtupleView->genPt_2/1000 ) ); 
      	      this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight *(1 - 0.2*NtupleView->genPt_1/1000 )*(1 - 0.2*NtupleView->genPt_2/1000 ) );
      	    }
            else if( NtupleView->gen_match_1 == 5 ){
              this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_1)/1000 ) );
              this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_1)/1000 ) );
            }
            else if( NtupleView->gen_match_2 == 5 ){
              this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_2)/1000 ) );
              this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_2)/1000 ) );
	    }
      	    else{
      	      this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
      	      this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
      	    }
          }
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_VVJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_VVJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_VVtauUp){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_VV+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);

        if( this->TSelection() || this->LSelection() ){
          if(this->ShapeSelector(0,  "shape")){
            this->GetHistbyName(s_VVT+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(1,  "shape")){
            this->GetHistbyName(s_VVT+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(10, "shape")){
            this->GetHistbyName(s_VVT+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          }
        }
      }
    }
    else if(fname == s_VVtauDown){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_VV+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);

        if( this->TSelection() || this->LSelection() ){
          if(this->ShapeSelector(0,  "shape")){
            this->GetHistbyName(s_VVT+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(1,  "shape")){
            this->GetHistbyName(s_VVT+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
          if(this->ShapeSelector(10, "shape")){
            this->GetHistbyName(s_VVT+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
          }
        }
      }
    }
    else if(fname == s_VVjecUp){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_VVjecUp+sub,strVar)->Fill(usedVar, weight);

        if( this->TSelection() || this->LSelection() ){
          this->GetHistbyName(s_VVTjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_VVJjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_VVJ+"_"+s_rest+s_jecUp+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_VVJ+"_"+s_rest+s_jecUp+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_VVjecDown){
      if( this->Baseline(sign,cat) ){
        this->GetHistbyName(s_VVjecDown+sub,strVar)->Fill(usedVar, weight);
        
        if( this->TSelection() || this->LSelection() ){
          this->GetHistbyName(s_VVTjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_VVJjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_VVJ+"_"+s_rest+s_jecDown+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_VVJ+"_"+s_rest+s_jecDown+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SelectionAnalyzer::signalSelections(float var, float weight, TString cat, TString strVar, TString fname, TString mass){

  TString sub = "+" + strVar +"_" + cat + "+";
  float usedVar=var;
  

  if(fname == s_ggH
     || fname == s_bbH
     || fname ==  s_SMggH
     || fname ==  s_SMvbf
     || fname ==  s_SMWminus
     || fname ==  s_SMWplus
     || fname ==  s_SMZH){

    if( this->Baseline("OS",cat) ){
      this->GetHistbyName(fname+mass+sub,strVar)->Fill(usedVar, weight);
      if(this->TSelection()){

        if(this->ShapeSelector(0,  "nom")){
          this->GetHistbyName(fname+mass+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(fname+mass+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        }
        if(this->ShapeSelector(1,  "nom")){
          this->GetHistbyName(fname+mass+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(fname+mass+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        }
        if(this->ShapeSelector(10,  "nom")){
          this->GetHistbyName(fname+mass+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(fname+mass+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        }

        if(channel != "tt"){
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_2)/1000 ) );
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_2)/1000 ) );
        }
        else{
          if( this->TSelection() ){
            this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + 0.2*NtupleView->genPt_1/1000 )*(1 + 0.2*NtupleView->genPt_2/1000 ) );
            this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight *(1 - 0.2*NtupleView->genPt_1/1000 )*(1 - 0.2*NtupleView->genPt_2/1000 ) );
          }
          else if( NtupleView->gen_match_1 == 5 ){
            this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_1)/1000 ) );
            this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_1)/1000 ) );
          }
          else if( NtupleView->gen_match_2 == 5 ){
            this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_2)/1000 ) );
            this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_2)/1000 ) );
          }
          else{
            this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
            this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
          }
        }
      }
      else{
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );        
      }
    }

    if(calcFF && !isSync) this->applyFF(usedVar,weight,cat,strVar,fname+mass,0,"");

    if(fname == s_ggH){
      if( this->Baseline("OS",cat) )                 this->GetHistbyName(fname+mass+s_CMSscalegg+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*this->getRenormScale(cat) );
      if( this->Baseline("OS",cat) )                 this->GetHistbyName(fname+mass+s_CMSscalegg+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(2-this->getRenormScale(cat) ) );
    }
    return;
  }
  else if(fname == s_ggHjecUp
     || fname == s_bbHjecUp
     || fname ==  s_SMggHjecUp
     || fname ==  s_SMvbfjecUp
     || fname ==  s_SMWminusjecUp
     || fname ==  s_SMWplusjecUp
     || fname ==  s_SMZHjecUp     ){

    if( this->Baseline("OS",cat) )                   this->GetHistbyName(fname.ReplaceAll(s_jecUp,mass+s_jecUp)+sub,strVar)->Fill(usedVar, weight);
    return;
  }
  else if(fname == s_ggHjecDown
     || fname == s_bbHjecDown
     || fname ==  s_SMggHjecDown
     || fname ==  s_SMvbfjecDown
     || fname ==  s_SMWminusjecDown
     || fname ==  s_SMWplusjecDown
     || fname ==  s_SMZHjecDown     ){

    if( this->Baseline("OS",cat) )                   this->GetHistbyName(fname.ReplaceAll(s_jecDown,mass+s_jecDown)+sub,strVar)->Fill(usedVar, weight);
    return;
  }
  else if(fname == s_ggHtauUp
          || fname == s_bbHtauUp
          || fname ==  s_SMggHtauUp
          || fname ==  s_SMvbftauUp
          || fname ==  s_SMWminustauUp
          || fname ==  s_SMWplustauUp
          || fname ==  s_SMZHtauUp){

    if( this->Baseline("OS",cat) && this->TSelection() ){
      if(this->ShapeSelector(0,  "shape")){
        this->GetHistbyName(fname.ReplaceAll(s_tauUp,mass)+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      }
      if(this->ShapeSelector(1,  "shape")){
        this->GetHistbyName(fname.ReplaceAll(s_tauUp,mass)+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      }
      if(this->ShapeSelector(10,  "shape")){
        this->GetHistbyName(fname.ReplaceAll(s_tauUp,mass)+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      }
    }
    return;
  }
  else if(fname == s_ggHtauDown
          || fname == s_bbHtauDown
          || fname ==  s_SMggHtauDown
          || fname ==  s_SMvbftauDown
          || fname ==  s_SMWminustauDown
          || fname ==  s_SMWplustauDown
          || fname ==  s_SMZHtauDown ){

    if( this->Baseline("OS",cat) && this->TSelection() ){
      if(this->ShapeSelector(0,  "shape")){
        this->GetHistbyName(fname.ReplaceAll(s_tauDown,mass)+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      }
      if(this->ShapeSelector(1,  "shape")){
        this->GetHistbyName(fname.ReplaceAll(s_tauDown,mass)+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      }
      if(this->ShapeSelector(10,  "shape")){
        this->GetHistbyName(fname.ReplaceAll(s_tauDown,mass)+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      }
    }
    return;
  }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SelectionAnalyzer::dataSelections(float var, float weight, TString cat, TString strVar, TString fname, TString extend){
 
    TString sub = extend + "+" + strVar +"_" + cat + "+";
    float usedVar=var;
    TString sign = "OS";
    if( cat.Contains("qcd_cr") ) sign = "SS";

    if( this->Baseline(sign,cat) )   this->GetHistbyName("data_obs"+sub,strVar)->Fill(usedVar, weight);

    if(calcFF) this->applyFF(var,weight,cat,strVar,fname,1,extend);

    
}

int SelectionAnalyzer::ShapeSelector(int dm, TString from){

  if( channel != "tt" ){
      if( from == "nom"  && NtupleView->decayMode_2 != dm) return 1;
      if(from == "shape" && NtupleView->decayMode_2 == dm) return 1;
  }
  else{
      if(from == "nom"   && NtupleView->decayMode_1 != dm && NtupleView->decayMode_2 != dm) return 1;
      if(from == "shape" && (NtupleView->decayMode_1 == dm || NtupleView->decayMode_2 == dm) ) return 1;
  }
  return 0;

}

int SelectionAnalyzer::LSelection(){

  if( ( channel != "tt"
        && NtupleView->gen_match_2 < 5 ) 
      || ( channel == "tt" &&
           !( NtupleView->gen_match_1 == 5 && NtupleView->gen_match_2 == 5 )
           && NtupleView->gen_match_1 < 6 && NtupleView->gen_match_2 < 6  )
      ) return 1;
  else return 0;
  
}

int SelectionAnalyzer::TSelection(){

  if( ( channel != "tt"
        && NtupleView->gen_match_2 == 5 )
      || ( channel == "tt"
           && NtupleView->gen_match_1 == 5
           && NtupleView->gen_match_2 == 5 )
      ) return 1;
  else return 0;
  
}

int SelectionAnalyzer::JSelection(){

  if( ( channel != "tt"
        && NtupleView->gen_match_2 == 6 )
      || ( channel == "tt"
           && ( NtupleView->gen_match_1 == 6
                || NtupleView->gen_match_2 == 6 ) )
      ) return 1;
  else return 0;
  
}

int SelectionAnalyzer::FFRest(){

  if( calcFF
      && channel == "tt"
      && !( NtupleView->gen_match_1 == 5 && NtupleView->gen_match_2 == 5 ) ) return 1;
  else return 0;

}

double SelectionAnalyzer::getJetToTauFakeUp( Float_t inputPt ){

  if(inputPt<200) return 1-(0.2*inputPt/100);
  else return 0.6;
  
}

double SelectionAnalyzer::getJetToTauFakeDown( Float_t inputPt ){

  if(inputPt<200) return 1+(0.2*inputPt/100);
  else return 1.4;
  
}



