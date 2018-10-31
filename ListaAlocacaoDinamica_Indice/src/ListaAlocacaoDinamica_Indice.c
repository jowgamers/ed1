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
	//Declaração de variáveis
	int tam,
		i,
		soma = 0,
		*vetor;

	//Validar entrada de número inteiro (tamanho do vetor)
	do{
		printf("\nDigite o tamanho do vetor: ");
		scanf("%d", &tam);

		if (tam <= 0) {
			printf("\nValor inválido.");
		}
	} while (tam <= 0);

	//Criar vetor dinamicamente
	vetor = (int*) malloc (tam * sizeof(int));
	//vetor = (int*) calloc (tam, sizeof(int));

	for (i = 0; i < tam; i++){
		//Receber o valor digitado
		do{
			printf("\nDigite o valor da %dª posição: ", i+1);
			scanf("%d", &vetor[i]);

			if (vetor[i] < 0) {
				printf("\nValor inválido.");
			}
		} while (vetor[i] < 0);

		//Alterar os valores das posições
		if (i % 2 == 0) {
			vetor[i] *= 2; //vetor[i] = vetor[i] * 2;
		} else {
			vetor[i] /= 2; //vetor[i] = vetor[i] / 2;
		}

		//Somar valores para exibir
		soma += vetor[i];
	}

	printf("\nÍndice\tValor");
	for (i = 0; i < tam; i++){
		printf("\n%d\t%d", i, vetor[i]);
	}

	//Liberar o espaço de memória
	free(vetor);
	return 0;
}
