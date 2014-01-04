Index
=====

Core of C++ based CGI CMS

Dependencies
============
openssl-devel
mysql-devel

Project File modify
===================
INCLUDEPATH += /usr/include/openssl/

LIBS += -L/usr/lib64/openssl/ -lcrypto -lssl

LIBS += -L/usr/lib64/mysql -lmysqlclient
