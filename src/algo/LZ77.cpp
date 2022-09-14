/*
    this library currently returns strings as output rather than actual binary bits
    so the compresed output may take more space than the input.
    Also, only compression is implemented till now
*/

#include "LZ77.hpp"

std::pair<int, int> longest_possible_substr(std::string &searchBuffer, std::string &lookaheadBuffer)
{

    uint16_t  _SB_SIZE = searchBuffer.size();
    uint8_t _LB_SIZE = lookaheadBuffer.size();

    uint16_t global_best = 0, pos = 0;

    for (int i = _SB_SIZE; i >= 0; i--)
    {
        int local_best = 0;
        //checking index bounds
        while (searchBuffer[i + local_best] == lookaheadBuffer[local_best] && local_best < _LB_SIZE && i + local_best < _SB_SIZE)
            local_best++;

        //update the best value
        if (local_best > global_best)
        {
            global_best = local_best;
            pos = i;
        }
        if (global_best == _LB_SIZE)
            break;
    }

    //in case that the pattern found was not long enough or if no match wat not found at all.
    if (global_best < MIN_BYTE_COMPRESS)
        return (std::make_pair(0, 0));

    return (std::make_pair(_SB_SIZE - pos, global_best));
}


void compress(std::string &inputData,std::string outputFile)
{
    // for testing purposes. Opening the output file
    std::ofstream OUTPUT_FILE;
    OUTPUT_FILE.open(outputFile, std::ios::binary);

    if (!OUTPUT_FILE)
    {
        std::cerr << "FILE ERROR : Couldn't Open Output File !!!" << std::endl;
        exit(-1);
    }

    std::cout << "Started writing to file !!!" << std::endl;

    int i = 0;

    while (i < inputData.size())
    {
        std::string compressedData = "";

        std::string searchBuf = i >= SIZE_SB ? inputData.substr(i - SIZE_SB, SIZE_SB) : inputData.substr(0, i);
        std::string laBuf = inputData.substr(i, std::min(SIZE_LB, (int)inputData.size() - i));



        std::pair<int, int> result = longest_possible_substr(searchBuf, laBuf);

        if (result.second == 0)
        {

            if (inputData[i] == '\n')
                OUTPUT_FILE << "\\n";

            else if (inputData[i] == '\r')
                OUTPUT_FILE << "\\r";

            else
                OUTPUT_FILE << inputData[i];

            i++;
        }

        else
        {
            i += result.second;
            OUTPUT_FILE << "<" << result.first << "," << result.second << ">";
        }
    }

    std::cout<<"Successfully written to file !!!"<<std::endl;
    OUTPUT_FILE.close();
}


void LZ77(std::string fileName,std::string outputFile)
{
    std::ifstream FILE_INPUT;

    FILE_INPUT.open(fileName, std::ios::in | std::ios::binary);

    if (!FILE_INPUT)
    {
        std::cerr << "FILE ERROR : Couldn't Open Input File !!!" << std::endl;
        exit(-1);
    }


    std::string data;

    // Finding the file size and moving ifstream data to std::string
    FILE_INPUT.seekg(0, std::ios::end);
    data.resize(FILE_INPUT.tellg());
    FILE_INPUT.seekg(0, std::ios::beg);
    FILE_INPUT.read(&data[0], data.size());
    FILE_INPUT.close();

    // debug/misc info
    std::cout << "File Size is : " << data.size() << std::endl;

    compress(data,outputFile);
}