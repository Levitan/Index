Index
=====

Core of C++ based CGI CMS

Dependencies
============
openssl-devel
mysql-devel

Project File modify (if use Qt-Creator)
=======================================
TARGET = index

INCLUDEPATH += /usr/include/openssl/

LIBS += -L/usr/lib64/openssl/ -lcrypto -lssl

LIBS += -L/usr/lib64/mysql -lmysqlclient

Compile with qmake
==================
mkdir build && cd build

qmake-qt4 -project ../

qmake-qt4

make
