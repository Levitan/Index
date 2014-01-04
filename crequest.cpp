#include "crequest.h"
#include <stdlib.h>

#define HTTP_DATA(x) ((x) ? x : "")

CRequest::CRequest()
{

    this->gateway_interface = HTTP_DATA(getenv("GATEWAY_INTERFACE"));       // CGI Version
    this->server_software   = HTTP_DATA(getenv("SERVER_SOFTWARE"));         // Webserver Name
    this->server_protocol   = HTTP_DATA(getenv("SERVER_PROTOCOL"));         // Protocol version
    this->method            = HTTP_DATA(getenv("REQUEST_METHOD"));          // Data transfer method
    this->http_accept       = HTTP_DATA(getenv("HTTP_ACCEPT"));             // Type tranfered data
    //this->charset           = STR(getenv("HTTP_ACCEPT_CHARSET"));           // Charset
    this->language          = HTTP_DATA(getenv("HTTP_ACCEPT_LANGUAGE"));    // Language
    this->host              = HTTP_DATA(getenv("HTTP_HOST"));               // Host Name (expample.com)
    char *ref               = getenv("HTTP_REFERER");                       // Previous visit page
    this->referer           = (ref) ? ref : "";
    this->user_agent        = HTTP_DATA(getenv("HTTP_USER_AGENT"));         // User Agent
    this->remote_addr       = HTTP_DATA(getenv("REMOTE_ADDR"));             // IP address
    this->script_name       = HTTP_DATA(getenv("SCRIPT_FILENAME"));         // CGI Name (/cgi-bin/index)
    this->server_admin      = HTTP_DATA(getenv("SERVER_ADMIN"));            // Admin E-Mail
    this->request_uri       = HTTP_DATA(getenv("REQUEST_URI"));             // path to cgi script
    this->document_root     = HTTP_DATA(getenv("DOCUMENT_ROOT"));           // Document root

//=======================================================================================================//

    get = new CVar();
    post = new CVar();
    cookie = new CVar();

    char *query = getenv("QUERY_STRING");
    if(query){
        DecodeString(query);
        get->addData(query, '&');
    }
    if(method == "POST"){
        content_length = atoi(getenv("CONTENT_LENGTH"));
        if(content_length > 0){
            char *tmp = new char[content_length+1];
            if(tmp){
                fread(tmp, content_length, 1, stdin);
                DecodeString(tmp);
                post->addData(tmp, '&');
                delete [] tmp;
            }
        }
    }
    char *cook = getenv("HTTP_COOKIE");
    if(cook){
        DecodeString(cook);
        cookie->addData(cook, ';');
    }
}

CRequest::~CRequest(){
    if(get)     delete get;
    if(post)    delete post;
    if(cookie)  delete cookie;
}

char CRequest::HexToChar(const char *text){
    char ch;
    if(text[0] >= 'A'){
        ch = ((text[0] & 0xDF) - 'A') + 10;
    }
    else {
        ch = text[0] - '0';
    }
    ch <<= 4;

    if(text[1] >= 'A'){
        ch += ((text[1] & 0xDF) - 'A') +10;
    }
    else { ch += text[1] - '0'; }
    return ch;
}

void CRequest::DecodeString(char *text){
    char ch;
    int a, b;
    for(a=0, b=0; text[a]; a++, b++){
        ch = text[a];
        if(ch == '%') {
            ch = HexToChar(&text[a+1]);
            text[b] = ch;
            a += 2;
        }
        ch = (ch == '+') ? ' ' : ch;
        text[b] = ch;
    }
    text[b] = 0;
}
