#include "poly.h"

void Zw_CnC3_multiply(Term *f, Term *g, Term *r){
    int t = T;
    int t2 = t*t;
    Term q = {Q,0};

    Term f0[N];
    Term f1[N];
    Term f2[N];

    for(int i = 0;i<N;i++){
        f0[i] = f[i];
    }
    for(int i = N;i<2*N;i++){
        f1[i-N] = f[i];
    }
    for(int i = 2*N ;i < 3*N;i++){
        f2[i-2*N] = f[i]; 
    }

    Term g0[N];
    Term g1[N];
    Term g2[N];

    for(int i = 0;i<N;i++){
        g0[i] = g[i];
    }
    for(int i = N;i<2*N;i++){
        g1[i-N] = g[i];
    }
    for(int i = 2*N ;i < 3*N;i++){
        g2[i-2*N] = g[i]; 
    }

    Term f0t[N];
    Term f0t2[N];
    Term f1t[N];
    Term f1t2[N];
    Term f2t[N];
    Term f2t2[N];

    poly_Zw_shift_t(f0,t,f0t);
    poly_Zw_shift_t(f0,t2,f0t2);
    poly_Zw_shift_t(f1,t,f1t);
    poly_Zw_shift_t(f1,t2,f1t2);
    poly_Zw_shift_t(f2,t,f2t);
    poly_Zw_shift_t(f2,t2,f2t2);

    Term f0g0[N];
    Term f2tg1[N];
    Term f1t2g2[N];

    poly_Zw_mul(f0,g0,f0g0);
    poly_Zw_mul(f2t,g1,f2tg1);
    poly_Zw_mul(f1t2,g2,f1t2g2);

    Term f1g0[N];
    Term f0tg1[N];
    Term f2t2g2[N];

    poly_Zw_mul(f1,g0,f1g0);
    poly_Zw_mul(f0t,g1,f0tg1);
    poly_Zw_mul(f2t2,g2,f2t2g2);

    Term f2g0[N];
    Term f1tg1[N];
    Term f0t2g2[N];

    poly_Zw_mul(f2,g0,f2g0);
    poly_Zw_mul(f1t,g1,f1tg1);
    poly_Zw_mul(f0t2,g2,f0t2g2);

    Term X[N];
    Term Y[N];
    Term Y2[N];

    poly_Zw_add3(f0g0,f2tg1,f1t2g2,X);
    poly_Zw_add3(f1g0,f0tg1,f2t2g2,Y);
    poly_Zw_add3(f2g0,f1tg1,f0t2g2,Y2);

    for(int i = 0;i<N;i++){
        r[i] = X[i];
        r[i+N] = Y[i];
        r[i+2*N] = Y2[i];
    }

    


}