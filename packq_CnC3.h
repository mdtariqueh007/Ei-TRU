#include "poly.h"
#include<stdio.h>

void poly_Sq_tobytes(unsigned char *r, const Term *a)
{

    Term q = {Q,0};

    // Term copy[N3];

    // poly_Zw_mod_q(a,q,copy);

    // printf("\n----------------------------Copy-----------------------\n");

    // poly_Zw_print(copy,N3);

    // printf("\n----------------------------  -----------------------\n");
   
  int i,j;
  int16_t t[8];
//   Term arr[4];

  int k = 0;

  for(i=0;i<PACK_DEG/8;i++)
  {
    for(j=0;j<8;j+=2){
        Term temp = a[k++];
        temp.a = (temp.a%(q.a) + q.a)%q.a;
        temp.b = (temp.b%(q.a) + q.a)%q.a;
        // printf("(%d + %dw)\n",newTemp.a,newTemp.b);
      t[j] = temp.a;
      t[j+1] = temp.b;
    }
    printf("\n************************************\n");
    for(int i = 0;i<8;i++){
        printf("%d ",t[i]);
    }
    printf("\n***********************************\n");

    r[11 * i + 0] = (unsigned char) ( t[0]        & 0xff);
    r[11 * i + 1] = (unsigned char) ((t[0] >>  8) | ((t[1] & 0x1f) << 3));
    r[11 * i + 2] = (unsigned char) ((t[1] >>  5) | ((t[2] & 0x03) << 6));
    r[11 * i + 3] = (unsigned char) ((t[2] >>  2) & 0xff);
    r[11 * i + 4] = (unsigned char) ((t[2] >> 10) | ((t[3] & 0x7f) << 1));
    r[11 * i + 5] = (unsigned char) ((t[3] >>  7) | ((t[4] & 0x0f) << 4));
    r[11 * i + 6] = (unsigned char) ((t[4] >>  4) | ((t[5] & 0x01) << 7));
    r[11 * i + 7] = (unsigned char) ((t[5] >>  1) & 0xff);
    r[11 * i + 8] = (unsigned char) ((t[5] >>  9) | ((t[6] & 0x3f) << 2));
    r[11 * i + 9] = (unsigned char) ((t[6] >>  6) | ((t[7] & 0x07) << 5));
    r[11 * i + 10] = (unsigned char) ((t[7] >>  3));
  }

  for(j=0;j<PACK_DEG-8*i;j+=2){

    Term temp = a[k++];
        temp.a = (temp.a%(q.a) + q.a)%q.a;
        temp.b = (temp.b%(q.a) + q.a)%q.a;
      t[j] = temp.a;
      t[j+1] = temp.b;
  }
  for(; j<8; j++)
    t[j] = 0;

  switch(PACK_DEG&0x07)
  {
    // cases 0 and 6 are impossible since 2 generates (Z/n)* and
    // p mod 8 in {1, 7} implies that 2 is a quadratic residue.
    case 4:
      r[11 * i + 0] = (unsigned char) (t[0]        & 0xff);
      r[11 * i + 1] = (unsigned char) (t[0] >>  8) | ((t[1] & 0x1f) << 3);
      r[11 * i + 2] = (unsigned char) (t[1] >>  5) | ((t[2] & 0x03) << 6);
      r[11 * i + 3] = (unsigned char) (t[2] >>  2) & 0xff;
      r[11 * i + 4] = (unsigned char) (t[2] >> 10) | ((t[3] & 0x7f) << 1);
      r[11 * i + 5] = (unsigned char) (t[3] >>  7) | ((t[4] & 0x0f) << 4);
      break;
    case 3:
      r[11 * i + 0] = (unsigned char) (t[0]        & 0xff);
      r[11 * i + 1] = (unsigned char) (t[0] >>  8) | ((t[1] & 0x1f) << 3);
      r[11 * i + 2] = (unsigned char) (t[1] >>  5) | ((t[2] & 0x03) << 6);
      r[11 * i + 3] = (unsigned char) (t[2] >>  2) & 0xff;
      r[11 * i + 4] = (unsigned char) (t[2] >> 10) | ((t[3] & 0x7f) << 1);

    case 2:
      r[11 * i + 0] = (unsigned char) (t[0]        & 0xff);
      r[11 * i + 1] = (unsigned char) (t[0] >>  8) | ((t[1] & 0x1f) << 3);
      r[11 * i + 2] = (unsigned char) (t[1] >>  5) | ((t[2] & 0x03) << 6);
      break;
  }
}

