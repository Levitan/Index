#include "cmysql.h"

CMySql::CMySql(CResponse *r, const char *h, const char *u, const char *p, const char *db)
{
    rp = r;
    conn = mysql_init(NULL);
    if(!conn){ rp->print(mysql_error(conn)); }
    if(!mysql_real_connect(conn, h, u, p, db, 0, NULL, 0)) { rp->print(mysql_error(conn));}
    result = NULL;
    m_assoc = new CVar;
}

CMySql::~CMySql(){
    delete m_assoc;
}

bool CMySql::is_connect(){
    return (bool) conn;
}

bool CMySql::query(const char *q){
    bool r = mysql_real_query(conn, q, strlen(q));
    if(!r){ result = mysql_store_result(conn); set_assoc();}
    return !r;
}

int CMySql::num_rows(){
    return mysql_num_rows(result);
}

int CMySql::num_fields(){
    return mysql_num_fields(result);
}

bool CMySql::fetch_row(){
    return (Row = mysql_fetch_row(result));
}

bool CMySql::fetch_field()
{
    return (Field = mysql_fetch_field(result));
}

void CMySql::close(){
    if(result){ mysql_free_result(result); }
    mysql_close(conn);
}

bool CMySql::fetch_assoc(){
    bool res = fetch_row();
    if(res){
        m_assoc->Clear();
        int cnt = num_fields();
        for(int i = 0; i < cnt; i++){
            m_assoc->add(assoc_str[i] + "=" + STR(Row[i]));
        }
    }
    return res;
}

STR CMySql::assoc(STR name){
    return m_assoc->Value(name);
}

void CMySql::set_assoc(){
    assoc_str.clear();
    while(fetch_field()){
        assoc_str.push_back(Field->name);
    }
}

