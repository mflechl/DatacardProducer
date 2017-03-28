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
  
  if( NtupleView->q_1 * NtupleView->q_2 < 0
      &&( ( cat.Contains(s_antiiso)
            && this->passIso("antiiso")
          )
          || this->passIso("base") 
      )
      && this->Vetos()
      && this->CategorySelection(cat,sign)
      ){
    if( sign == "OS") return 1;
    if( sign == "FF"
        && !NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2
        && NtupleView->byVLooseIsolationMVArun2v1DBoldDMwLT_2
        ) return 1;
    if( sign == "FF1"
        && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2
        && !NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_1
        && NtupleView->byVLooseIsolationMVArun2v1DBoldDMwLT_1
        ) return 1;
    if( sign == "FF2"
        && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_1
        && !NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2
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
    //if(channel == "tt" && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_1 && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2 ) return 1;
  }
  else if(type == "relaxed"){
    if(channel == "et" && NtupleView->iso_1 < Parameter.analysisCut.elIso_relaxed) return 1;
    if(channel == "mt" && NtupleView->iso_1 < Parameter.analysisCut.muIso_relaxed) return 1;
  }
  else if(type == "antiiso"){
    if(channel == "et" && NtupleView->iso_1 < Parameter.analysisCut.elIso_antiIsoHigh && NtupleView->iso_1 > Parameter.analysisCut.elIso_antiIsoLow) return 1;
    if(channel == "mt" && NtupleView->iso_1 < Parameter.analysisCut.muIso_antiIsoHigh && NtupleView->iso_1 > Parameter.analysisCut.muIso_antiIsoLow) return 1;
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

  if(cat == s_inclusive) return 1;
  ///////////////////////  0jet category     ///////////////////////////////
  if(cat == s_nobtag      )    return this->Btag("nobtag");
  if(cat == s_btag        )    return this->Btag("btag");
  if(cat == s_nobtagLow   )    return this->Btag("nobtag") && this->LowMt(iso);
  if(cat == s_btagLow     )    return this->Btag("btag") && this->LowMt(iso);
  if(cat == s_nobtagLoose )    return this->Btag("nobtag") && this->LooseMt(iso);
  if(cat == s_btagLoose   )    return this->Btag("btag") && this->LooseMt(iso);
  if(cat == s_nobtagHigh  )    return this->Btag("nobtag") && this->HighMt(iso);
  if(cat == s_btagHigh    )    return this->Btag("btag") && this->HighMt(iso);
  
  return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int GlobalClass::Btag(TString btag){

  if(btag == "btag" 
    && NtupleView->nbtag > 0) return 1;

  if(btag == "nobtag" 
     && NtupleView->nbtag ==0) return 1;

  return 0;

}

int GlobalClass::LowMt(TString iso){

  if(NtupleView->mt_1 <  Parameter.analysisCut.mTLow){ 

    if(iso == "OS" && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2 ) return 1;
    if(iso == "FF") return 1;
  } 


  return 0;
}
int GlobalClass::HighMt(TString iso){

  if(NtupleView->mt_1 > Parameter.analysisCut.mTLow
     && NtupleView->mt_1 < Parameter.analysisCut.mTHigh){

     if(iso == "OS" && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2) return 1;
     if(iso == "FF") return 1;
 }
  return 0;
  
}
int GlobalClass::LooseMt(TString iso){
  if(NtupleView->mt_1 <  Parameter.analysisCut.mTHigh){

    if(iso == "OS"
       && !NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2
       && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2) return 1;
    if(iso == "FF") return 1;
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

  int nbins = 1;
  double nmin = 0;
  double nmax = 1;

  int usingVarBins = 0;

  if( name.Contains(s_wjets) ){
    nbins = 1;
    nmin  = 80;
    nmax  = 200;
    histograms[name] = new TH1D(name,"", nbins, nmin, nmax  ) ;

    return histograms.at(name);
  }
  if( name.Contains(s_antiiso) ){
    nbins = 4;
    nmin  = 40;
    nmax  = 200;
    histograms[name] = new TH1D(name,"", nbins, nmin, nmax  ) ;


    return histograms.at(name);
  }

  if( channel != "tt" && name.Contains("2D") ){
    if( name.Contains(Parameter.variable2D.D2_0Jet.name) ){
      nbins = ( Parameter.variable2D.D2_0Jet.binsX.size()-1 ) * ( Parameter.variable2D.D2_0Jet.binsY.size()-1 );
      nmin = 0;
      nmax = nbins;
    }
    else if( name.Contains(Parameter.variable2D.D2_boosted.name) ){
      nbins = (doSvfit=="SVFIT") ? ( Parameter.variable2D.D2_boosted.binsX.size()-1 ) * ( Parameter.variable2D.D2_boosted.binsY_svfit.size()-1 ) : ( Parameter.variable2D.D2_boosted.binsX.size()-1 ) * ( Parameter.variable2D.D2_boosted.binsY_mvis.size()-1 );
      nmin = 0;
      nmax = nbins;
    }
    else if( name.Contains(Parameter.variable2D.D2_vbf.name) ){
      nbins = (doSvfit=="SVFIT") ? ( Parameter.variable2D.D2_vbf.binsX.size()-1 ) * ( Parameter.variable2D.D2_vbf.binsY_svfit.size()-1 ) : ( Parameter.variable2D.D2_vbf.binsX.size()-1 ) * ( Parameter.variable2D.D2_vbf.binsY_mvis.size()-1 );
      nmin = 0;
      nmax = nbins;
    }
    histograms[name] = new TH1D(name,"", nbins, nmin, nmax  ) ;


    return histograms.at(name);
  }
  if( channel == "tt" && name.Contains("2D") ){
    if( name.Contains(Parameter.variable2D_tt.D2_0Jet.name) ){
      nbins = ( Parameter.variable2D_tt.D2_0Jet.binsX.size()-1 );
      nmin = 0;
      nmax = nbins;
    }
    else if( name.Contains(Parameter.variable2D_tt.D2_boosted.name) ){
      nbins = (doSvfit=="SVFIT") ? ( Parameter.variable2D_tt.D2_boosted.binsX.size()-1 ) * ( Parameter.variable2D_tt.D2_boosted.binsY_svfit.size()-1 ) : ( Parameter.variable2D_tt.D2_boosted.binsX.size()-1 ) * ( Parameter.variable2D_tt.D2_boosted.binsY_mvis.size()-1 );
      nmin = 0;
      nmax = nbins;
    }
    else if( name.Contains(Parameter.variable2D_tt.D2_vbf.name) ){
      nbins = (doSvfit=="SVFIT") ? ( Parameter.variable2D_tt.D2_vbf.binsX.size()-1 ) * ( Parameter.variable2D_tt.D2_vbf.binsY_svfit.size()-1 ) : ( Parameter.variable2D_tt.D2_vbf.binsX.size()-1 ) * ( Parameter.variable2D_tt.D2_vbf.binsY_mvis.size()-1 );
      nmin = 0;
      nmax = nbins;
    }
    histograms[name] = new TH1D(name,"", nbins, nmin, nmax  ) ;


    return histograms.at(name);
  }

  if(strVar == s_norm){
    nbins = 4;
    nmin  = 0;
    nmax  = 4;
  }
  
  if(strVar == s_mvis){
    if(Parameter.variable.m_vis.doVarBins) {
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.m_vis.varBins) ;
    }
    else{
      nbins = Parameter.variable.m_vis.nbins;
      nmin  = Parameter.variable.m_vis.nmin;;
      nmax  = Parameter.variable.m_vis.nmax;
    }
  }

  if(strVar == s_msv){
    if(Parameter.variable.m_sv.doVarBins) {
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.m_sv.varBins) ;
    }
    else{
      nbins = Parameter.variable.m_sv.nbins;
      nmin  = Parameter.variable.m_sv.nmin;;
      nmax  = Parameter.variable.m_sv.nmax;
    }
  }

  if(strVar == s_ptsv){
    if(Parameter.variable.pt_sv.doVarBins) {
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.pt_sv.varBins) ;
    }
    else{
      nbins = Parameter.variable.pt_sv.nbins;
      nmin  = Parameter.variable.pt_sv.nmin;;
      nmax  = Parameter.variable.pt_sv.nmax;
    }
  }

  else if(strVar == s_jpt1
          || strVar == s_jpt2
        ){
    if(Parameter.variable.jpt.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.jpt.varBins) ;
    }
    else{
      nbins = Parameter.variable.jpt.nbins;
      nmin  = Parameter.variable.jpt.nmin;
      nmax  = Parameter.variable.jpt.nmax;
    }
  }
  else if(strVar == s_pt1 || strVar == s_pt2){
    if(Parameter.variable.pt.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.pt.varBins) ;
    }
    else{
      nbins = Parameter.variable.pt.nbins;
      nmin  = Parameter.variable.pt.nmin;
      nmax  = Parameter.variable.pt.nmax;
    }
  }
  else if(strVar == s_eta1 || strVar == s_eta2){
    if(Parameter.variable.eta.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.eta.varBins) ;
    }
    else{
      nbins = Parameter.variable.eta.nbins;
      nmin  = Parameter.variable.eta.nmin;
      nmax  = Parameter.variable.eta.nmax;
    }
  }
  else if(strVar == s_jeta1 || strVar == s_jeta2){
    if(Parameter.variable.jeta.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.jeta.varBins) ;
    }
    else{
      nbins = Parameter.variable.jeta.nbins;
      nmin  = Parameter.variable.jeta.nmin;
      nmax  = Parameter.variable.jeta.nmax;
    }
  }
  else if(strVar == "jdeta"){
    if(Parameter.variable.jdeta.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.jdeta.varBins) ; 
    }
    else{
      nbins = Parameter.variable.jdeta.nbins;
      nmin  = Parameter.variable.jdeta.nmin;
      nmax  = Parameter.variable.jdeta.nmax;
    }
  }
  else if(strVar == s_mt1){
    if(Parameter.variable.mt_1.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.mt_1.varBins) ;
    }
    else{
      nbins = Parameter.variable.mt_1.nbins;
      nmin  = Parameter.variable.mt_1.nmin;
      nmax  = Parameter.variable.mt_1.nmax;
    }
  }
  else if(strVar == s_met){
    if(Parameter.variable.met.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.met.varBins) ;
    }
    else{
      nbins = Parameter.variable.met.nbins;
      nmin  = Parameter.variable.met.nmin;
      nmax  = Parameter.variable.met.nmax;
    }
  }
  else if(strVar == s_mttot){
    if(Parameter.variable.mttot.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.mttot.varBins) ;
    }
    else{
      nbins = Parameter.variable.mttot.nbins;
      nmin  = Parameter.variable.mttot.nmin;
      nmax  = Parameter.variable.mttot.nmax;
    }
  }
  else if(strVar == s_Hpt){
    if(Parameter.variable.Hpt.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.Hpt.varBins) ;
    }
    else{
      nbins = Parameter.variable.Hpt.nbins;
      nmin  = Parameter.variable.Hpt.nmin;
      nmax  = Parameter.variable.Hpt.nmax;
    }
  }
  else if(strVar == "High_mt_1"){
    if(Parameter.variable.High_mt_1.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.High_mt_1.varBins) ;
    }
    else{
      nbins = Parameter.variable.High_mt_1.nbins;
      nmin  = Parameter.variable.High_mt_1.nmin;
      nmax  = Parameter.variable.High_mt_1.nmax;
    }
  }
  else if(strVar == "Low_mt_1"){
    if(Parameter.variable.Low_mt_1.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.Low_mt_1.varBins) ;
    }
    else{
      nbins = Parameter.variable.Low_mt_1.nbins;
      nmin  = Parameter.variable.Low_mt_1.nmin;
      nmax  = Parameter.variable.Low_mt_1.nmax;
    }
  }
  else if(strVar == "iso_1"){
    if(Parameter.variable.iso_1.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.iso_1.varBins) ;
    }
    else{
      nbins = Parameter.variable.iso_1.nbins;
      nmin  = Parameter.variable.iso_1.nmin;
      nmax  = Parameter.variable.iso_1.nmax;
    }
  }
  else if(strVar == s_mjj){
    if(Parameter.variable.mjj.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.mjj.varBins) ;
    }
    else{
      nbins = Parameter.variable.mjj.nbins;
      nmin  = Parameter.variable.mjj.nmin;
      nmax  = Parameter.variable.mjj.nmax;
    }
  }
  else if(strVar == "jeta1eta2"){
    if(Parameter.variable.jeta1eta2.doVarBins){
      usingVarBins = 1;
      histograms[name] = this->getBinnedHisto(name,Parameter.variable.jeta1eta2.varBins) ;
    }
    else{
      nbins = Parameter.variable.jeta1eta2.nbins;
      nmin  = Parameter.variable.jeta1eta2.nmin;
      nmax  = Parameter.variable.jeta1eta2.nmax;
    }
  }
  
  //else throw std::invalid_argument( "Cannot create histo: " + name + ". Binning not found"  );

  if(!usingVarBins) histograms[name] = new TH1D(name,"", nbins, nmin, nmax  ) ;

  return histograms.at(name);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double GlobalClass::QCD_OSSS(TString cat){

  return 1.0;
}

