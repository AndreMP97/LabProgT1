#ifndef _B
#define _B

typedef struct _bignum {
  int value; //valor
  struct _bignum *next;
} *BigNumber;

BigNumber newBigNum(int elem, BigNumber rest);
int first(BigNumber n);
BigNumber rest(BigNumber n);
void printBN(BigNumber n);
//BigNumber add
//BigNumber sub
//BigNumber mult
//BigNumber div
#endif
