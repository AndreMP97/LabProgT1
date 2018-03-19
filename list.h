#ifndef _L
#define _L

typedef struct _list {
  int value;
  struct _list *next;
}  *List;

List newList(int h, List rest);
int head(List l);
List tail(List l);
void printlist(List l);
int length(List l);
List append(List l1, List l2);
int member(int x, List l);

#endif
