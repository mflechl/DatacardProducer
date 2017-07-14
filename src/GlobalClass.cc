#include "interface/GlobalClass.h"
#include "TLorentzVector.h"
#include <iostream>
#include <utility>
#include <sstream>
#include <TObject.h>
#include <algorithm>

using namespace std;

GlobalClass::GlobalClass()
{  
  TH1::SetDefaultSumw2(1);

  ifstream B("config/Binning.json");
  B >> Binning;
}
GlobalClass::~GlobalClass()
{
}

int GlobalClass::getNjets(){
  if(isJEC==1) return NtupleView->njetsUp;
  else if(isJEC==-1) return NtupleView->njetsDown;
  else return NtupleView->njets;
}

float GlobalClass::getMjj(){
  if(isJEC==1) return NtupleView->mjjUp;
  else if(isJEC==-1) return NtupleView->mjjDown;
  else return NtupleView->mjj;
}

float GlobalClass::getJdeta(){
  if(isJEC==1) return abs(NtupleView->jdetaUp);
  else if(isJEC==-1) return abs(NtupleView->jdetaDown);
  else return abs(NtupleView->jdeta);
}

float GlobalClass::getMT(){
  if(useMVAMET) return NtupleView->mt_1;
  return NtupleView->pfmt_1;
}

float GlobalClass::getMT2(){
  if(useMVAMET) return NtupleView->mt_2;
  return NtupleView->pfmt_2;
}

float GlobalClass::CalcHPt(){

  TLorentzVector tau;
  TLorentzVector mu;
  TLorentzVector met;

  mu.SetPtEtaPhiM(NtupleView->pt_1, NtupleView->eta_1, NtupleView->phi_1, NtupleView->m_1);
  tau.SetPtEtaPhiM(NtupleView->pt_2, NtupleView->eta_2, NtupleView->phi_2, NtupleView->m_2);
  if(useMVAMET)met.SetPtEtaPhiM(NtupleView->mvamet,0.,NtupleView->mvametphi,0.);
  else met.SetPtEtaPhiM(NtupleView->met,0.,NtupleView->metphi,0.);

  return (tau + mu + met).Pt();
}

int GlobalClass::Baseline(TString sign, TString cat){
  if( cat.Contains("looseiso") ){
    if( cat.Contains("wjets_cr") ){
      return this->W_CR("OS", "loose", cat, 1);
    }
    if( cat.Contains("wjets_ss_cr") ){
      return this->W_CR("SS", "loose", cat, 1);
    }
  } 
  else{
    if( cat.Contains("wjets_cr") ){
      return this->W_CR("OS", FFiso, cat, 1);
    }
    if( cat.Contains("wjets_ss_cr") ){
      return this->W_CR("SS", FFiso, cat, 1);
    }
  }

  if( this->passIso("base") 
      && this->Vetos()
      && this->CategorySelection(cat,sign)
      ){

      if( sign == "OS" || sign == "SS")  return 1;

      if( sign == "FF" && NtupleView->byVLooseIsolationMVArun2v1DBoldDMwLT_2){
          if(FFiso == "medium" && !NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2) return 1;
          if(FFiso == "tight" && !NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2) return 1;
      }

      if( sign == "FF1"
          && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2
          && !NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_1
          && NtupleView->byVLooseIsolationMVArun2v1DBoldDMwLT_1
          ) return 1;
      if( sign == "FF2"
          && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_1
          && !NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2
          && NtupleView->byVLooseIsolationMVArun2v1DBoldDMwLT_2
          ) return 1;

  }
  
   
  return 0;
}

int GlobalClass::passMTCut(){
  if( !applyMTCut ) return 1;
  if( this->getMT() < Parameter.analysisCut.mTLow ) return 1;
  return 0;
}

int GlobalClass::passIso(TString type){
  if(channel == "tt") return 1;
  if(type == "base"){
    if(channel == "et" && NtupleView->iso_1 < Parameter.analysisCut.elIso_base) return 1;
    if(channel == "mt" && NtupleView->iso_1 < Parameter.analysisCut.muIso_base) return 1;
  }
  return 0;
}

//FIXME: temporary fix, has to be undone as soon as tauLepVeto is correct for etau channel
int GlobalClass::Vetos(){
  if(NtupleView->passesThirdLepVeto){
    if(channel == "et" && NtupleView->againstMuonLoose3_2 && NtupleView->againstElectronTightMVA6_2 && NtupleView->passesDiElectronVeto) return 1;
    if(channel == "mt" && NtupleView->passesTauLepVetos && NtupleView->passesDiMuonVeto) return 1;
    if(channel == "tt" && NtupleView->passesTauLepVetos) return 1; 
  }
  return 0;
}

