#include "poly.h"

void poly_Zw_add3(const Term* a, const Term *b,const Term* c, Term* r){

   

    for(int i = 0;i<N;i++){
        r[i].a = a[i].a + b[i].a + c[i].a;
        r[i].b = a[i].b + b[i].b + c[i].b;
    }

    

    
}