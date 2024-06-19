#include "poly.h"

Term poly_div_rat(Term A, Term q){ // q is of form (c + 0 w) where c is prime
    
    Term rem;

    
    
    int x = (A.a%(q.a) + q.a)%(q.a);
    int y = (A.b%(q.a) + q.a)%(q.a);

    if(q.a==2){
        if(x==1 && y==1){
            rem.a = -1;
            rem.b = -1;
        }
        else{
            rem.a = x;
            rem.b = y;
        }

        return rem;
    }

    int X = 2 * x;
    int Y = 2 * y;

    if((x+y)>(q.a) && X>y && Y>=x){
        rem.a = x - q.a;
        rem.b = y - q.a;
    }
    else if((X-y)>q.a && Y<x){
        rem.a = x - q.a;
        rem.b = y;
    }
    else if((Y-x)>=q.a && X<=y){
        rem.a = x;
        rem.b = y - q.a;
    }
    else{
        rem.a = x;
        rem.b = y;
    } 


    return rem;

}

void poly_Zw_mod_q(const Term* a, Term q, Term* r){
    
    for(int i = 0;i<N;i++){
        r[i] = poly_div_rat(a[i],q);
    }
}