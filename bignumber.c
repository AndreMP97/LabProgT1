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

BigNumber add(int x, BigNumber n) {
  struct _bignum *temp = newBigNum(x,NULL);
  struct _bignum *last = rest(n);
  if (n -> next == NULL) {
    n -> next = temp;
    return n;
  }
  while (last -> next != NULL) {
    last = last -> next;
  }
  last -> next = temp;
  return n;
}

void printBN(BigNumber n) {
  if (n == NULL) {
    printf("BigNumber não encontrado!\n");
    exit(-1);
  }
  struct _bignum *temp = rest(n);
  printf("%d", first(n));
  while (temp != NULL) {
    printf("%d", first(temp));
    temp = temp -> next;
  }
  printf("\n");
}

int size(BigNumber n) {
  if (n == NULL) {
    printf("BigNumber não encontrado!\n");
    exit(-1);
  }
  int conta=1;
  struct _bignum *temp = rest(n);
  while (temp != NULL) {
    conta++;
    temp = temp -> next;
  }
  return conta;
}