int GlobalClass::OS_W(TString cat){

  if(NtupleView->q_1 * NtupleView->q_2 < 0
     &&( ( cat.Contains(s_antiiso)
           && this->passIso("antiiso")
           )
         || ( this->passIso("base") )
         )
     && this->getMT() > Parameter.analysisCut.mTHigh
     && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2
     && this->CategorySelection(cat, "wo")
     && this->Vetos()) return 1;
  return 0;
}

int GlobalClass::SS_W(TString cat){

  if(NtupleView->q_1 * NtupleView->q_2 > 0
     &&( ( cat.Contains(s_antiiso)
           && this->passIso("antiiso")
           )
         || ( this->passIso("base") )
         )
     && this->getMT() > Parameter.analysisCut.mTHigh
     && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2
     && this->CategorySelection(cat, "wo")
     && this->Vetos()) return 1;
  return 0;
}

int GlobalClass::relaxed_W(TString cat, TString mt){

  if(NtupleView->q_1 * NtupleView->q_2 < 0
     && this->passIso("relaxed")
     && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2
     && this->Vetos()
     && this->CategorySelection(cat, "wo")){

    if(mt == "low" && this->getMT() < Parameter.analysisCut.mTLow) return 1;
    if(mt == "high" && this->getMT() > Parameter.analysisCut.mTHigh) return 1;
  }
  return 0;
}

