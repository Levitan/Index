#ifndef CRESPONSE_H
#define CRESPONSE_H

#include <time.h>
#include "cvar.h"

class CResponse
{
public:
    CResponse();
    ~CResponse();
    void print(STR text);
    bool setHeader(STR text);
    void delCookie(STR name);
    void setCookie(STR name, STR value, int seconds=1, STR path="", STR domain="");
    STR gmtTime(int seconds);

private:
    CVar *header;
    bool sending;
    void sendHeader();
};

#endif // CRESPONSE_H
