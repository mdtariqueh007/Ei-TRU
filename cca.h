#include "pke.h"
#include "sample.h"
#include "pack3_CnC3.h"
#include "packq_CnC3.h"

void CCA_keypair(unsigned char* sk,unsigned char *pk){
    Term P = {2,0};
    unsigned char arr_seed[N3_SAMPLE_FG_BYTES]
    pke_keypair(f,g,h,P,arr_seed);

    poly_Sq_tobytes(sk,f);
    poly_Sq_tobytes(pk,h);
}

void CCA_enc(unsigned char* c,const char*m,const unsigned char* pk){
    Term h[N3];
    Term mprime[N3];
    Term phi[N3];

    poly_S3_frombytes(mprime,m);

    unsigned char tmpmsg[PPKE_MESSAGEBYTES];

    poly_S3_tobytes(tempmsg,mprime);

    poly_Sq_frombytes(h,pk);

    sample_phi(phi,h,mprime);

    group_ring H;
    group_ring MPRIME;
    Term P = {2,0};
    Term q = {Q,0};
    group_ring E;
    E.a = (Term*)malloc(N*sizeof(Term));
    E.b = (Term*)malloc(N*sizeof(Term));
    E.c = (Term*)malloc(N*sizeof(Term));

    pke_encrypt(&H, &MPRIME,phi,P,q,&E);

    Term ciphertext[N3];

    for(int i = 0;i<N;i++){
        ciphertext[i] = E->a[i];
        ciphertext[i+N] = E->b[i];
        ciphertext[i+2*N] = E->c[i];
    }

    poly_Sq_tobytes(c,ciphertext);

    

    

    


}

void CCA_dec(unsigned char*m, const unsigned char *ciphertext, const unsigned char* secretkey, const unsigned char* publickey){
    Term h[N3];
    Term f[N3];
    Term ct[N3];
    Term phi[N3];

    poly_Sq_frombytes(h,publickey);

    poly_S3_frombytes(f,secretkey);

    poly_S3_frombytes(ct,ciphertext)

    group_ring F;
    group_ring A;
    A.a = (Term*)malloc(N*sizeof(Term));
    A.b = (Term*)malloc(N*sizeof(Term));
    A.c = (Term*)malloc(N*sizeof(Term));
    group_ring M;

    poly_to_CnC3(h,&H);
    poly_to_CnC3(f,&F);
    poly_to_CnC3(ct,&M);



    Term P = {2,0};
    Term q = {Q,0};

    poly_Sq_frombytes()
    pke_decrypt(F,M,P,q,A);

    Term message[N3];

    for(int i = 0;i<N;i++){
        message[i] = A->a[i];
        message[i+N] = A->b[i];
        message[i+2*N] = A->c[i];
    }

    Term copy_message[N3];

    for(int i = 0;i<N3;i++){
        copy_message[i] = message[i];
    }

    sample_phi(phi,h,copy_message);

    

    


}



