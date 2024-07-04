#include "poly_r.h"

void poly_ZwCnC3_add(group_ring* A, group_ring* B,group_ring* E){
    poly_Zw_add(A->a,B->a,E->a);
    poly_Zw_add(A->b,B->b,E->b);
    poly_Zw_add(A->c,B->c,E->c);
}
void poly_ZwCnC3_sub(group_ring* A, group_ring* B,group_ring* E){
    poly_Zw_sub(A->a,B->a,E->a);
    poly_Zw_sub(A->b,B->b,E->b);
    poly_Zw_sub(A->c,B->c,E->c);
}