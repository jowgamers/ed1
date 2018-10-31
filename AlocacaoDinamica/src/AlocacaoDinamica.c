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
	printf("\nDigite o n�mero: ");
	scanf("%d", x);
	printf("\nValor digitado = %d", *x);

	//declarar ponteiro de float
	float *y = (float*) malloc (sizeof(float));

	//declara um vetor com 5 posi��es double
	printf("\nTamanho do double %i bytes.", sizeof(double));
	//double *w = (double*) malloc (5 * sizeof(double)); //Cria 40 espa�os de mem�ria sem inicializa��o
	double *w = (double*) calloc (5, sizeof(double)); //Cria 5 espa�os double j� inicializados com zero.

	//Lembre-se que w aponta para o vetor, portanto, ser� necess�rio manipular todos os endere�os
	printf("\nDigite o valor = ");
	scanf("%lf", w);
	printf("\nValor digitado = %.2lf", *w);


	//Liberar os espa�os de mem�ria
	free(x);
	free(y);
	free(w);
	return 0;
}
