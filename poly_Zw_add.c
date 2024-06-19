#include "poly.h"

void poly_Zw_add(const Term* a, const Term *b, Term* r){

   

    for(int i = 0;i<N;i++){
        r[i].a = a[i].a + b[i].a;
        r[i].b = a[i].b + b[i].b;
    }

    

    
}
