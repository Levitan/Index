#ifndef CCRYPT_H
#define CCRYPT_H

#include "cvar.h"

class CCrypt
{
public:
    CCrypt();
    static STR md5(STR value);
    static STR genStr();
};

#endif // CCRYPT_H
