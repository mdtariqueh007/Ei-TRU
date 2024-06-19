#include "poly.h"

int poly_Zw_cmp(const Term* a, const Term *b){
    for(int i = 0;i<N;i++){
        if(a[i].a!=b[i].a || a[i].b!=b[i].b){
            return 0;
        }
    }

    return 1;
}