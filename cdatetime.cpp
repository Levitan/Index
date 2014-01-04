#include "cdatetime.h"

CDateTime::CDateTime()
{
}

time_t CDateTime::Now(){
    return time(NULL);
}

STR CDateTime::Date(){
    return dtf("%d.%m.%Y");
}

STR CDateTime::Time(){
    return dtf("%H:%M:%S");
}

STR CDateTime::dtf(STR fmt, time_t t){
    if(fmt == "") { fmt = "%d.%m.%Y %H:%M:%S"; }
    if(t == 0) { t = Now(); }
    struct tm *lt = localtime(&t);
    char buff[80];
    strftime(buff, 80, fmt.c_str(), lt);
    return STR(buff);
}
