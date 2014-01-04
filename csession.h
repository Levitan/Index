#ifndef CSESSION_H
#define CSESSION_H

#include "cvar.h"
#include "cconfig.h"
#include "cresponse.h"
#include "crequest.h"
#include "cdatetime.h"
#include "ccrypt.h"

class CSession : public CConfig
{
public:
    CSession(CRequest *rq, CResponse *rp);
    ~CSession();
    void Destroy();
    void Create();
    STR SESSION(STR name);
    void setSession(STR name, STR value);
    void setSession(STR name, int value);
    void setSession(STR name, float value);
    void unset(STR name);

private:
    CResponse *resp;
    CRequest *req;
    CConfig *cfg;
    STR session_file;
    STR session_id;
    STR session_path;
    STR session_ext;
    STR session_name;
    int session_day;
    STR session_tl;

    bool getSession();
    void newSession();

};

#endif // CSESSION_H
