#include <stdio.h>
#include <stdlib.h>
#include "bignumber.h"
#include "list.h"
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

BigNumber addNumber(int x, BigNumber n) {
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
    return;
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

BigNumber sumBN(BigNumber n1, BigNumber n2) {
  if (n1 == NULL) {
    return n2;
  }
  else if (n2 == NULL) {
    return n1;
  }
 else {
   List l1 = BigNumbertoList(n1), l2 = BigNumbertoList(n2), result = (List) malloc(sizeof(*result));
   result = addList(l1,l2);
   printf("***DEBUG***\n");
   printf("Lista 1 = ");
   printlist(l1);
   printf("Lista 2 = ");
   printlist(l2);
   printf("Lista 3 = ");
   printlist(result);
 }
 return NULL;
}