int GlobalClass::CategorySelection(TString cat, TString iso){

  if( (iso == "OS" || iso.Contains("FF") ) && NtupleView->q_1 * NtupleView->q_2 > 0 ) return 0;
  if(iso == "SS" && NtupleView->q_1 * NtupleView->q_2 < 0 ) return 0;

  if( cat.Contains("loosebtag") ){
    if(cat.Contains("loosebtag_qcd_cr")) return LooseBtagCategory("SS",cat);
    return LooseBtagCategory("OS",cat);
  }

  TString Tiso = "tight";
  if(cat.Contains("loose") && (cat.Contains("btag") && !cat.Contains("nobtag")) ) Tiso = "loose";
  else if(cat.Contains("loose")) Tiso = "medium";
  
  if(iso.Contains("FF") ) Tiso = "no";

  TString tmp = cat;
  tmp.ReplaceAll("_qcd_cr","");
  if( !tmp.Contains("looseiso") && !tmp.Contains("loosemt") ){
    tmp.ReplaceAll("_looseTiso","");
  }

  if(tmp == s_inclusive       )    return 1;    

  
  if(tmp == s_nobtag          )    return this->Btag("nobtag") && this->TauIso(Tiso);
  if(tmp == s_btag            )    return this->Btag("btag")   && this->TauIso(Tiso);
  if(tmp == s_nobtag_tight    )    return this->Btag("nobtag") && this->TightMt(iso);
  if(tmp == s_btag_tight      )    return this->Btag("btag")   && this->TightMt(iso);
  if(tmp == s_nobtag_loosemt  )    return this->Btag("nobtag") && this->LooseMt(iso);
  if(tmp == s_btag_loosemt    )    return this->Btag("btag")   && this->LooseMt(iso);
  
  return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GlobalClass::LooseBtagCategory(TString iso,TString cat){
  TString tmp = cat;
  TString mt = "SR";
  if(cat.Contains("wjets_cr") ) mt = "CR";
  tmp.ReplaceAll("_wjets_cr","");
  tmp.ReplaceAll("_qcd_cr","");
  tmp.ReplaceAll("_loosebtag","");

  if( this->passIso("base") && this->Vetos() ){

      if(tmp == s_inclusive && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2) return 1;

      if(tmp == s_nobtag          )    return this->LooseBtag("nobtag");
      if(tmp == s_btag            )    return this->LooseBtag("btag");
      if(tmp == s_nobtag_tight    )    return this->LooseBtag("nobtag") && this->TightMt(iso,mt);
      if(tmp == s_btag_tight      )    return this->LooseBtag("btag")   && this->TightMt(iso,mt);
      if(tmp == s_nobtag_loosemt  )    return this->LooseBtag("nobtag") && this->LooseMt(iso,mt);
      if(tmp == s_btag_loosemt    )    return this->LooseBtag("btag")   && this->LooseMt(iso,mt);

  }
  
  return 0;
}
int GlobalClass::Btag(TString btag){

  if(btag == "btag" 
    && NtupleView->nbtag > 0  
   // && NtupleView->njets <= 1
    ) return 1;

  if(btag == "nobtag" 
     && NtupleView->nbtag ==0) return 1;

  return 0;

}

int GlobalClass::LooseBtag(TString btag){

  if(btag == "btag"
    // && NtupleView->njets <= 1
     && NtupleView->njetspt20 > 0) return 1;

  if(btag == "nobtag" 
     && NtupleView->nbtag ==0) return 1;

  return 0;

}

int GlobalClass::TauIso(TString Tiso){

  if(Tiso == "tight"){
    if(NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_1 
       && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2 ) return 1;
  }
  if(Tiso == "medium"){
    if( NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_1
        && !NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2
        && NtupleView->byLooseIsolationMVArun2v1DBoldDMwLT_2 ) return 1;
  }
  if(Tiso == "loose"){
    if( NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_1
        && !NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2
        && NtupleView->byVLooseIsolationMVArun2v1DBoldDMwLT_2 ) return 1;
  }
  if(Tiso == "no") return 1;
}

int GlobalClass::TightMt(TString iso,TString mt){

  if(applyMTCut){
    if( mt == "SR" && this->getMT() >  Parameter.analysisCut.mTLow) return 0;
    if( mt == "CR" && this->getMT() <  Parameter.analysisCut.mTHigh) return 0;
  }
  if(iso == "FF") return 1;
  if(iso == "OS" || iso == "SS"){
    if(FFiso == "medium" && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2 ) return 1;
    if(FFiso == "tight" && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2 ) return 1;
  }
    
  


  return 0;
}
int GlobalClass::LooseMt(TString iso,TString mt){

  if(applyMTCut){
    if( mt == "SR" 
        && !(this->getMT() > Parameter.analysisCut.mTLow
             && this->getMT() < Parameter.analysisCut.mTHigh) ) return 0;
    if( mt == "CR" && this->getMT() <  Parameter.analysisCut.mTHigh) return 0;
  }

  if(iso == "FF") return 1;
  if(iso == "OS" || iso == "SS"){
      if(FFiso == "medium" && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2 ) return 1;
      if(FFiso == "tight" && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2) return 1;
  }
  
  
  return 0;
  
}


int GlobalClass::W_CR(TString sign, TString iso, TString cat, bool mtcut){
  if(sign == "OS" && NtupleView->q_1 * NtupleView->q_2 > 0) return 0;
  if(sign == "SS" && NtupleView->q_1 * NtupleView->q_2 < 0) return 0;
  if(mtcut && this->getMT() < Parameter.analysisCut.mTHigh ) return 0;
  if( cat.Contains("nobtag") && NtupleView->nbtag > 0 ) return 0;
  if( cat.Contains("btag") && !cat.Contains("loosebtag") && !cat.Contains("nobtag") && !(NtupleView->nbtag > 0) ) return 0;
  if( cat.Contains("loosebtag") && !(NtupleView->njetspt20 > 0) ) return 0;

  if( this->passIso("base") 
      && this->Vetos() ){

    if(iso == "medium" && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2) return 1;
    if(iso == "tight" && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2) return 1;

  }
  return 0;

}

TH1D* GlobalClass::GetHistbyName(TString name, TString strVar){

  try{
    return histograms.at(name);
  }
  catch(const out_of_range& err){
    return this->JITHistoCreator(name, strVar);
  }
}

void GlobalClass::returnBinning(double* returnHisto, vector<double> input){
  for(int i=0; i<input.size(); i++) returnHisto[i]=input.at(i);
}

int GlobalClass::returnBins(vector<double> input){
  return input.size();
}

TH1D* GlobalClass::getBinnedHisto(TString name,vector<double> input){
  double binning[this->returnBins(input)];
  this->returnBinning(binning,input);
  TH1D* tmp=new TH1D(name,"",this->returnBins(input)-1,&binning[0]);
  return tmp;
}

TH1D* GlobalClass::JITHistoCreator(TString name, TString strVar){

  TString binning = "default";
  if(strVar == s_mttot || strVar == s_mvis){
    if( name.Contains("_btag") )        binning = "btag";
    else if( name.Contains("_nobtag") ) binning = "nobtag";
  }
  if(strVar == s_pt1 || strVar == s_pt2){
    binning = channel;
  }

  if(Binning[strVar.Data()]["doVarBins"]){

    try{
      histograms[name] = this->getBinnedHisto(name,Binning[strVar.Data()]["varBins"].at(binning.Data() ) ) ;
    }
    catch(const out_of_range& err){
      histograms[name] = this->getBinnedHisto(name,Binning[strVar.Data()]["varBins"].at("default") ) ;
    }
    
  }
  else{
    histograms[name] = new TH1D(name,"", Binning[strVar.Data()]["nbins"], Binning[strVar.Data()]["nmin"], Binning[strVar.Data()]["nmax"]  ) ;
  }


  return histograms.at(name);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int GlobalClass::returnBin(vector<double> bins, double value){

  if( value<bins.at(0) ) return -1;
  else if( value > bins.at( bins.size() -1 ) ) return -1;
  for(int i=0; i<bins.size()-1; i++){
    if( value>bins.at(i) && value<bins.at(i+1) ) return i;
  }
  return -1;
}

void GlobalClass::resetZeroBins(TString hist, TString var){

  if(resetZero){
    for(int i = 1; i <= this->GetHistbyName(hist,var)->GetNbinsX(); i++){
      if( this->GetHistbyName(hist,var)->GetBinContent(i) < 0 ){
        this->GetHistbyName(hist,var)->SetBinContent(i,0.);
        this->GetHistbyName(hist,var)->SetBinError(i,0.);
      }
    }
  }
  
}

void GlobalClass::resetZeroBins(TH1D* hist){

  if(resetZero){
    for(int i = 1; i <= hist->GetNbinsX(); i++){
      if( hist->GetBinContent(i) < 0 ){ 
        hist->SetBinContent(i,0.);
        hist->SetBinError(i,0.);
      }
    }
  }
  
}
