#include <stdio.h>
#include "fib.h"
#include "list.h"
#include "bignumber.h"

int main() {
  BigNumber n;
  int t;
  for (int i = 0; getchar() != '\n'; i++) {
    if (i==0) {
      scanf("%1d",&t);
      n = newBigNum(t,NULL);
    }
    else {
      scanf("%1d",&t);
      n = newBigNum(t,n);
    }
  }
  printf("First List element: %d\n",first(n));
  printBN(n);
}
//bignum bignum.c list.c main.c
