#include "interface/CreateHistos.h"

#include <iostream>
#include <string>

void runFile(TString isTest) {

	
    CreateHistos *Analyzer = new CreateHistos(isTest);

    Analyzer->run();

    delete Analyzer;
  

}
#ifndef __CINT__
int main(int argc, char* argv[]) {
  runFile(argc == 2 ? argv[1] : "" );

      
}
#endif
