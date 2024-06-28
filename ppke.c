#include "ppke.h"
#include "inverse.h"
#include "packq_CnC3.h"
#include "pack3_CnC3.h"

int ppke_keypair(unsigned char *pk, unsigned char* sk,unsigned char arr_seed[N3_SAMPLE_FG_BYTES]){
    Term q = {Q,0};
    Term P = {p_,0};

    Term h[N3];
    Term g[N3];
    Term f[N3];

    int flag = 0;

    Term fq[N3];
    int loop = 0;
    while(flag==0){

        // printf("In loop\n");
        loop++;

        // Term f[N3];

        sample_lf(f,arr_seed);

        poly_Zw_mul_p(f,P,N3);

        poly_S3_tobytes(sk,f);

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

            randombytes(arr_seed,N3_SAMPLE_FG_BYTES);
        }
        

    }

    // unsigned char arr_seed_g[N3_SAMPLE_BYTES];

    // randombytes(arr_seed_g,N3_SAMPLE_BYTES);

    // Term g[N3];

    sample_lg(g,arr_seed+N3_SAMPLE_F_BYTES);

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

    // printf("Key generation before :\n");
    // for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d, ",sk[i]);
    // }
    // printf("\n");
    // poly_pack_Sq_tobytes(sk,f);
    // printf("Key generation:\n");
    // for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d, ",sk[i]);
    // }
    // printf("\n");
    poly_pack_Sq_tobytes(pk,h);

    // printf("original f : \n");
    // poly_Zw_print(f,N3);
    // printf("original h : \n");
    // poly_Zw_print(h,N3);

    return loop;

    
    



}

// group_ring* H, group_ring* M,Term *phi,Term P,Term q,group_ring*E

void ppke_encrypt(unsigned char* c,Term* phi, Term *h, Term* m){

    Term P = {p_,0};
    Term q = {Q,0};

    // printf("Text: \n");
    // poly_ZwCnC3_print(M);
    // printf("\n------------------------------\n");

    group_ring H;
    group_ring M;
    group_ring E;

    Term e[N3];

    poly_to_CnC3(e,&E);


    poly_to_CnC3(h,&H);
    poly_to_CnC3(m,&M);

    poly_Zw_mul_p(H.a,P,N);
    poly_Zw_mul_p(H.b,P,N);
    poly_Zw_mul_p(H.c,P,N);

    poly_ZwCnC3_mod(&H,q,&H);


    // unsigned char arr_seed[N3_SAMPLE_BYTES];

    // randombytes(arr_seed,N3_SAMPLE_BYTES);

    // Term phi[N3];

    // sample_lphi(phi,arr_seed);

    group_ring PHI;

    poly_to_CnC3(phi,&PHI);
    poly_ZwCnC3_mod(&PHI,q,&PHI);

    

    poly_ZwCnC3_mul(&H, &PHI, T, &E);//E = PHI*H

    poly_ZwCnC3_mod(&E,q,&E);


    Term t_prime[N3];

    for(int i = 0;i<N;i++){
        t_prime[i] = E.a[i];
        t_prime[i+N] = E.b[i];
        t_prime[i+2*N] = E.c[i];
    }

    // printf("In_Encrypt : T : \n");
    // poly_Zw_print(t_prime,N3);
    // printf("\n------------------------------------\n");

    // printf("ph*phi: \n"); 

    // poly_ZwCnC3_print(E);

    // printf("\n-----------------------------------\n");
    Term mask[N3];

    // for(int i = 0;i<N3;i++){

    // }

    // printf("Address of E: %u\n",(unsigned char*)(&E));

    unsigned char t_seed[LENGTH_OF_HASH];

    sha3_512(t_seed,(unsigned char*)(&t_prime),N3*2);
    // printf("IN_ENCRYPT t_seed : \n");
    // for(int i = 0;i<LENGTH_OF_HASH;i++){
    //     printf("%d ",t_seed[i]);
    // }

    // printf("\n-------------------\n");

    sample_mask(mask,t_seed);

    // printf("in enc mask :\n");
    // poly_Zw_print(mask,N3);
    // printf("\n-------------------\n");

    group_ring MASK;

    poly_to_CnC3(mask,&MASK);

    

    // printf("IN ENCRYPT M: ");
    // poly_ZwCnC3_print(M);
    // printf("\n------------------------------------\n");

    // printf("IN ENCRYPT MASK : ");
    // poly_ZwCnC3_print(&MASK);
    // printf("\n------------------------------------\n");

    poly_ZwCnC3_sub(&M,&MASK,&M);//
    poly_ZwCnC3_mod(&M,P,&M);// M = M - MASK
    
    // printf("M - MASK: \n");
    // poly_ZwCnC3_print(M);
    // printf("\n------------------------------------\n");
    

    



   

    // printf("In_Encrypt : M' : \n");
    // poly_ZwCnC3_print(M);
    // printf("\n------------------------------------\n");

    poly_ZwCnC3_add(&E,&M,&E);

    poly_ZwCnC3_mod(&E,q,&E);

    // printf("CipherText_In_Encrypt : M' : \n");
    // poly_ZwCnC3_print(E);
    // printf("\n------------------------------------\n");
    CnC3_to_poly(&E,e);

    // printf("Cipher polynomial: \n");poly_Zw_print(e,N3);

    poly_pack_Sq_tobytes(c,e);

    //  printf("\n*******************   OUTPUT OF ENCRYPT           ****************************\n");

    // for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d ,",c[i]);
    // }

    // printf("\n***********************************************\n");
}

