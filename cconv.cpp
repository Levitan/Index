#include <stdlib.h>
#include "cconv.h"

CConv::CConv()
{
}

int CConv::ToInt(STR s){
    return atoi(s.c_str());
}

float CConv::ToFloat(STR s){
    return atof(s.c_str());
}

STR CConv::ToStr(int v){
    char buff[12];
    sprintf(buff, "%d", v);
    return STR(buff);
}

STR CConv::ToStr(float v, int len){
    STR format = "%17."+ToStr(len)+"lf";
    char buff[32];
    sprintf(buff, format.c_str(), v);
    return STR(buff);
}
