#ifndef CVAR_H
#define CVAR_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

typedef std::string STR;
typedef struct __VAR{
    STR Name;
    STR Value;
}VAR;

class CVar
{
public:
    CVar();
    void add(STR text);
    STR Name(unsigned int index);
    STR Value(STR name);
    STR Strings(unsigned int index);
    void Clear() { data.clear(); }
    int Count() const { return data.size(); }
    void setSplits(STR splt) { splits = splt; }
    void addData(const char *url, char splt, bool clear=true);
    void Load(STR FileName, bool clear=true);
    STR getData();
    void rewriteValue(STR text);
    bool Save(STR FileName);
    void setVar(VAR *var, STR text);
    STR trim(const STR &text);
    void delVar(STR name);
private:
    std::vector<VAR> data;
    STR splits;
};

#endif // CVAR_H
