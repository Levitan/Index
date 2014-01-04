#ifndef CMYSQL_H
#define CMYSQL_H

#include <cstring>
#include <mysql/mysql.h>
#include "cvar.h"
#include "cresponse.h"

class CMySql
{
public:
    CMySql(CResponse *r, const char *h, const char *u, const char *p, const char *db);
    ~CMySql();
    MYSQL_ROW Row;
    MYSQL_FIELD *Field;

    bool is_connect();
    bool query(const char *q);
    int num_rows();
    int num_fields();
    bool fetch_row();
    bool fetch_field();
    void close();
    bool fetch_assoc();
    STR assoc(STR name);

private:
    MYSQL *conn;
    MYSQL_RES *result;
    CResponse *rp;
    std::vector<STR> assoc_str;
    CVar *m_assoc;
    void set_assoc();
};

#endif // CMYSQL_H
