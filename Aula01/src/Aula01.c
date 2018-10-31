/*
 ============================================================================
 Name        : Aula01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	//Variáveis
	char letra = 'A';
	int idade = 17,
		cont;

	/*printf("\n%d - %p", idade, &idade);
	printf("\n%c - %d", letra, letra);
	printf("\n%i", sizeof(idade));
	printf("\n%d", cont);*/
	printf("\n%d", idade == 17);
	return 0;
}
