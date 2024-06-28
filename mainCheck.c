#include <stdio.h>

// #include "poly_r.h"
// #include "sample.h"
// #include "rng.h"

// #include "crypto_sort_int32.h"



#include<time.h>

// #include "pke.h"
// #include "ppke.h"

#include "pack3_CnC3.h"
#include "packq_CnC3.h"
#include "cca.h"

#define test_cases 100


int main(){
    /////////////////////////////////////////////
    clock_t t_; 
    t_ = clock(); 
    // fun(); 
    

    
    int test = test_cases;

    while(test--){

        printf("Test %d: \n",test_cases - test );

    // Term f[N3];
    // Term fq[N3];
    // Term g[N3];

    // Term h[N3];



    

     
    // group_ring H;
    // group_ring PHI;
    // group_ring M;
    // group_ring Original_M;
    // group_ring E;
    // E.a = (Term*)malloc(N*sizeof(Term));
    // E.b = (Term*)malloc(N*sizeof(Term));
    // E.c = (Term*)malloc(N*sizeof(Term));
    // group_ring F;
    // group_ring A;
    // A.a = (Term*)malloc(N*sizeof(Term));
    // A.b = (Term*)malloc(N*sizeof(Term));
    // A.c = (Term*)malloc(N*sizeof(Term));
    // Term P = {2,0};
    // Term q = {Q,0};

    ///////////////////////////////////

    // Term a[N3] = {{-1, -2}, {-2, -2}, {-2, -2}, {0, 2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {-2, 0}, {0, 0}, {0, -2}, {0, 0}, {0, -2}, {-2, -2}, {2, 2}, {2, 0}, {2, 2}, {0, 0}, {-2, 0}, {-2, -2}, {0, 2}, {0, -2}, {2, 0}, {0, 0}, {2, 0}, {0, 2}, {-2, 0}, {-2, 0}, {-2, -2}, {2, 0}, {2, 0}, {0, 0}, {-2, -2}, {2, 2}, {0, 2}, {-2, 0}, {0, 0}, {0, 2}, {-2, -2}, {0, 0}, {0, 0}, {0, 0}, {2, 2}, {0, -2}, {0, 2}, {2, 2}, {-2, 0}, {-2, 0}, {0, 2}, {0, 2}, {0, 0}, {2, 2}, {2, 2}, {0, 2}, {2, 2}, {-2, -2}, {2, 0}, {0, -2}, {0, 0}, {0, -2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {2, 0}, {-2, 0}, {0, 2}, {-2, -2}, {0, 0}, {0, 0}, {0, 0}, {0, 2}, {2, 2}, {-2, -2}, {-2, -2}, {2, 2}, {-2, -2}, {0, 0}, {2, 2}, {0, 0}, {0, 0}, {0, 2}, {0, 2}, {-2, -2}, {0, 2}, {0, 2}, {-2, 0}, {0, 0}, {0, 2}, {-2, 0}, {0, 0}, {2, 2}, {2, 2}, {-2, -2}, {-2, 0}, {0, 0}, {0, -2}, {-2, 0}, {2, 0}, {-2, 0}, {-2, -2}, {0, -2}, {-2, 0}, {0, 0}, {2, 0}, {0, 0}, {2, 0}, {0, 0}, {2, 2}, {-2, -2}, {0, -2}, {-2, -2}, {0, 0}, {2, 0}, {0, 0}, {0, 2}, {0, -2}, {0, 0}, {0, 0}, {0, -2}, {2, 0}, {2, 2}, {0, 0}, {0, 2}, {0, 0}, {0, 0}, {-2, -2}, {2, 0}, {0, 2}, {0, 0}, {-2, 0}, {0, 0}, {0, 2}, {2, 0}, {-2, 0}, {0, -2}, {0, 0}, {2, 2}, {0, 2}, {2, 0}, {2, 2}, {0, 0}, {0, 0}, {0, 0}, {2, 0}, {-2, 0}, {2, 0}, {0, 0}, {2, 0}, {0, 2}, {0, 0}, {-2, 0}, {-2, -2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {-2, -2}, {-2, 0}, {0, 0}, {2, 2}, {0, 0}, {-2, 0}, {2, 0}, {2, 2}, {0, 0}, {2, 2}, {2, 2}, {0, 2}, {2, 0}, {0, 0}, {0, -2}, {0, 0}, {0, -2}, {0, 0}, {-2, 0}, {-2, 0}, {-2, 0}};
    // Term a_inv[N3];


    // Almost_inverse_ZpwCnC3(a,Q,a_inv);



    // generate_keys(f,fq,g,h,P);

    ///////////////////////////////////////////////////////////////////////

    // unsigned char fg_seed[N3_SAMPLE_FG_BYTES];

    // randombytes(fg_seed,N3_SAMPLE_FG_BYTES);

    // pke_keypair(f,g, h, P,fg_seed);

    
    // printf("\n----------------------Public key ------------------------------------------\n");
    // poly_Zw_print(h,N3);
    // printf("\n----------------------              ------------------------------------------\n");
    // poly_to_CnC3(h,&H);

    // unsigned char a[(LOGQ*N3+3)/4];

    // poly_pack_Sq_tobytes(a,h);

    // for(int i = 0;i<(LOGQ*N3+3)/4;i++){
    //     printf("%d ",a[i]);
    // }

    // printf("\n");

    // Term res[N3];

    // poly_unpack_Sq_frombytes(h,a);

    

    // printf("Unpacking: \n");
    // poly_Zw_print(h,N3);
    // poly_to_CnC3(h,&H);

    // int cnt = 0;
    // for(int i = 0;i<N3;i++){
    //     if(res[i].a!=h[i].a || res[i].b!=h[i].b){
    //         cnt++;
    //         printf("%d\n",i);
    //     }
    // }

    // printf("Incorrect at %d places\n",cnt);

    // return 0;
    




    ////////////////////////////////////////////////////////////////

    // unsigned char arr_seed[N3_SAMPLE_BYTES];

    // randombytes(arr_seed,N3_SAMPLE_BYTES);

    // Term phi[N3];

    // sample_lphi(phi,arr_seed);

    // poly_to_CnC3(phi,&PHI);

    /////////////////////////////////////////////////////

    // unsigned char arr_seed_m[N3_SAMPLE_M_BYTES];

    // randombytes(arr_seed_m,N3_SAMPLE_M_BYTES);

    // Term m[N3];


    // sample_lm(m,arr_seed_m);

    // poly_to_CnC3(m,&M);
    // poly_to_CnC3(m,&Original_M);

    ////////////////////////////////////////////////////////////

    // printf("\n-----------------M---------------------\n");

    // poly_ZwCnC3_print(&Original_M);

    // printf("\n-------------------M--------------------\n");

    ////////////////////////////////////////////////////////////

    // unsigned char arr_seed[N3_SAMPLE_BYTES];

    // randombytes(arr_seed,N3_SAMPLE_BYTES);

    // Term phi[N3];

    // sample_lphi(phi,arr_seed);

    // pke_encrypt(&H,&M,phi,P,q,&E);

    ///////////////////////////////////////////////////////////



    // printf("\n-----------------E---------------------\n");

    // poly_ZwCnC3_print(&E);

    // printf("\n-------------------E--------------------\n");

    ///////////////////////////////////////

    // poly_to_CnC3(f,&F);

    
    

    // pke_decrypt(&F,&E,P,q,&A);

    //////////////////////////////////

    // printf("\n-----------------A---------------------\n");

    // poly_ZwCnC3_print(&A);

    // printf("\n-------------------A--------------------\n");



    
/////////////////////////////////////////////////////
    // int one = 0;
    // int y = 0;
    // int y2 = 0;

    // if(poly_Zw_cmp(Original_M.a,A.a)){
    //     one = 1;
    // }
    // else{
    //     one = 0;
    // }
    // if(poly_Zw_cmp(Original_M.b,A.b)){
    //     y = 1;
    // }
    // else{
    //     y = 0;
    // }
    // if(poly_Zw_cmp(Original_M.c,A.c)){
    //     y2 = 1;
    // }
    // else{
    //     y2 = 0;
    // }

    // printf("%d %d %d\n",one,y,y2);

    // if(one && y && y2){
    //     printf("True\n");
        
    // }
    // else{
    //     printf("False\n");
    // }


    // unsigned char pk[CHAR_BYTES];
    // unsigned char sk[CHAR_BYTES];

    // unsigned char fg_seed[N3_SAMPLE_FG_BYTES];

    // randombytes(fg_seed,N3_SAMPLE_FG_BYTES);

    // ppke_keypair(pk, sk,fg_seed);

    // unsigned char c[CHAR_BYTES];

    // unsigned char arr_seed[N3_SAMPLE_BYTES];

    // randombytes(arr_seed,N3_SAMPLE_BYTES);

    // Term phi[N3];

    // sample_lphi(phi,arr_seed); 

    // unsigned char arr_seed_m[N3_SAMPLE_M_BYTES];

    // randombytes(arr_seed_m,N3_SAMPLE_M_BYTES);

    // Term m[N3];


    // sample_lm(m,arr_seed_m);
    
    // Term h[N3];

    // poly_unpack_Sq_frombytes(h,pk);

    // ppke_encrypt(c,phi,h,m);

    // // unsigned char a[CHAR_BYTES];

    // Term f[N3];

    // poly_unpack_Sq_frombytes(f,sk);

    // Term retrieved_msg[N3];
    // ppke_decrypt(retrieved_msg, c,f);

    // // Term original_msg[N3];

    // // poly_unpack_Sq_frombytes(original_msg,m);
    // // poly_unpack_Sq_frombytes(retrieved_msg,a);

    // poly_Zw_print(m,N3);
    // poly_Zw_print(retrieved_msg,N3);

    // int cnt_ = 0;

    // for(int i = 0;i<N3;i++){
    //     if(m[i].a!=retrieved_msg[i].a || m[i].b!=retrieved_msg[i].b){
    //         cnt_++;
    //         printf("%d \n",i);
    //     }
    // }

    // printf("Incorrect cnt : %d\n",cnt_);

    // if(poly_Zw_cmp(m,retrieved_msg,N3)){
    //     printf("True\n");
    // }
    // else{
    //     printf("False\n");
    // }


    //****************************************************************** */

    unsigned char pk[CHAR_BYTES];
    unsigned char sk[PPKE_MESSAGEBYTES];
    // printf("CHAR_BYTES : %d\n",CHAR_BYTES);
    // int CHAR = 1;
    // unsigned char random[CHAR];

    // printf("Start address of sk : %d\n",&sk[0]);
    // printf("End address of sk : %d\n",&sk[CHAR_BYTES-1]);
    // printf("start address of random : %d\n",&random[0]);

    



    CCA_keypair(pk,sk);

    // printf("%d is size of sk\n",sizeof(sk));

    // printf("Key generation:\n");
    // for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d, ",sk[i]);
    // }
    // printf("\n");

    // for(int i = 0;i<CHAR_BYTES;i++){
    //     sk_copy[i] = sk[i];
    // }


    unsigned char arr_seed_m[N3_SAMPLE_M_BYTES];

    randombytes(arr_seed_m,N3_SAMPLE_M_BYTES);
     

    Term m[N3];

    sample_lm(m,arr_seed_m);

   

    /******************************************************* */

    // printf("\n*******************   ORIGINAL MESSAGE           ****************************\n");

    // poly_Zw_print(m,N3);

    // printf("\n***********************************************\n");

    /************************************** */

    unsigned char message[PPKE_MESSAGEBYTES];
    unsigned char c[CHAR_BYTES];
    unsigned char a[PPKE_MESSAGEBYTES];

    poly_S3m_tobytes(message,m);

    //  printf("Key generation before encryption:\n");
    // for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d, ",sk[i]);
    // }


    /******************************************* */

    // printf("message packed: \n"); for(int i = 0;i<PPKE_MESSAGEBYTES;i++){
    //     printf("%d ",message[i]);
    // }
    // printf("\n");

    // Term unpacked_message[N3];

    // poly_unpack_Sq_frombytes(unpacked_message,message);

    // printf("unpacked message:\n");
    // poly_Zw_print(unpacked_message,N3);

    // int cnt = 0;

    // for(int i = 0;i<N3;i++){
    //     if(m[i].a!=unpacked_message[i].a || m[i].b!=unpacked_message[i].b){
    //         printf("%d \n",i);
    //         cnt++;
    //     } 
    // }

    // printf("Incorrect at %d unpacking\n",cnt);

    /*************************************************** */

    // printf("CHAR_BYTES : %d\n",CHAR_BYTES);
    // printf("PPKE_MESSAGEBYTES : %d\n",PPKE_MESSAGEBYTES);
    // printf("CIPHERTEXTBYTES : %d\n",CIPHERTEXTBYTES);

    printf("PPKE_SECRETKEYBYTES : %d\n",PPKE_SECRETKEYBYTES);
   
    

    CCA_encrypt(c,message,pk);
    // printf("In main\n");


       


    int ret_val = CCA_decrypt(a,c,sk,pk);

    if(ret_val==0){
        printf("Successfull\n");
    }

    /********************************************** */




    

    







    





    



    // printf("\n-------------End --------------\n");

    
    }

    t_ = clock() - t_; 
    double time_taken = ((double)t_)/CLOCKS_PER_SEC; // in seconds 
 
    printf("Took %f seconds to execute \n", time_taken);

    ///////////////////////////////////////////////////////////////////

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



    // Term A[12] = {{-1,-1},{1,0},{0,1},{0,0},{-1,-1},{1,0},{0,1},{0,0},{-1,-1},{1,0},{0,1},{-1,-1}};
    // Term B[12];
    // int arr[4];

    // poly_S4_map(A,arr);

    // for(int i = 0;i<4;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");

    // poly_Zw_print(A,12);


    // unsigned char msg[PPKE_MESSAGEBYTES];

    // poly_S3_tobytes(msg,A);

    // for(int i = 0;i<PPKE_MESSAGEBYTES;i++){
    //     printf("%d ",msg[i]);
    // }

    // printf("\n");

    // poly_S3_frombytes(B,msg);

    // poly_Zw_print(B,12);

    // printf("Mod check\n");

    // Term L = {-53,-89};
    // Term q = {11,0};

    // Term remainder = poly_div_rat(L,q);

    // printf("(%d + %dw)\n",remainder.a,remainder.b);

    







    
    

    return 0;

}