#ifndef DECRYPT_H
#define DECRYPT_H

#include "sample.h"
#include "poly_r.h"

#define decrypt CRYPTO_NAMESPACE(decrypt)
void decrypt(group_ring *F, group_ring* E,Term P, Term q, group_ring *A);

#endif