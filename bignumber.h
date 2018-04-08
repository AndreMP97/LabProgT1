#ifndef _B
#define _B

typedef struct _bignum {
  int value; //valor
  struct _bignum *next;
} *BigNumber;

BigNumber newBigNum(int elem, BigNumber rest);
int first(BigNumber n);
BigNumber rest(BigNumber n);
BigNumber parseBN(int arr[], int len);
BigNumber push(int x, BigNumber n);
BigNumber addNumber(int x, BigNumber n);
void printBN(BigNumber n);
int size(BigNumber n);
BigNumber sumBN(BigNumber n1, BigNumber n2);
//BigNumber sub
//BigNumber mult
//BigNumber div
#endif
