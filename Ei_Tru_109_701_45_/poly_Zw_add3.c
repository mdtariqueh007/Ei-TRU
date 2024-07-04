#include "poly.h"

void poly_Zw_add3(const Term* a, const Term *b,const Term* c, Term* r){

    Term q = {Q,0};

    for(int i = 0;i<N;i++){
        r[i].a = a[i].a + b[i].a + c[i].a;
        r[i].b = a[i].b + b[i].b + c[i].b;
    }

    poly_Zw_mod_q(r,q,r);

    

    
}