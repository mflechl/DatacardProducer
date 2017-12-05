CXX=g++  -std=c++11
INCDIR=.
ROOTINC=$(shell root-config --incdir)
ROOTLIB=$(shell root-config --libs ) -lTreePlayer

OBJ=GlobalClass.o FFCalculator.o SelectionAnalyzer.o CreateHistos.o ntuple.o
FF=../tmp/slc6_amd64_gcc530/src/HTTutilities/Jet2TauFakes/src/HTTutilitiesJet2TauFakes/libHTTutilitiesJet2TauFakes.so
GLOBAL_HEADERS=interface/FakeFactorConfig.h interface/NameStrings.h Settings.h interface/json.hpp

all: $(OBJ) makeHTTDatacards

%.o: src/%.cc interface/%.h
	$(CXX) -I$(INCDIR) -I$(ROOTINC) $(ROOTLIB) -fpic -c $<

CreateHistos.o: src/CreateHistos.cc interface/CreateHistos.h interface/SelectionAnalyzer.h interface/FFCalculator.h interface/GlobalClass.h $(GLOBAL_HEADERS)
	$(CXX) -I$(INCDIR) -I$(ROOTINC) $(ROOTLIB) -fpic -c $<

SelectionAnalyzer.o: src/SelectionAnalyzer.cc interface/SelectionAnalyzer.h interface/FFCalculator.h interface/GlobalClass.h $(GLOBAL_HEADERS)
	$(CXX) -I$(INCDIR) -I$(ROOTINC) $(ROOTLIB) -fpic -c $<

FFCalculator.o: src/FFCalculator.cc interface/FFCalculator.h interface/GlobalClass.h $(GLOBAL_HEADERS)
	$(CXX) -I$(INCDIR) -I$(ROOTINC) $(ROOTLIB) -fpic -c $<

GlobalClass.o: src/GlobalClass.cc interface/GlobalClass.h ntuple.C ntuple.h $(GLOBAL_HEADERS)
	$(CXX) -I$(INCDIR) -I$(ROOTINC) $(ROOTLIB) -fpic -c $<

ntuple.o: ntuple.C ntuple.h
	$(CXX) -I$(INCDIR) -I$(ROOTINC) $(ROOTLIB) -c ntuple.C

makeHTTDatacards: runFile.cc $(OBJ) $(FF)
	$(CXX) -I$(INCDIR) -I$(ROOTINC) $(ROOTLIB) -o $@ $(OBJ) $(FF) runFile.cc


clean:
	rm -f *.o makeHTTDatacards




Settings.h:#include "interface/NameStrings.h"