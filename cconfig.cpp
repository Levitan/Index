#include <stdlib.h>
#include "cconfig.h"
#include "cconv.h"

CConfig::CConfig()
{
    conf = new CVar();
}

CConfig::~CConfig(){
    delete conf;
}

int CConfig::getInt(STR name){
    return CConv::ToInt(conf->Value(name));
}

float CConfig::getFloat(STR name){
    return CConv::ToFloat(conf->Value(name));
}

STR CConfig::getString(STR name){
    //return conf->Value(name);
    return conf->trim(conf->Value(name));
}

bool CConfig::setInt(STR name, int value){
    conf->rewriteValue(name + "=" + CConv::ToStr(value));
    return conf->Save(FN);
}

bool CConfig::setFloat(STR name, float value){
    conf->rewriteValue(name + "=" + CConv::ToStr(value));
    return conf->Save(FN);
}

bool CConfig::setString(STR name, STR value){
    conf->rewriteValue(name + "=" + value);
    return conf->Save(FN);
}

void CConfig::Open(STR FileName){
    FN = FileName;
    conf->Load(FileName);
}

void CConfig::Delete(STR name){
    conf->delVar(name);
    conf->Save(FN);
}
