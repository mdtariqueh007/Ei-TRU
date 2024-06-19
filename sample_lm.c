#include "sample.h"
#include "crypto_hash_sha3256.h"
#include <string.h>

void sample_fixed_type_lm(int *r, const unsigned char u[N3_SAMPLE_BYTES])
{
    int32_t s[N3];
    int i;

    for (i = 0; i < (N3); i++)
    {
        s[i] = (u[4*i+0]) + (u[4*i+1]<<8) + (u[4*i+2]<<16) + (u[4*i+3]<<24);
    }

    for(int i = 0;i<(N3);i++){
        r[i] = (s[i] & 3);
    }

    // r[N-1] = 0;
}

void sample_lm(Term *r, const unsigned char u[N3_SAMPLE_BYTES]){
    int map[4][2] = {{0,0},{1,0},{0,1},{-1,-1}};

    int arr[N3];

    sample_fixed_type_lm(arr,u);

    for(int i = 0;i<N3;i++){
        r[i].a = map[arr[i]][0];
        r[i].b = map[arr[i]][1];
    }
}



void sample_mask(Term* mask,unsigned char t_seed[LENGTH_OF_HASH]){
    unsigned char uniformbytes[N3_SAMPLE_M_BYTES];
    int filled = 0;

    sha3_512(t_seed,t_seed,LENGTH_OF_HASH);

    while(filled<N3_SAMPLE_M_BYTES){
        int rem = N3_SAMPLE_M_BYTES - filled;
        if(rem>=LENGTH_OF_HASH){
            memcpy(uniformbytes+filled,t_seed,LENGTH_OF_HASH);
        }
        else{
            memcpy(uniformbytes+filled,t_seed,rem);
            
        }
        filled += LENGTH_OF_HASH;
        sha3_512(t_seed,t_seed,LENGTH_OF_HASH);
    }
    sample_lm(mask,uniformbytes);
}