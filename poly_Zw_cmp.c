#include "poly.h"

Term q = {Q,0};

int poly_Zw_cmp(const Term* a, const Term *b){
    for(int i = 0;i<N;i++){
        if((a[i].a%q.a + q.a)%q.a!=(b[i].a%q.a + q.a)%q.a || (a[i].b%q.a + q.a)%q.a!=(b[i].b%q.a + q.a)%q.a){
            return 0;
        }
    }

    return 1;
}