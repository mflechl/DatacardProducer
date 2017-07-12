## Setup

    cmsrel CMSSW_XXX  
    cd CMSSW_XXX/src/  
    cmsenv  
    git clone https://github.com/CMS-HTT/Jet2TauFakes.git HTTutilities/Jet2TauFakes  
    mkdir HTTutilities/Jet2TauFakes/data/  
    cp -r /afs/cern.ch/user/j/jbrandst/public/Htautau/FakeRate/2016/20170228/* HTTutilities/Jet2TauFakes/data/  
    scram b -j 8  
    git init  
    git remote add origin git@github.com:mflechl/DatacardProducer.git  
    git checkout -b master/SM/MSSM  
    git pull origin master/SM/MSSM  

## Usage

**Settings.h**

Is used to define channel, FF version, ntuple version and production as well as the variables to run.
Depending on the analysis some additional settings such es the FF isolation or the application of an mt cut
can be given here.

**steerDatacardProducer.py**

Compiles the code and runs with the configuration given in Settings.h.
Two additional flags can be set:

-   **-t**

    Runs over all input samples but only reads 10000 events from each. Usefull to test availability of ntuples.

-   **-m**

    Creates a minimal datacard without the systematic templates. Usefull for the first synchronisation steps.




Further information can be found here: https://wiki.hephy.at/index.php/HiggsSampleProduction