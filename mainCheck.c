#include <stdio.h>

#include "poly_r.h"
#include "sample.h"
#include "rng.h"

#include "crypto_sort_int32.h"

#include "encrypt.h"
#include "decrypt.h"

#include "key_gen.h"

#include<time.h>

#include "pke.h"

#define test_cases 5


int main(){

    clock_t t_; 
    t_ = clock(); 
    // fun(); 
    

    
    int test = test_cases;

    while(test--){

        printf("Test %d: \n",test_cases - test );

    Term f[N3];
    Term fq[N3];
    Term g[N3];

    Term h[N3];



    

     
    group_ring H;
    group_ring PHI;
    group_ring M;
    group_ring Original_M;
    group_ring E;
    E.a = (Term*)malloc(N*sizeof(Term));
    E.b = (Term*)malloc(N*sizeof(Term));
    E.c = (Term*)malloc(N*sizeof(Term));
    group_ring F;
    group_ring A;
    A.a = (Term*)malloc(N*sizeof(Term));
    A.b = (Term*)malloc(N*sizeof(Term));
    A.c = (Term*)malloc(N*sizeof(Term));
    Term P = {2,0};
    Term q = {Q,0};

    // Term a[N3] = {{-1, -2}, {-2, -2}, {-2, -2}, {0, 2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {-2, 0}, {0, 0}, {0, -2}, {0, 0}, {0, -2}, {-2, -2}, {2, 2}, {2, 0}, {2, 2}, {0, 0}, {-2, 0}, {-2, -2}, {0, 2}, {0, -2}, {2, 0}, {0, 0}, {2, 0}, {0, 2}, {-2, 0}, {-2, 0}, {-2, -2}, {2, 0}, {2, 0}, {0, 0}, {-2, -2}, {2, 2}, {0, 2}, {-2, 0}, {0, 0}, {0, 2}, {-2, -2}, {0, 0}, {0, 0}, {0, 0}, {2, 2}, {0, -2}, {0, 2}, {2, 2}, {-2, 0}, {-2, 0}, {0, 2}, {0, 2}, {0, 0}, {2, 2}, {2, 2}, {0, 2}, {2, 2}, {-2, -2}, {2, 0}, {0, -2}, {0, 0}, {0, -2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {2, 0}, {-2, 0}, {0, 2}, {-2, -2}, {0, 0}, {0, 0}, {0, 0}, {0, 2}, {2, 2}, {-2, -2}, {-2, -2}, {2, 2}, {-2, -2}, {0, 0}, {2, 2}, {0, 0}, {0, 0}, {0, 2}, {0, 2}, {-2, -2}, {0, 2}, {0, 2}, {-2, 0}, {0, 0}, {0, 2}, {-2, 0}, {0, 0}, {2, 2}, {2, 2}, {-2, -2}, {-2, 0}, {0, 0}, {0, -2}, {-2, 0}, {2, 0}, {-2, 0}, {-2, -2}, {0, -2}, {-2, 0}, {0, 0}, {2, 0}, {0, 0}, {2, 0}, {0, 0}, {2, 2}, {-2, -2}, {0, -2}, {-2, -2}, {0, 0}, {2, 0}, {0, 0}, {0, 2}, {0, -2}, {0, 0}, {0, 0}, {0, -2}, {2, 0}, {2, 2}, {0, 0}, {0, 2}, {0, 0}, {0, 0}, {-2, -2}, {2, 0}, {0, 2}, {0, 0}, {-2, 0}, {0, 0}, {0, 2}, {2, 0}, {-2, 0}, {0, -2}, {0, 0}, {2, 2}, {0, 2}, {2, 0}, {2, 2}, {0, 0}, {0, 0}, {0, 0}, {2, 0}, {-2, 0}, {2, 0}, {0, 0}, {2, 0}, {0, 2}, {0, 0}, {-2, 0}, {-2, -2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {-2, -2}, {-2, 0}, {0, 0}, {2, 2}, {0, 0}, {-2, 0}, {2, 0}, {2, 2}, {0, 0}, {2, 2}, {2, 2}, {0, 2}, {2, 0}, {0, 0}, {0, -2}, {0, 0}, {0, -2}, {0, 0}, {-2, 0}, {-2, 0}, {-2, 0}};
    // Term a_inv[N3];


    // Almost_inverse_ZpwCnC3(a,Q,a_inv);



    // generate_keys(f,fq,g,h,P);

    unsigned char fg_seed[N3_SAMPLE_FG_BYTES];

    randombytes(fg_seed,N3_SAMPLE_FG_BYTES);

    pke_keypair(f,g, h, P,fg_seed);

    
    poly_to_CnC3(h,&H);

    // unsigned char arr_seed[N3_SAMPLE_BYTES];

    // randombytes(arr_seed,N3_SAMPLE_BYTES);

    // Term phi[N3];

    // sample_lphi(phi,arr_seed);

    // poly_to_CnC3(phi,&PHI);

    unsigned char arr_seed_m[N3_SAMPLE_M_BYTES];

    randombytes(arr_seed_m,N3_SAMPLE_M_BYTES);

    Term m[N3];


    sample_lm(m,arr_seed_m);

    poly_to_CnC3(m,&M);
    poly_to_CnC3(m,&Original_M);

    // printf("\n-----------------M---------------------\n");

    // poly_ZwCnC3_print(&Original_M);

    // printf("\n-------------------M--------------------\n");

    unsigned char arr_seed[N3_SAMPLE_BYTES];

    randombytes(arr_seed,N3_SAMPLE_BYTES);

    pke_encrypt(&H,&M,P,q,&E,arr_seed);



    // printf("\n-----------------E---------------------\n");

    // poly_ZwCnC3_print(&E);

    // printf("\n-------------------E--------------------\n");

    

    poly_to_CnC3(f,&F);

    
    

    pke_decrypt(&F,&E,P,q,&A);

    // printf("\n-----------------A---------------------\n");

    // poly_ZwCnC3_print(&A);

    // printf("\n-------------------A--------------------\n");



    

    int one = 0;
    int y = 0;
    int y2 = 0;

    if(poly_Zw_cmp(Original_M.a,A.a)){
        one = 1;
    }
    else{
        one = 0;
    }
    if(poly_Zw_cmp(Original_M.b,A.b)){
        y = 1;
    }
    else{
        y = 0;
    }
    if(poly_Zw_cmp(Original_M.c,A.c)){
        y2 = 1;
    }
    else{
        y2 = 0;
    }

    printf("%d %d %d\n",one,y,y2);

    if(one && y && y2){
        printf("True\n");
        
    }
    else{
        printf("False\n");
    }


    





    



    printf("\n-------------End --------------\n");

    
    }

    t_ = clock() - t_; 
    double time_taken = ((double)t_)/CLOCKS_PER_SEC; // in seconds 
 
    printf("Took %f seconds to execute \n", time_taken);

    // Term a1[N3];
    
    // Term b1[N3];

    // for(int i = 0;i<N3;i++){
    //     a1[i].a = i + 1;
    //     a1[i].b = i + 1;
       
    //     b1[i].a = i + 1;
    //     b1[i].b = i + 1;


        
    // }

    // group_ring* ARR;
    // group_ring* BRR;

    // poly_to_CnC3(a1,ARR);
    // poly_to_CnC3(b1,BRR);



    // unsigned char t_seed[LENGTH_OF_HASH];
    // unsigned char t_seed_2[LENGTH_OF_HASH];

    // sha3_512(t_seed,(unsigned char*)(&a1),N3);
    // printf("\nttttttttttttttttttttttttttttttttttt\n");
    // for(int i = 0;i<LENGTH_OF_HASH;i++){
    //     printf("%d ",t_seed[i]);
    // }

    // printf("\nttttttttttttttttttttttttttttttttttt\n");
    // sha3_512(t_seed_2,(unsigned char*)(&b1),N3);
    // printf("\nttttttttttttttttttttttttttttttttttt\n");
    // for(int i = 0;i<LENGTH_OF_HASH;i++){
    //     printf("%d ",t_seed_2[i]);
    // }

    // printf("\nttttttttttttttttttttttttttttttttttt\n");



    
    

    return 0;

}