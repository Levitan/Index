#ifndef CDATETIME_H
#define CDATETIME_H

#include <time.h>
#include "cvar.h"

class CDateTime
{
public:
    CDateTime();
    static time_t Now();
    static STR Date();
    static STR Time();
    static STR dtf(STR fmt = "", time_t t = 0);
};

#endif // CDATETIME_H
