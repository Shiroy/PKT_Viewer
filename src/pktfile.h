#ifndef PKT_H
#define PKT_h

#include <string>

struct PKT_Header
{
    char signature[3]; // 'PKT'
    char version[3]; //ex : 0x00, 0x03
    char snifferID;
    unsigned long buid; //ex : 13623
    char locale[4]; //ex : "frFR"
    char sessionKey[40];
    unsigned long optionalHearderLength;
};

class PKTFile
{
    public:
    PKTFile(std::string filename = std::string());

    bool Open(std::string filename = std::string());

    void SetFilename(std::string filename){m_filename = filename;}
    std::string GetFilename(){return m_filename;}



    private:

    std::string m_filename;
};

#endif
