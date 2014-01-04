#include <openssl/md5.h>
#include <openssl/rand.h>
#include "ccrypt.h"

CCrypt::CCrypt()
{
}

STR CCrypt::md5(STR value){
    MD5_CTX ctx;
    unsigned char buff[MD5_DIGEST_LENGTH];
    MD5_Init(&ctx);
    MD5_Update(&ctx, value.c_str(), value.length());
    MD5_Final(buff, &ctx);
    char res[33];
    for(int i = 0; i < 16; i++){
        sprintf(res+i*2, "%02x", buff[i]);
    }
    return STR(res);
}

STR CCrypt::genStr(){
    unsigned char buff[128];
    if(RAND_bytes(buff, 127)){
        return md5((char *)buff);
    }
    return "";
}
