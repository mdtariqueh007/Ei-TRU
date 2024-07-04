CC=/usr/bin/cc
LDFLAGS=-lcrypto

CFLAGS = -DCRYPTO_NAMESPACE\(s\)=ntru_\#\#s

SOURCES = crypto_sort_int32.c poly_Zw_add.c poly_Zw_add3.c poly_Zw_mod_q.c poly_Zw_mul.c poly_Zw_cmp.c poly_Zw_print.c poly_Zw_shift_t.c poly_Zw_sub.c main.c rng.c poly_ZwCnC3_mul.c poly_ZwCnC3_print.c sample_lf.c sample_lg.c sample_lm.c sample_lphi.c poly_to_CnC3.c poly_Zw_mul_p.c poly_ZwCnC3_add.c poly_ZwCnC3_mod.c inverse.c fips202.c ppke.c cca.c pack3_CnC3.c packq_CnC3.c cpucycles.c helper.c Zw_CnC3_multiply.c
HEADERS = crypto_sort_int32.h params.h poly.h rng.h poly_r.h sample.h inverse.h fips202.h crypto_hash_sha3256.h ppke.h pack3_CnC3.h packq_CnC3.h cca.h cpucycles.h helper.h

main: $(HEADERS) $(SOURCES)
	$(CC) -DCRYPTO_NAMESPACE\(s\)=ntru_\#\#s -o $@ $(SOURCES) $(LDFLAGS)

.PHONY: clean

clean:
	-rm main