#include "cresponse.h"

CResponse::CResponse(){
    header = new CVar;
    header->setSplits(": ");
    header->add("Content-type: text/html; charset-utf-8");
    sending = false;

}

CResponse::~CResponse(){
    delete header;
}

void CResponse::print(STR text){
    if(!sending){
        sendHeader();
        sending = true;
    }
    std::cout << text;
}

bool CResponse::setHeader(STR text){
    VAR var;
    header->setVar(&var, text);
    if(var.Name== "Set-Cookie"){
        header->add(text);
    }
    else{
        header->rewriteValue(text);
    }
    return !sending;
}

void CResponse::delCookie(STR name){
    setCookie(name, "", -(60*60*24));
}

void CResponse::setCookie(STR name, STR value, int seconds, STR path, STR domain){
    STR res = "Set-Cookie: "+name + "=" + value;
    if(seconds != 1)
        res += "; expires="+gmtTime(seconds);
    if(path != "")
        res += "; path="+path;
    if(domain != "")
        res += "; domain="+domain;
    setHeader(res);
}

STR CResponse::gmtTime(int seconds){
    time_t t;
    time(&t);
    t += seconds;
    struct tm *gmt = gmtime(&t);
    char buff[80];
    strftime(buff, 80, "%a, %d %b %Y %H:%M:%S GMT", gmt);
    return STR(buff);
}

void CResponse::sendHeader(){
    std::cout << header->getData() << "\r\n";
}

