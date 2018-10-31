/*
 ============================================================================
 Name        : Matriz.c
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
	//Vetores
	//Variáveis
	int i; //variável comum
	int vet[5]; //vetor
	float vetFloat[] = {6.96, 16, 18.9};

	printf("\nEndereço de memória de i %p", &i);

	for (i = 0; i < 5; i++){
		printf("\nEndereço de memória de vet[%d] %p", i, &vet[i]);
	}


	//Matrizes
	int mat[2][3];
	float matFloat[][3] = {15.8, 78, 96.8, 15, 7, 96.9};
	int l, c;
	for (l = 0; l < 2; l++){
		for (c = 0; c < 3; c++){
			mat[l][c] = l + c;
		}
	}

	return 0;
}
