#include "ctemplate.h"

CTemplate::CTemplate(CResponse *r, CRequest *rq, STR tpl)
{
    req = rq;
    responce = r;
    source = open_tpl(tpl);
    lt = rt = "$";
}

STR CTemplate::open_tpl(STR tplName){
    FILE *F = fopen(tplName.c_str(), "r");
    if(!F) { return ""; }
    char buff[1024];
    STR str;
    while(!feof(F)){
        if(fgets(buff, 1024, F)){
            str += STR(buff);
        }
    }
    fclose(F);
    return str;
}

STR CTemplate::replace(STR sr, STR rp, STR src){
    int n = src.find(sr);
    if(n != -1){
        src.replace(n, sr.length(), rp);
        return replace(sr, rp, src);
    }
    return src;
}

void CTemplate::push(STR tag, STR text){
    STR fnd = lt+tag+rt;
    source = replace(fnd, text, source);
}

void CTemplate::display(){
    setData();
    responce->print(source);
}

bool CTemplate::open_item(STR tpl){
    src_items = open_tpl(tpl);
    if(src_items != ""){
        return true;
    }
    return false;
}

void CTemplate::push_item(STR tag, STR text){
    STR fnd = lt + tag + rt;
    items += replace(fnd, text, src_items);
}

STR CTemplate::getItems(){
    STR tmp = items;
    items = "";
    src_items = "";
    return tmp;
}

void CTemplate::setData(){
    push("TIME", CDateTime::Time());
    push("DATE", CDateTime::Date());
    push("HOST", "http://" + req->host);
}
