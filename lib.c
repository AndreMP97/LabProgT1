#include <stdio.h>
#include "lib.h"

void enterPrompt(){
	printf("Pressione [Enter] para continuar.\n");
	while(getchar() != '\n'){
		;
	}
	getchar();
}

void clearScreen(){
	printf("\033[2J\033[1;1H");
}

void menu() {
  printf("1) Fibonnaci recursivo;\n");
  printf("2) Fibonnaci iterativo;\n");
  printf("3) Operações com Big Numbers;\n");
  printf("4) Sair;\n");
}
