#include "poly.h"

void poly_Zw_mul_p(Term *r, Term P,int len){
    int p = P.a;

    for(int i = 0;i<len;i++){
        r[i].a = p*r[i].a;
        r[i].b = p*r[i].b;
    }
}

