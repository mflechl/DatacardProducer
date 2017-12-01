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

  ifstream A("config/Analysis.json");
  ifstream B("config/Binning.json");
  ifstream D("config/Datasets.json");
  A >> Analysis;
  B >> Binning;
  D >> Datasets;
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

int GlobalClass::Baseline(TString sign, TString cat){

  if( this->passIso("base") 
      && this->Vetos()
      && this->CategorySelection(cat,sign)
      ){

      if( ( sign == "os" || sign == "ss") 
          && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2 )  return 1;

      if( sign == "FF" && NtupleView->byVLooseIsolationMVArun2v1DBoldDMwLT_2
                       && !NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2
        )return 1;
    
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
  if( this->getMT() < Analysis["MTCut"]["low"][channel] ) return 1;
  return 0;
}

int GlobalClass::passIso(TString type){
  if(channel == "tt") return 1;
  if(NtupleView->iso_1 < Analysis["iso"][type.Data()][channel] ) return 1;
  return 0;
}

//FIXME: temporary fix, has to be undone as soon as tauLepVeto is correct for etau channel
int GlobalClass::Vetos(){
  if(NtupleView->passesThirdLepVeto){
    if(channel == "et" && NtupleView->passesTauLepVetos && NtupleView->passesDiElectronVeto) return 1;
    if(channel == "mt" && NtupleView->passesTauLepVetos && NtupleView->passesDiMuonVeto) return 1;
    if(channel == "tt" && NtupleView->passesTauLepVetos) return 1; 
  }
  return 0;
}

int GlobalClass::CategorySelection(TString cat, TString sign){

  vector<TString> splCat = this->splitString(cat, "_" );
  TString subcat = "";
  if( splCat.size() > 1 ) subcat = splCat.at(1);

  ////// Sign
  if( (sign == "os" || sign.Contains("FF") ) && NtupleView->q_1 * NtupleView->q_2 > 0 ) return 0;
  if(  sign == "ss" && NtupleView->q_1 * NtupleView->q_2 < 0 ) return 0;

  ////// mT region
  float mT    = this->getMT();
  if( applyMTCut && channel != "tt" ){
    if( subcat != "wcr" &&  mT > Analysis["MTCut"]["low"][channel] ) return 0;
    if( subcat == "wcr" &&  mT < Analysis["MTCut"]["high"][channel] ) return 0;
  }

  ////// Cat selection
  if(splCat.at(0) == s_inclusive     )    return 1;    
  if(splCat.at(0) == s_0jet          )    return this->zeroJetCat();
  if(splCat.at(0) == s_boosted       )    return this->boostedCat();
  if(splCat.at(0) == s_vbf           )    return this->vbfCat();
  
  return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool GlobalClass::zeroJetCat(){
  if( this->getNjets() > 0 ) return 0;
  if( channel != "tt" && NtupleView->pt_2 < 30 ) return 0;
  if( channel == "tt" && NtupleView->pt_1 < 50 ) return 0;

  return 1;
}
bool GlobalClass::boostedCat(){
  int   njet  = this->getNjets();

  ////////////////////////////
  if(channel == "et"){
    if(NtupleView->pt_2 < 30 ) return 0;
    if( njet == 1 
        || ( njet >= 2
             && ( this->getMjj() <= 300
                  || NtupleView->pt_tt < 50 
                )
            )  
      ) return 1;
  }
  ////////////////////////////
  else if(channel == "mt"){
    if(NtupleView->pt_2 < 30 ) return 0;
    if( njet == 1 
        || ( njet >= 2
             && ( this->getMjj() <= 300
                  || NtupleView->pt_tt < 50
                  || NtupleView->pt_2 < 40
                )
            )  
      ) return 1;    
  }
  ////////////////////////////
  else if(channel == "tt"){
    if( njet == 1
        || !(njet >= 2
             && NtupleView->pt_tt > 100
             && this->getJdeta() > 2.5
            )
      ) return 1;
  }

  return 0;
}
bool GlobalClass::vbfCat(){
  if( this->getNjets() < 2 ) return 0;


  if(channel == "et"){
    if( NtupleView->pt_2 < 30 ) return 0;
    if( NtupleView->pt_tt > 50
        && this->getMjj() > 300
      ) return 1;
  }
  else if(channel == "mt"){
    if( NtupleView->pt_2 < 40 ) return 0;
    if( NtupleView->pt_tt > 50
        && this->getMjj() >  300
      ) return 1;   
  }
  else if(channel == "tt"){
    if( NtupleView->pt_tt > 100 
        && this->getJdeta() > 2.5
      ) return 1;
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

//void GlobalClass::returnBinning(double* returnHisto, vector<double> input){
//  for(int i=0; i<input.size(); i++) returnHisto[i]=input.at(i);
//}
void GlobalClass::returnBinning(double* returnHisto, vector<double> input1d, vector<double> input2d){
  if (input2d.size()>0) for(int i=0; i<this->returnBins(input1d,input2d)+1; i++) returnHisto[i]=i-0.5; //bins: -0.5;0.5;1.5; etc
  else for(int i=0; i<input1d.size(); i++) returnHisto[i]=input1d.at(i);
}

//int GlobalClass::returnBins(vector<double> input){
//  return input.size();
//}
int GlobalClass::returnBins(vector<double> input1d,vector<double> input2d){
  if (input2d.size()>0) return (input1d.size()-1)*(input2d.size()-1);
  else return input1d.size()-1;
}

//TH1D* GlobalClass::getBinnedHisto(TString name,vector<double> input){
//  double binning[this->returnBins(input)];
//  this->returnBinning(binning,input);
//  TH1D* tmp=new TH1D(name,"",this->returnBins(input)-1,&binning[0]);
//  return tmp;
//}
TH1D* GlobalClass::getBinnedHisto(TString name,vector<double> input1d,vector<double> input2d, TString strVar){
  double binning[this->returnBins(input1d,input2d)+1];
  this->returnBinning(binning,input1d,input2d);
  TH1D* tmp=new TH1D(name,"",this->returnBins(input1d,input2d),&binning[0]);

  //save binning
  if ( strVar!="" && binning1d.find(strVar) == binning1d.end() ) { //does not exist yet
    binning1d.insert(make_pair(strVar,input1d));
    binning2d.insert(make_pair(strVar,input2d));
  }

  return tmp;
}

TH1D* GlobalClass::JITHistoCreator(TString name, TString strVar){

  TString binning = "default";

  if ( DEBUG==2) std::cout << "Trying to create histogram for variable " << strVar << endl;

  if(Binning[strVar.Data()]["doVarBins"]["check"]){

    if(Binning[strVar.Data()]["doVarBins"]["type"] == (string)"cat"){
      if( name.Contains("btag") && !name.Contains("nobtag") )        binning = "btag";
      else binning = "nobtag";
    }
    if(Binning[strVar.Data()]["doVarBins"]["type"] == (string)"channel"){
      binning = channel;
    }  

    if ( strVar.Contains(s_join2d) ){
      try{
	histograms[name] = this->getBinnedHisto(name,Binning[strVar.Data()]["varBins_1D"].at(binning.Data() ), Binning[strVar.Data()]["varBins_2D"].at(binning.Data() ), strVar ) ;
      }
      catch(const out_of_range& err){
	histograms[name] = this->getBinnedHisto(name,Binning[strVar.Data()]["varBins_1D"].at("default"),Binning[strVar.Data()]["varBins_2D"].at("default"), strVar ) ;
      }
    } else{
      try{
	histograms[name] = this->getBinnedHisto(name,Binning[strVar.Data()]["varBins"].at(binning.Data() ) ) ;
      }
      catch(const out_of_range& err){
	histograms[name] = this->getBinnedHisto(name,Binning[strVar.Data()]["varBins"].at("default") ) ;
      }
    }
   
  }
  else{
    if ( strVar.Contains(s_join2d) ){
      histograms[name] = new TH1D(name,"", Binning[strVar.Data()]["nbins"], Binning[strVar.Data()]["nmin"], Binning[strVar.Data()]["nmax"]  ) ; //TODO!!
    } else{
      histograms[name] = new TH1D(name,"", Binning[strVar.Data()]["nbins"], Binning[strVar.Data()]["nmin"], Binning[strVar.Data()]["nmax"]  ) ;
    }
  }

  return histograms.at(name);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GlobalClass::splitString(TString str,TString sep,vector<TString>& vec){
  TObjArray *toa = str.Tokenize(sep);
  for (Int_t i = 0; i < toa->GetEntries(); i++){
    vec.push_back(((TObjString *)(toa->At(i)))->String());
  }
}

std::vector<TString> GlobalClass::splitString(TString str,TString sep){
  std::vector<TString> vec;
  this->splitString(str,sep,vec);
  return vec;
}

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
