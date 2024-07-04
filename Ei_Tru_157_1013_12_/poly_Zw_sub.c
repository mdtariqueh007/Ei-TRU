#include "poly.h"

void poly_Zw_sub(const Term* a, const Term *b, Term* r){

    

    for(int i = 0;i<N;i++){
        r[i].a = a[i].a - b[i].a;
        r[i].b = a[i].b - b[i].b;
    }

    
}
void ZwCnC3_sub(const Term* a, const Term *b, Term* r){

    

    for(int i = 0;i<N3;i++){
        r[i].a = a[i].a - b[i].a;
        r[i].b = a[i].b - b[i].b;
    }

    
}