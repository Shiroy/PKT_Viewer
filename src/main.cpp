#include <iostream>
#include "pktfile.h"

void usage()
{
    std::cout << "Usage : PKT filename" << std::endl << "It will generate a new filename with human readable informations." << std::endl;
}

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        usage();
    }

    PKTFile file(argv[1]);

    if(!file.Open())
        return 1;

    file.ReadHeader();

    return 0;
}
