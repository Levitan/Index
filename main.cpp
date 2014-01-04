#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "cvar.h"
#include "crequest.h"
#include "cresponse.h"
#include "cconfig.h"
#include "cconv.h"
#include "cmysql.h"
#include "ctemplate.h"
#include "ccrypt.h"
#include "csession.h"

int main(){

    CRequest *req = new CRequest;
    CResponse *resp = new CResponse;
    CSession sess(req, resp);
    sess.Create();
    sess.setSession("test", "SSSSSSSSSs");
    for(int i=0; i<req->cookie->Count(); i++){
        resp->print(req->cookie->Strings(i));
    }
    resp->print("");
    //    CConfig conf("./conf/config.cfg");
    //    CMySql *sql = new CMySql(resp,
    //                             conf.getString("DB_HOST").c_str(),
    //                             conf.getString("DB_ROOT").c_str(),
    //                             conf.getString("DB_PASS").c_str(),
    //                             conf.getString("DB_NAME").c_str()
    //                             );
    //    resp->print("<pre>");
    //    if(sql->query("SELECT * FROM test")){
    //        while(sql->fetch_assoc())
    //            resp->print(sql->assoc("name") + "\n");
    //    }
//        CTemplate tpl(resp, req, req->document_root+"/tpls/default/index.tpl");
//        //resp->print("http://"+ req->host +"/tpls/default/index.tpl");

//        tpl.push("MENU", "<ul><li class='current_page_item'><a href='#'>Home</a></li><li><a href='#'>Blog</a></li><li><a href='#'>About</a></li><li><a href='#' class='last'>Contact</a></li></ul>");
//        tpl.push("BODY", "<h1>Hello, INDEX!</h1>");
//        tpl.open_item(req->document_root + "/tpls/default/item.tpl");
//        tpl.push_item("ITEM_BODY", "<h2>item text</h2>");
//        tpl.push_item("ITEM_TITLE", "Item Title №1");
//        /*for(int i = 0; i < 5; i++){
//            tpl.push_item("ITEM_BODY", "<h2>item text</h2>");
//            //tpl.push_item("ITEM_TITLE", "Item Title №" + CConv::ToStr(i));
//            //tpl.push_item("DATE", CDateTime::Date());
//        }*/
//        tpl.push("ITEM", tpl.getItems());
//        tpl.push("TITLE", "INDEX");
//        tpl.display();
    delete req;
    delete resp;
    return 0;
}

