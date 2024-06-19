#include "poly.h"

int isSame(Term A,Term B){
    if(A.a==B.a && A.b==B.b){
        return 1;
    }

    return 0;
}

Term multiply_terms(Term t1, Term t2){ // assuming the two terms are (a+bw) and (c+dw)
    Term result;

    int ac = t1.a * t2.a;
    int bd = t1.b * t2.b;

    int ab_dc = (t1.a - t1.b) * (t2.b - t2.a);

    result.a = ac - bd;
    result.b = ac + ab_dc;

    return result;

}

void poly_Zw_mul(const Term *f, const Term *g, Term *r){
    
    int k,i;
    Term temp;

    for(k=0; k<N; k++)
    {
        r[k].a = 0;
        r[k].b = 0;
        for(i=1; i<N-k; i++){
            temp = multiply_terms(f[k+i],g[N-i]);
            // r->coeffs[k] += a->coeffs[k+i] * b->coeffs[NTRU_N-i];
            r[k].a += temp.a;
            r[k].b += temp.b;
        }
        for(i=0; i<k+1; i++){
            // r->coeffs[k] += a->coeffs[k-i] * b->coeffs[i];
            temp = multiply_terms(f[k-i],g[i]);
            r[k].a += temp.a;
            r[k].b += temp.b;
        }

    }
}

void poly_Zw_mul_mod_q(const Term *f, const Term *g,Term q, Term *r){
    
    int k,i;
    Term temp;

    for(k=0; k<N; k++)
    {
        r[k].a = 0;
        r[k].b = 0;
        for(i=1; i<N-k; i++){
            temp = multiply_terms(f[k+i],g[N-i]);
            // r->coeffs[k] += a->coeffs[k+i] * b->coeffs[NTRU_N-i];
            r[k].a += temp.a;
            r[k].b += temp.b;
        }
        for(i=0; i<k+1; i++){
            // r->coeffs[k] += a->coeffs[k-i] * b->coeffs[i];
            temp = multiply_terms(f[k-i],g[i]);
            r[k].a += temp.a;
            r[k].b += temp.b;
        }

    }
    poly_Zw_mod_q(r,q,r);
}