#ifndef CREQUEST_H
#define CREQUEST_H

#include <stdlib.h>
#include "cvar.h"

class CRequest
{
public:
    CRequest();
    ~CRequest();
    STR gateway_interface;
    STR server_software;
    STR server_protocol;
    STR method;
    STR http_accept;
    STR charset;
    STR language;
    STR host;
    STR referer;
    STR user_agent;
    STR remote_addr;
    STR script_name;
    STR server_admin;
    int port;
    STR request_uri;
    int content_length;
    STR document_root;

    CVar *get;
    CVar *post;
    CVar *cookie;

    char HexToChar(const char *text);
    void DecodeString(char *text);

    STR GET(STR name) { return get->Value(name); }
    STR POST(STR name) { return post->Value(name); }
    STR COOKIE(STR name) { return cookie->Value(name); }
};

#endif // CREQUEST_H
