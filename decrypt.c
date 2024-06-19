#include "decrypt.h"

void decrypt(group_ring *F, group_ring* E,Term P, Term q, group_ring *A){

    poly_ZwCnC3_mod(F,q,F);
    poly_ZwCnC3_mod(E,q,E);

    poly_ZwCnC3_mul(F,E,T,A);

    

    

    poly_ZwCnC3_mod(A,q,A);

    // printf("e*f:  \n");

    // poly_ZwCnC3_print(A);

    // printf("\n----------------------------\n");

    poly_ZwCnC3_mod(A,P,A);

    // printf("m1:  \n");

    // poly_ZwCnC3_print(A);

    // printf("\n----------------------------\n");
}