## Setup

    cmsrel CMSSW_8_0_25  
    cd CMSSW_8_0_25/src/  
    cmsenv  
    git clone https://github.com/CMS-HTT/Jet2TauFakes.git HTTutilities/Jet2TauFakes  
    mkdir HTTutilities/Jet2TauFakes/data/  
    cp -r /afs/cern.ch/user/j/jbrandst/public/FFforMSSM/20170628_*/* HTTutilities/Jet2TauFakes/data/  
    scram b -j 8
    mkdir histos
    mkdir histos/mt
    mkdir histos/et
    mkdir histos/tt
    git init  
    git remote add origin git@github.com:mflechl/DatacardProducer.git  
    git checkout -b MSSM  
    git pull origin MSSM  

## Usage

**JSON config files**
-   **config/Analysis.json**     
    All non-boolean analysis cuts should be defined here. Additionally, the version of the Fake Faktor input files 
    and  the luminosity (may be different for each channel) are defined here.

-   **config/Binning.json** 
    Variable or fixed binning for any variable used to produced datacards with is defined here

-   **config/Datasets.json**    
    All information concerning the samples to process are given here

**Settings.h**  
General configurations and debug options are given here. Most important option is the vector of variables to produce datacards with.

**steerDatacardProducer.py**

Compiles the code and runs with the configuration given in Settings.h and the JSON-files. 

-   Channel is specified with option [-c].  
    Default value is "mt". To run over all channels simultaneously use "all"

-   Produce datacards using NLO bbH with option [-n].   

-   Minimal datacard is produced with option [-m].  
    Produces a datacard for the specified channel and the variables given in Settings.h.
    **Only creates nominal templates**.

-   Test availability of sample with option [-t].   
    Runs over 10000 events of each sample.


