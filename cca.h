#include "ppke.h"
#include "sample.h"
// #include "pack3_CnC3.h"
// #include "packq_CnC3.h"


void CCA_keypair(unsigned char* pk,unsigned char *sk){
    
    unsigned char arr_seed[N3_SAMPLE_FG_BYTES];
    randombytes(arr_seed,N3_SAMPLE_FG_BYTES);

    ppke_keypair(pk,sk,arr_seed);  
}

void CCA_encrypt(unsigned char *c,const unsigned char *m,unsigned char *pk){
    Term h[N3];
    Term phi[N3];
    Term mprime[N3];

    poly_S3m_frombytes(mprime,m);

    // printf("\n*******************   ORIGINAL MESSAGE TEXT           ****************************\n");

    // for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d ,",m[i]);
    // }


    // printf("\n***********************************************\n");

    // printf("\n*******************   MPRIME MESSAGE           ****************************\n");

    // poly_Zw_print(mprime,N3);

    // printf("\n***********************************************\n");

    unsigned char tmpmsg[CHAR_BYTES];

    poly_S3m_tobytes(tmpmsg,mprime);

    // printf("\n*******************   TEMP MESSAGE TEXT           ****************************\n");

    // for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d ,",tmpmsg[i]);
    // }
    

    // printf("\n***********************************************\n");

    poly_unpack_Sq_frombytes(h,pk);

    sample_phi(phi,h,mprime);

    ppke_encrypt(c,phi,h,mprime);
    // printf("In encryption\n");

    // printf("\n*******************   MPRIME MESSAGE           ****************************\n");

    // poly_Zw_print(mprime,N3);

    // printf("\n***********************************************\n");
}

int CCA_decrypt(unsigned char *m, const unsigned char* ciphertext, unsigned char *secretkey, const unsigned char* publickey){
    
    Term h[N3];
    Term f[N3];
    Term phi[N3];
    Term message[N3];


    // printf("In decryption\n");

    // printf("Secret key:\n");for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d, ",secretkey[i]);
    // }
    // printf("\n");

    // secretkey[0]++;

    poly_unpack_Sq_frombytes(h,publickey);

    poly_S3_frombytes(f,secretkey);

    f[0].a += 1;

    // printf("f:\n");poly_Zw_print(f,N3);

    //  printf("\n*******************   INPUT OF DECRYPT          ****************************\n");

    // for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d ,",ciphertext[i]);
    // }
    // printf("\n***********************************************\n");
    //  printf("\n*******************   F          ****************************\n");

    // poly_Zw_print(f,N3);
    // printf("\n***********************************************\n");
    //  printf("\n*******************   H          ****************************\n");

    // poly_Zw_print(h,N3);
    // printf("\n***********************************************\n");

    ppke_decrypt(message,ciphertext,f);

    Term copy_message[N3];
    for(int i = 0;i<N3;i++){
        copy_message[i] = message[i];
    }

    // printf("\n*******************   DECRYPTED MESSAGE           ****************************\n");

    // poly_Zw_print(message,N3);

    // printf("\n***********************************************\n");


    sample_phi(phi,h,copy_message);

    unsigned char cprime[CHAR_BYTES];

    ppke_encrypt(cprime,phi,h,copy_message);

    // printf("cprime\n"); for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d ",cprime[i]);
    // }
    // printf("\n");
    // printf("ciphertext\n"); for(int i = 0;i<CHAR_BYTES;i++){
    //     printf("%d ",ciphertext[i]);
    // }
    // printf("\n");

    int cnt = 0;

    for(int i = 0;i<(CHAR_BYTES);i++){
        if(cprime[i]!=ciphertext[i]){
            cnt++;
            printf("%d: (%d,%d)",i,cprime[i],ciphertext[i]);
            printf("decryption failure\n");
            return -1;
        }
    }

    printf("Incorrect at %d indices\n",cnt);

    poly_S3m_tobytes(m,message);
    return 0;
}



