#ifndef CCONV_H
#define CCONV_H

#include "cvar.h"

class CConv
{
public:
    CConv();
    static int      ToInt(STR s);
    static float    ToFloat(STR s);
    static STR      ToStr(int v);
    static STR      ToStr(float v, int len=6);
};

#endif // CCONV_H
