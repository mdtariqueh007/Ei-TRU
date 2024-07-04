#ifndef PARAMS_H
#define PARAMS_H

#include <math.h>

#define N 127
#define T 19
#define Q 2039
#define p_ 2
#define N3 3*N
// #define LOGQ
#define N_SAMPLE_BYTES ((30*(N-1)+7)/8)
#define N3_SAMPLE_BYTES ((30*(N3-1)+7)/8)
#define N3_SAMPLE_M_BYTES ((32*(N3)+7)/8)

#define LOGQ (int)ceil(log2(4.0*Q/3.0))


// #if Q == 1013
// #define CHAR_BYTES (LOGQ*N3*2+7)/8 + 1
// #else 
#define CHAR_BYTES (LOGQ*N3*2+15)/8 //added 1 for Q==1013
// #endif


#define T_SAMPLE_BYTES ((30*(2*N)+7)/8)
#define SAMPLE_BYTE 0

#define N3_SAMPLE_F_BYTES N3_SAMPLE_BYTES+T_SAMPLE_BYTES
#define N3_SAMPLE_FG_BYTES N3_SAMPLE_F_BYTES+N3_SAMPLE_BYTES
// #define N3_SAMPLE_M_BYTES N3_SAMPLE_BYTES
// #define N3_SAMPLE_M_BYTES N3_SAMPLE_BYTES+SAMPLE_BYTE

#define LENGTH_OF_HASH 64

#define PACK_DEG (2*N3)
#define PACK_TRINARY_BYTES ((PACK_DEG+4)/5)
// #define PACK_TRINARY_BYTES ((PACK_DEG)/7)

#define PPKE_MESSAGEBYTES (PACK_TRINARY_BYTES)
// #define PPKE_MESSAGEBYTES (CHAR_BYTES)

#define PPKE_CIPHERTEXTBYTES (CHAR_BYTES)
#define PPKE_SECRETKEYBYTES (PPKE_MESSAGEBYTES)
#define PPKE_PUBLICKEYBYTES (PPKE_MESSAGEBYTES)

#define CRYPTO_SECRETKEYBYTES PPKE_SECRETKEYBYTES
#define CRYPTO_PUBLICKEYBYTES PPKE_CIPHERTEXTBYTES
#define CRYPTO_CIPHERTEXTBYTES PPKE_CIPHERTEXTBYTES
#define CRYPTO_BYTES 32

#define CRYPTO_ALGNAME "Ei_Tru_127_2039_19"

#ifndef CRYPTO_NAMESPACE
#define CRYPTO_NAMESPACE(s) s
#endif

#endif