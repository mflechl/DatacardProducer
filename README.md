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
#test run with sh run.sh test