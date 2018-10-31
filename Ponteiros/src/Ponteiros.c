/*
 ============================================================================
 Name        : Ponteiros.c
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

	int vetor[] = {34, 78, 93};
	int *pontVetor = vetor; //int *pontVetor = &vetor[0];


	printf ("\nPrimeiro valor - %d - %p", *pontVetor, pontVetor);
	pontVetor++;
	printf ("\nSegundo valor - %d - %p", *pontVetor, pontVetor);
	(*pontVetor)++;
	printf ("\nTerceiro valor - %d - %p", *pontVetor, pontVetor);
	(*(++pontVetor))++; //Incrementa o ponteiro e o conte�do apontado
	printf ("\nQuarto valor - %d - %p", *pontVetor, pontVetor);


/*
	int idade = 23;
	int *pontIdade = &idade;

	printf("\n%d - Idade de forma direta", idade);
	*pontIdade = 36; //� o mesmo que idade = 36;

	printf("\n%d - Idade de forma indireta", *pontIdade);

	printf("\n%p - Endere�o de mem�ria de idade de forma direta", &idade);
	printf("\n%p - Endere�o de mem�ria de idade de forma indireta", pontIdade);
	printf("\n%p - Endere�o de mem�ria do ponteiro", &pontIdade);

*/


	return 0;
}
