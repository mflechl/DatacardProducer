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
General configurations are given here. This includes the build of the FakeFactor File, version and production of the ntuples, variables to produce datacards with and some flags for debugging.
To override some of the given Parameters from the steering script three defines are included.

-   **APPLY_MT_CUT**  
    Takes 0 or 1 as argument. Is used to forcefully enable or disable the mt cut. Necessary e.g. to produce mt plots in et and mt channel.

-   **CHANNEL**  
    Overrides the channel given by the steering skript.   
    **WARNING** If option "all" is given to the steering script all datacards are produced with the same channel. 
    
-   **USE_CONST_CAT**
    
    Uses the categories given in the Settings file. 

**steerDatacardProducer.py**

Compiles the code and runs with the configuration given in Settings.h.
Two additional flags can be set:
-   **-c**  
    Produces a datacard with the given channel [mt, et, tt]. A full set of datacards is produced when option "all" is given.

-   **-t**  
    Runs over all input samples but only reads 10000 events from each. Usefull to test availability of ntuples.

-   **-m**  
    Creates a minimal datacard without the systematic templates. Usefull for the first synchronisation steps.


Further information can be found here: https://wiki.hephy.at/index.php/HiggsSampleProduction