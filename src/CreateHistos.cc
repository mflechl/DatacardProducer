#include "interface/CreateHistos.h"
#include "TLorentzVector.h"
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <TObject.h>
#include <algorithm>


using namespace std;

CreateHistos::CreateHistos(TString runOption_, TString ch){

  // Basic initialization of channel categories and mt cut
  runOption = runOption_;
  channel = ch;
  for(auto cat : Analysis["categories"][channel] ) categories.push_back( cat ); 
  applyMTCut = Analysis["applyMTCut"][channel];   

  // Initialization of FF version
  FFiso = Analysis["FFiso"][channel];
  FFbuild = Analysis["FFbuild"][channel];
  FFversion = FFbuild + FFiso+".root";

  // Name of output folder and prompt for run option 
  folder = channel;
  if(runOption == "quicktest") cout << "testing code on one sample" << endl;
  if(runOption == "test")      cout << "testing availability of input files" << endl;
  if(runOption == "minimal")   cout << "creating minimal datacard" << endl;
  if(runOption == "nlo"){
    folder = channel + "_nlo";
    cout << "creating nlo datacard" << endl;
  }

  // Initialize masspoints
  if(runOption == "minimal") for(auto mass : Datasets["masspoints"]["test"] ) masspoints.push_back( mass );
  else if (runOption != "quicktest") for(auto mass : Datasets["masspoints"]["full"] ) masspoints.push_back( mass );

  // Initialize set of energy scale shifts
  vector<string> shifts = {""};
  if( runOption != "minimal" && runOption != "quicktest" ){    
    for(auto shift : Datasets["shifts"][channel] ) shifts.push_back( shift );
  }

  // Set of background samples to process
  vector<TString> bkg_samples = { s_Z,
                                  s_TT,
                                  s_VV,
                                  s_SMggH,
                                  s_SMvbf,
                                  s_SMWminus,
                                  s_SMWplus,
                                  s_SMZH };
  if (runOption == "quicktest") bkg_samples = { };

  // Create filepaths mapped to unique identifier for data an MC samples
  files[s_data].first = this->getFilestring( Datasets["id"][s_data.Data()][channel] );
  files[s_W].first = this->getFilestring( Datasets["id"][s_W.Data()] );
  for(auto shift : shifts ){
    for( auto sample : bkg_samples ){
      files[sample+shift].first = this->getFilestring(  Datasets["id"][sample.Data()], shift );
    }
    for(auto mass : masspoints){
        files[s_ggH+shift+mass].first = this->getFilestring( Datasets["id"]["ggH"], shift, mass );
        files[s_ggH+shift+mass].second = mass;

        if(runOption == "nlo") files[s_bbH.Data()+shift+mass].first = this->getFilestring( Datasets["id"]["bbHnlo"], shift, mass );
        else files[s_bbH+shift+mass].first = this->getFilestring( Datasets["id"]["bbH"], shift, mass );
        files[s_bbH+shift+mass].second = mass;   
    }
  }
  
  // ##############Deprecated in MSSM ##############
  // ################################################
  // if( jecShift  && runOption != "minimal" ){
  //   for(auto jshift : {s_jecUp, s_jecDown} ){
  //     for( auto sample : bkg_samples ){
  //       files[sample.Data()+jshift].first = this->getFilestring(  Datasets["id"][sample.Data()] );
  //     }
  //     for(auto mass : masspoints){
  //       files[s_ggH.Data()+jshift+mass].first = this->getFilestring(Datasets["id"]["ggH"],"",mass);
  //       files[s_ggH.Data()+jshift+mass].second = this->getFilestring( mass);


  //       files[s_bbH+jshift+mass].first = this->getFilestring( Datasets["id"]["bbH"],"",mass);
  //       files[s_bbH+jshift+mass].second = this->getFilestring( mass);

  //     }
  //   }
  // }

  for(auto var : variables)      vars.push_back(var);
  for(auto cat : categories){
    cats.push_back(cat);
    if(channel != "tt"){
      cats.push_back(cat+"_wjets_cr");
      cats.push_back(cat+"_wjets_ss_cr");
      cats.push_back(cat+"_qcd_cr");
      cats.push_back(cat+"_loosebtag");
      cats.push_back(cat+"_loosebtag_qcd_cr");
      cats.push_back(cat+"_loosebtag_wjets_cr");
      cats.push_back(cat+"_loosebtag_wjets_ss_cr");
    }
    else{
      cats.push_back(cat+"_looseTiso");
      cats.push_back(cat+"_qcd_cr");
      cats.push_back(cat+"_looseTiso_qcd_cr");
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

TString CreateHistos::getFilestring(TString input, TString ES, TString mass){

  TString newstring = input;
  string v = Datasets["version"][channel];
  TString inputfolder ="/data/higgs/data_2016/ntuples_"+v+"/"+channel+"/ntuples_"+doSvfit+"_merged/";
  TString appendix = channel+"_"+v+"_TES.root";
  
  newstring = inputfolder + newstring + appendix;
  newstring.ReplaceAll("XXX",mass);
  if(ES == "") newstring.ReplaceAll("_TES",ES);
  else newstring.ReplaceAll("TES",ES);

  return newstring;

}

void CreateHistos::loadFile(TString filename, int isData){

  TChain *tchain = new TChain("TauCheck");
  tchain->Add(filename);
  NtupleView = std::unique_ptr<ntuple>(new ntuple( tchain, isData ) );
  
}

void CreateHistos::run(){

  //clearHistos();
  float weight = 1;
  float weight_data = 1;
  float var = -999;
  TString bold = "\033[1m";
  TString red = "\033[1;31m";
  TString green = "\033[1;32m";
  TString endc = "\033[0m";
  initFakeFactors();

  
  for(auto strVar : vars) cout << "Variable " << strVar << endl;
  for(auto cat : categories) cout << "Category " << cat << endl;
  cout << endl;
  cout << "----Settings:-----" << endl;
  cout << left << setw(12) << setfill(' ')  << "Channel: "    << channel << endl;
  cout << left << setw(12) << setfill(' ')  << "Run Option: "   << runOption <<  endl;
  if(calcFF) cout << left << setw(12) << setfill(' ')  << "FF version: " << FFversion <<  endl;
  else cout << left << setw(12) << setfill(' ')  << "FF is not calculated !!"  <<  endl;
  cout << "------------------" << endl;
  cout << endl;
  if(channel == "tt" && applyMTCut ) cout << "##### WARNING ######    mt cut applied in tt channel!!" << endl;
  else if(channel != "tt" && !applyMTCut) cout << "##### WARNING ######  NO  mt cut applied in mt or et channel!!" << endl;


  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(doInitialize){

    for(auto cat : cats){
      for(auto strVar : vars){

          initDYSelections(cat,strVar);
          initTSelections(cat,strVar);
          initVVSelections(cat,strVar);
          initEWKZSelections(cat,strVar);
          //initSignalSelections(cat,strVar);

      }
    }
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TString filetype = "";
  int fileindex = 0;
  string remFolder = getFilestring("").Data();
  remFolder = remFolder.substr(0, remFolder.find_last_of("/") );
  float perc;
  TString filename = "";
  TString mass = "";
  cout.precision(3);

  if ( DEBUG ) std::cout << "CreateHistos::run \t remFolder= " << remFolder << std::endl;

  for (auto const& file : files){

    filetype = file.first; 
    filename = file.second.first;
    mass = file.second.second;
    filetype.ReplaceAll( mass, "" );

  if ( DEBUG==2 ) std::cout << "CreateHistos::run \t filename= " << filename << std::endl;

    if( access(filename.Data(),F_OK ) != 0 ){
      cout << red +" Warning "+endc+"File does not exist ->  " << filename.ReplaceAll(remFolder,"") << endl;
      continue;
    }

    ////////////////////////////////
    // Fileindex      Filetype
    // 0              data
    // 1              DY
    // 2              Signal
    // 3              TT
    // 4              W
    // 5              Diboson
    // 6              EWK
    fileindex = this->getFiletype(filetype);
    if ( DEBUG==2 ) std::cout << "CreateHistos::run \t fileindex= " << fileindex << std::endl;

    if(jecShift){

    }
    if(filetype.Contains(s_jecUp)) this->isJEC=1;
    else if(filetype.Contains(s_jecDown)) this->isJEC=-1;
    else this->isJEC=0;

    this->loadFile(filename,fileindex==0);
    Int_t nentries=0;
    if(runOption == "test" || runOption == "quicktest"){
      nentries = min( Int_t(NtupleView->fChain->GetEntries()), Int_t( 10000 ) );
    }else{
      nentries = Int_t(NtupleView->fChain->GetEntries());
    }

    if(nentries > 0) cout<< "Contains "+green;
    else cout<< "Contains " + red;
    cout<< left << setw(8) << setfill(' ')  << nentries;
    cout<<endc+" events. File:  "<<bold + filename.ReplaceAll(remFolder,"") + endc<<endl;

    //    Double_t xxtest;
    //    NtupleView->fChain->SetBranchAddress(s_mttot, &xxtest);

    vector<Double_t> p_vars;
    //    p_vars.reserve(vars.size());
    for(auto strVar : vars){
      p_vars.push_back(-1);
      NtupleView->fChain->SetBranchAddress(strVar, &p_vars.back());
    }

    for (Int_t jentry=0; jentry<nentries;jentry++){       

      if(jentry % 200000 == 0){
        if(nentries > 0){
          perc =  ( (float)jentry / (float)nentries ) * 100;
        }
        cout<< "                                                             \r"<< flush;
        cout<< jentry << "/" << nentries <<"\t\t" << perc << "%\r"<< flush;
      }

      NtupleView->GetEntry(jentry);

      if( !this->SpecialCuts() ) continue;

      if( channel== "mt" && (NtupleView->Flag_badMuons || NtupleView->Flag_duplicateMuons || !NtupleView->trg_singlemuon) ) continue;
      if( channel== "et" && ( !NtupleView->trg_singleelectron ) )continue;
      if( channel== "tt" && !NtupleView->trg_doubletau )continue;


      weight = NtupleView->stitchedWeight;
      weight *= NtupleView->puweight;
      weight *= this->recalcEffweight();
      weight *= NtupleView->genweight;
      weight *= NtupleView->trk_sf;
      weight *= (float)Analysis["Luminosity"][channel];

      if(channel != "tt") weight *= NtupleView->antilep_tauscaling;
      else weight *= this->getAntiLep_tauscaling();


      if( fileindex == 1 || fileindex == 6 ) weight *= NtupleView->ZWeight;
      if( fileindex == 3 ) weight *= NtupleView->topWeight_run1;


      for(auto cat : cats){

	int ind=0;
        for(auto strVar : vars){

	  //	  std::cout << "XXX " << p_vars.at(0) << std::endl;

          var = -999;

	  if ( p_vars.size()>ind )
	    var=p_vars.at(ind);
	  else
	    continue;
	  ++ind;

	  //TODO: if you want to impose cuts, do it here - not when selecting variables (e.g. jeta_1)


          if( fileindex == 1 )                this->DYSelections(var, weight, cat, strVar, filetype);
          else if( fileindex == 2 )           this->signalSelections(var, weight, cat, strVar, filetype, mass);
          else if( fileindex == 3 )           this->TSelections(var, weight, cat, strVar, filetype);
          else if( fileindex == 4 )           this->WSelections(var, weight, cat, strVar, filetype);             
          else if( fileindex == 5 )           this->VVSelections(var, weight, cat, strVar, filetype);                 
          else if( fileindex == 6 )           this->EWKZSelections(var, weight, cat, strVar, filetype);       
          else if( filetype == s_data )       this->dataSelections(var, weight_data, cat, strVar, filetype);

        }
      }
    }//end loop over entries
  }//end loop over files
  cout.precision(10);
  for(auto cat : cats){
    for(auto strVar : vars){
      this->EstimateW(strVar, cat);
      this->EstimateQCD(strVar, cat);
      if(calcFF) this->EstimateFF(strVar, cat);
      //if(cat != s_inclusive) this->createInclusive(strVar, cat);
    }
  }
  
  //cats.push_back(s_inclusive);
  
  cout << "Done running over events." << endl;
  writeHistos( channel, cats, vars );
  
}

double CreateHistos::getMT3(){
  TLorentzVector leg1,leg2;
  leg1.SetPtEtaPhiM( NtupleView->pt_1,NtupleView->eta_1,NtupleView->phi_1,NtupleView->m_1 );
  leg2.SetPtEtaPhiM( NtupleView->pt_2,NtupleView->eta_2,NtupleView->phi_2,NtupleView->m_2 );

  return sqrt( 2*leg1.Pt() * leg2.Pt() * ( 1- TMath::Cos( leg1.DeltaPhi(leg2) ) ) );
}

bool CreateHistos::SpecialCuts(){
  if(runOption == "1p" && NtupleView->decayMode_2 < 4) return true;
  if(runOption == "3p" && NtupleView->decayMode_2 == 10) return true;
  if(runOption == "pt_l50" && NtupleView->pt_2 <= 50) return true;
  if(runOption == "pt_5080" && NtupleView->pt_2 > 50 && NtupleView->pt_2 <= 80) return true;
  if(runOption == "pt_g80" && NtupleView->pt_2 > 80) return true;
  if(runOption == "pt_g80_1p" && NtupleView->pt_2 > 80 && NtupleView->decayMode_2 < 4) return true;
  if(runOption == "pt_g80_3p" && NtupleView->pt_2 > 80 && NtupleView->decayMode_2 == 10) return true;
  if(runOption == "pt_g100" && NtupleView->pt_2 > 100) return true;
  if(runOption == "pt_g120" && NtupleView->pt_2 > 120) return true;
  if(runOption == "nom") return true;
  if(runOption == "nlo") return true;
  if(runOption == "minimal") return true;
  if(runOption == "test") return true;
  if(runOption == "quicktest") return true;
  return false;
}

float CreateHistos::recalcEffweight(){
  float idiso_1 = NtupleView->idisoweight_1;
  float idiso_2 = NtupleView->idisoweight_2;

  if(channel == "tt"){
    if(NtupleView->gen_match_1 == 5 && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_1) idiso_1 = 0.97;
    else if(NtupleView->gen_match_1 == 5 && (NtupleView->byLooseIsolationMVArun2v1DBoldDMwLT_1 || NtupleView->byVLooseIsolationMVArun2v1DBoldDMwLT_1) ) idiso_1 = 0.99;
    else idiso_1 = 1.;

    if(NtupleView->gen_match_2 == 5 && NtupleView->byMediumIsolationMVArun2v1DBoldDMwLT_2) idiso_2 = 0.97;
    else if(NtupleView->gen_match_2 == 5 && (NtupleView->byLooseIsolationMVArun2v1DBoldDMwLT_2 || NtupleView->byVLooseIsolationMVArun2v1DBoldDMwLT_2)) idiso_2 = 0.99;
    else idiso_2 = 1.;
  }
  else{
    if(NtupleView->gen_match_2 == 5 && NtupleView->byTightIsolationMVArun2v1DBoldDMwLT_2) idiso_2 = 0.95;
    else if(NtupleView->gen_match_2 == 5 && (NtupleView->byLooseIsolationMVArun2v1DBoldDMwLT_2 || NtupleView->byVLooseIsolationMVArun2v1DBoldDMwLT_2) ) idiso_2 = 0.99;
    else idiso_2 = 1.;
  }
  return NtupleView->trigweight_1 * NtupleView->trigweight_2 * idiso_1 * idiso_2 ;
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
    if(channel == "tt"){
      //run2 SF for VLoose for tau2
      float scaleFactor_tautau = 1;
      if( NtupleView->gen_match_2 == 1                                                                                                                                                        
	        || NtupleView->gen_match_2 == 3 ){

        if( fabs(NtupleView->eta_2 ) < 1.46) scaleFactor_tautau = 1.21;
        else if( fabs(NtupleView->eta_2 ) > 1.558) scaleFactor_tautau =  1.38;
      }  
      //run2 SF with bad muon filter for cut-based Loose for tau2
      if( NtupleView->gen_match_2 == 2                                                                                                                                                          
	        || NtupleView->gen_match_2 == 4 ){

        if( fabs(NtupleView->eta_2) < 0.4 ) scaleFactor_tautau =  1.22;
      	else if( fabs(NtupleView->eta_2) < 0.8 ) scaleFactor_tautau =  1.12;
      	else if( fabs(NtupleView->eta_2) < 1.2 ) scaleFactor_tautau =  1.26;
      	else if( fabs(NtupleView->eta_2) < 1.7 ) scaleFactor_tautau =  1.22;
      	else if( fabs(NtupleView->eta_2) < 2.3 ) scaleFactor_tautau =  2.39;
      }

      if( NtupleView->gen_match_1 == 1                                                                                                                                                        
	        || NtupleView->gen_match_1 == 3 ){

        if( fabs(NtupleView->eta_1 ) < 1.46) scaleFactor_tautau *= 1.21;
        else if( fabs(NtupleView->eta_1 ) > 1.558) scaleFactor_tautau *=  1.38;
      }  
      //run2 SF with bad muon filter for cut-based Loose for tau2
      if( NtupleView->gen_match_1 == 2                                                                                                                                                          
	        || NtupleView->gen_match_1 == 4 ){

        if( fabs(NtupleView->eta_1) < 0.4 ) scaleFactor_tautau *=  1.22;
      	else if( fabs(NtupleView->eta_1) < 0.8 ) scaleFactor_tautau *=  1.12;
      	else if( fabs(NtupleView->eta_1) < 1.2 ) scaleFactor_tautau *=  1.26;
      	else if( fabs(NtupleView->eta_1) < 1.7 ) scaleFactor_tautau *=  1.22;
      	else if( fabs(NtupleView->eta_1) < 2.3 ) scaleFactor_tautau *=  2.39;
      }
      return scaleFactor_tautau;

    }
    return 1.0;

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//UGLIEST FUNCTION EVER WRITTEN -> PLEASE SIMPLIFY!!!!!
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CreateHistos::EstimateFF(TString strVar, TString cat, TString extend){

  if( std::find(categories.begin(), categories.end(), cat) == categories.end() ) return;
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
      cout<< tmp << ": " << ratio << endl;
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
      if(cat.Contains("btag") && !cat.Contains("nobtag") ) return 1.01;
      if(cat.Contains("nobtag") ) return 1.14;
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
      if(cat.Contains("btag") && !cat.Contains("nobtag") ) return 1.16;
      if(cat.Contains("nobtag") ) return 1.11;
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
double CreateHistos::getW_mtHL(TString strVar, TString cat, TString sign){
  TString sub = "+" + strVar +"_" + cat;
  if(cat.Contains("btag") && !cat.Contains("nobtag") ) sub = "+" + strVar +"_" + cat+"_loosebtag";
  if(sign == "OS")  return this->GetHistbyName(s_W+ "_MC"+ sub + "+",strVar)->Integral() / this->GetHistbyName(s_W+ "_MC"+ sub+"_wjets_cr+",strVar)->Integral();
  if(sign == "SS")  return this->GetHistbyName(s_W+ "_MC"+ sub + "_qcd_cr+",strVar)->Integral() / this->GetHistbyName(s_W+ "_MC"+ sub+"_wjets_ss_cr+",strVar)->Integral();
}
double CreateHistos::getW_BtagConv(TString strVar, TString cat, TString cr){
  TString sub = "+" + strVar +"_" + cat ;
  return this->GetHistbyName(s_W+ "_MC" + sub + cr + "+",strVar)->Integral() / this->GetHistbyName(s_W+"_MC"+sub + "_loosebtag" + cr + "+",strVar)->Integral();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CreateHistos::EstimateW(TString strVar, TString cat){
  if(cat.Contains("wjets_cr") || cat.Contains("loosebtag") || cat.Contains("wjets_ss_cr") || cat.Contains("qcd_cr") ) return;

  double R_W = this->getW_osss(strVar, cat);
  double R_QCD = this->getQCD_osss(cat);
  double HLExt_OS = this->getW_mtHL(strVar, cat,"OS");
  double HLExt_SS = this->getW_mtHL(strVar, cat,"SS");
  double BConv_SR = 1.;
  double BConv_CR = 1.;



  TString bt = "";
  if(cat.Contains("btag") && !cat.Contains("nobtag")){
    BConv_SR = this->getW_BtagConv(strVar, cat);
    BConv_CR = this->getW_BtagConv(strVar, cat, "_wjets_cr");
    bt = "_loosebtag";
  }
  TString sub = "+" + strVar +"_" + cat;

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


  this->GetHistbyName(s_W+sub+"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_W+"_MC"+sub+"_wjets_ss_cr+",strVar) );
  this->GetHistbyName(s_W+sub+"_wjets_cr+",strVar)->Add( this->GetHistbyName(s_W +"_MC"+sub+"_wjets_cr+",strVar) );
  this->GetHistbyName(s_W +sub +"_qcd_cr+",strVar)->Add( this->GetHistbyName(s_W+ "_MC" +sub +"_qcd_cr+",strVar) );
  this->GetHistbyName(s_W +sub +"+",strVar)->Add( this->GetHistbyName(s_W+ "_MC" +sub +"+",strVar) ); 
  if(channel != "tt"){
    cout << "W numbers " << cat << endl;
    cout << "R_W           "   << R_W << endl;
    cout << "R_QCD         " << R_QCD << endl;
    cout << "HLExt_OS      " << HLExt_OS << endl;
    cout << "HLExt_SS      " << HLExt_SS << endl;
    cout << "BConv_SR      "<< BConv_SR << endl;
    cout << "BConv_CR      "<< BConv_CR << endl;
    cout << "W_SS_CR_norm  "<< wjets_ss_cr_norm << endl;
    cout << "WSS/W         "<< wjets_ss_cr_norm / this->GetHistbyName(s_W +sub +"+",strVar)->Integral() << endl;
    cout << "WSS/W_QCD     "<< wjets_ss_cr_norm / this->GetHistbyName(s_W +sub +"_qcd_cr+",strVar)->Integral() << endl;
    cout << "WSS/WCR       "<< wjets_ss_cr_norm / this->GetHistbyName(s_W+sub+"_wjets_cr+",strVar)->Integral() << endl;
    cout << "WSS/WSS       "<< wjets_ss_cr_norm / this->GetHistbyName(s_W+sub+"_wjets_ss_cr+",strVar)->Integral() << endl;
    cout << "data OS       "<< this->GetHistbyName("data_os_obs"+sub+"_wjets_cr+",strVar)->Integral()  << endl;
    cout << "BG OS         "<< this->GetHistbyName("backgrounds_os"+sub+"_wjets_cr+",strVar)->Integral() << endl;
    cout << "data SS       "<< this->GetHistbyName("data_ss_obs"+sub+"_wjets_ss_cr+",strVar)->Integral() << endl;
    cout << "BG SS         "<< this->GetHistbyName("backgrounds_ss"+sub+"_wjets_ss_cr+",strVar)->Integral() << endl;
    cout << "------" << endl;
  }

  TString w_FakeShape_up="W_CMS_htt_wFakeShape_13TeVUp";
  TString w_FakeShape_down="W_CMS_htt_wFakeShape_13TeVDown";

  this->GetHistbyName(w_FakeShape_up +sub+"+",strVar)->Add( this->GetHistbyName(s_W+ "_MC_fakeShapeUp_" +sub +"+",strVar) );
  this->GetHistbyName(w_FakeShape_down +sub+"+",strVar)->Add( this->GetHistbyName(s_W+ "_MC_fakeShapeDown_" +sub +"+",strVar) );

  if(channel != "tt"){
    this->GetHistbyName(s_W +sub +"+",strVar)->Scale( (wjets_ss_cr_norm * HLExt_OS * R_W* BConv_SR ) / this->GetHistbyName(s_W +sub +"+",strVar)->Integral() );
    this->GetHistbyName(s_W +sub +"_qcd_cr+",strVar)->Scale( (wjets_ss_cr_norm * HLExt_SS* BConv_SR) / this->GetHistbyName(s_W +sub +"_qcd_cr+",strVar)->Integral() );
    this->GetHistbyName(s_W+sub+"_wjets_cr+",strVar)->Scale( (wjets_ss_cr_norm *R_W * BConv_CR) / this->GetHistbyName(s_W+sub+"_wjets_cr+",strVar)->Integral() );
    this->GetHistbyName(s_W+sub+"_wjets_ss_cr+",strVar)->Scale( (wjets_ss_cr_norm * BConv_CR) / this->GetHistbyName(s_W+sub+"_wjets_ss_cr+",strVar)->Integral() );

    this->GetHistbyName(w_FakeShape_up +sub +"+",strVar)->Scale( (wjets_ss_cr_norm * HLExt_OS * R_W* BConv_SR ) / this->GetHistbyName(w_FakeShape_up +sub +"+",strVar)->Integral() );
    this->GetHistbyName(w_FakeShape_down +sub +"+",strVar)->Scale( (wjets_ss_cr_norm * HLExt_OS * R_W* BConv_SR ) / this->GetHistbyName(w_FakeShape_down +sub +"+",strVar)->Integral() );
  }
}

void CreateHistos::EstimateQCD(TString strVar, TString cat){
  if(cat.Contains("wjets_cr") || cat.Contains("loosebtag") || cat.Contains("wjets_ss_cr") || cat.Contains("qcd_cr") ) return;
  TString sub = "+" + strVar +"_" + cat ;

  if(channel != "tt"){
    TString bt = "";
    if(cat.Contains("btag") && !cat.Contains("nobtag")) bt = "_loosebtag";

    double CR_QCD_norm = 1.;

    this->GetHistbyName("QCD" + sub +"_qcd_cr+" ,strVar)->Add( this->GetHistbyName(s_data+sub  + "_qcd_cr+",strVar));
    this->GetHistbyName("QCD" + sub +"_qcd_cr+" ,strVar)->Add( this->GetHistbyName(s_Z+sub  + "_qcd_cr+",strVar), -1);
    this->GetHistbyName("QCD" + sub +"_qcd_cr+" ,strVar)->Add( this->GetHistbyName(s_VV+sub  + "_qcd_cr+",strVar), -1);
    this->GetHistbyName("QCD" + sub +"_qcd_cr+" ,strVar)->Add( this->GetHistbyName(s_TT+sub  + "_qcd_cr+",strVar), -1);
    CR_QCD_norm   = this->GetHistbyName("QCD" + sub +"_qcd_cr+" ,strVar)->Integral();
    CR_QCD_norm  -= this->GetHistbyName(s_W+sub + "_qcd_cr+",strVar)->Integral();

    this->GetHistbyName("QCD" + sub +"_qcd_cr+" ,strVar)->Add( this->GetHistbyName(s_W+ "_MC" +sub   + "_qcd_cr+",strVar), -1);
    this->GetHistbyName("QCD" + sub +"_qcd_cr+" ,strVar)->Scale( CR_QCD_norm / this->GetHistbyName("QCD" + sub +"_qcd_cr+" ,strVar)->Integral() );

    this->GetHistbyName("QCD"+ sub + "+" ,strVar)->Add( this->GetHistbyName("QCD" + sub +"_qcd_cr+" ,strVar) );
    this->GetHistbyName("QCD"+ sub + "+" ,strVar)->Scale( this->getQCD_osss(cat) );

    this->GetHistbyName("QCD" + sub +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_data + sub +"_wjets_ss_cr+",strVar)   );
    this->GetHistbyName("QCD" + sub +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_Z + sub +"_wjets_ss_cr+",strVar), -1 );
    this->GetHistbyName("QCD" + sub +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_VV + sub +"_wjets_ss_cr+",strVar), -1 );
    this->GetHistbyName("QCD" + sub +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_TT + sub +"_wjets_ss_cr+",strVar), -1 );
    CR_QCD_norm   = this->GetHistbyName("QCD" + sub +"_wjets_ss_cr+" ,strVar)->Integral();
    CR_QCD_norm  -= this->GetHistbyName(s_W+sub + "_wjets_ss_cr+",strVar)->Integral();

    this->GetHistbyName("QCD" + sub +"_wjets_ss_cr+",strVar)->Add( this->GetHistbyName(s_W + "_MC" + sub +"_wjets_ss_cr+",strVar), -1 );
    this->GetHistbyName("QCD" + sub +"_wjets_ss_cr+" ,strVar)->Scale( CR_QCD_norm / this->GetHistbyName("QCD" + sub +"_wjets_ss_cr+" ,strVar)->Integral() );

    this->GetHistbyName("QCD" + sub +"_wjets_cr+",strVar)->Add( this->GetHistbyName("QCD" + sub +"_wjets_ss_cr+",strVar) );
    this->GetHistbyName("QCD" + sub +"_wjets_cr+",strVar)->Scale( this->getQCD_osss(cat) );
  }
  else {
    this->GetHistbyName("QCD" + sub +"+" ,strVar)->Add( this->GetHistbyName(s_data+sub  + "_looseTiso+",strVar));
    this->GetHistbyName("QCD" + sub +"+" ,strVar)->Add( this->GetHistbyName(s_Z+sub  + "_looseTiso+",strVar), -1);
    //this->GetHistbyName("QCD" + sub +"+" ,strVar)->Add( this->GetHistbyName(s_EWKZ+sub  + "_looseTiso+",strVar), -1);
    this->GetHistbyName("QCD" + sub +"+" ,strVar)->Add( this->GetHistbyName(s_VV+sub  + "_looseTiso+",strVar), -1);
    this->GetHistbyName("QCD" + sub +"+" ,strVar)->Add( this->GetHistbyName(s_TT+sub  + "_looseTiso+",strVar), -1);
    this->GetHistbyName("QCD" + sub +"+" ,strVar)->Add( this->GetHistbyName(s_W+ "_MC" +sub   + "_looseTiso+",strVar), -1);

    double SS_loose = this->GetHistbyName(s_data+sub  + "_looseTiso_qcd_cr+",strVar)->Integral();
    SS_loose -= this->GetHistbyName(s_Z+sub  + "_looseTiso_qcd_cr+",strVar)->Integral();
    //SS_loose -= this->GetHistbyName(s_EWKZ+sub  + "_looseTiso_qcd_cr+",strVar)->Integral();
    SS_loose -= this->GetHistbyName(s_VV+sub  + "_looseTiso_qcd_cr+",strVar)->Integral();
    SS_loose -= this->GetHistbyName(s_TT+sub  + "_looseTiso_qcd_cr+",strVar)->Integral();
    SS_loose -= this->GetHistbyName(s_W+ "_MC" +sub   + "_looseTiso_qcd_cr+",strVar)->Integral();

    double SS = this->GetHistbyName(s_data+sub  + "_qcd_cr+",strVar)->Integral();
    SS -= this->GetHistbyName(s_Z+sub  + "_qcd_cr+",strVar)->Integral();
    //SS -= this->GetHistbyName(s_EWKZ+sub  + "_qcd_cr+",strVar)->Integral();
    SS -= this->GetHistbyName(s_VV+sub  + "_qcd_cr+",strVar)->Integral();
    SS -= this->GetHistbyName(s_TT+sub  + "_qcd_cr+",strVar)->Integral();
    SS -= this->GetHistbyName(s_W+ "_MC" +sub   + "_qcd_cr+",strVar)->Integral();

    this->GetHistbyName("QCD" + sub +"+" ,strVar)->Scale( SS / SS_loose );    
  }


}

void CreateHistos::createInclusive(TString strVar, TString cat){
  if(cat.Contains("wjets_cr") || cat.Contains("loosebtag") || cat.Contains("wjets_ss_cr") || cat.Contains("qcd_cr")  || cat.Contains("looseTiso") ) return;
  TString sub = "+" + strVar +"_" + cat + "+";
  TString name;
  for (auto const& Hname : histograms){
    name = Hname.first;
    if( name.Contains(sub) && !name.Contains(s_jetFakes+"_"+s_norm) ){
      name.ReplaceAll(sub,"");
      this->GetHistbyName(name + "+" + strVar + "_inclusive+", strVar)->Add(this->GetHistbyName(name + sub, strVar) );
    }
  }

}

void CreateHistos::writeHistos( TString channel, vector<TString> cats, vector<TString> vars ){

  stringstream outfile_name;
  TString sub;
  TString tmp;
  TString subDC="";
  if(runOption != "nom" && runOption != "nlo") subDC="."+runOption;

  for(auto var : vars){
    outfile_name << "histos/"<<folder << "/htt_" << channel << ".inputs-mssm-13TeV-"<<var<<subDC<<".root";
    //outfile_name << "histos/htt_" << channel+"_"+UseIso << ".inputs-mssm-13TeV-"<<var<<subDC<<".root";
    outfile = new TFile(outfile_name.str().c_str(), "RECREATE") ;

    for(auto cat : cats){
      //if(cat.Contains("loosebtag") ) continue;
      if(!keepDebugHistos
          && ( cat.Contains("loosebtag")
               || ( cat.Contains("loose") 
                    && !cat.Contains("loosemt")
                    && !cat.Contains("looseiso")
                  )
               || ( channel == "tt"
                    && cat.Contains("qcd_cr")
                  )
             )   
        ) continue;
      outfile->mkdir(channel +"_"+ cat );
      outfile->cd(channel +"_"+ cat); 
      sub = "+" + var +"_" + cat + "+";



      for (auto const& name : histograms){

        if(name.first.Contains(sub) ){

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
                  || name.first.Contains("_rest")               
                  )
              && !name.first.Contains(s_ggH)
              && !name.first.Contains(s_bbH)
             ) continue;

          tmp = name.first;
          tmp.ReplaceAll(sub, "");
          tmp.ReplaceAll(s_jecUp,s_CMSjecScale+s_13TeVUp);
          tmp.ReplaceAll(s_jecDown,s_CMSjecScale+s_13TeVDown);
          tmp.ReplaceAll(s_jetToTauFakeUp,s_CMSjetToTauFake+s_13TeVUp);
          tmp.ReplaceAll(s_jetToTauFakeDown,s_CMSjetToTauFake+s_13TeVDown);
          histograms.at( name.first )->SetName(tmp);
          this->resetZeroBins(histograms.at( name.first ));
          //if(histograms.at( name.first )->GetEntries() == 0 ) cout << "Warning: " << name.first << " not filled" << endl;
          histograms.at( name.first )->Write(tmp, TObject::kWriteDelete);
          

        }
      }
    }
    outfile->Close();
    outfile_name.str("");
  }
    
}

int CreateHistos::getFiletype(TString fileName){

  vector<int> index;

  index.push_back( this->isZFile(fileName) );
  index.push_back( this->isSignalFile(fileName) );
  index.push_back( this->isTTFile(fileName) );
  index.push_back( this->isWFile(fileName) );
  index.push_back( this->isVVFile(fileName) );
  index.push_back( this->isEWKZFile(fileName) );

  for(auto ind : index){
    if(ind != 0) return ind;
  }
  return 0;
}

int CreateHistos::isZFile(TString fileName){
  if(fileName == s_Z) return 1;
  if(fileName == s_ZtauUp) return 1;
  if(fileName == s_ZtauDown) return 1;
  if(fileName == s_Z+"T0Up") return 1;
  if(fileName == s_Z+"T0Down") return 1;
  if(fileName == s_Z+"T1Up") return 1;
  if(fileName == s_Z+"T1Down") return 1;
  if(fileName == s_Z+"T10Up") return 1;
  if(fileName == s_Z+"T10Down") return 1;
  if(fileName == s_ZjecUp) return 1;
  if(fileName == s_ZjecDown) return 1;
  if(fileName == s_ZE0Up) return 1;
  if(fileName == s_ZE0Down) return 1;
  if(fileName == s_ZE1Up) return 1;
  if(fileName == s_ZE1Down) return 1;

  return 0;
}



int CreateHistos::isSignalFile(TString fileName){

    if(fileName == s_ggH) return 2;
    if(fileName == s_ggHtauUp) return 2;
    if(fileName == s_ggHtauDown) return 2;
    if(fileName == s_ggH+"T0Up") return 2;
    if(fileName == s_ggH+"T0Down") return 2;
    if(fileName == s_ggH+"T1Up") return 2;
    if(fileName == s_ggH+"T1Down") return 2;
    if(fileName == s_ggH+"T10Up") return 2;
    if(fileName == s_ggH+"T10Down") return 2;
    if(fileName == s_ggHjecUp) return 2;
    if(fileName == s_ggHjecDown) return 2;
    if(fileName == s_bbH) return 2;
    if(fileName == s_bbHtauUp) return 2;
    if(fileName == s_bbHtauDown) return 2;
    if(fileName == s_bbH+"T0Up") return 2;
    if(fileName == s_bbH+"T0Down") return 2;
    if(fileName == s_bbH+"T1Up") return 2;
    if(fileName == s_bbH+"T1Down") return 2;
    if(fileName == s_bbH+"T10Up") return 2;
    if(fileName == s_bbH+"T10Down") return 2;
    if(fileName == s_bbHjecUp) return 2;
    if(fileName == s_bbHjecDown) return 2;

    if(fileName == s_SMggH ) return 2;
    if(fileName == s_SMvbf ) return 2;
    if(fileName == s_SMWminus ) return 2;
    if(fileName == s_SMWplus ) return 2;
    if(fileName == s_SMZH ) return 2;

    if(fileName == s_SMggHtauUp ) return 2;
    if(fileName == s_SMvbftauUp ) return 2;
    if(fileName == s_SMWminustauUp ) return 2;
    if(fileName == s_SMWplustauUp ) return 2;
    if(fileName == s_SMZHtauUp ) return 2;
    if(fileName == s_SMggHtauDown ) return 2;
    if(fileName == s_SMvbftauDown ) return 2;
    if(fileName == s_SMWminustauDown ) return 2;
    if(fileName == s_SMWplustauDown ) return 2;
    if(fileName == s_SMZHtauDown ) return 2;

    if(fileName == s_SMggH+"T0Up") return 2;
    if(fileName == s_SMggH+"T0Down") return 2;
    if(fileName == s_SMggH+"T1Up") return 2;
    if(fileName == s_SMggH+"T1Down") return 2;
    if(fileName == s_SMggH+"T10Up") return 2;
    if(fileName == s_SMggH+"T10Down") return 2;

    if(fileName == s_SMvbf+"T0Up") return 2;
    if(fileName == s_SMvbf+"T0Down") return 2;
    if(fileName == s_SMvbf+"T1Up") return 2;
    if(fileName == s_SMvbf+"T1Down") return 2;
    if(fileName == s_SMvbf+"T10Up") return 2;
    if(fileName == s_SMvbf+"T10Down") return 2;

    if(fileName == s_SMWminus+"T0Up") return 2;
    if(fileName == s_SMWminus+"T0Down") return 2;
    if(fileName == s_SMWminus+"T1Up") return 2;
    if(fileName == s_SMWminus+"T1Down") return 2;
    if(fileName == s_SMWminus+"T10Up") return 2;
    if(fileName == s_SMWminus+"T10Down") return 2;

    if(fileName == s_SMWplus+"T0Up") return 2;
    if(fileName == s_SMWplus+"T0Down") return 2;
    if(fileName == s_SMWplus+"T1Up") return 2;
    if(fileName == s_SMWplus+"T1Down") return 2;
    if(fileName == s_SMWplus+"T10Up") return 2;
    if(fileName == s_SMWplus+"T10Down") return 2;

    if(fileName == s_SMZH+"T0Up") return 2;
    if(fileName == s_SMZH+"T0Down") return 2;
    if(fileName == s_SMZH+"T1Up") return 2;
    if(fileName == s_SMZH+"T1Down") return 2;
    if(fileName == s_SMZH+"T10Up") return 2;
    if(fileName == s_SMZH+"T10Down") return 2;

    if(fileName == s_SMggHjecUp ) return 2;
    if(fileName == s_SMvbfjecUp ) return 2;
    if(fileName == s_SMWminusjecUp ) return 2;
    if(fileName == s_SMWplusjecUp ) return 2;
    if(fileName == s_SMZHjecUp ) return 2;
    if(fileName == s_SMggHjecDown ) return 2;
    if(fileName == s_SMvbfjecDown ) return 2;
    if(fileName == s_SMWminusjecDown ) return 2;
    if(fileName == s_SMWplusjecDown ) return 2;
    if(fileName == s_SMZHjecDown ) return 2;

  return 0;
}

int CreateHistos::isTTFile(TString fileName){
  if(fileName == s_TT) return 3;
  if(fileName == s_TTtauUp) return 3;
  if(fileName == s_TTtauDown) return 3;
  if(fileName == s_TT+"T0Up") return 3;
  if(fileName == s_TT+"T0Down") return 3;
  if(fileName == s_TT+"T1Up") return 3;
  if(fileName == s_TT+"T1Down") return 3;
  if(fileName == s_TT+"T10Up") return 3;
  if(fileName == s_TT+"T10Down") return 3;
  if(fileName == s_TTjecUp) return 3;
  if(fileName == s_TTjecDown) return 3;

  return 0;  
}

int CreateHistos::isWFile(TString fileName){
  if(fileName == s_W) return 4;
  if(fileName == s_WjecUp) return 4;
  if(fileName == s_WjecDown) return 4;

  return 0;
}

int CreateHistos::isVVFile(TString fileName){
  if(fileName == s_VV) return 5;
  if(fileName == s_VVtauUp) return 5;
  if(fileName == s_VVtauDown) return 5;
  if(fileName == s_VV+"T0Up") return 5;
  if(fileName == s_VV+"T0Down") return 5;
  if(fileName == s_VV+"T1Up") return 5;
  if(fileName == s_VV+"T1Down") return 5;
  if(fileName == s_VV+"T10Up") return 5;
  if(fileName == s_VV+"T10Down") return 5;
  if(fileName == s_VVjecUp) return 5;
  if(fileName == s_VVjecDown) return 5;

  return 0;
}

int CreateHistos::isEWKZFile(TString fileName){
  if(fileName == s_EWKZ) return 6;
  if(fileName == s_EWKZtauUp) return 6;
  if(fileName == s_EWKZtauDown) return 6;
  if(fileName == s_EWKZjecUp) return 6;
  if(fileName == s_EWKZjecDown) return 6;

  return 0;
}
