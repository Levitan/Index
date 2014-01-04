TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cvar.cpp \
    crequest.cpp \
    cresponse.cpp \
    cconv.cpp \
    cconfig.cpp \
    cmysql.cpp \
    cdatetime.cpp \
    ctemplate.cpp \
    ccrypt.cpp \
    csession.cpp \
    utility.cpp

HEADERS += \
    cvar.h \
    crequest.h \
    cresponse.h \
    cconv.h \
    cconfig.h \
    cmysql.h \
    cdatetime.h \
    ctemplate.h \
    ccrypt.h \
    csession.h \
    utility.h

INCLUDEPATH += /usr/include/openssl/

LIBS += -L/usr/lib64/openssl/ -lcrypto -lssl
LIBS += -L/usr/lib64/mysql -lmysqlclient