int GlobalClass::SS_Low(TString cat){

  if(NtupleView->q_1 * NtupleView->q_2 > 0
     &&( ( cat.Contains(s_antiiso)
           && this->passIso("antiiso")
           )
         || ( this->passIso("base") )
         )
     && this->getMT() < Parameter.analysisCut.mTLow
     && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2
     && this->CategorySelection(cat, "wo")
     && this->Vetos()) return 1;
  return 0;
}

int GlobalClass::SS_Low_relaxed(TString cat){

  if(NtupleView->q_1 * NtupleView->q_2 > 0
     &&( ( cat.Contains(s_antiiso)
           && this->passIso("antiiso")
           )
         || ( this->passIso("base") )
         )
     && this->getMT() < Parameter.analysisCut.mTLow
     && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2
     && this->CategorySelection(cat, "wo")
     && this->Vetos()) return 1;
  return 0;
}

int GlobalClass::returnBin(vector<double> bins, double value){

  if( value<bins.at(0) ) return -1;
  else if( value > bins.at( bins.size() -1 ) ) return -1;
  for(int i=0; i<bins.size()-1; i++){
    if( value>bins.at(i) && value<bins.at(i+1) ) return i;
  }
  return -1;
}

double GlobalClass::get2DVar(TString sub){

  if( sub.Contains(s_wjets) ) return 80;
  if (sub.Contains(s_antiiso) ){
    int binX= (doSvfit=="SVFIT" &&
               ( sub.Contains(s_boosted)
                 || sub.Contains(s_vbf)
                 )
               ) ? this->returnBin(Parameter.variable2D.antiiso.binsX,NtupleView->m_sv) : this->returnBin(Parameter.variable2D.antiiso.binsX,NtupleView->m_vis);
    return Parameter.variable2D.antiiso.binsX[binX-1];
  }

  if( channel != "tt" ){
    if( sub.Contains(Parameter.variable2D.D2_0Jet.name) ){
      int binX=this->returnBin(Parameter.variable2D.D2_0Jet.binsX,NtupleView->pt_2);
      int binY=this->returnBin(Parameter.variable2D.D2_0Jet.binsY,NtupleView->m_vis);
      //if(binX>=0 && binY>=0) return binX+binY*(Parameter.variable2D.D2_0Jet.binsX.size()-1);
      if(binX>=0 && binY>=0) return binY+binX*(Parameter.variable2D.D2_0Jet.binsY.size()-1);
    }
    else if( sub.Contains(Parameter.variable2D.D2_boosted.name) ){
      int binX= (doSvfit=="SVFIT") ? this->returnBin(Parameter.variable2D.D2_boosted.binsX,NtupleView->pt_sv) : this->returnBin(Parameter.variable2D.D2_boosted.binsX,this->CalcHPt());
      int binY= (doSvfit=="SVFIT") ? this->returnBin(Parameter.variable2D.D2_boosted.binsY_svfit,NtupleView->m_sv) : this->returnBin(Parameter.variable2D.D2_boosted.binsY_mvis,NtupleView->m_vis); 
      if(binX>=0 && binY>=0) {
        if(doSvfit=="SVFIT") return binY+binX*(Parameter.variable2D.D2_boosted.binsY_svfit.size()-1);
        else return binY+binX*(Parameter.variable2D.D2_boosted.binsY_mvis.size()-1);
        //return binX+binY*(Parameter.variable2D.D2_boosted.binsX.size()-1);
      }
    }
    else if( sub.Contains(Parameter.variable2D.D2_vbf.name) ){
      int binX=this->returnBin(Parameter.variable2D.D2_vbf.binsX,this->getMjj());
      int binY= (doSvfit=="SVFIT") ? this->returnBin(Parameter.variable2D.D2_vbf.binsY_svfit,NtupleView->m_sv) : this->returnBin(Parameter.variable2D.D2_vbf.binsY_mvis,NtupleView->m_vis); 
      if(binX>=0 && binY>=0) {
        if(doSvfit=="SVFIT") return binY+binX*(Parameter.variable2D.D2_vbf.binsY_svfit.size()-1);
        else return binY+binX*(Parameter.variable2D.D2_vbf.binsY_mvis.size()-1);
        //return binX+binY*(Parameter.variable2D.D2_vbf.binsX.size()-1);
      }
    }
  }

  else if( channel == "tt" ){
    if( sub.Contains(Parameter.variable2D_tt.D2_0Jet.name) ){
      int binX= (doSvfit=="SVFIT") ? this->returnBin(Parameter.variable2D_tt.D2_0Jet.binsX,NtupleView->m_sv) : this->returnBin(Parameter.variable2D_tt.D2_0Jet.binsX,NtupleView->m_vis);
      if( binX>=0 ) return binX;
    }
    else if( sub.Contains(Parameter.variable2D_tt.D2_boosted.name) ){
      int binX= (doSvfit=="SVFIT") ? this->returnBin(Parameter.variable2D_tt.D2_boosted.binsX,NtupleView->pt_sv) : this->returnBin(Parameter.variable2D_tt.D2_boosted.binsX,this->CalcHPt());
      int binY= (doSvfit=="SVFIT") ? this->returnBin(Parameter.variable2D_tt.D2_boosted.binsY_svfit,NtupleView->m_sv) : this->returnBin(Parameter.variable2D_tt.D2_boosted.binsY_mvis,NtupleView->m_vis); 
      if(binX>=0 && binY>=0) {
        if(doSvfit=="SVFIT") return binY+binX*(Parameter.variable2D_tt.D2_boosted.binsY_svfit.size()-1);
        else return binY+binX*(Parameter.variable2D_tt.D2_boosted.binsY_mvis.size()-1);
        //return binX+binY*(Parameter.variable2D.D2_boosted.binsX.size()-1);
      }
    }
    else if( sub.Contains(Parameter.variable2D_tt.D2_vbf.name) ){
      int binX=this->returnBin(Parameter.variable2D_tt.D2_vbf.binsX,this->getMjj());
      int binY= (doSvfit=="SVFIT") ? this->returnBin(Parameter.variable2D_tt.D2_vbf.binsY_svfit,NtupleView->m_sv) : this->returnBin(Parameter.variable2D_tt.D2_vbf.binsY_mvis,NtupleView->m_vis); 
      if(binX>=0 && binY>=0) {
        if(doSvfit=="SVFIT") return binY+binX*(Parameter.variable2D_tt.D2_vbf.binsY_svfit.size()-1);
        else return binY+binX*(Parameter.variable2D_tt.D2_vbf.binsY_mvis.size()-1);
        //return binX+binY*(Parameter.variable2D.D2_vbf.binsX.size()-1);
      }
    }
  }
  
  else return -1;
  
}