void poly_Sq_frombytes(Term *r, const unsigned char *a)
{
    int arr[2*N3];
  int i;
  for(i=0;i<PACK_DEG/8;i++)
  {
    arr[8*i+0] = (a[11*i+ 0] >> 0) | (((uint16_t)a[11*i+ 1] & 0x07) << 8);
    arr[8*i+1] = (a[11*i+ 1] >> 3) | (((uint16_t)a[11*i+ 2] & 0x3f) << 5);
    arr[8*i+2] = (a[11*i+ 2] >> 6) | (((uint16_t)a[11*i+ 3] & 0xff) << 2) | (((uint16_t)a[11*i+ 4] & 0x01) << 10);
    arr[8*i+3] = (a[11*i+ 4] >> 1) | (((uint16_t)a[11*i+ 5] & 0x0f) << 7);
    arr[8*i+4] = (a[11*i+ 5] >> 4) | (((uint16_t)a[11*i+ 6] & 0x7f) << 4);
    arr[8*i+5] = (a[11*i+ 6] >> 7) | (((uint16_t)a[11*i+ 7] & 0xff) << 1) | (((uint16_t)a[11*i+ 8] & 0x03) <<  9);
    arr[8*i+6] = (a[11*i+ 8] >> 2) | (((uint16_t)a[11*i+ 9] & 0x1f) << 6);
    arr[8*i+7] = (a[11*i+ 9] >> 5) | (((uint16_t)a[11*i+10] & 0xff) << 3);
  }


  switch(PACK_DEG&0x07)
  {
    // cases 0 and 6 are impossible since 2 generates (Z/n)* and
    // p mod 8 in {1, 7} implies that 2 is a quadratic residue.
    case 4:
      arr[8*i+0] = (a[11*i+ 0] >> 0) | (((uint16_t)a[11*i+ 1] & 0x07) << 8);
      arr[8*i+1] = (a[11*i+ 1] >> 3) | (((uint16_t)a[11*i+ 2] & 0x3f) << 5);
      arr[8*i+2] = (a[11*i+ 2] >> 6) | (((uint16_t)a[11*i+ 3] & 0xff) << 2) | (((uint16_t)a[11*i+ 4] & 0x01) << 10);
      arr[8*i+3] = (a[11*i+ 4] >> 1) | (((uint16_t)a[11*i+ 5] & 0x0f) << 7);
      break;

    case 3:
      
      arr[8*i+0] = (a[11*i+ 0] >> 0) | (((uint16_t)a[11*i+ 1] & 0x07) << 8);
      arr[8*i+1] = (a[11*i+ 1] >> 3) | (((uint16_t)a[11*i+ 2] & 0x3f) << 5);
      arr[8*i+2] = (a[11*i+ 2] >> 6) | (((uint16_t)a[11*i+ 3] & 0xff) << 2) | (((uint16_t)a[11*i+ 4] & 0x01) << 10);
      break;

    case 2:
      arr[8*i+0] = (a[11*i+ 0] >> 0) | (((uint16_t)a[11*i+ 1] & 0x07) << 8);
      arr[8*i+1] = (a[11*i+ 1] >> 3) | (((uint16_t)a[11*i+ 2] & 0x3f) << 5);
      break;
  }
  int k = 0;

  Term q = {Q,0};

  for(int i = 0;i<N3;i++){
    r[i].a = arr[k++];
    r[i].b = arr[k++];
  }
  // r->coeffs[NTRU_N-1] = 0;
}