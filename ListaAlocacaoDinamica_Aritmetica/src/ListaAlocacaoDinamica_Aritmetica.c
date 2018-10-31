/*
 ============================================================================
 Name        : ListaAlocacaoDinamica_Aritmetica.c
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
	int i,
		tam,
		soma = 0,
		*vetor;

	//Validar entrada de número inteiro (tamanho do vetor)
	printf("\nDigite o tamanho do vetor: ");
	scanf("%d", &tam);
	while (tam <= 0) {
		printf("\nTamanho inválido."
				"\nDigite o tamanho do vetor: ");
		scanf("%d", &tam);
	}

	//Criar vetor dinamicamente
	vetor = (int*) calloc (tam, sizeof(int));
	//vetor = (int*) malloc (tam * sizeof(int));

	for (i = 0; i < tam; i++){
		//Receber o valor digitado
		printf("\nDigite o valor da %dª posição: ", i+1);
		scanf("%d", vetor);

		while (*vetor < 0) {
			printf("\nValor inválido."
					"\nDigite o valor da %dª posição: ", i+1);
			scanf("%d", vetor);
		}

		//Alterar os valores das posições
		if (i % 2 == 0) {
			*vetor *= 2; //*vetor = *vetor * 2;
		} else {
			*vetor /= 2; //*vetor = *vetor / 2;
		}

		//Somar valores para exibir
		soma += *vetor;

		vetor++;
	}

	vetor -=tam;

	printf("\nÍndice\tValor");
	for (i = 0; i < tam; i++){
		printf("\n%d\t%d", i, *vetor);
		vetor++;
	}

	//Liberar o espaço de memória
	free(vetor);
	return 0;
}
