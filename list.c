#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>

List newList(int h, List rest) {
  List l = (List) malloc(sizeof(*l));
  if (l == NULL) {
    printf("NO MEMORY AVAILABLE!\n");
    abort();
  }
  l -> value = h;
  l -> next = rest;
  return l;
}

int head(List l) {
  if (l == NULL) {
    printf("Lista vazia!\n");
    exit(-1);
  }
  return l->value;
}

List tail(List l) {
  if (l == NULL) {
    printf("Lista vazia!\n");
    exit(-1);
  }
  return l->next;
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
