CC=/usr/bin/cc
LDFLAGS=-lcrypto
CFLAGS = -DCRYPTO_NAMESPACE\(s\)=ntru_\#\#s

SOURCES = crypto_sort_int32.c poly_Zw_add.c poly_Zw_add3.c poly_Zw_mod_q.c poly_Zw_mul.c poly_Zw_cmp.c poly_Zw_print.c poly_Zw_shift_t.c poly_Zw_sub.c mainCheck.c rng.c poly_ZwCnC3_mul.c poly_ZwCnC3_print.c sample_lf.c sample_lg.c sample_lm.c sample_lphi.c poly_to_CnC3.c poly_Zw_mul_p.c poly_ZwCnC3_add.c poly_ZwCnC3_mod.c encrypt.c decrypt.c inverse.c key_gen.c fips202.c pke.c
HEADERS = crypto_sort_int32.h params.h poly.h rng.h poly_r.h sample.h encrypt.h decrypt.h inverse.h key_gen.h fips202.h crypto_hash_sha3256.h pke.h pack3_CnC3.h packq_CnC3.h

mainCheck: $(HEADERS) $(SOURCES)
	$(CC) -DCRYPTO_NAMESPACE\(s\)=ntru_\#\#s -o $@ $(SOURCES) $(LDFLAGS)

.PHONY: clean

clean:
	-rm mainCheck