void GlobalClass::resetZeroBins(TString hist, TString var){

  if(resetZero){
    for(int i = 1; i <= this->GetHistbyName(hist,var)->GetNbinsX(); i++){
      if( this->GetHistbyName(hist,var)->GetBinContent(i) < 0 ) this->GetHistbyName(hist,var)->SetBinContent(i,0.);
    }
  }
  
}

void GlobalClass::resetZeroBins(TH1D* hist){

  if(resetZero){
    for(int i = 1; i <= hist->GetNbinsX(); i++){
      if( hist->GetBinContent(i) < 0 ) hist->SetBinContent(i,0.);
    }
  }
  
}

double GlobalClass::getWSFUncertainty( TString cat ){

  if(channel == "mt"){
    if( cat.Contains(s_0jet) ) return 0.1;
    else if( cat.Contains(s_boosted) ) return 0.1;
    else if( cat.Contains(s_vbf) ) return 0.3;
  }
  else if(channel == "et"){
    if( cat.Contains(s_0jet) ) return 0.1;
    else if( cat.Contains(s_boosted) ) return 0.1;
    else if( cat.Contains(s_vbf) ) return 0.3;
  }

  return 1;
  
}

double GlobalClass::getQCDSFUncertainty( TString cat ){

  if(channel == "mt"){
    if( cat.Contains(s_0jet) ) return 0.15;
    else if( cat.Contains(s_boosted) ) return 0.15;
    else if( cat.Contains(s_vbf) ) return 0.3;
  }
  else if(channel == "et"){
    if( cat.Contains(s_0jet) ) return 0.15;
    else if( cat.Contains(s_boosted) ) return 0.15;
    else if( cat.Contains(s_vbf) ) return 0.3;
  }

  return 1;
  
}

