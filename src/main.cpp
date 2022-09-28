#include <iostream>

#include "misc.hpp"
#include "algo/LZ77.hpp"


void print_help(){
    std::cerr<<"Usage: jwc [OPTIONS] [input file] [output file]"<<std::endl;
    std::cerr<<"       jwc -t [input file to test the program]"<<std::endl<<std::endl;

    std::cerr << "Options:" << std::endl;
    std::cerr<<"\t -c    compress the input file and save it in output file."<<std::endl;
    std::cerr<<"\t -d    decompress the input file and save it in output file."<<std::endl;
  
}



int main(int argc,char* argv[]){

    if (argc < 3)
    {
        print_help();
        exit(1);
    }

    std::string flag = argv[1];
    if (flag == "-c")
    {

        std::string inFilePath = argv[2], compressedFilePath = argv[3];
        compress(inFilePath, compressedFilePath);

        unsigned long long inFileSize = get_file_size(inFilePath);
        unsigned long long compressedFileSize = get_file_size(compressedFilePath);

        std::cout << "Compression Ratio : " << compression_ratio(inFileSize, compressedFileSize) << std::endl;
    }
    else if (flag == "-d")
    {

        std::string compressedFilePath = argv[2], deCompressedFilePath = argv[3];
        decompress(compressedFilePath, deCompressedFilePath);

        unsigned long long compressedFileSize = get_file_size(compressedFilePath);
        unsigned long long deCompressedFileSize = get_file_size(deCompressedFilePath);

        std::cout << "Decompressed File successfully" << std::endl;
    }
    else if (flag == "-t")
    {

        std::string inFilePath = argv[2];

        std::cout << "Starting Compression ..." << std::endl;
        std::cout << "It may take some time..." << std::endl;
        compress(inFilePath, "Compressed-data.jwc");
        std::cout << "Compression Finished !!!" << std::endl
             << std::endl;

        std::cout << "Starting Decompression ..." << std::endl;
        decompress("Compressed-data.jwc", "Decompressed-data.txt");
        std::cout << "Decompression Finished !!!" << std::endl
             << std::endl;
        ;

        unsigned long long initialFileSize = get_file_size(inFilePath);
        unsigned long long compressedFileSize = get_file_size("Compressed-data.jwc");
        unsigned long long deCompressedFileSize = get_file_size("Decompressed-data.txt");

        std::cout << "Input File Size [Bytes] : " << initialFileSize << std::endl
             << "Compressed File Size [Bytes] : "<<compressedFileSize<<std::endl
             << "Decompressed File Size [Bytes] : " << deCompressedFileSize << std::endl
             << std::endl;

        if (initialFileSize == deCompressedFileSize)
        {
            std::cout << "Compression Ratio : " << compression_ratio(initialFileSize, compressedFileSize) << "%" << std::endl
                 << std::endl;

            std::cout << "Byte Size of Input File and Decompressed File match..." << std::endl;
            std::cout << "Successful Compression / Decompression." << std::endl;
        }
        else
        {
            std::cout << "Byte Size of Input File and Decompressed File DO NOT match." << std::endl;
            std::cout << "Possible error in Compression / Decompression" << std::endl;
        }
    }else{
        print_help();
    }

    return 0;
}