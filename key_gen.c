#include "key_gen.h"


void generate_keys(Term *f,Term *fq ,Term *g, Term *h, Term P){
    Term q = {Q,0};

    int flag = 0;

    // Term fq[N3];

    unsigned char arr_seed_f[N3_SAMPLE_BYTES+T_SAMPLE_BYTES+N3_SAMPLE_BYTES];

    randombytes(arr_seed_f,N3_SAMPLE_BYTES+T_SAMPLE_BYTES+N3_SAMPLE_BYTES);
    while(flag==0){

        // printf("In loop\n");


        // Term f[N3];

        sample_lf(f,arr_seed_f);

        poly_Zw_mul_p(f,P,N3);

        f[0].a += 1;

        

        // Term fq[N3];

        // poly_Zw_print(f,N3);
        // printf("\n**************************\n");
        // for(int i = 0;i<N3;i++){
        //     printf("[%d , %d] ,",f[i].a,f[i].b);
        // }
        // printf("\n**************************\n");
        flag = Almost_inverse_ZpwCnC3(f,Q,fq);
        // poly_Zw_print(fq,N3);

        if(flag==0){

            randombytes(arr_seed_f,N3_SAMPLE_BYTES+T_SAMPLE_BYTES+N3_SAMPLE_BYTES);
        }
        

    }

    // unsigned char arr_seed_g[N3_SAMPLE_BYTES];

    // randombytes(arr_seed_g,N3_SAMPLE_BYTES);

    // Term g[N3];

    sample_lg(g,arr_seed_f+N3_SAMPLE_BYTES+T_SAMPLE_BYTES);

    group_ring FQ;
    group_ring G;

    poly_to_CnC3(fq,&FQ);
    poly_to_CnC3(g,&G);

    group_ring RES_FQ_G;
    RES_FQ_G.a = (Term*)malloc(N*sizeof(Term));
    RES_FQ_G.b = (Term*)malloc(N*sizeof(Term));
    RES_FQ_G.c = (Term*)malloc(N*sizeof(Term));

    poly_ZwCnC3_mul(&FQ,&G,T,&RES_FQ_G);

    // poly_Zw_mul_mod_q(fq,g,q,h);
    poly_ZwCnC3_mod(&RES_FQ_G,q,&RES_FQ_G);

    for(int i = 0;i<N;i++){
        h[i] = RES_FQ_G.a[i];
    }
    for(int i = N;i<2*N;i++){
        h[i] = RES_FQ_G.b[i-N];
    }
    for(int i = 2*N;i<3*N;i++){
        h[i] = RES_FQ_G.c[i-2*N];
    }

    // printf("\nInside key gen\n");

    // printf("fq: "); poly_Zw_print(fq,N3);
    // printf("g: "); poly_Zw_print(g,N3);
    // printf("h: "); poly_Zw_print(h,N3);

    // poly_ZwCnC3_print(&RES_FQ_G);

    // printf("\nInside key gen\n");



}