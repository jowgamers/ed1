/*
 ============================================================================
 Name        : FuncoesVetor.c
 Author      : Amanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
void somarElementos(int *pVet, int tam, int *soma);

int main(){
	int soma, vet[] = {15, 25, 65, 78};
	somarElementos(vet, 4, &soma); //somarElementos(&vet[0], 4, &soma);

	printf("A soma dos elementos é %d", soma);
	return 0;
}

void somarElementos(int *pVet, int tam, int *soma){
	int i;
	*soma = 0;
	for (i = 0; i < tam; i++){
		*soma += *pVet;
		pVet++;
	}
}
