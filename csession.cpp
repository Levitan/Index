#include "csession.h"
#include "utility.h"

CSession::CSession(CRequest *rq, CResponse *rp)
{
    req = rq;
    resp = rp;
    cfg = new CConfig;
    cfg->Open("conf/session.cfg");
    session_ext = cfg->getString("SESSION_EXT");
    session_name = cfg->getString("SESSION_NAME");
    session_day = cfg->getInt("SESSION_LIFETIME");
    session_path = cfg->getString("SESSION_PATH");
    session_tl = cfg->getString("SESSION_TNAME");
}

CSession::~CSession(){
    delete cfg;
}

void CSession::Destroy(){
    resp->delCookie(session_name);
    remove(session_file.c_str());
}

void CSession::Create(){
    if(!getSession())
        newSession();
}

STR CSession::SESSION(STR name){
    return getString(name);
}

void CSession::setSession(STR name, STR value){
    setString(name, value);
}

void CSession::setSession(STR name, int value){
    setInt(name, value);
}

void CSession::setSession(STR name, float value){
    setFloat(name, value);
}

void CSession::unset(STR name){
    Delete(name);
}

bool CSession::getSession(){
    session_id = req->COOKIE(session_name);
    if(session_id == ""){
        return false;
    }
    session_file = session_path + session_id + session_ext;
    if(FileExists(session_file)){
        Open(session_file);
        int timelife = getInt(session_tl);
        if(timelife > CDateTime::Now()){
            return true;
        }
        else {
            Destroy();
        }
    }
    return false;
}

void CSession::newSession(){
    session_id = CCrypt::genStr();
    session_file = session_file = session_path + session_id + session_ext;
    if(FileExists(session_file)){
        newSession();
    }
    Save(session_file);
    Open(session_file);
    setInt(session_tl, CDateTime::Now() + 3600 * 24 * session_day);
    resp->setCookie(session_name, session_id, 3600*24*session_day*2);


}
