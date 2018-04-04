#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lib.h"
#include "fib.h"
#include "list.h"
#include "bignumber.h"

void options(int opt);
void show();

int main() {
  show();
  return 0;
}
//bignum bignum.c list.c main.c

void options(int opt) {
  switch (opt) {
    case 1: {
      int fib, res;
      clearScreen();
      printf("Selecione o número de Fibonnaci a calcular: ");
      scanf("%d",&fib);
      if (fib > INT_MAX) {
        clearScreen();
        printf("***Erro!*** Valor superior a um inteiro positivo!\n");
        enterPrompt();
        show();
      }
      else if (fib < 0) {
        clearScreen();
        printf("Erro! Valor inferior a zero!\n");
        enterPrompt();
        show();
      }
      else {
        res=fibonacci(fib);
        printf("Resultado = %d\n",res);
        enterPrompt();
        show();
        break;
      }
      break;
    }
    case 2: {
      exit(0);
      break;
    }
    case 3: {
      exit(0);
      break;
    }
    case 4: {
      clearScreen();
      printf("Bye!\n");
      exit(0);
      break;
    }
    default: {
      printf("Opção inválida!\n");
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
