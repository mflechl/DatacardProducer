#include "interface/CreateHistos.h"
#include "TLorentzVector.h"
#include <iostream>
#include <sstream>
#include <TObject.h>
#include <algorithm>

using namespace std;

CreateHistos::CreateHistos(){
  TString tmp = "";
  files[s_Z].first = Parameter.dataset.Z;
  files[s_EWKZ].first = Parameter.dataset.EWKZ;
  files[s_W].first = Parameter.dataset.W;
  files[s_TT].first = Parameter.dataset.TT;
  files[s_VV].first = Parameter.dataset.VV;

  if(channel=="mt" && !doMC )files[s_data].first = Parameter.dataset.data_mt;
  else if(channel=="mt" && doMC)files[s_data].first = Parameter.dataset.MCsum_mt;
  if(channel=="et")files[s_data].first = Parameter.dataset.data_et;
  if(channel=="tt")files[s_data].first = Parameter.dataset.data_tt;

  for(auto mass : Parameter.dataset.masspoints){
    tmp = Parameter.dataset.ggH;
    files[s_ggH+mass].first = tmp.ReplaceAll("XXX",mass);
    files[s_ggH+mass].second = mass;

    tmp = Parameter.dataset.bbH;
    files[s_bbH+mass].first = tmp.ReplaceAll("XXX",mass);
    files[s_bbH+mass].second = mass;
  }

  if(ptShift){
    files[s_ZtauUp].first = Parameter.dataset.ZtauUp;
    files[s_ZtauDown].first = Parameter.dataset.ZtauDown;
    files[s_EWKZtauUp].first = Parameter.dataset.EWKZtauUp;
    files[s_EWKZtauDown].first = Parameter.dataset.EWKZtauDown;
    files[s_TTtauUp].first = Parameter.dataset.TTtauUp;
    files[s_TTtauDown].first = Parameter.dataset.TTtauDown;
    files[s_VVtauUp].first = Parameter.dataset.VVtauUp;
    files[s_VVtauDown].first = Parameter.dataset.VVtauDown;

    for(auto mass : Parameter.dataset.masspoints){

      tmp = Parameter.dataset.ggHtauUp;
      files[s_ggHtauUp+mass].first = tmp.ReplaceAll("XXX",mass);
      files[s_ggHtauUp+mass].second = mass;

      tmp = Parameter.dataset.ggHtauDown;
      files[s_ggHtauDown+mass].first = tmp.ReplaceAll("XXX",mass);
      files[s_ggHtauDown+mass].second = mass;

      tmp = Parameter.dataset.bbHtauUp;
      files[s_bbHtauUp+mass].first = tmp.ReplaceAll("XXX",mass);
      files[s_bbHtauUp+mass].second = mass;

      tmp = Parameter.dataset.bbHtauDown;
      files[s_bbHtauDown+mass].first = tmp.ReplaceAll("XXX",mass);
      files[s_bbHtauDown+mass].second = mass;
    }
  }
  if(jecShift){
    files[s_ZjecUp].first = Parameter.dataset.Z;
    files[s_ZjecDown].first = Parameter.dataset.Z;
    files[s_EWKZjecUp].first = Parameter.dataset.EWKZ;
    files[s_EWKZjecDown].first = Parameter.dataset.EWKZ;
    files[s_WjecUp].first = Parameter.dataset.W;
    files[s_WjecDown].first = Parameter.dataset.W;
    files[s_TTjecUp].first = Parameter.dataset.TT;
    files[s_TTjecDown].first = Parameter.dataset.TT;
    files[s_VVjecUp].first = Parameter.dataset.VV;
    files[s_VVjecDown].first = Parameter.dataset.VV;

    for(auto mass : Parameter.dataset.masspoints){
      tmp = Parameter.dataset.ggH;
      files[s_ggHjecUp+mass].first = tmp.ReplaceAll("XXX",mass);
      files[s_ggHjecUp+mass].second = mass;

      tmp = Parameter.dataset.ggH;
      files[s_ggHjecDown+mass].first = tmp.ReplaceAll("XXX",mass);
      files[s_ggHjecDown+mass].second = mass;

      tmp = Parameter.dataset.bbH;
      files[s_bbHjecUp+mass].first = tmp.ReplaceAll("XXX",mass);
      files[s_bbHjecUp+mass].second = mass;

      tmp = Parameter.dataset.bbH;
      files[s_bbHjecDown+mass].first = tmp.ReplaceAll("XXX",mass);
      files[s_bbHjecDown+mass].second = mass;
    }
  }

  for(auto var : variables)      vars.push_back(var);
  for(auto cat : categories){
    cats.push_back(cat);
    if(channel != "tt"){
      cats.push_back(cat+"_wjets_cr");
      cats.push_back(cat+"_wjets_ss_cr");
      cats.push_back(cat+"_qcd_cr");
      cats.push_back(cat+"_loosebtag");
      //cats.push_back(cat+"_loosebtag_ss");
      cats.push_back(cat+"_loosebtag_wjets_cr");
      cats.push_back(cat+"_loosebtag_wjets_ss_cr");
    }
    else{
      cats.push_back(cat+"_loose");
      cats.push_back(cat+"_qcd_cr");
      cats.push_back(cat+"_loose_qcd_cr");
    }
  };
  
  
}

CreateHistos::~CreateHistos(){

  cout << "Deleting instance of CreateHistos" << endl;

  FFinputs.clear();

  map<TString, FakeFactor*>::iterator itr;
  for (itr=FFObj.begin(); itr!=FFObj.end(); ++itr)
    {
      delete itr->second;
      FFObj.erase(itr);
    }
  map<TString, TFile*>::iterator fitr;
  for (fitr=FFfile.begin(); fitr!=FFfile.end(); ++fitr)
    {
      fitr->second->Close();
      FFfile.erase(fitr);
    }
}

void CreateHistos::loadFile(TString filename){

  TChain *tchain = new TChain("TauCheck");
  tchain->Add(filename);
  
  NtupleView = new ntuple(tchain);
  cout<<"File: "<<filename<<" loaded"<<endl;
 
}

