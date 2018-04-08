#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lib.h"
#include "fib.h"
//#include "list.h"
#include "bignumber.h"

void options(int opt);
void show();
void showBN();
void BNumoptions(int opt);
int getfib();

int main() {
  show();
  return 0;
}
//bignum bignum.c list.c main.c

void options(int opt) {
  switch (opt) {
    case 1: {
      int fib=getfib(), res;
      if (fib == -1) {
        enterPrompt();
        show();
      }
      else {
        clearScreen();
        res=fibonacci(fib);
        printf("Resultado = %d\n",res);
        enterPrompt();
        show();
      }
      break;
    }
    case 2: {
      int fib=getfib(), res;
      if (fib == -1) {
        enterPrompt();
        show();
      }
      else {
        clearScreen();
        res=dynamicfib(fib);
        printf("Resultado = %d\n",res);
        enterPrompt();
        show();
      }
      break;
    }
    case 3: {
      showBN();
      break;
    }
    case 4: {
      clearScreen();
      printf("Bye!\n");
      exit(0);
      break;
    }
    default: {
      clearScreen();
      printf("Opção inválida!\n");
      enterPrompt();
      show();
      break;
    }
  }
}

void show() {
  clearScreen();
  int opt;
  menu();
  printf("Escolha uma opção: ");
  scanf("%d",&opt);
  options(opt);
}

void showBN() {
  clearScreen();
  int opt;
  menuBigNumber();
  printf("Escolha uma opção: ");
  scanf("%d",&opt);
  BNumoptions(opt);
}

void BNumoptions(int opt) {
  switch (opt) {
    case 1: {
      int first, x;
      clearScreen();
      BigNumber n1 = newBigNum(9,(newBigNum(9,newBigNum(9,newBigNum(9,NULL)))));
      //BigNumber n1 = newBigNum(1,(newBigNum(2,NULL)));
      BigNumber n2 = newBigNum(4,(newBigNum(9,NULL)));
      printf("BigNumber n1 = ");
      printBN(n1);
      printf("BigNumber n2 = ");
      printBN(n2);
      printf("***RESULTADO***\n");
      printBN(sumBN(n1,n2));
      enterPrompt();
      showBN();
      break;
    }
    case 2: {
      show();
      break;
    }
    default: {
      clearScreen();
      printf("Opção inválida!\n");
      enterPrompt();
      showBN();
      break;
    }
  }
}

int getfib() {
  int fib;
  clearScreen();
  printf("Selecione o número de Fibonnaci a calcular: ");
  scanf("%d",&fib);
  if (fib > INT_MAX) {
    clearScreen();
    printf("***Erro!*** Valor superior a um inteiro positivo!\n");
    return -1;
  }
  else if (fib < 0) {
    clearScreen();
    printf("Erro! Valor inferior a zero!\n");
    return -1;
  }
  else {
    return fib;
  }
}
