#include "poly.h"

void poly_Zw_shift_t(const Term *f ,int t, Term* r){
    
    // int curr = 0;

    // for(int i = 0;i<N;i++){
    //     // int ind = curr;
    //     r[curr] = f[i];
    //     curr += t;
    //     while(curr>=N){
    //         curr -= N;
    //     }

    // }

    for(int i = 0;i<N;i++){
        r[(i*t)%N] = f[i];
    }

}