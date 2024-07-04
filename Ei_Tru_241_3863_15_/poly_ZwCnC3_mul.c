#include "poly_r.h"

void poly_ZwCnC3_mul(group_ring* z, group_ring* a,int t,group_ring* result){

    // Term *u = z->a;
    // Term *v = z->b;
    // Term *w = z->c;

    // Term* A = a->a;
    // Term* B = a->b;
    // Term* G = a->c;

    Term u[N];
    Term v[N];
    Term w[N];

    Term A[N];
    Term B[N];
    Term G[N];

    for(int i = 0;i<N;i++){
        u[i] = z->a[i];
        v[i] = z->b[i];
        w[i] = z->c[i];

        A[i] = a->a[i];
        B[i] = a->b[i];
        G[i] = a->c[i];
    }


    int t2 = t*t;

    //1
    Term uA[N];

    poly_Zw_mul(u,A,uA);

    Term wt[N];
    
    poly_Zw_shift_t(w,t,wt);

    Term wtB[N];

    poly_Zw_mul(wt,B,wtB);

    Term vt2[N];
    
    poly_Zw_shift_t(v,t2,vt2);

    Term vt2G[N];

    poly_Zw_mul(vt2,G,vt2G);

    
    poly_Zw_add3(uA,wtB,vt2G,result->a);

    

    //y

    Term vA[N];

    poly_Zw_mul(v,A,vA);

    Term ut[N];

    poly_Zw_shift_t(u,t,ut);

    Term utB[N];

    poly_Zw_mul(ut,B,utB);

    Term wt2[N];

    poly_Zw_shift_t(w,t2,wt2);

    Term wt2G[N];

    poly_Zw_mul(wt2,G,wt2G);

    poly_Zw_add3(vA, utB, wt2G, result->b);

    //y2

    Term wA[N];

    poly_Zw_mul(w,A,wA);

    Term vt[N];

    poly_Zw_shift_t(v,t,vt);

    Term vtB[N];

    poly_Zw_mul(vt,B,vtB);

    Term ut2[N];

    poly_Zw_shift_t(u,t2,ut2);

    Term ut2G[N];

    poly_Zw_mul(ut2,G,ut2G);

    poly_Zw_add3(wA, vtB, ut2G, result->c);
}