// group_ring *F, group_ring* E,Term P, Term q, group_ring *A

void ppke_decrypt(Term *a, const unsigned char * ciphertext, Term *f){

    // printf("\n Decryption \n");

    Term P = {p_,0};
    Term q = {Q,0};

    group_ring A;
    group_ring F;

    poly_to_CnC3(a,&A);
    poly_to_CnC3(f,&F);

    group_ring E;

    Term e[N3];

    poly_unpack_Sq_frombytes(e,ciphertext);

    poly_to_CnC3(e,&E);

    poly_ZwCnC3_mod(&F,q,&F);
    poly_ZwCnC3_mod(&E,q,&E);

    // printf("CipherText_In_Decrypt : C : \n");
    // poly_ZwCnC3_print(E);
    // printf("\n------------------------------------\n");

    poly_ZwCnC3_mul(&F,&E,T,&A);
    poly_ZwCnC3_mod(&A,q,&A);// A = E*F

    poly_ZwCnC3_mod(&A,P,&A);



    // printf("In_Decrypt : M' : \n");
    // poly_ZwCnC3_print(A);
    // printf("\n------------------------------------\n");


    Term t[N3];
    group_ring T_;
    // group_ring *X;
    // X = &T_;

    // printf("Address of T_ : %u\n",(unsigned char*)(&X));
    // printf("Address of T_ : %u\n",(unsigned char*)(X));
    // // printf("Address of T_ : %u\n",(unsigned char*)(&T));
    // printf("Address of T_ : %u\n",(unsigned char*)(T));

    poly_to_CnC3(t,&T_);

    poly_ZwCnC3_sub(&E,&A,&T_);

    poly_ZwCnC3_mod(&T_,q,&T_);

    for(int i = 0;i<N;i++){
        t[i] = T_.a[i];
        t[i+N] = T_.b[i];
        t[i+2*N] = T_.c[i];
    }



    // printf("In_Decrypt : T : \n");
    // poly_Zw_print(t,N3);
    // printf("\n------------------------------------\n");

    
    Term mask[N3];

    // for(int i = 0;i<N3;i++){

    // }

    unsigned char t_seed[LENGTH_OF_HASH];

    sha3_512(t_seed,(unsigned char*)(&t),N3*2);
    // printf("IN_DECRYPT t_seed : \n");
    // for(int i = 0;i<LENGTH_OF_HASH;i++){
    //     printf("%d ",t_seed[i]);
    // }

    // printf("\n-----------------\n");

    sample_mask(mask,t_seed);

    // printf("in dec mask :\n");
    // poly_Zw_print(mask,N3);
    // printf("\n-------------------\n");


    group_ring MASK;

    poly_to_CnC3(mask,&MASK);

    // printf("IN DECRYPT MASK: ");
    // poly_ZwCnC3_print(&MASK);
    // printf("\n------------------------------------\n");

    // poly_ZwCnC3_mod(&MASK,q,&MASK);
    // poly_ZwCnC3_mod(A,q,A);

    poly_ZwCnC3_add(&A,&MASK,&A);

    poly_ZwCnC3_mod(&A,P,&A);

    CnC3_to_poly(&A,a);
    

    // printf("Decrypted Text:  \n");

    // poly_ZwCnC3_print(A);

    // printf("\n----------------------------\n");

    

    // printf("m1:  \n");

    // poly_ZwCnC3_print(A);

    // printf("\n----------------------------\n");
}
