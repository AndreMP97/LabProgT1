#include <stdio.h>
#include <stdlib.h>
#include "bignumber.h"
#include <stdbool.h>

BigNumber newBigNum(int elem, BigNumber rest) {
  BigNumber n = (BigNumber) malloc(sizeof(*n));
  if (n == NULL) {
    printf("NO MEMORY AVAILABLE!\n");
    abort();
  }
  n -> value = elem;
  n -> next = rest;
  return n;
}

int first(BigNumber n) {
  if (n == NULL) {
    printf("BigNumber não encontrado!\n");
    exit(-1);
  }
  return n -> value;
}

BigNumber rest(BigNumber n) {
  if (n == NULL) {
    printf("BigNumber não encontrado!\n");
    exit(-1);
  }
  return n -> next;
}

void printBN(BigNumber n) {
  if (n == NULL) {
    printf("BigNumber não encontrado!\n");
    exit(-1);
  }
  struct _bignum *temp = rest(n);
  printf("%d ", first(n));
  while (temp != NULL) {
    printf("%d ", first(temp));
    temp = temp -> next;
  }
  printf("\n");
}
