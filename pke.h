#ifndef PKE_H
#define PKE_H

#include "poly_r.h"
#include "sample.h"
#include "rng.h"
#include "crypto_sort_int32.h"
#include "encrypt.h"
#include "decrypt.h"
#include "key_gen.h"
#include "crypto_hash_sha3256.h"


#define pke_keypair CRYPTO_NAMESPACE(pke_keypair)
#define pke_encrypt CRYPTO_NAMESPACE(pke_encrypt)
#define pke_decrypt CRYPTO_NAMESPACE(pke_decrypt)
void pke_keypair(Term *f,Term *g, Term *h, Term P,unsigned char arr_seed[N3_SAMPLE_FG_BYTES]);
void pke_encrypt(group_ring* H, group_ring* M,Term *phi,Term P,Term q,group_ring*E);
void pke_decrypt(group_ring *F, group_ring* E,Term P, Term q, group_ring *A);

#endif






