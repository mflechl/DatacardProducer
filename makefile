CXX=g++  -std=c++11
INCDIR=.
ROOTINC=$(shell root-config --incdir)
ROOTLIB=$(shell root-config --libs)

all:  GlobalClass.o FFCalculator.o SelectionAnalyzer.o CreateHistos.o ntuple.o makeHTTDatacards

%.o: src/%.cc
	$(CXX) -I$(INCDIR) -I$(ROOTINC) $(ROOTLIB) -lRooFitCore -lMathMore -fpic -c $<

ntuple.o: ntuple.C
	$(CXX) -I$(INCDIR) -I$(ROOTINC) $(ROOTLIB) -lRooFitCore -lMathMore -c ntuple.C

makeHTTDatacards: runFile.cc
	$(CXX) -I$(INCDIR) -I$(ROOTINC) $(ROOTLIB) -lRooFitCore -lMathMore -o $@ ntuple.o  GlobalClass.o CreateHistos.o FFCalculator.o SelectionAnalyzer.o  libHTTutilitiesJet2TauFakes.so runFile.cc


clean:
	rm *.o makeHTTDatacards
