#include "pktfile.h"
#include <fstream>
#include <iostream>

PKTFile::PKTFile(std::string filename)
{
    m_filename = filename;
}

bool PKTFile::Open(std::string filename)
{
    if(!filename.empty())
        SetFilename(filename);

    std::ifstream file(GetFilename().c_str());

    if(!file)
    {
        std::cout << "Impossible d'ouvrir le fichier : " << GetFilename() << std::endl;
        return false;
    }

    return true;
}