void CreateHistos::run(TString isTest){


  //clearHistos();
  float weight = 1;
  float weight_data = 1;
  float var = -999;
  
  initFakeFactors();

  cout << "Channel: " << channel << endl;
  for(auto strVar : vars) cout << "Variable " << strVar << endl;
  for(auto cat : cats) cout << "Category " << cat << endl;
  cout << endl;
  cout << "----Settings:-----" << endl;
  cout << "2D: " << do2DFit << endl;
  cout << "applyMTcut: " << applyMTCut << endl;
  cout << "useMVAMET: " << useMVAMET << endl;
  cout << "calcFF: " << calcFF << endl;
  cout << "FF version: " << FFversion << endl;
  cout << doSvfit << endl;
  cout << "Reduced string: " << reduced << endl;
  cout << endl;

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(doInitialize){

    for(auto cat : cats){
      for(auto strVar : vars){
        if( !do2DFit || cat == s_inclusive ){
          initDYSelections(cat,strVar);
          initTSelections(cat,strVar);
          initVVSelections(cat,strVar);
          initEWKZSelections(cat,strVar);
          initSignalSelections(cat,strVar);
        }
        else if( do2DFit ){
          if( channel == "tt"
              && (cat.Contains(s_wjets)
                  || cat.Contains(s_antiiso) )
              ) continue;
          initDYSelections(cat,strVar,"2D");
          initTSelections(cat,strVar,"2D");
          initVVSelections(cat,strVar,"2D");
          initEWKZSelections(cat,strVar,"2D");
          initSignalSelections(cat,strVar,"2D");
        }
      }
    }
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TString filetype = "";
  TString filename = "";
  TString mass = "";

  for (auto const& file : files){

    filetype = file.first;
    filename = file.second.first;
    mass = file.second.second;
    filetype.ReplaceAll( mass, "" );
  
    if(filetype.Contains(s_jecUp)) this->isJEC=1;
    else if(filetype.Contains(s_jecDown)) this->isJEC=-1;
    else this->isJEC=0;

    this->loadFile(filename);
    Int_t nentries=0;
    if(isTest=="test"){
      nentries = min( Int_t(NtupleView->fChain->GetEntries()), Int_t( 10000 ) );
    }else{
      nentries = Int_t(NtupleView->fChain->GetEntries());
    }
    cout<<"The input chain contains: "<<nentries<<" events."<<endl;
    float perc;
    for (Int_t jentry=0; jentry<nentries;jentry++){       

      if(jentry % 200000 == 0){
        if(nentries > 0){
          perc =  ( (float)jentry / (float)nentries ) * 100;
        }
        cout.precision(3);
        cout<< "                                                             \r"<< flush;
        cout<< jentry << "/" << nentries <<"\t\t" << perc << "%\r"<< flush;
      }

      NtupleView->GetEntry(jentry);

      if( channel=="et" && !NtupleView->trg_singleelectron ) continue;
      if( channel=="tt" && !( NtupleView->trg_doubletau || NtupleView->trg_singletau ) ) continue;

      weight = NtupleView->stitchedWeight*NtupleView->puweight*NtupleView->effweight*NtupleView->genweight*NtupleView->antilep_tauscaling*usedLuminosity;
      if(!doMC){
        if( isZFile(filetype) || isEWKZFile(filetype) ) weight *= NtupleView->ZWeight;
        if( isTTFile(filetype) ) weight *= NtupleView->topWeight;
      }
      else if(doMC) weight_data=weight;

      //FIXME: delete this function if not needed anymore
      //if(channel == "et") weight = weight * this->getAntiLep_tauscaling();

      for(auto cat : cats){

        if( !doMC && isZFile(filetype) ) weight *= this->getZmumuWeight( cat );

        for(auto strVar : vars){

          var = -999;
          if(strVar == s_mvis)                                var = NtupleView->m_vis;
          else if(strVar == s_msv)                            var = NtupleView->m_sv;
          else if(strVar == s_ptsv)                           var = NtupleView->pt_sv;
          else if(strVar == s_mt1)                            var = this->getMT();
          else if(strVar == s_jpt1)                           var = NtupleView->jpt_1;
          else if(strVar == s_jpt2)                           var = NtupleView->jpt_2;
          
          else if(strVar == s_pt1)                            var = NtupleView->pt_1;
          else if(strVar == s_pt2)                            var = NtupleView->pt_2;
          else if(strVar == s_eta1)                           var = NtupleView->eta_1;
          else if(strVar == s_eta2)                           var = NtupleView->eta_2;
          else if(strVar == s_met)                            var = NtupleView->met;
          else if(strVar == s_mttot)                          var = NtupleView->mt_tot;
          else if(strVar == s_Hpt)                            var = this->CalcHPt(); 


          else if(strVar == "jeta_1"
             && NtupleView->jpt_1 > 30)     var = NtupleView->jeta_1;

          else if(strVar == "jeta_2"
             && NtupleView->jpt_2 > 30)     var = NtupleView->jeta_2;

          else if(strVar == "mjj")          var = this->getMjj();

          else if(strVar == "jeta1eta2"
             && NtupleView->jpt_1 > 30
             && NtupleView->jpt_2 > 30)     var = NtupleView->jeta1eta2;

          else if(strVar == "jdeta"
             && NtupleView->jpt_1 > 30
             && NtupleView->jpt_2 > 30)     var = NtupleView->jdeta;

          else continue;

          if( !do2DFit || cat == s_inclusive ){

            if( isZFile(filetype) )                     this->DYSelections(var, weight, cat, strVar, filetype);
            
            else if( isEWKZFile(filetype) )             this->EWKZSelections(var, weight, cat, strVar, filetype);
          
            else if( isTTFile(filetype) )               this->TSelections(var, weight, cat, strVar, filetype);
            
            else if( isVVFile(filetype) )               this->VVSelections(var, weight, cat, strVar, filetype);

            else if( isWFile(filetype) )                this->WSelections(var, weight, cat, strVar, filetype);

            else if( filetype == s_data )               this->dataSelections(var, weight_data, cat, strVar, filetype);

            else if( isSignalFile(filetype) )           this->signalSelections(var, weight, cat, strVar, filetype, mass);

          }
                  }
        
      }
    }
  }
  if( channel != "tt" ){
    for(auto cat : cats){
      for(auto strVar : vars){
        this->EstimateW(strVar, cat);
        this->EstimateQCD(strVar, cat);
      }
    }
  }
  if(calcFF){
    for(auto cat : categories){
      for(auto strVar : vars){
        if( !do2DFit || cat == s_inclusive )            this->EstimateFF(strVar, cat);
      }
    } 
  }
  
  cout << "Done running over events." << endl;
  writeHistos( channel, cats, vars );
  
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float CreateHistos::getAntiLep_tauscaling(){


    if(channel == "mt"){
      if(NtupleView->againstMuonTight3_2 > 0.5
         && ( NtupleView->gen_match_2 == 2 
             || NtupleView->gen_match_2 == 4)
         ){

        if(fabs(NtupleView->eta_2) < 1.2) return 1.28;       // +-0.06
        else if (fabs(NtupleView->eta_2) < 1.7) return 2.6;   // +-2.6
        else if (fabs(NtupleView->eta_2) < 2.3) return 2.1;  // +-0.9
      }
    }
    if(channel == "et"){
      if(NtupleView->againstElectronTightMVA6_2 > 0.5
         && ( NtupleView->gen_match_2 == 1 
             || NtupleView->gen_match_2 == 3)
         ){

        if(fabs(NtupleView->eta_2) < 1.46) return 1.42;       // +-0.06
        else if (fabs(NtupleView->eta_2) > 1.558) return 1.994;   // +-2.6
      }
    }
    return 1.0;

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//UGLIEST FUNCTION EVER WRITTEN -> PLEASE SIMPLIFY!!!!!
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CreateHistos::EstimateFF(TString strVar, TString cat, TString extend){
  TString sub = extend + "+" + strVar +"_" + cat + "+";

  double normUp_jetFakes=0;
  double normUp_jetFakes_syst=0;
  double normUp_data=0;
  double normUp_data_syst=0;
  double normUp_W=0;
  double normUp_W_syst=0;
  double normUp_Z=0;
  double normUp_Z_syst=0;
  double normUp_EWKZ=0;
  double normUp_EWKZ_syst=0;  
  double normUp_TT=0;
  double normUp_TT_syst=0;
  double normUp_VV=0;
  double normUp_VV_syst=0;
  double normDown_jetFakes=0;
  double normDown_jetFakes_syst=0;
  double normDown_data=0;
  double normDown_data_syst=0;
  double normDown_W=0;
  double normDown_W_syst=0;
  double normDown_Z=0;
  double normDown_Z_syst=0;
  double normDown_EWKZ=0;
  double normDown_EWKZ_syst=0;
  double normDown_TT=0;
  double normDown_TT_syst=0;
  double normDown_VV=0;
  double normDown_VV_syst=0;
  
  this->GetHistbyName(s_jetFakes+sub,strVar)->Add( this->GetHistbyName(s_data+"_"+s_jetFakes+sub,strVar)   );
  this->GetHistbyName(s_jetFakes+sub,strVar)->Add( this->GetHistbyName(s_W+"_"+s_jetFakes+sub,strVar), -1 );
  this->GetHistbyName(s_jetFakes+sub,strVar)->Add( this->GetHistbyName(s_TT+"_"+s_jetFakes+sub,strVar),  -1 );
  this->GetHistbyName(s_jetFakes+sub,strVar)->Add( this->GetHistbyName(s_Z+"_"+s_jetFakes+sub,strVar), -1 );
  this->GetHistbyName(s_jetFakes+sub,strVar)->Add( this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+sub,strVar), -1 );
  this->GetHistbyName(s_jetFakes+sub,strVar)->Add( this->GetHistbyName(s_VV+"_"+s_jetFakes+sub,strVar), -1 );

  if(jecShift){
    this->GetHistbyName(s_jetFakesjecUp+sub,strVar)->Add( this->GetHistbyName(s_data+"_"+s_jetFakes+sub,strVar)   );
    this->GetHistbyName(s_jetFakesjecUp+sub,strVar)->Add( this->GetHistbyName(s_WjecUp+"_"+s_jetFakes+sub,strVar), -1 );
    this->GetHistbyName(s_jetFakesjecUp+sub,strVar)->Add( this->GetHistbyName(s_TTjecUp+"_"+s_jetFakes+sub,strVar),  -1 );
    this->GetHistbyName(s_jetFakesjecUp+sub,strVar)->Add( this->GetHistbyName(s_ZjecUp+"_"+s_jetFakes+sub,strVar), -1 );
    this->GetHistbyName(s_jetFakesjecUp+sub,strVar)->Add( this->GetHistbyName(s_EWKZjecUp+"_"+s_jetFakes+sub,strVar), -1 );
    this->GetHistbyName(s_jetFakesjecUp+sub,strVar)->Add( this->GetHistbyName(s_VVjecUp+"_"+s_jetFakes+sub,strVar), -1 );

    this->GetHistbyName(s_jetFakesjecDown+sub,strVar)->Add( this->GetHistbyName(s_data+"_"+s_jetFakes+sub,strVar)   );
    this->GetHistbyName(s_jetFakesjecDown+sub,strVar)->Add( this->GetHistbyName(s_WjecDown+"_"+s_jetFakes+sub,strVar), -1 );
    this->GetHistbyName(s_jetFakesjecDown+sub,strVar)->Add( this->GetHistbyName(s_TTjecDown+"_"+s_jetFakes+sub,strVar),  -1 );
    this->GetHistbyName(s_jetFakesjecDown+sub,strVar)->Add( this->GetHistbyName(s_ZjecDown+"_"+s_jetFakes+sub,strVar), -1 );
    this->GetHistbyName(s_jetFakesjecDown+sub,strVar)->Add( this->GetHistbyName(s_EWKZjecDown+"_"+s_jetFakes+sub,strVar), -1 );
    this->GetHistbyName(s_jetFakesjecDown+sub,strVar)->Add( this->GetHistbyName(s_VVjecDown+"_"+s_jetFakes+sub,strVar), -1 );
  }

  this->GetHistbyName(s_jetFakes+"_Zvar_systUp"+sub,strVar)->Add( this->GetHistbyName(s_data+"_"+s_jetFakes+sub,strVar)   );
  this->GetHistbyName(s_jetFakes+"_Zvar_systUp"+sub,strVar)->Add( this->GetHistbyName(s_W+"_"+s_jetFakes+sub,strVar), -1 );
  this->GetHistbyName(s_jetFakes+"_Zvar_systUp"+sub,strVar)->Add( this->GetHistbyName(s_TT+"_"+s_jetFakes+sub,strVar),  -1 );
  this->GetHistbyName(s_jetFakes+"_Zvar_systUp"+sub,strVar)->Add( this->GetHistbyName(s_Z+"_"+s_jetFakes+"_Up"+sub,strVar), -1 );  
  this->GetHistbyName(s_jetFakes+"_Zvar_systUp"+sub,strVar)->Add( this->GetHistbyName(s_VV+"_"+s_jetFakes+sub,strVar), -1 );

  this->GetHistbyName(s_jetFakes+"_Zvar_systDown"+sub,strVar)->Add( this->GetHistbyName(s_data+"_"+s_jetFakes+sub,strVar)   );
  this->GetHistbyName(s_jetFakes+"_Zvar_systDown"+sub,strVar)->Add( this->GetHistbyName(s_W+"_"+s_jetFakes+sub,strVar), -1 );
  this->GetHistbyName(s_jetFakes+"_Zvar_systDown"+sub,strVar)->Add( this->GetHistbyName(s_TT+"_"+s_jetFakes+sub,strVar),  -1 );
  this->GetHistbyName(s_jetFakes+"_Zvar_systDown"+sub,strVar)->Add( this->GetHistbyName(s_Z+"_"+s_jetFakes+"_Down"+sub,strVar), -1 );
  this->GetHistbyName(s_jetFakes+"_Zvar_systDown"+sub,strVar)->Add( this->GetHistbyName(s_VV+"_"+s_jetFakes+sub,strVar), -1 );

  this->GetHistbyName(s_jetFakes+"_TTvar_systUp"+sub,strVar)->Add( this->GetHistbyName(s_data+"_"+s_jetFakes+sub,strVar)   );
  this->GetHistbyName(s_jetFakes+"_TTvar_systUp"+sub,strVar)->Add( this->GetHistbyName(s_W+"_"+s_jetFakes+sub,strVar), -1 );
  this->GetHistbyName(s_jetFakes+"_TTvar_systUp"+sub,strVar)->Add( this->GetHistbyName(s_TT+"_"+s_jetFakes+"_Up"+sub,strVar),  -1 );
  this->GetHistbyName(s_jetFakes+"_TTvar_systUp"+sub,strVar)->Add( this->GetHistbyName(s_Z+"_"+s_jetFakes+sub,strVar), -1 );
  this->GetHistbyName(s_jetFakes+"_TTvar_systUp"+sub,strVar)->Add( this->GetHistbyName(s_VV+"_"+s_jetFakes+sub,strVar), -1 );

  this->GetHistbyName(s_jetFakes+"_TTvar_systDown"+sub,strVar)->Add( this->GetHistbyName(s_data+"_"+s_jetFakes+sub,strVar)   );
  this->GetHistbyName(s_jetFakes+"_TTvar_systDown"+sub,strVar)->Add( this->GetHistbyName(s_W+"_"+s_jetFakes+sub,strVar), -1 );
  this->GetHistbyName(s_jetFakes+"_TTvar_systDown"+sub,strVar)->Add( this->GetHistbyName(s_TT+"_"+s_jetFakes+"_Down"+sub,strVar),  -1 );
  this->GetHistbyName(s_jetFakes+"_TTvar_systDown"+sub,strVar)->Add( this->GetHistbyName(s_Z+"_"+s_jetFakes+sub,strVar), -1 );
  this->GetHistbyName(s_jetFakes+"_TTvar_systDown"+sub,strVar)->Add( this->GetHistbyName(s_VV+"_"+s_jetFakes+sub,strVar), -1 );

  this->resetZeroBins(s_jetFakes+sub,strVar);
  this->resetZeroBins(s_jetFakes+"_Zvar_systUp"+sub,strVar);
  this->resetZeroBins(s_jetFakes+"_Zvar_systDown"+sub,strVar);
  this->resetZeroBins(s_jetFakes+"_TTvar_systUp"+sub,strVar);
  this->resetZeroBins(s_jetFakes+"_TTvar_systDown"+sub,strVar);
  if(jecShift){
    this->resetZeroBins(s_jetFakesjecUp+sub,strVar);
    this->resetZeroBins(s_jetFakesjecDown+sub,strVar);
  }

  double ratio = 0;
  for( auto syst : FFsyst[channel] ){
    TString tmp=syst;
    this->getCorrectUncertaintyString( tmp );
    this->GetHistbyName(s_jetFakes+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+tmp+sub,strVar)   );
    if( this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+tmp+sub,strVar)->Integral(0,this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+tmp+sub,strVar)->GetNbinsX()+1 ) > 0
        && this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+tmp+sub,strVar)->Integral(0,this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+tmp+sub,strVar)->GetNbinsX()+1 ) < 10e10 )       this->GetHistbyName(s_jetFakes+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+tmp+sub,strVar), -1 );
    if( this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+tmp+sub,strVar)->Integral(0,this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+tmp+sub,strVar)->GetNbinsX()+1 ) > 0
        && this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+tmp+sub,strVar)->Integral(0,this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+tmp+sub,strVar)->GetNbinsX()+1 ) < 10e10 )     this->GetHistbyName(s_jetFakes+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+tmp+sub,strVar),  -1 );
    if( this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+tmp+sub,strVar)->Integral(0,this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+tmp+sub,strVar)->GetNbinsX()+1 ) > 0
        && this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+tmp+sub,strVar)->Integral(0,this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+tmp+sub,strVar)->GetNbinsX()+1 ) < 10e10 )       this->GetHistbyName(s_jetFakes+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+tmp+sub,strVar), -1 );
    if( this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+tmp+sub,strVar)->Integral(0,this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+tmp+sub,strVar)->GetNbinsX()+1 ) > 0
        && this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+tmp+sub,strVar)->Integral(0,this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+tmp+sub,strVar)->GetNbinsX()+1 ) < 10e10 ) this->GetHistbyName(s_jetFakes+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+tmp+sub,strVar), -1 );
    if( this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+tmp+sub,strVar)->Integral(0,this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+tmp+sub,strVar)->GetNbinsX()+1 ) > 0
        && this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+tmp+sub,strVar)->Integral(0,this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+tmp+sub,strVar)->GetNbinsX()+1 ) < 10e10 )     this->GetHistbyName(s_jetFakes+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+tmp+sub,strVar), -1 );

    this->resetZeroBins(s_jetFakes+"_"+tmp+sub,strVar);
    
    this->GetHistbyName(s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_jetFakes+"_"+tmp+sub,strVar)  );
    ratio = ( this->GetHistbyName(s_jetFakes+sub,strVar)->Integral( 0, this->GetHistbyName(s_jetFakes+sub,strVar)->GetNbinsX()+1  ) )/( this->GetHistbyName(s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Integral( 0, this->GetHistbyName(s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->GetNbinsX()+1  ) );
    this->GetHistbyName(s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Scale( ratio );
    if(tmp.Contains("syst")){
      cout << ratio << endl;
      if( ratio < 1) normUp_jetFakes_syst = TMath::Sqrt( TMath::Power(normUp_jetFakes_syst,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_jetFakes_syst = TMath::Sqrt( TMath::Power(normDown_jetFakes_syst,2) + TMath::Power( 1-ratio,2 ) );
    } else{
      if( ratio < 1) normUp_jetFakes = TMath::Sqrt( TMath::Power(normUp_jetFakes,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_jetFakes = TMath::Sqrt( TMath::Power(normDown_jetFakes,2) + TMath::Power( 1-ratio,2 ) );
    }
    
    this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+tmp+sub,strVar)  );
    ratio = ( this->GetHistbyName(s_data+"_"+s_jetFakes+sub,strVar)->Integral( 0, this->GetHistbyName(s_data+"_"+s_jetFakes+sub,strVar)->GetNbinsX()+1  ) )/( this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Integral( 0, this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->GetNbinsX()+1  ) );
    this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Scale( ratio );
    if(tmp.Contains("syst")){
      if( ratio < 1) normUp_data_syst = TMath::Sqrt( TMath::Power(normUp_data_syst,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_data_syst = TMath::Sqrt( TMath::Power(normDown_data_syst,2) + TMath::Power( 1-ratio,2 ) );
    } else{
      if( ratio < 1) normUp_data = TMath::Sqrt( TMath::Power(normUp_data,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_data = TMath::Sqrt( TMath::Power(normDown_data,2) + TMath::Power( 1-ratio,2 ) );
    }
    
    this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+tmp+sub,strVar)  );
    ratio = ( this->GetHistbyName(s_W+"_"+s_jetFakes+sub,strVar)->Integral( 0, this->GetHistbyName(s_W+"_"+s_jetFakes+sub,strVar)->GetNbinsX()+1  ) )/( this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Integral( 0, this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->GetNbinsX()+1  ) );
    this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Scale( ratio );
    if(tmp.Contains("syst")){
      if( ratio < 1) normUp_W_syst = TMath::Sqrt( TMath::Power(normUp_W_syst,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_W_syst = TMath::Sqrt( TMath::Power(normDown_W_syst,2) + TMath::Power( 1-ratio,2 ) );
    } else{
      if( ratio < 1) normUp_W = TMath::Sqrt( TMath::Power(normUp_W,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_W = TMath::Sqrt( TMath::Power(normDown_W,2) + TMath::Power( 1-ratio,2 ) );
    }
    
    this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+tmp+sub,strVar)  );
    ratio = ( this->GetHistbyName(s_TT+"_"+s_jetFakes+sub,strVar)->Integral( 0, this->GetHistbyName(s_TT+"_"+s_jetFakes+sub,strVar)->GetNbinsX()+1  ) )/( this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Integral( 0, this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->GetNbinsX()+1  ) );
    this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Scale( ratio );
    if(tmp.Contains("syst")){
      if( ratio < 1) normUp_TT_syst = TMath::Sqrt( TMath::Power(normUp_TT_syst,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_TT_syst = TMath::Sqrt( TMath::Power(normDown_TT_syst,2) + TMath::Power( 1-ratio,2 ) );
    } else{
      if( ratio < 1) normUp_TT = TMath::Sqrt( TMath::Power(normUp_TT,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_TT = TMath::Sqrt( TMath::Power(normDown_TT,2) + TMath::Power( 1-ratio,2 ) );
    }
    
    this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+tmp+sub,strVar)  );
    ratio = ( this->GetHistbyName(s_Z+"_"+s_jetFakes+sub,strVar)->Integral( 0, this->GetHistbyName(s_Z+"_"+s_jetFakes+sub,strVar)->GetNbinsX()+1  ) )/( this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Integral( 0, this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->GetNbinsX()+1  ) );
    this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Scale( ratio );
    if(tmp.Contains("syst")){
      if( ratio < 1) normUp_Z_syst = TMath::Sqrt( TMath::Power(normUp_Z_syst,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_Z_syst = TMath::Sqrt( TMath::Power(normDown_Z_syst,2) + TMath::Power( 1-ratio,2 ) );
    } else{
      if( ratio < 1) normUp_Z = TMath::Sqrt( TMath::Power(normUp_Z,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_Z = TMath::Sqrt( TMath::Power(normDown_Z,2) + TMath::Power( 1-ratio,2 ) );
    }

    this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+tmp+sub,strVar)  );
    ratio = ( this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+sub,strVar)->Integral( 0, this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+sub,strVar)->GetNbinsX()+1  ) )/( this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Integral( 0, this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->GetNbinsX()+1  ) );
    this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Scale( ratio );
    if(tmp.Contains("syst")){
      if( ratio < 1) normUp_EWKZ_syst = TMath::Sqrt( TMath::Power(normUp_EWKZ_syst,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_EWKZ_syst = TMath::Sqrt( TMath::Power(normDown_EWKZ_syst,2) + TMath::Power( 1-ratio,2 ) );
    } else{
      if( ratio < 1) normUp_EWKZ = TMath::Sqrt( TMath::Power(normUp_EWKZ,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_EWKZ = TMath::Sqrt( TMath::Power(normDown_EWKZ,2) + TMath::Power( 1-ratio,2 ) );
    }
    
    this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Add( this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+tmp+sub,strVar)  );
    ratio = ( this->GetHistbyName(s_VV+"_"+s_jetFakes+sub,strVar)->Integral( 0, this->GetHistbyName(s_VV+"_"+s_jetFakes+sub,strVar)->GetNbinsX()+1  ) )/( this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Integral( 0, this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->GetNbinsX()+1  ) );
    this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+s_norm+"_"+tmp+sub,strVar)->Scale( ratio );
    if(tmp.Contains("syst")){
      if( ratio < 1) normUp_VV_syst = TMath::Sqrt( TMath::Power(normUp_VV_syst,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_VV_syst = TMath::Sqrt( TMath::Power(normDown_VV_syst,2) + TMath::Power( 1-ratio,2 ) );
    } else{
      if( ratio < 1) normUp_VV = TMath::Sqrt( TMath::Power(normUp_VV,2) + TMath::Power( 1-ratio,2 ) );
      else normDown_VV = TMath::Sqrt( TMath::Power(normDown_VV,2) + TMath::Power( 1-ratio,2 ) );
    }
  }
  this->GetHistbyName(s_jetFakes+"_"+s_norm+sub,s_norm);
  this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+s_norm+sub,s_norm);
  this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+s_norm+sub,s_norm);
  this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+s_norm+sub,s_norm);
  this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+s_norm+sub,s_norm);
  this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+s_norm+sub,s_norm);
  this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+s_norm+sub,s_norm);
  this->GetHistbyName(s_jetFakes+"_"+s_norm+sub)->SetBinContent(1,normUp_jetFakes);
  this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(1,normUp_data);
  this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(1,normUp_W);
  this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(1,normUp_TT);
  this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(1,normUp_Z);
  this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(1,normUp_EWKZ);
  this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(1,normUp_VV);
  this->GetHistbyName(s_jetFakes+"_"+s_norm+sub)->SetBinContent(2,normDown_jetFakes);
  this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(2,normDown_data);
  this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(2,normDown_W);
  this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(2,normDown_TT);
  this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(2,normDown_Z);
  this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(2,normDown_EWKZ);
  this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(2,normDown_VV);
  this->GetHistbyName(s_jetFakes+"_"+s_norm+sub)->SetBinContent(3,normUp_jetFakes_syst);
  this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(3,normUp_data_syst);
  this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(3,normUp_W_syst);
  this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(3,normUp_TT_syst);
  this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(3,normUp_Z_syst);
  this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(3,normUp_EWKZ_syst);
  this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(3,normUp_VV_syst);
  this->GetHistbyName(s_jetFakes+"_"+s_norm+sub)->SetBinContent(4,normDown_jetFakes_syst);
  this->GetHistbyName(s_data+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(4,normDown_data_syst);
  this->GetHistbyName(s_W+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(4,normDown_W_syst);
  this->GetHistbyName(s_TT+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(4,normDown_TT_syst);
  this->GetHistbyName(s_Z+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(4,normDown_Z_syst);
  this->GetHistbyName(s_EWKZ+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(4,normDown_EWKZ_syst);
  this->GetHistbyName(s_VV+"_"+s_jetFakes+"_"+s_norm+sub)->SetBinContent(4,normDown_VV_syst);

  if(channel == "tt"){
    this->GetHistbyName(s_FFrest+sub,strVar)->Add( this->GetHistbyName(s_ZJ+"_"+s_rest+sub,strVar)   );
    this->GetHistbyName(s_FFrest+sub,strVar)->Add( this->GetHistbyName(s_EWKZ+"_"+s_rest+sub,strVar)   );
    this->GetHistbyName(s_FFrest+sub,strVar)->Add( this->GetHistbyName(s_W+"_"+s_rest+sub,strVar)   );
    this->GetHistbyName(s_FFrest+sub,strVar)->Add( this->GetHistbyName(s_TTJ+"_"+s_rest+sub,strVar)   );
    this->GetHistbyName(s_FFrest+sub,strVar)->Add( this->GetHistbyName(s_VVJ+"_"+s_rest+sub,strVar)   );

    this->GetHistbyName(s_ZJ+"_"+s_rest+sub,strVar)->Add( this->GetHistbyName(s_EWKZ+"_"+s_rest+sub,strVar)   );

    if(jecShift){
      this->GetHistbyName(s_FFrestjecUp+sub,strVar)->Add( this->GetHistbyName(s_Z+"_"+s_restjecUp+sub,strVar)   );
      this->GetHistbyName(s_FFrestjecUp+sub,strVar)->Add( this->GetHistbyName(s_EWKZ+"_"+s_restjecUp+sub,strVar)   );
      this->GetHistbyName(s_FFrestjecUp+sub,strVar)->Add( this->GetHistbyName(s_W+"_"+s_restjecUp+sub,strVar)   );
      this->GetHistbyName(s_FFrestjecUp+sub,strVar)->Add( this->GetHistbyName(s_TT+"_"+s_restjecUp+sub,strVar)   );
      this->GetHistbyName(s_FFrestjecUp+sub,strVar)->Add( this->GetHistbyName(s_VV+"_"+s_restjecUp+sub,strVar)   );

      this->GetHistbyName(s_ZJ+"_"+s_restjecUp+sub,strVar)->Add( this->GetHistbyName(s_EWKZ+"_"+s_restjecUp+sub,strVar)   );

      this->GetHistbyName(s_FFrestjecDown+sub,strVar)->Add( this->GetHistbyName(s_Z+"_"+s_restjecDown+sub,strVar)   );
      this->GetHistbyName(s_FFrestjecDown+sub,strVar)->Add( this->GetHistbyName(s_EWKZ+"_"+s_restjecDown+sub,strVar)   );
      this->GetHistbyName(s_FFrestjecDown+sub,strVar)->Add( this->GetHistbyName(s_W+"_"+s_restjecDown+sub,strVar)   );
      this->GetHistbyName(s_FFrestjecDown+sub,strVar)->Add( this->GetHistbyName(s_TT+"_"+s_restjecDown+sub,strVar)   );
      this->GetHistbyName(s_FFrestjecDown+sub,strVar)->Add( this->GetHistbyName(s_VV+"_"+s_restjecDown+sub,strVar)   );

      this->GetHistbyName(s_ZJ+"_"+s_restjecDown+sub,strVar)->Add( this->GetHistbyName(s_EWKZ+"_"+s_restjecDown+sub,strVar)   );
    }
  }
  //cout << "NormUp: " << normUp << endl;
  //cout << "NormDown: " << normDown << endl;
  //cout << "//////////////////////////////////////" << endl;

}
double CreateHistos::getQCD_osss(TString cat){
  if(channel == "mt"){
    if(cat.Contains("looseiso")){
      if(cat.Contains("btag") && !cat.Contains("nobtag") ) return 0.95;
      if(cat.Contains("nobtag") ) return 1.20;
      if(cat.Contains("inclusive") ) return 1.19;
    }
    else{
      if(cat.Contains("btag") && !cat.Contains("nobtag") ) return 1.08;
      if(cat.Contains("nobtag") ) return 1.12;
      if(cat.Contains("inclusive") ) return 1.10;      
    }
  }
  if(channel == "et"){
    if(cat.Contains("looseiso")){
      if(cat.Contains("btag") && !cat.Contains("nobtag") ) return 0.84;
      if(cat.Contains("nobtag") ) return 0.97;
      if(cat.Contains("inclusive") ) return 0.99;
    }
    else{
      if(cat.Contains("btag") && !cat.Contains("nobtag") ) return 1.21;
      if(cat.Contains("nobtag") ) return 1.02;
      if(cat.Contains("inclusive") ) return 1.04;      
    }
  }

  return 1.0;
}
double CreateHistos::getW_osss(TString strVar, TString cat){

  TString sub = "+" + strVar +"_" + cat+"_wjets_cr+";
  if(cat.Contains("btag") && !cat.Contains("nobtag") ) sub = "+" + strVar +"_" + cat+"_loosebtag_wjets_cr+";
  
  return this->GetHistbyName("OS_incl_"+s_W+sub,strVar)->Integral() / this->GetHistbyName("SS_incl_"+s_W+sub,strVar)->Integral();
}
double CreateHistos::getW_mtHL(TString strVar, TString cat){
  TString sub = "+" + strVar +"_" + cat;
  if(cat.Contains("btag") && !cat.Contains("nobtag") ) sub = "+" + strVar +"_" + cat+"_loosebtag";

  return this->GetHistbyName(s_W+ "_MC"+ sub + "+",strVar)->Integral() / this->GetHistbyName(s_W+ "_MC"+ sub+"_wjets_cr+",strVar)->Integral();
}
double CreateHistos::getW_BtagConv(TString strVar, TString cat){
  TString sub = "+" + strVar +"_" + cat +"+";
  return this->GetHistbyName(s_W+ "_MC" + sub,strVar)->Integral() / this->GetHistbyName("SR_looseB_MC_"+s_W+sub,strVar)->Integral();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CreateHistos::EstimateW(TString strVar, TString cat){
  if(cat.Contains("wjets_cr") || cat.Contains("loosebtag") || cat.Contains("wjets_ss_cr") || cat.Contains("qcd_cr") ) return;

  double R_W = this->getW_osss(strVar, cat);
  double R_QCD = this->getQCD_osss(cat);
  double HLExt = this->getW_mtHL(strVar, cat);
  double BConv_SR = this->getW_BtagConv(strVar, cat);
  double BConv_CR = this->getW_BtagConv(strVar, cat + "_wjets_cr");
    cout << "  "<<BConv_CR<< "     "<<BConv_SR<< "     " << endl;
  //double BConv = 1; //FIXME after SS_W ist calculated correctly using loose btag regions for ALL histos conv scale can be applied

  TString bt = "";
  if(cat.Contains("btag") && !cat.Contains("nobtag")) bt = "_loosebtag";
  TString sub = "+" + strVar +"_" + cat;

  cout << R_W << "  " << R_QCD << "  " << HLExt << "  "<< this->getW_BtagConv(strVar, cat)<< "  " << endl;

  this->GetHistbyName("data_os_obs"+sub+"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_data + sub + bt +"_wjets_cr+",strVar)   );
  this->GetHistbyName("backgrounds_os"+sub+"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_Z + sub + bt +"_wjets_cr+",strVar) );
  this->GetHistbyName("backgrounds_os"+sub+"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_EWKZ + sub + bt +"_wjets_cr+",strVar));
  this->GetHistbyName("backgrounds_os"+sub+"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_VV + sub + bt +"_wjets_cr+",strVar) );
  this->GetHistbyName("backgrounds_os"+sub+"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_TT + sub + bt +"_wjets_cr+",strVar) );

  this->GetHistbyName("data_ss_obs"+sub+"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_data + sub + bt +"_wjets_ss_cr+",strVar)   );
  this->GetHistbyName("backgrounds_ss"+sub+"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_Z + sub + bt +"_wjets_ss_cr+",strVar) );
  this->GetHistbyName("backgrounds_ss"+sub+"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_EWKZ + sub + bt +"_wjets_ss_cr+",strVar));
  this->GetHistbyName("backgrounds_ss"+sub+"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_VV + sub + bt +"_wjets_ss_cr+",strVar) );
  this->GetHistbyName("backgrounds_ss"+sub+"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_TT + sub + bt +"_wjets_ss_cr+",strVar) );

  double wjets_ss_cr_norm  = this->GetHistbyName("data_os_obs"+sub+"_wjets_cr+",strVar)->Integral() - this->GetHistbyName("backgrounds_os"+sub+"_wjets_cr+",strVar)->Integral();
         wjets_ss_cr_norm -= (this->GetHistbyName("data_ss_obs"+sub+"_wjets_ss_cr+",strVar)->Integral() - this->GetHistbyName("backgrounds_ss"+sub+"_wjets_ss_cr+",strVar)->Integral() ) * R_QCD;
         wjets_ss_cr_norm *= ( 1 /  ( R_W - R_QCD ) );



  this->GetHistbyName(s_W+sub+"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_W+"_MC"+sub+bt+"_wjets_ss_cr+",strVar) );
  this->GetHistbyName(s_W+sub+"_wjets_ss_cr+",strVar)->Scale( (wjets_ss_cr_norm * BConv_CR) / this->GetHistbyName(s_W+sub+"_wjets_ss_cr+",strVar)->Integral() );

  this->GetHistbyName(s_W+sub+"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_W +"_MC"+sub+bt+"_wjets_cr+",strVar) );
  this->GetHistbyName(s_W+sub+"_wjets_cr+",strVar)->Scale( (R_W * wjets_ss_cr_norm* BConv_CR) / this->GetHistbyName(s_W+sub+"_wjets_cr+",strVar)->Integral() );

  this->GetHistbyName(s_W +sub +"_qcd_cr+",strVar)->Add( this->GetHistbyName(s_W+ "_MC" +sub +"_qcd_cr+",strVar) );
  this->GetHistbyName(s_W +sub +"_qcd_cr+",strVar)->Scale( (wjets_ss_cr_norm * HLExt* BConv_SR) / this->GetHistbyName(s_W +sub +"_qcd_cr+",strVar)->Integral() );

  this->GetHistbyName(s_W +sub +"+",strVar)->Add( this->GetHistbyName(s_W+ "_MC" +sub +"+",strVar) ); 
  this->GetHistbyName(s_W +sub +"+",strVar)->Scale( (wjets_ss_cr_norm * HLExt * R_W* BConv_SR ) / this->GetHistbyName(s_W +sub +"+",strVar)->Integral() );



  TString w_FakeShape_up="W_CMS_htt_wFakeShape_13TeVUp";
  TString w_FakeShape_down="W_CMS_htt_wFakeShape_13TeVDown";

  this->GetHistbyName(w_FakeShape_up +sub+"+",strVar)->Add( this->GetHistbyName(s_W+ "_MC_fakeShapeUp_" +sub +"+",strVar) );
  this->GetHistbyName(w_FakeShape_down +sub+"+",strVar)->Add( this->GetHistbyName(s_W+ "_MC_fakeShapeDown_" +sub +"+",strVar) );


  this->GetHistbyName(w_FakeShape_up +sub +"+",strVar)->Scale( (wjets_ss_cr_norm * HLExt * R_W* BConv_SR ) / this->GetHistbyName(w_FakeShape_up +sub +"+",strVar)->Integral() );
  this->GetHistbyName(w_FakeShape_down +sub +"+",strVar)->Scale( (wjets_ss_cr_norm * HLExt * R_W* BConv_SR ) / this->GetHistbyName(w_FakeShape_down +sub +"+",strVar)->Integral() );
}

void CreateHistos::EstimateQCD(TString strVar, TString cat){
  if(cat.Contains("wjets_cr") || cat.Contains("loosebtag") || cat.Contains("wjets_ss_cr") || cat.Contains("qcd_cr") ) return;
  TString sub = "+" + strVar +"_" + cat + "_qcd_cr+";

  double CR_QCD_norm = this->GetHistbyName(s_data+sub,strVar)->Integral();
  CR_QCD_norm  -= this->GetHistbyName(s_W+sub,strVar)->Integral();
  CR_QCD_norm  -= this->GetHistbyName(s_Z+sub,strVar)->Integral();
  CR_QCD_norm  -= this->GetHistbyName(s_EWKZ+sub,strVar)->Integral();
  CR_QCD_norm  -= this->GetHistbyName(s_VV+sub,strVar)->Integral();
  CR_QCD_norm  -= this->GetHistbyName(s_TT+sub,strVar)->Integral();
  TString bt = "";
  if(cat.Contains("btag") && !cat.Contains("nobtag")) bt = "_loosebtag";

  double SR_QCD_norm = CR_QCD_norm * this->getQCD_osss(cat);

  this->GetHistbyName("QCD+" + strVar +"_" + cat +"+" ,strVar)->Add( this->GetHistbyName(s_data+sub,strVar));
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"+" ,strVar)->Add( this->GetHistbyName(s_Z+sub,strVar), -1);
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"+" ,strVar)->Add( this->GetHistbyName(s_EWKZ+sub,strVar), -1);
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"+" ,strVar)->Add( this->GetHistbyName(s_VV+sub,strVar), -1);
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"+" ,strVar)->Add( this->GetHistbyName(s_TT+sub,strVar), -1);
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"+" ,strVar)->Add( this->GetHistbyName(s_W+ "_MC" +sub ,strVar), -1);

  // this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_data + "+" + strVar +"_" + cat + bt +"_wjets_cr+",strVar)   );
  // this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_Z + "+" + strVar +"_" + cat +bt +"_wjets_cr+",strVar), -1 );
  // this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_EWKZ + "+" + strVar +"_" + cat +bt +"_wjets_cr+",strVar), -1 );
  // this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_VV + "+" + strVar +"_" + cat +bt +"_wjets_cr+",strVar), -1 );
  // this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_TT + "+" + strVar +"_" + cat +bt +"_wjets_cr+",strVar), -1 );
  // this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_W +"+" + strVar +"_" + cat +bt +"_wjets_cr+",strVar), -1 );


  this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_data + "+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar)   );
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_Z + "+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar), -1 );
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_EWKZ + "+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar), -1 );
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_VV + "+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar), -1 );
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_TT + "+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar), -1 );
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_W + "+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar), -1 );

  this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_cr+",strVar)->Add( this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_ss_cr+",strVar) );
  this->GetHistbyName("QCD+" + strVar +"_" + cat +"_wjets_cr+",strVar)->Scale( this->getQCD_osss(cat) );

  this->GetHistbyName("QCD"+ sub ,strVar)->Add( this->GetHistbyName("QCD+" + strVar +"_" + cat +"+" ,strVar) );
  this->GetHistbyName("QCD"+ sub ,strVar)->Scale(CR_QCD_norm / this->GetHistbyName("QCD"+ sub ,strVar)->Integral());

  this->GetHistbyName("QCD+" + strVar +"_" + cat +"+" ,strVar)->Scale(SR_QCD_norm / this->GetHistbyName("QCD+" + strVar +"_" + cat +"+" ,strVar)->Integral());

}

void CreateHistos::writeHistos( TString channel, vector<TString> cats, vector<TString> vars ){

  stringstream outfile_name;
  TString sub;
  TString tmp;
  TString D2="";
  if(do2DFit) D2+="-2D";
  if(doMC) D2+="-MCsum";

  for(auto var : vars){
    //outfile_name << "histos/FF/"  << "htt_" << channel << ".inputs-mssm-13TeV-"<<var<<D2<<".root";
    outfile_name << "histos/"<<channel <<"_"<<UseIso  << "/htt_" << channel << ".inputs-mssm-13TeV-"<<var<<D2<<".root";
    outfile = new TFile(outfile_name.str().c_str(), "RECREATE") ;

    for(auto cat : cats){
      //if(cat.Contains("loosebtag") ) continue;
      outfile->mkdir(channel +"_"+ cat );
      outfile->cd(channel +"_"+ cat); 
      sub = "+" + var +"_" + cat + "+";

      for (auto const& name : histograms){

        if(name.first.Contains(sub) ){
          if(!keepDebugHistos
             && ( name.first.Contains("SS_Low")
                  || name.first.Contains("relaxed")
                  || name.first.Contains("SS_"+s_W)
                  //|| name.first.Contains("OS_"+s_W)
                  || name.first.Contains(s_W+"_OSW")
                  || name.first.Contains(s_WjecUp+"_OSW")
                  || name.first.Contains(s_WjecDown+"_OSW")
                  )
             ) continue;
          if(!keepFFDebugHistos
             && ( name.first.Contains(s_data+"_"+s_jetFakes)
                  || name.first.Contains(s_W+"_"+s_jetFakes)
                  || name.first.Contains(s_WjecUp+"_"+s_jetFakes)
                  || name.first.Contains(s_WjecDown+"_"+s_jetFakes)
                  || name.first.Contains(s_Z+"_"+s_jetFakes)
                  || name.first.Contains(s_ZjecUp+"_"+s_jetFakes)
                  || name.first.Contains(s_ZjecDown+"_"+s_jetFakes)
                  || name.first.Contains(s_TT+"_"+s_jetFakes)
                  || name.first.Contains(s_TTjecUp+"_"+s_jetFakes)
                  || name.first.Contains(s_TTjecDown+"_"+s_jetFakes)
                  || name.first.Contains(s_VV+"_"+s_jetFakes)
                  || name.first.Contains(s_VVjecUp+"_"+s_jetFakes)
                  || name.first.Contains(s_VVjecDown+"_"+s_jetFakes)
                  || name.first.Contains(s_EWKZ+"_"+s_jetFakes)
                  || name.first.Contains(s_EWKZjecUp+"_"+s_jetFakes)
                  || name.first.Contains(s_EWKZjecDown+"_"+s_jetFakes)                  
                  )
             ) continue;
          if(!keepZGenJetsSplitting
             && ( name.first.Contains("Z_0Jets")
                  || name.first.Contains("Z_1Jets")
                  || name.first.Contains("Z_ge2Jets")
                  )
             ) continue;
          tmp = name.first;
          if( (cat.Contains(s_wjets)
               ||cat.Contains(s_antiiso) )
              && tmp.Contains(s_West) ) continue;
          if( (cat.Contains(s_wjets)
               ||cat.Contains(s_antiiso) )
              && tmp.Contains(s_QCDest) ) continue;
          if( tmp.Contains("SR_MC") ) continue;
          if( ( cat.Contains(s_wjets)
                || cat.Contains(s_antiiso) )
              && tmp.Contains("SR_"+s_W) ) continue;
          else if( !cat.Contains(s_wjets)
                   && !cat.Contains(s_antiiso)
                   && tmp.Contains("SR_"+s_W ) ) tmp.ReplaceAll("SR_","");
          else if( cat.Contains(s_wjets)
                   && tmp.Contains("WCR_"+s_W ) ) tmp.ReplaceAll("WCR_","");
          else if( cat.Contains(s_antiiso)
                   && tmp.Contains("AICR_"+s_W ) ) tmp.ReplaceAll("AICR_","");
          else if( tmp.Contains("WCR_"+s_W)
                   || tmp.Contains("AICR_"+s_W) ) continue;
          if( cat.Contains(s_wjets)
              && tmp.Contains("OS_W_"+s_QCD ) ) tmp.ReplaceAll("OS_W_","");
          // else if( cat.Contains(s_wjets)
          //          && !tmp.Contains(s_QCDSFUncert)
          //          && tmp.Contains(s_QCD) ) continue;

          if(tmp.Contains("OS_"+s_W)) continue;
          tmp.ReplaceAll(sub, "");
          tmp.ReplaceAll(s_jecUp,s_CMSjecScale+s_13TeVUp);
          tmp.ReplaceAll(s_jecDown,s_CMSjecScale+s_13TeVDown);
          tmp.ReplaceAll(s_jetToTauFakeUp,s_CMSjetToTauFake+s_13TeVUp);
          tmp.ReplaceAll(s_jetToTauFakeDown,s_CMSjetToTauFake+s_13TeVDown);
          histograms.at( name.first )->SetName(tmp);
          this->resetZeroBins(histograms.at( name.first ));
          histograms.at( name.first )->Write(tmp, TObject::kWriteDelete);
          

        }
      }
    }
    outfile->Close();
    outfile_name.str("");
  }
    
}

int CreateHistos::isZFile(TString fileName){
  if(fileName == s_Z) return 1;
  if(fileName == s_ZtauUp) return 1;
  if(fileName == s_ZtauDown) return 1;
  if(fileName == s_ZjecUp) return 1;
  if(fileName == s_ZjecDown) return 1;

  return 0;
}

int CreateHistos::isEWKZFile(TString fileName){
  if(fileName == s_EWKZ) return 1;
  if(fileName == s_EWKZtauUp) return 1;
  if(fileName == s_EWKZtauDown) return 1;
  if(fileName == s_EWKZjecUp) return 1;
  if(fileName == s_EWKZjecDown) return 1;

  return 0;
}

int CreateHistos::isSignalFile(TString fileName){

    if(fileName == s_ggH) return 1;
    if(fileName == s_ggHtauUp) return 1;
    if(fileName == s_ggHtauDown) return 1;
    if(fileName == s_ggHjecUp) return 1;
    if(fileName == s_ggHjecDown) return 1;
    if(fileName == s_bbH) return 1;
    if(fileName == s_bbHtauUp) return 1;
    if(fileName == s_bbHtauDown) return 1;
    if(fileName == s_bbHjecUp) return 1;
    if(fileName == s_bbHjecDown) return 1;

  return 0;
}

int CreateHistos::isTTFile(TString fileName){
  if(fileName == s_TT) return 1;
  if(fileName == s_TTtauUp) return 1;
  if(fileName == s_TTtauDown) return 1;
  if(fileName == s_TTjecUp) return 1;
  if(fileName == s_TTjecDown) return 1;

  return 0;  
}

int CreateHistos::isWFile(TString fileName){
  if(fileName == s_W) return 1;
  if(fileName == s_WjecUp) return 1;
  if(fileName == s_WjecDown) return 1;

  return 0;
}

int CreateHistos::isVVFile(TString fileName){
  if(fileName == s_VV) return 1;
  if(fileName == s_VVtauUp) return 1;
  if(fileName == s_VVtauDown) return 1;
  if(fileName == s_VVjecUp) return 1;
  if(fileName == s_VVjecDown) return 1;

  return 0;
}
