#include "sample.h"
#include "rng.h"
#include "crypto_hash_sha3256.h"
#include <string.h>

void sample_lphi(Term* r,const unsigned char u[N3_SAMPLE_BYTES]){
    sample_lg(r,u);
}  

void sample_phi(Term* phi,const Term* h, const Term* m){
    unsigned char r_seed[2*LENGTH_OF_HASH];

    sha3_512(r_seed,(unsigned char*)(m), N3);
    sha3_512(r_seed+LENGTH_OF_HASH,(unsigned char*)(h), N3);

    int filled = 0;

    unsigned char uniformbytes[N3_SAMPLE_BYTES];

    sha3_512(r_seed,r_seed,LENGTH_OF_HASH*2);

    while(filled<N3_SAMPLE_BYTES){
        int rem = N3_SAMPLE_BYTES - filled;
        if(rem>=LENGTH_OF_HASH){
            memcpy(uniformbytes+filled,r_seed,LENGTH_OF_HASH);
        }
        else{
            memcpy(uniformbytes+filled,r_seed,rem);
        }
        filled += LENGTH_OF_HASH;
        sha3_512(r_seed,r_seed,LENGTH_OF_HASH);
    }
    sample_lphi(phi,uniformbytes);

    
}

