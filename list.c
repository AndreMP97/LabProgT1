#include <stdio.h>
#include <stdlib.h>
#include "bignumber.h"
#include "list.h"
#include <stdbool.h>

List newList(int h, List rest) {
  List l = (List) malloc(sizeof(*l));
  if (l == NULL) {
    printf("NO MEMORY AVAILABLE!\n");
    abort();
  }
  l -> n = h;
  l -> next = rest;
  return l;
}

int head(List l) {
  if (l == NULL) {
    printf("Lista vazia!\n");
    exit(-1);
  }
  return l -> n;
}

List tail(List l) {
  if (l == NULL) {
    printf("Lista vazia!\n");
    exit(-1);
  }
  return l -> next;
}

void printlist(List l) {
  if (l == NULL) {
    printf("Lista vazia!\n");
    exit(-1);
  }
  struct _list *temp = tail(l);
  printf("%d ",head(l));
  while (temp != NULL) {
    printf("%d ",head(temp));
    temp = temp->next;
  }
  printf("\n");
}

int length(List l) {
  if (l == NULL) {
    printf("Lista vazia!\n");
    exit(-1);
  }
  int conta=1;
  struct _list *temp = tail(l);
  while (temp != NULL) {
    conta++;
    temp = temp->next;
  }
  return conta;
}

List append(List l1, List l2) {
  if (l1 == NULL) {
    return l2;
  }
  return newList(head(l1),append(tail(l1),l2));
}

void swapList(List l1, List l2) {
  List t = l1;
  l1 = l2;
  l2 = t;
}

int member(int x, List l) {
  if (l == NULL) {
    printf("Lista vazia!\n");
    exit(-1);
  }
  if (x == head(l)) {
    return 1;
  }
  else {
    struct _list *temp = tail(l);
    while (temp != NULL) {
      if (x == head(temp)) {
        return 1;
      }
      temp = temp->next;
    }
  }
  return 0;
}

List BigNumbertoList(BigNumber n) {
  BigNumber temp = n;
  List l = newList(temp -> value, NULL);
  while ((temp = temp -> next) != NULL) {
    l = newList(temp -> value, l);
  }
  return l;
}

List sumList(List l1, List l2, int *carry) {
  if (l2 == NULL) {
    return NULL;
  }
  int sum;
  List result = (List)malloc(sizeof(*result));
  sum = l1 -> n + l2 -> n + *carry;
  *carry = sum/10;
  sum = sum%10;
  result -> n = sum;
  printf("head(l1) = %d | head(l2) = %d | sum = %d\n",head(l1), head(l2), sum);
  result -> next = sumList(l1 -> next, l2 -> next, carry);
  printf("Debug list = ");
  printlist(result);
  return result;
}

void addCarry(List l1, List curr, int *carry, List result) {
  int sum;
  if (l1 != curr) {
    addCarry(l1 -> next, curr, carry, result);
    sum = l1 -> n + *carry;
    *carry = sum/10;
    sum = sum%10;
    result = newList(sum,result);
  }
}

List addList(List l1, List l2) {
  List curr;
  List result = (List)malloc(sizeof(*result));
  if (l1 == NULL) {
    return l2;
  }
  else if (l2 == NULL) {
    return l1;
  }
  int size1 = length(l1), size2 = length(l2), carry = 0;
  if (size1 == size2) {
    result = sumList(l1, l2, &carry);
  }
  else {
    int diff = abs(size1-size2);
    if (size1 < size2) {
      swapList(l1,l2);
    }
    printf("***DEBUG*** SIZE1 > SIZE2\n");
    printf("Lista 1 = ");
    printlist(l1);
    printf("Lista 2 = ");
    printlist(l2);
    //for (curr = l1; diff--; curr = curr -> next);
    result = sumList(l1, l2, &carry);
    addCarry(l1, l2, &carry, result);
  }
  if (carry) {
    printf("Carry = %d\n",carry);
    result = newList(carry,result);
  }
  printf("Debug list FINAL = ");
  printlist(result);
  return result;
}
