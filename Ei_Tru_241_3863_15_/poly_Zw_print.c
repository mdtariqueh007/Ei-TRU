#include "poly.h"
#include <stdio.h>

void poly_Zw_print(Term *p,int len){
    for(int i = 0;i<len;i++){
        printf("(%d + %dw)x^%d",p[i].a,p[i].b,i);
        if(i<len-1){
            printf("+ ");
        }
    }

    printf("\n");
}