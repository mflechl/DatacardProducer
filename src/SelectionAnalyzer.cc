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
  this->GetHistbyName(s_ZTTjecUp+sub,strVar);
  this->GetHistbyName(s_ZTTjecDown+sub,strVar);
  
}

void SelectionAnalyzer::initEWKZSelections(TString cat, TString strVar, TString extend){

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
  this->GetHistbyName(s_VVTjecUp+sub,strVar);
  this->GetHistbyName(s_VVTjecDown+sub,strVar);
  this->GetHistbyName(s_VV+sub,strVar);
  this->GetHistbyName(s_VVjecUp+sub,strVar);
  this->GetHistbyName(s_VVjecDown+sub,strVar);

}

void SelectionAnalyzer::initSignalSelections(TString cat, TString strVar, TString extend){

  TString sub = extend + "+" + strVar +"_" + cat + "+";

  this->GetHistbyName(s_qqH+"125"+sub,strVar);
  this->GetHistbyName(s_ggH+"125"+sub,strVar);
  this->GetHistbyName(s_qqH+"125"+s_jecUp+sub,strVar);
  this->GetHistbyName(s_qqH+"125"+s_jecDown+sub,strVar);
  this->GetHistbyName(s_ggH+"125"+s_jecUp+sub,strVar);
  this->GetHistbyName(s_ggH+"125"+s_jecDown+sub,strVar);
  this->GetHistbyName(s_qqH+"125"+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_qqH+"125"+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ggH+"125"+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ggH+"125"+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar);
  this->GetHistbyName(s_ggH+"125"+s_CMSscalegg+s_13TeVUp+sub,strVar);
  this->GetHistbyName(s_ggH+"125"+s_CMSscalegg+s_13TeVDown+sub,strVar);

}

void SelectionAnalyzer::Write_CR_Histos(float var, float weight, TString cat, TString strVar, TString fname){
  TString sub = "+" + strVar +"_" + cat + "+";

  if( cat.Contains("looseiso") &&  cat.Contains("wjets_cr")){

    if( this->W_CR("OS", "loose", cat, 1) ) this->GetHistbyName("OS_"+fname+sub,strVar)->Fill(var, weight);
    if( this->W_CR("SS", "loose", cat, 1) ) this->GetHistbyName("SS_"+fname+sub,strVar)->Fill(var, weight);
  } 
  else if( cat.Contains("wjets_cr") ){
    if( this->W_CR("OS", "tight", cat, 1) ) this->GetHistbyName("OS_"+fname+sub,strVar)->Fill(var, weight);
    if( this->W_CR("SS", "tight", cat, 1) ) this->GetHistbyName("SS_"+fname+sub,strVar)->Fill(var, weight);
  }
  else if( cat.Contains("qcd_cr") ){
    if( this->Baseline("SS",cat)  )    this->GetHistbyName("SS_QCD_"+fname+sub,strVar)->Fill(var, weight);
  }
}

