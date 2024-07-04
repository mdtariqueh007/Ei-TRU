#include "poly.h"

Term q = {Q,0};

int poly_Zw_cmp(const Term* a, const Term *b,int len){
    for(int i = 0;i<len;i++){
        if(a[i].a!=b[i].a || a[i].b!=b[i].b){
            return 0;
        }
    }

    return 1;
}