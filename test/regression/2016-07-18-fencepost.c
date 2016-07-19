#include <stdint.h>
#include <stdio.h>
#include <string.h>

int checksum(void *p, int len){
    int accum = 0;
    unsigned char* pp = (unsigned char*)p;
    int i;
    for (i = 0; i <= len; i++){
        accum += *pp++;
    }
    return accum;
}

int main(){

    void *teststr;
    int len;
    klee_make_symbolic(&teststr, sizeof teststr, "string");
    klee_make_symbolic(&len, sizeof len, "string len");    
    return checksum(teststr, len);
}

