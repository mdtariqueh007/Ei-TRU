#ifndef KEY_GEN_H
#define KEY_GEN_H

#include "poly_r.h"
#include <stdio.h>
#include "sample.h"

// #include "Almost_inverse_ZpwCn.h"
#include "inverse.h"
#include "rng.h"

#define generate_keys CRYPTO_NAMESPACE(generate_keys)
void generate_keys(Term *f,Term *fq ,Term *g, Term *h, Term P);

#endif



