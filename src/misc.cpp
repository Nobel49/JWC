#include "misc.hpp"



double compression_ratio(unsigned long long inFileSize, unsigned long long compressedFileSize)
{

    return ((long long )(inFileSize - compressedFileSize) / (double)inFileSize) * 100;
}

unsigned long long get_file_size(std::string file_name)
{
    struct stat file_stats;
    unsigned long long res = stat(file_name.c_str(), &file_stats);
    return file_stats.st_size;
}