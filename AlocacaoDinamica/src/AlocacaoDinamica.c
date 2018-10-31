/*
 ============================================================================
 Name        : AlocacaoDinamica.c
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

	//Declarar ponteiro de inteiro
	int *x;
	x = (int*) malloc (sizeof(int));
	printf("\nDigite o número: ");
	scanf("%d", x);
	printf("\nValor digitado = %d", *x);

	//declarar ponteiro de float
	float *y = (float*) malloc (sizeof(float));

	//declara um vetor com 5 posições double
	printf("\nTamanho do double %i bytes.", sizeof(double));
	//double *w = (double*) malloc (5 * sizeof(double)); //Cria 40 espaços de memória sem inicialização
	double *w = (double*) calloc (5, sizeof(double)); //Cria 5 espaços double já inicializados com zero.

	//Lembre-se que w aponta para o vetor, portanto, será necessário manipular todos os endereços
	printf("\nDigite o valor = ");
	scanf("%lf", w);
	printf("\nValor digitado = %.2lf", *w);


	//Liberar os espaços de memória
	free(x);
	free(y);
	free(w);
	return 0;
}
