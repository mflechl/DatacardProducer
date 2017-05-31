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
        float esup =  NtupleView->zpt_weight_esup == 0 ? 1 : NtupleView->zpt_weight_esup ;
        float esdown =  NtupleView->zpt_weight_esdown == 0 ? 1 : NtupleView->zpt_weight_esdown ;
        float statpt0up = NtupleView->zpt_weight_statpt0up == 0 ? 1 : NtupleView->zpt_weight_statpt0up;
        float statpt0down = NtupleView->zpt_weight_statpt0down == 0 ? 1 : NtupleView->zpt_weight_statpt0down;
        float statpt40up = NtupleView->zpt_weight_statpt40up == 0 ? 1 : NtupleView->zpt_weight_statpt40up;
        float statpt40down = NtupleView->zpt_weight_statpt40down == 0 ? 1 : NtupleView->zpt_weight_statpt40down;
        float statpt80up = NtupleView->zpt_weight_statpt80up == 0 ? 1 : NtupleView->zpt_weight_statpt80up;
        float statpt80down = NtupleView->zpt_weight_statpt80down == 0 ? 1 : NtupleView->zpt_weight_statpt80down;
        float ttup = NtupleView->zpt_weight_ttup == 0 ? 1 : NtupleView->zpt_weight_ttup;
        float ttdown = NtupleView->zpt_weight_ttdown == 0 ? 1 : NtupleView->zpt_weight_ttdown;

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

      	  this->GetHistbyName(s_ZL+s_CMSdyShape_scale+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*esup );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_scale+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*esdown );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt0+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt0up );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt0+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt0down );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt40+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt40up );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt40+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt40down );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt80+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt80up );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_m400pt80+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt80down );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_tjXsec+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*ttup );
      	  this->GetHistbyName(s_ZL+s_CMSdyShape_stat_tjXsec+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*ttdown );
	  

          this->GetHistbyName(s_ZL+s_CMSzmumu+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * this->applyZmumuUncertainty( cat ) );
          this->GetHistbyName(s_ZL+s_CMSzmumu+s_13TeVDown+sub,strVar)->Fill(usedVar, weight / this->applyZmumuUncertainty( cat ) );
        }
        else if( this->TSelection() ){

          this->GetHistbyName(s_ZTT+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZTT+s_CMSdyShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * NtupleView->ZWeight );
          this->GetHistbyName(s_ZTT+s_CMSdyShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->ZWeight );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_scale+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*esup );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_scale+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*esdown );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt0+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt0up );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt0+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt0down );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt40+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt40up );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt40+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt40down );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt80+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt80up );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_m400pt80+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt80down );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_tjXsec+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*ttup );
      	  this->GetHistbyName(s_ZTT+s_CMSdyShape_stat_tjXsec+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*ttdown );

          this->GetHistbyName(s_ZTT+s_CMSzmumu+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * this->applyZmumuUncertainty( cat ) );
          this->GetHistbyName(s_ZTT+s_CMSzmumu+s_13TeVDown+sub,strVar)->Fill(usedVar, weight / this->applyZmumuUncertainty( cat ) );
          if(channel != "tt"){

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
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_scale+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*esup );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_scale+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*esdown );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt0+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt0up );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt0+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt0down );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt40+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt40up );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt40+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt40down );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt80+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt80up );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_m400pt80+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*statpt80down );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_tjXsec+s_13TeVUp+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*ttup );
      	  this->GetHistbyName(s_ZJ+s_CMSdyShape_stat_tjXsec+s_13TeVDown+sub,strVar)->Fill(usedVar, (weight/NtupleView->ZWeight)*ttdown );

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

    else if(fname == s_Z+"T0Up"){
      if( this->Baseline(sign,cat) && this->TSelection() ){
        this->GetHistbyName(fname.ReplaceAll("T0Up","TT")+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_Z+"T1Up"){
      if( this->Baseline(sign,cat) && this->TSelection() ){
        this->GetHistbyName(fname.ReplaceAll("T1Up","TT")+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_Z+"T10Up"){
      if( this->Baseline(sign,cat) && this->TSelection() ){
        this->GetHistbyName(fname.ReplaceAll("T10Up","TT")+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }

    else if(fname == s_Z+"T0Down"){
      if( this->Baseline(sign,cat) && this->TSelection() ){
        this->GetHistbyName(fname.ReplaceAll("T0Down","TT")+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_Z+"T1Down"){
      if( this->Baseline(sign,cat) && this->TSelection() ){
        this->GetHistbyName(fname.ReplaceAll("T1Down","TT")+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_Z+"T10Down"){
      if( this->Baseline(sign,cat) && this->TSelection() ){
        this->GetHistbyName(fname.ReplaceAll("T10Down","TT")+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        return;
      }    
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

          if(channel != "tt"){
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
      	      this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight *(1 - 0.2*NtupleView->genPt_1/1000 )*(1 - 0.2*NtupleView->genPt_2/1000 ) );
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

    else if(fname == s_TT+"T0Up"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T0Up","T")+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_TT+"T1Up"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T1Up","T")+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_TT+"T10Up"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T10Up","T")+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }

    else if(fname == s_TT+"T0Down"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T0Down","T")+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_TT+"T1Down"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T1Down","T")+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_TT+"T10Down"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T10Down","T")+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        return;
      }    
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
          this->GetHistbyName(s_VVT+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_VVJ+sub,strVar)->Fill(usedVar, weight);
        }
        if( this->TSelection() || this->LSelection() ){



          if(channel != "tt"){

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
    else if(fname == s_VV+"T0Up"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T0Up","T")+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_VV+"T1Up"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T1Up","T")+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_VV+"T10Up"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T10Up","T")+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }

    else if(fname == s_VV+"T0Down"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T0Down","T")+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_VV+"T1Down"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T1Down","T")+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        return;
      }
    }
    else if(fname == s_VV+"T10Down"){
      if( this->Baseline(sign,cat) && ( this->TSelection() || this->LSelection() ) ){
        this->GetHistbyName(fname.ReplaceAll("T10Down","T")+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        return;
      }    
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

  TString sign = "OS";
  if( cat.Contains("qcd_cr") ) sign = "SS";
  

  if(fname == s_ggH
     || fname == s_bbH
     || fname ==  s_SMggH
     || fname ==  s_SMvbf
     || fname ==  s_SMWminus
     || fname ==  s_SMWplus
     || fname ==  s_SMZH){

    if( this->Baseline(sign,cat) ){
      this->GetHistbyName(fname+mass+sub,strVar)->Fill(usedVar, weight);

      if(channel != "tt"){
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
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_2)/1000 ) );
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_2)/1000 ) );
        }
        else{
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight );
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight );
        }
      }
      if(channel == "tt"){
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
  

    if(calcFF && !isSync) this->applyFF(usedVar,weight,cat,strVar,fname+mass,0,"");

    if(fname == s_ggH){
      if( this->Baseline(sign,cat) )                 this->GetHistbyName(fname+mass+s_CMSscalegg+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*this->getRenormScale(cat) );
      if( this->Baseline(sign,cat) )                 this->GetHistbyName(fname+mass+s_CMSscalegg+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(2-this->getRenormScale(cat) ) );
    }
    return;
  }
  else if(fname.Contains(s_jecUp)     ){

    if( this->Baseline(sign,cat) )                   this->GetHistbyName(fname.ReplaceAll(s_jecUp,mass+s_jecUp)+sub,strVar)->Fill(usedVar, weight);
    return;
  }
  else if(fname.Contains(s_jecDown)     ){

    if( this->Baseline(sign,cat) )                   this->GetHistbyName(fname.ReplaceAll(s_jecDown,mass+s_jecDown)+sub,strVar)->Fill(usedVar, weight);
    return;
  }

  else if( fname .Contains("T0Up") ){
    if( this->Baseline(sign,cat)  ){
      this->GetHistbyName(fname.ReplaceAll("T0Up","")+mass+s_CMStauScale+s_1p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      return;
    }
  }
  else if(fname.Contains("T1Up")){
    if( this->Baseline(sign,cat)  ){
      this->GetHistbyName(fname.ReplaceAll("T1Up","")+mass+s_CMStauScale+s_1p1p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      return;
    }
  }
  else if(fname.Contains("T10Up")){
    if( this->Baseline(sign,cat)  ){
      this->GetHistbyName(fname.ReplaceAll("T10Up","")+mass+s_CMStauScale+s_3p0p0+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      return;
    }
  }

  else if(fname.Contains("T0Down")){
    if( this->Baseline(sign,cat)  ){
      this->GetHistbyName(fname.ReplaceAll("T0Down","")+mass+s_CMStauScale+s_1p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      return;
    }
  }
  else if(fname.Contains("T1Down")){
    if( this->Baseline(sign,cat)  ){
      this->GetHistbyName(fname.ReplaceAll("T1Down","")+mass+s_CMStauScale+s_1p1p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      return;
    }
  }
  else if(fname.Contains("T10Down")){
    if( this->Baseline(sign,cat)  ){
      this->GetHistbyName(fname.ReplaceAll("T10Down","")+mass+s_CMStauScale+s_3p0p0+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      return;
    }    
  }
  else if( fname.Contains(s_tauUp) ){

    if( this->Baseline(sign,cat) && this->TSelection() ){
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
  else if(fname.Contains(s_tauDown)  ) {

    if( this->Baseline(sign,cat) && this->TSelection() ){
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