void SelectionAnalyzer::DYSelections(float var, float weight, TString cat, TString strVar, TString fname, TString extend){

    TString sub = extend + "+" + strVar +"_" + cat + "+";
    float usedVar=var;
    if(extend=="2D") usedVar = this->get2DVar(sub)+0.1;

    if(fname == s_Z){

      if( this->Baseline("OS",cat) ){

        this->GetHistbyName(s_Z+sub,strVar)->Fill(usedVar, weight);
        ////////////////////////////////////////////////////////////////
        if( this->LSelection() ){
          this->GetHistbyName(s_ZLL+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZL+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZL+s_CMSdyShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * NtupleView->ZWeight );
          this->GetHistbyName(s_ZL+s_CMSdyShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->ZWeight );
          this->GetHistbyName(s_ZL+s_CMSzmumu+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * this->applyZmumuUncertainty( cat ) );
          this->GetHistbyName(s_ZL+s_CMSzmumu+s_13TeVDown+sub,strVar)->Fill(usedVar, weight / this->applyZmumuUncertainty( cat ) );
        }
        else if( this->TSelection() ){
          this->GetHistbyName(s_ZTT+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZTT+s_CMSdyShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * NtupleView->ZWeight );
          this->GetHistbyName(s_ZTT+s_CMSdyShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->ZWeight );
          this->GetHistbyName(s_ZTT+s_CMSzmumu+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * this->applyZmumuUncertainty( cat ) );
          this->GetHistbyName(s_ZTT+s_CMSzmumu+s_13TeVDown+sub,strVar)->Fill(usedVar, weight / this->applyZmumuUncertainty( cat ) );
          if(channel != "tt"){
            this->GetHistbyName(s_ZTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_1)/1000 ) );
            this->GetHistbyName(s_ZTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_1)/1000 ) );
          }
          else{
            this->GetHistbyName(s_ZTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + ( (0.2 * NtupleView->genPt_1)/1000 )*( (0.2 * NtupleView->genPt_2)/1000 ) ) );
            this->GetHistbyName(s_ZTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight *(1 - ( (0.2 * NtupleView->genPt_1)/1000 )*( (0.2 * NtupleView->genPt_2)/1000 ) ) );
          }
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_ZLL+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZJ+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_ZJ+s_CMSdyShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * NtupleView->ZWeight );
          this->GetHistbyName(s_ZJ+s_CMSdyShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->ZWeight );
          this->GetHistbyName(s_ZJ+s_CMSjetToTauFake+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*this->getJetToTauFakeUp(NtupleView->pt_2) );
          this->GetHistbyName(s_ZJ+s_CMSjetToTauFake+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*this->getJetToTauFakeDown(NtupleView->pt_2) );
          this->GetHistbyName(s_ZJ+s_CMSzmumu+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * this->applyZmumuUncertainty( cat ) );
          this->GetHistbyName(s_ZJ+s_CMSzmumu+s_13TeVDown+sub,strVar)->Fill(usedVar, weight / this->applyZmumuUncertainty( cat ) );
        }
        ////////////////////////////////////////////////////////////////
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_ZJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_ZJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);

      this->Write_CR_Histos(usedVar, weight, cat, strVar, s_Z);
      
    }
    else if(fname == s_ZtauUp){
      if( this->Baseline("OS",cat) ){
        if( this->TSelection() ){
          this->GetHistbyName(s_ZTT+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->LSelection() ){
          this->GetHistbyName(s_ZL+s_CMSZLShape+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        }
      }
    }
    else if(fname == s_ZtauDown){
      if( this->Baseline("OS",cat) ){
        if(  this->TSelection() ){
          this->GetHistbyName(s_ZTT+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        }
        else if(  this->LSelection() ){
          this->GetHistbyName(s_ZL+s_CMSZLShape+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        }
      }
    }
    else if(fname == s_ZjecUp){
      if( this->Baseline("OS",cat) ){
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
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_ZJjecUp+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_ZJjecUp+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_ZjecDown){
      if( this->Baseline("OS",cat) ){
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
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_ZJjecDown+"_+"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_ZJjecDown+"_+"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
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
    if(extend=="2D") usedVar = this->get2DVar(sub)+0.1;

    if(fname == s_EWKZ){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_EWKZ+sub,strVar)->Fill(usedVar, weight);
        ////////////////////////////////////////////////////////////////
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_EWKZ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_EWKZ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);

      this->Write_CR_Histos(usedVar, weight, cat, strVar, s_EWKZ);
      
    }
    else if(fname == s_EWKZtauUp){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_EWKZ+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
      }
    }
    else if(fname == s_EWKZtauDown){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_EWKZ+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
      }
    }
    else if(fname == s_EWKZjecUp){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_EWKZjecUp+sub,strVar)->Fill(usedVar, weight);
        ////////////////////////////////////////////////////////////////
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_EWKZjecUp+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_EWKZjecUp+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);

      
    }
    else if(fname == s_EWKZjecDown){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_EWKZjecDown+sub,strVar)->Fill(usedVar, weight);
        ////////////////////////////////////////////////////////////////
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_EWKZjecDown+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_EWKZjecDown+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
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
    if(extend=="2D") usedVar = this->get2DVar(sub)+0.1;

    if(fname == s_TT){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_TT+sub,strVar)->Fill(usedVar, weight);
        this->GetHistbyName(s_TT+s_CMSttShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight * NtupleView->topWeight);
        this->GetHistbyName(s_TT+s_CMSttShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->topWeight);
        if( this->LSelection() || this->TSelection() ){ // for TT TSelection and L Selection are combined
          this->GetHistbyName(s_TTT+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_TTT+s_CMSttShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*NtupleView->topWeight);
          this->GetHistbyName(s_TTT+s_CMSttShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->topWeight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_TTJ+sub,strVar)->Fill(usedVar, weight);
          this->GetHistbyName(s_TTJ+s_CMSttShape+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*NtupleView->topWeight);
          this->GetHistbyName(s_TTJ+s_CMSttShape+s_13TeVDown+sub,strVar)->Fill(usedVar, weight/NtupleView->topWeight);
          this->GetHistbyName(s_TTJ+s_CMSjetToTauFake+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*this->getJetToTauFakeUp(NtupleView->pt_2) );
          this->GetHistbyName(s_TTJ+s_CMSjetToTauFake+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*this->getJetToTauFakeDown(NtupleView->pt_2) );
        }
        if(this->TSelection()){
          if(channel != "tt"){

            this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_1)/1000 ) );
            this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_1)/1000 ) );
          }
          else{
            this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + ( (0.2 * NtupleView->genPt_1)/1000 )*( (0.2 * NtupleView->genPt_2)/1000 ) ) );
            this->GetHistbyName(s_TTT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight *(1 - ( (0.2 * NtupleView->genPt_1)/1000 )*( (0.2 * NtupleView->genPt_2)/1000 ) ) );
          }
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_TTJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_TTJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);

      this->Write_CR_Histos(usedVar, weight, cat, strVar, s_TT);
      
    }
    else if(fname == s_TTtauUp){
      if( this->Baseline("OS",cat) ){                
        this->GetHistbyName(s_TT+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);

        if( this->LSelection() || this->TSelection()  ){
          this->GetHistbyName(s_TTT+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        }
      }
    }
    else if(fname == s_TTtauDown){
      if( this->Baseline("OS",cat) ){                
        this->GetHistbyName(s_TT+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);

        if( this->LSelection() || this->TSelection() ){
          this->GetHistbyName(s_TTT+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        }
      }
    }
    else if(fname == s_TTjecUp){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_TTjecUp+sub,strVar)->Fill(usedVar, weight);

        if( this->LSelection() || this->TSelection() ){
          this->GetHistbyName(s_TTTjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_TTJjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_TTJjecUp+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_TTJjecUp+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_TTjecDown){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_TTjecDown+sub,strVar)->Fill(usedVar, weight);

        if( this->LSelection() || this->TSelection() ){
          this->GetHistbyName(s_TTTjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        else if ( this->JSelection() ){
          this->GetHistbyName(s_TTJjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_TTJjecDown+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_TTJjecDown+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
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
    if(extend=="2D") usedVar = this->get2DVar(sub)+0.1;
    
    if(fname == s_W){
      if( this->Baseline("OS",cat) ){ 
        this->GetHistbyName("SR_MC"+s_W+sub,strVar)->Fill(usedVar, weight);

        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_W+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_W+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

     
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);

      this->Write_CR_Histos(usedVar, weight, cat, strVar, s_W);
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
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName("SR_MC"+s_WjecUp+sub,strVar)->Fill(usedVar, weight);

        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_WjecUp+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_WjecUp+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_WjecDown){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName("SR_MC"+s_WjecDown+sub,strVar)->Fill(usedVar, weight);

        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_WjecDown+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_WjecDown+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
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
    if(extend=="2D") usedVar = this->get2DVar(sub)+0.1;
    
    if(fname == s_VV){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_VV+sub,strVar)->Fill(usedVar, weight);

        if( this->LSelection() || this->TSelection() ){ //// for VV TSelection and L Selection are combined
          this->GetHistbyName(s_VVT+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_VVJ+sub,strVar)->Fill(usedVar, weight);
        }
        if(this->TSelection()){
          if(channel != "tt"){
            this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_1)/1000 ) );
            this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_1)/1000 ) );
          }
          else{
            this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + ( (0.2 * NtupleView->genPt_1)/1000 )*( (0.2 * NtupleView->genPt_2)/1000 ) ) );
            this->GetHistbyName(s_VVT+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight *(1 - ( (0.2 * NtupleView->genPt_1)/1000 )*( (0.2 * NtupleView->genPt_2)/1000 ) ) );
          }
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_VVJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_VVJ+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }
      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);

      this->Write_CR_Histos(usedVar, weight, cat, strVar, s_VV);
      
    }
    else if(fname == s_VVtauUp){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_VV+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);

        if( this->LSelection() || this->TSelection()  ){
          this->GetHistbyName(s_VVT+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
        }
      }
    }
    else if(fname == s_VVtauDown){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_VV+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);

        if( ( this->LSelection() || this->TSelection() ) ){
          this->GetHistbyName(s_VVT+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
        }
      }
    }
    else if(fname == s_VVjecUp){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_VVjecUp+sub,strVar)->Fill(usedVar, weight);

        if( this->LSelection() || this->TSelection() ){
          this->GetHistbyName(s_VVTjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_VVJjecUp+sub,strVar)->Fill(usedVar, weight);
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_VVJjecUp+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_VVJjecUp+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
        }
      }

      if(calcFF) this->applyFF(usedVar,weight,cat,strVar,fname,0,extend);
      
    }
    else if(fname == s_VVjecDown){
      if( this->Baseline("OS",cat) ){
        this->GetHistbyName(s_VVjecDown+sub,strVar)->Fill(usedVar, weight);
        
        if( this->LSelection() || this->TSelection() ){
          this->GetHistbyName(s_VVTjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        else if( this->JSelection() ){
          this->GetHistbyName(s_VVJjecDown+sub,strVar)->Fill(usedVar, weight);
        }
        if( this->FFRest() ){
          if( NtupleView->gen_match_1 < 6 ) this->GetHistbyName(s_VVJjecDown+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
          if( NtupleView->gen_match_2 < 6 ) this->GetHistbyName(s_VVJjecDown+"_"+s_rest+sub,strVar)->Fill(usedVar, weight*0.5);
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
     || fname == s_bbH){

    if( this->Baseline("OS",cat) ){
      this->GetHistbyName(fname+mass+sub,strVar)->Fill(usedVar, weight);
      if(this->TSelection()){
        if(channel != "tt"){
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + (0.2 * NtupleView->genPt_1)/1000 ) );
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(1 - (0.2 * NtupleView->genPt_1)/1000 ) );
        }
        else{
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight *(1 + ( (0.2 * NtupleView->genPt_1)/1000 )*( (0.2 * NtupleView->genPt_2)/1000 ) ) );
          this->GetHistbyName(fname+mass+s_CMSmssmHigh+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight *(1 - ( (0.2 * NtupleView->genPt_1)/1000 )*( (0.2 * NtupleView->genPt_2)/1000 ) )  );
        }
      }
    }
    if(fname == s_ggH){
      if( this->Baseline("OS",cat) )                 this->GetHistbyName(fname+mass+s_CMSscalegg+s_13TeVUp+sub,strVar)->Fill(usedVar, weight*this->getRenormScale(cat) );
      if( this->Baseline("OS",cat) )                 this->GetHistbyName(fname+mass+s_CMSscalegg+s_13TeVDown+sub,strVar)->Fill(usedVar, weight*(2-this->getRenormScale(cat) ) );
    }
    return;
  }
  else if(fname == s_ggHjecUp
     || fname == s_bbHjecUp){

    if( this->Baseline("OS",cat) )                   this->GetHistbyName(fname.ReplaceAll(s_jecUp,mass+s_jecUp)+sub,strVar)->Fill(usedVar, weight);
    return;
  }
  else if(fname == s_ggHjecDown
     || fname == s_bbHjecDown){

    if( this->Baseline("OS",cat) )                   this->GetHistbyName(fname.ReplaceAll(s_jecDown,mass+s_jecDown)+sub,strVar)->Fill(usedVar, weight);
    return;
  }
  else if(fname == s_ggHtauUp
          || fname == s_bbHtauUp){
    if( this->Baseline("OS",cat) )                   this->GetHistbyName(fname.ReplaceAll(s_tauUp,mass)+s_CMStauScale+channel+"_"+s_13TeVUp+sub,strVar)->Fill(usedVar, weight);
    return;
  }
  else if(fname == s_ggHtauDown
          || fname == s_bbHtauDown){
    if( this->Baseline("OS",cat) )                   this->GetHistbyName(fname.ReplaceAll(s_tauDown,mass)+s_CMStauScale+channel+"_"+s_13TeVDown+sub,strVar)->Fill(usedVar, weight);
    return;
  }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SelectionAnalyzer::dataSelections(float var, float weight, TString cat, TString strVar, TString fname, TString extend){
 
    TString sub = extend + "+" + strVar +"_" + cat + "+";
    float usedVar=var;
    if(extend=="2D") usedVar = this->get2DVar(sub)+0.1;

    if( this->Baseline("OS",cat) )          this->GetHistbyName("data_obs"+sub,strVar)->Fill(usedVar, weight);

    if(calcFF) this->applyFF(var,weight,cat,strVar,fname,1,extend);

    this->Write_CR_Histos(usedVar, weight, cat, strVar, s_data);
    
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



