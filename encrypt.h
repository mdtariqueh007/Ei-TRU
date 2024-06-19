#ifndef ENCRYPT_H
#define ENCRYPT_H

#include "sample.h"
#include "poly_r.h"


#define encrypt CRYPTO_NAMESPACE(encrypt)
void encrypt(group_ring *H, group_ring* PHI, group_ring* M,Term P,Term q, group_ring *E);

#endif



