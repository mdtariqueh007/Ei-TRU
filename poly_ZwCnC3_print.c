#include "poly_r.h"

#include<stdio.h>

void poly_ZwCnC3_print(group_ring* r){
    printf("\n(");
    poly_Zw_print(r->a, N);
    printf(")\n + ");
    printf("\n(");
    poly_Zw_print(r->b, N);
    printf(")y\n + ");
    printf("\n(");
    poly_Zw_print(r->c, N);
    printf(")y^2\n");
}