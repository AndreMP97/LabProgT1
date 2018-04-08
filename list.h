#ifndef _L
#define _L

#include "bignumber.h"

typedef struct _list {
  int n;
  struct _list *next;
}  *List;

List newList(int h, List rest);
int head(List l);
List tail(List l);
List addLast(int x, List l);
void printlist(List l);
int length(List l);
List append(List l1, List l2);
void swapList(List l1, List l2);
int member(int x, List l);
List BigNumbertoList(BigNumber n);
List sumList(List l1, List l2, int *carry);
void addCarry(List l1, List curr, int *carry, List result);
List addList(List l1, List l2);

#endif
