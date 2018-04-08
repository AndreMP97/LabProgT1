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

List addLast(int x, List l) {
  struct _list *temp = newList(x,NULL);
  struct _list *last = tail(l);
  if (l -> next == NULL) {
    l -> next = temp;
    return l;
  }
  while (last -> next != NULL) {
    last = last -> next;
  }
  last -> next = temp;
  return l;
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

BigNumber ListtoBN(List l) {
  List temp = l;
  BigNumber n = newBigNum(temp -> n, NULL);
  while ((temp = temp -> next) != NULL) {
    n = newBigNum(temp -> n, n);
  }
  return n;
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
  result -> next = sumList(l1 -> next, l2 -> next, carry);
  return result;
}

void addCarry(List l1, List curr, int *carry, List result) {
  int sum;
  if (*carry > 0) {
    while (curr != NULL) {
      sum = l1 -> n + *carry;
      *carry = sum/10;
      sum = sum%10;
      result = addLast(sum,result);
      curr = curr -> next;
    }
  }
  else {
    result = addLast(curr -> n, result);
  }
}

List addList(List l1, List l2) {
  List curr = l1;
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
    if (size1 < size2) {
      swapList(l1,l2);
    }
    result = sumList(l1, l2, &carry);
    for(int s = size2; s > 0; s--){
      curr = curr -> next;
    }
    addCarry(l1, curr, &carry, result);
  }
  if (carry) {
    result = addLast(carry,result);
  }
  return result;
}
