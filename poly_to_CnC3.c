#include "poly_r.h"

void poly_to_CnC3(Term* p,group_ring* result){

    result->a = (Term*)malloc(N*sizeof(Term));
    result->b = (Term*)malloc(N*sizeof(Term));
    result->c = (Term*)malloc(N*sizeof(Term));

    
    for(int i = 0;i<N;i++){
        result->a[i] = p[i];
    }
    for(int i = N;i<2*N;i++){
        result->b[i-N] = p[i];
    }
    for(int i = 2*N;i<3*N;i++){
        result->c[i-2*N] = p[i];
    }

}