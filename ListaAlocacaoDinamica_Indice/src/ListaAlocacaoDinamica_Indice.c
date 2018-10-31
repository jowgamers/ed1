/*
 ============================================================================
 Name        : ListaAlocacaoDinamica_Indice.c
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
	//Declara��o de vari�veis
	int tam,
		i,
		soma = 0,
		*vetor;

	//Validar entrada de n�mero inteiro (tamanho do vetor)
	do{
		printf("\nDigite o tamanho do vetor: ");
		scanf("%d", &tam);

		if (tam <= 0) {
			printf("\nValor inv�lido.");
		}
	} while (tam <= 0);

	//Criar vetor dinamicamente
	vetor = (int*) malloc (tam * sizeof(int));
	//vetor = (int*) calloc (tam, sizeof(int));

	for (i = 0; i < tam; i++){
		//Receber o valor digitado
		do{
			printf("\nDigite o valor da %d� posi��o: ", i+1);
			scanf("%d", &vetor[i]);

			if (vetor[i] < 0) {
				printf("\nValor inv�lido.");
			}
		} while (vetor[i] < 0);

		//Alterar os valores das posi��es
		if (i % 2 == 0) {
			vetor[i] *= 2; //vetor[i] = vetor[i] * 2;
		} else {
			vetor[i] /= 2; //vetor[i] = vetor[i] / 2;
		}

		//Somar valores para exibir
		soma += vetor[i];
	}

	printf("\n�ndice\tValor");
	for (i = 0; i < tam; i++){
		printf("\n%d\t%d", i, vetor[i]);
	}

	//Liberar o espa�o de mem�ria
	free(vetor);
	return 0;
}
