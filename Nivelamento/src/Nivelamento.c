/*
 ============================================================================
 Name        : Nivelamento.c
 Author      : Amanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int x = 15;
	char letra = 'A';

	printf("\nDigite o valor de x: ");
	scanf("%d", &x);

	printf("\nDigite uma letra: ");
	fflush(stdin);
	scanf("%c", &letra);

	if (x >= 13)
		printf("O valor de x � %i", x);

	printf("%d", x); //Imprimindo vari�vel
	printf("\nMeu nome � Amanda"); //Imprimindo texto
	printf("\nO valor de x � %d e x/3 � %d\nE a letra � %c", x,x/3, letra); //Imprimindo texto e vari�vel


	return 0;
}
