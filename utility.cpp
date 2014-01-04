#include "utility.h"

bool FileExists(STR fn){
    FILE *F = fopen(fn.c_str(), "r");
    if(F){
        fclose(F);
        return true;
    }
    return false;
}
