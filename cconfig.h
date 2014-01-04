#ifndef CCONFIG_H
#define CCONFIG_H

#include "cvar.h"

class CConfig : public CVar
{
public:
    CConfig();
    ~CConfig();
    int     getInt      (STR name);
    float   getFloat    (STR name);
    STR     getString   (STR name);

    bool    setInt      (STR name, int value);
    bool    setFloat    (STR name, float value);
    bool    setString   (STR name, STR value);
//================================================//
    void Open(STR FileName);
    void Delete(STR name);

private:
    CVar *conf;
    STR FN;
};

#endif // CCONFIG_H