double GlobalClass::getRenormScale( TString cat ){

  double HiggsPt = (doSvfit=="SVIFT") ? NtupleView->pt_sv : this->CalcHPt();

  if(channel == "mt"){
    if(cat == s_0jet) return 0.929 + 0.0001702 * NtupleView->pt_2;
    else if(cat == s_boosted) return 0.919 - 0.0010055 * HiggsPt;
    else if(cat == s_vbf) return 1.026 + 0.000066 * NtupleView->mjj;
  }
  else if(channel == "et"){
    if(cat == s_0jet) return 0.973 + 0.0003405 * NtupleView->pt_2;
    else if(cat == s_boosted) return 0.986 - 0.0000278 * HiggsPt;
    else if(cat == s_vbf) return 0.971 + 0.0000327 * NtupleView->mjj;
  }
  else if(channel == "tt"){
    if(cat == s_0jet) return 0.814 + 0.0027094 * NtupleView->pt_1;
    else if(cat == s_boosted) return 0.973 - 0.0008596 * HiggsPt;
    else if(cat == s_vbf) return 1.094 + 0.0000545 * NtupleView->mjj;
  }

  return 1;

}

double GlobalClass::getZmumuWeight( TString cat ){

  double HiggsPt = (doSvfit=="SVIFT") ? NtupleView->pt_sv : this->CalcHPt();

  if( cat == s_0jet ) return 1.;
  else if( cat == s_boosted && channel != "tt" ){
    if( HiggsPt<100 )      return 0.971;
    else if( HiggsPt<150 ) return 0.975;
    else if( HiggsPt<200 ) return 0.96;
    else if( HiggsPt<250 ) return 0.964;
    else if( HiggsPt<300 ) return 0.934;
    else                   return 0.942;
  } 
  else if( cat == s_boosted && channel == "tt" ){
    if( HiggsPt<100 )      return 0.973;
    else if( HiggsPt<170 ) return 0.959;
    else if( HiggsPt<300 ) return 0.934;
    else                   return 0.993;
  }   
  else if(cat == s_vbf && channel != "tt" ){
    if( this->getMjj()<300 )  return 1;
    if( this->getMjj()<700 )  return 1.043;
    if( this->getMjj()<1100 ) return 0.965;
    if( this->getMjj()<1500 ) return 0.901;
    else                      return 0.888;
  } 
  else if(cat == s_vbf && channel == "tt" ){
    if( this->getMjj()<300 )  return 1.05;
    if( this->getMjj()<500 )  return 1.032;
    if( this->getMjj()<800 )  return 1.044;
    else                      return 1.002;
  }
  
  return 1;
  
}

double GlobalClass::applyZmumuUncertainty( TString cat ){

  if( cat == s_vbf ) return this->getZmumuWeight(cat);
  else return 1;
  
} 

TString GlobalClass::return2DString( TString cat ){

  if( cat.Contains(s_0jet) )           return "0jet_";
  else if( cat.Contains(s_boosted) )   return "boosted_";
  else if( cat.Contains(s_vbf) )       return "vbf_";
  else                                 return "";
             
}
