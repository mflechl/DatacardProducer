#include "interface/CreateHistos.h"

#include <iostream>
#include <string>

void runFile(TString isTest, TString ch) {

    CreateHistos *Analyzer = new CreateHistos(isTest, ch);
    Analyzer->run();
    delete Analyzer;
  
}
#ifndef __CINT__
int main(int argc, char* argv[]) {
	if(argc == 3){
		runFile(argv[1],argv[2]);
	}
	else{
		cout << "Wrong run parameters" << endl;
	}
}
#endif
