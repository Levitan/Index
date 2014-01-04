#include "cvar.h"

CVar::CVar(){
    splits = "=";
}

void CVar::setVar(VAR *var, STR text){
    int n = text.find(splits);
    if(n > 0){
        var->Name = text.substr(0, n);
        int x = n + splits.length();
        int y = text.length() - x;
        var->Value = text.substr(x, y);
    }
    else {
        var->Name = text;
    }
}

STR CVar::trim(const STR &text)
{
    STR str = text;
    int p2 = str.find_last_not_of(" \t\r\n\0\a\b\f\v");
    int p1 = str.find_first_not_of(" \t\r\n\0\a\b\f\v");
    if(p2 != STR::npos) str.erase(p2+1);
    if(p1 != STR::npos) str.erase(0, p1);
    return str;
}

void CVar::delVar(STR name){
    int cnt;
    for(int i=0; i < cnt; i++){
        if(data[i].Name == name){
            data.erase(data.begin()+i, data.begin()+i+1);
        }
    }
}

void CVar::add(STR text){
    VAR tmp;
    setVar(&tmp, text);
    data.push_back(tmp);
}

STR CVar::Name(unsigned int index){
    if(index > data.size()) { return ""; }
    return data[index].Name;
}

STR CVar::Value(STR name){
    for(unsigned int i; i < data.size(); i++){
        if(data[i].Name == name){
            return data[i].Value;
        }
    }
    return "";
}

STR CVar::Strings(unsigned int index){
    if(index > data.size()) { return ""; }
    if(data[index].Value == "") { return data[index].Name; }
    return data[index].Name + splits + data[index].Value;
}

void CVar::addData(const char *url, char splt, bool clear){
    if(clear) { data.clear();}
    STR text = "";
    while(*url != 0){
        if(*url != splt){ text += *url; }
        else { add(text); text = ""; }
        url++;
    }
    add(text);
}

void CVar::Load(STR FileName, bool clear){
    if(clear) { data.clear();}
    char buff[1024];
    FILE *F = fopen(FileName.c_str(), "r");
    if(F){
        while(!feof(F)){
            fgets(buff, sizeof(buff), F);
            if(buff[0] != 0) {add(buff);}
            buff[0] = 0;
        }
        fclose(F);
    }
}

STR CVar::getData(){
    STR text = "";
    for(unsigned int i = 0; i < data.size(); i++){
        text += Strings(i) + "\r\n";
    }
    return text;
}

void CVar::rewriteValue(STR text){
    VAR var;
    setVar(&var, text);
    for(int i =0; i < Count(); i++){
        if(var.Name == data[i].Name){
            data[i].Value = var.Value;
            return;
        }
    }
    data.push_back(var);
}

bool CVar::Save(STR FileName)
{
    FILE *F;
    F = fopen(FileName.c_str(), "w+");
    if(!F) { return false; }
    fprintf(F, getData().c_str());
    fclose(F);
    return true;
}
