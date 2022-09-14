#include <iostream>
#include <string>

// #include "writeFile.hpp"
#include "algo/LZ77.hpp"


int main(int argc,char* argv[]){

    if(argc<3){
        std::cerr<<"Please enter the input and output file as program arguments !!!"<<std::endl;
        std::cerr << "Exiting Program !!! " << std::endl;
        exit(1);
    }

    std::string inFile = argv[1], outFile = argv[2];

    
    //testing LZ77
    LZ77(inFile,outFile);


    return 0;
}