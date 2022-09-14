#pragma once

//includes
#include <iostream>
#include <string>
#include <tuple>
#include <bitset>
#include <fstream>

//some magic constants
#define SIZE_SB 512
#define SIZE_LB 16
#define MIN_BYTE_COMPRESS 5


//function prototypes.
std::pair<int, int> longest_possible_substr(std::string &searchBuffer, std::string &lookaheadBuffer);
void compress(std::string &inputData);
void LZ77(std::string fileName,std::string outputFile);

