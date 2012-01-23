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

    if(m_file)
        m_file.close();

    m_file.open(GetFilename().c_str());

    if(!m_file)
    {
        std::cout << "Impossible d'ouvrir le fichier : " << GetFilename() << std::endl;
        return false;
    }

    return true;
}

bool PKTFile::ReadHeader()
{
    if(!m_file)
        return false;

    m_file.get(m_header.signature, 4);
    std::cout << "Header : " << m_header.signature << std::endl;

    m_file.get(m_header.version, 3);
    std::cout << "Version : " << GetPKTVersion() << std::endl;

    m_file.get(m_header.snifferID);
    std::cout << "Sniffer ID : " << GetSnifferID() << std::endl;

    ReadBuild();
    std::cout << "Build : " << GetBuild() << std::endl;

    m_file.get(m_header.locale, 5);
    std::cout << "Locale : " << GetLocale() << std::endl;

    m_file.get(m_header.sessionKey, 41);
    std::cout << "Session key : " << m_header.sessionKey << std::endl;

    ReadInvertU32(m_header.date);
    std::cout << "Date : " << m_header.date << std::endl;

    ReadInvertU32(m_header.startTickCount);
    std::cout << "Start tick count : " << m_header.startTickCount << std::endl;

    ReadInvertU32(m_header.optionalHearderLength);
    std::cout << "Optionnal header length : " << m_header.optionalHearderLength << std::endl;

    return true;
}

int PKTFile::GetPKTVersion()
{
    return m_header.version[0] | m_header.version[1];
}

int PKTFile::GetSnifferID()
{
    return m_header.snifferID;
}

unsigned int PKTFile::GetBuild()
{
    return m_header.build;
}

void PKTFile::ReadBuild()
{
    ReadInvertU32(m_header.build);
}

char *PKTFile::GetLocale()
{
    return m_header.locale;
}

void PKTFile::ReadInvertU32(unsigned int &result)
{
    unsigned char buffer[4];
    result = 0;

    for(int i = 0 ; i < 4 ; i++)
    {
        m_file >> buffer[i];
    }

    for(int i = 3 ; i >=0 ; i--)
    {
        result |= buffer[i] << (i*8);
    }
}
