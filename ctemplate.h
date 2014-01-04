#ifndef CTEMPLATE_H
#define CTEMPLATE_H

#include "cvar.h"
#include "cresponse.h"
#include "cdatetime.h"
#include "crequest.h"

class CTemplate
{
public:
    CTemplate(CResponse *r, CRequest *rq, STR tpl);
    STR open_tpl(STR tplName);
    static STR replace(STR sr, STR rp, STR src);
    void push(STR tag, STR text);
    void setLRT(STR l, STR r) { lt = l; rt = r; }
    void display();
    bool open_item(STR tpl);
    void push_item(STR tag, STR text);
    STR getItems();

private:
    STR source;
    CResponse *responce;
    STR lt, rt;
    CRequest *req;
    void setData();
    STR src_items;
    STR items;
};

#endif // CTEMPLATE_H
