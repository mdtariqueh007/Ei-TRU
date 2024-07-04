#include "poly_r.h"

void poly_ZwCnC3_mod(group_ring* A, Term q, group_ring* r){
    poly_Zw_mod_q(A->a,q,r->a);
    poly_Zw_mod_q(A->b,q,r->b);
    poly_Zw_mod_q(A->c,q,r->c);
}