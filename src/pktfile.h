#ifndef PKT_H
#define PKT_h

#include <string>
#include <fstream>

struct PKT_Header
{
    char signature[3]; // 'PKT'
    char version[2]; //ex : 0x01, 0x03
    char snifferID;
    unsigned int build; //ex : 13623
    char locale[4]; //ex : "frFR"
    char sessionKey[40];
    unsigned int date;
    unsigned int startTickCount;
    unsigned int optionalHearderLength;
};

class PKTFile
{
    public:
    PKTFile(std::string filename = std::string());

    bool Open(std::string filename = std::string());

    void SetFilename(std::string filename){m_filename = filename;}
    std::string GetFilename(){return m_filename;}

    bool ReadHeader();
    int GetPKTVersion();
    int GetSnifferID();
    unsigned int GetBuild();
    char *GetLocale();

    private:

    void ReadBuild();
    void ReadInvertU32(unsigned int &var);

    std::string m_filename;
    std::ifstream m_file;

    PKT_Header m_header;
};

#endif
