/*
 ============================================================================
 Name        : listaRecursividade.c
 Author      : Amanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Prot�tipos
//Exerc�cio 01
int somarIterativo(int x, int y);
int somarRecursivo(int x, int y);
int somarRecursivoCauda(int x, int y, int soma);

void exibirMultiplicacaoRecursivo(int a, int b);

float somarSerie(int n);
float somarSerieRecursivoCauda(int n, float resultado);

int somarVetorIterativo(int *vet, int tamanho);
int somarVetorRecursivo(int *vet, int tamanho);
int somarVetorRecursivoCauda(int *vet, int tamanho, int soma);

//Fun��es
int main(void) {
	setbuf(stdout, NULL);
	//Exerc�cio 01
	//printf("\n5 * 7 = %d\n", somarIterativo(5, 7));
	//printf("\n0 * 7 = %d\n", somarRecursivo(0, 7));
	//printf("\n5 * 7 = %d\n", somarRecursivoCauda(5, 7, 0));

	//Exerc�cio 02
	//exibirMultiplicacaoRecursivo(5, 6);

	//Exerc�cio 03
	//printf("\nResultado do somat�rio � %.2f\n", somarSerie(3));
	//printf("\nResultado do somat�rio de cauda � %.2f\n", somarSerieRecursivoCauda(3, 0));;

	//Exerc�cio 04
	int tamanho = 5;
	int *vet = (int*) malloc (tamanho * sizeof(int));
	//printf("\n%d\n", somarVetorIterativo(vet, tamanho));
	//printf("\n%d\n", somarVetorRecursivo(vet, tamanho));
	printf("\n%d\n", somarVetorRecursivoCauda(vet, tamanho, 0));

	//Exerc�cio 05

	return EXIT_SUCCESS;
}

//Exerc�cio 01 - Multiplica��o por somas recursivas
int somarIterativo(int x, int y){
	int i, resultado = 0;
	for (i = 1; i <= x; i++){
		resultado += y;
	}
	return resultado;
}

int somarRecursivo(int x, int y){
	if (y == 0 || x == 0) {
		return 0;
	} else if (x == 1) {
		return y;
	} else {
		return y + somarRecursivo(x-1, y);
	}
}

int somarRecursivoCauda(int x, int y, int soma){
	if (y == 0 || x == 0) {
		return 0;
	} else if (x == 1) {
		return soma + y;
	} else {
		return somarRecursivoCauda(x-1, y, y + soma);
	}
}

//Exerc�cio 02 - Exibir tabuada
void exibirMultiplicacaoRecursivo(int a, int b){
	if (b <= 1){
		printf("\n%d * %d = %d\n", a, b, a * b);
	} else {
		exibirMultiplicacaoRecursivo(a, b-1);
		printf("\n%d * %d = %d\n", a, b, a * b);
	}

	/*As linhas abaixo substituem as linhas acima, por�m,
	 * observe que n�o existe caso base expl�cito, mas ele est� presente.
	 */

	//	if (b > 1){
	//		exibirMultiplicacaoRecursivo(a, b-1);
	//	}
	//
	//	printf("\n%d * %d = %d\n", a, b, a * b);

}

//Exerc�cio 04 - Somar itens de um vetor
//Preencher o vetor com x elementos aleat�rios
//Somar os elementos de um vetor.

float somarSerie(int n){
	if (n == 1) {
		return 1;
	} else {
		return pow(n, 3) / pow(10, n-1) + somarSerie(n-1);
	}
}

float somarSerieRecursivoCauda(int n, float resultado){
	if (n == 0){
		return resultado;
	} else {
		return somarSerieRecursivoCauda(n - 1, pow(n, 3) / pow(10, n-1) + resultado);
	}
}


int somarVetorIterativo(int *vet, int tamanho){
	int i, soma = 0;
	for (i = 1; i <= tamanho; i++){
		*vet = rand() % 100; //Preenchi o conte�do da apontada
		printf("\n%d\n", *vet);
		soma += *vet; //Somei o conte�do
		vet++; //Passei para o pr�ximo endere�o de mem�ria
	}
	return soma;
}

int somarVetorRecursivo(int *vet, int tamanho){
	//Preenche o espa�o de mem�ria
	*vet = rand() % 100;
	printf("\n%d\n", *vet);

	if (tamanho == 1) {
		return *vet; //retorna s� o espa�o atual.
	} else {
		return *vet + somarVetorRecursivo(vet+1, tamanho-1);
	}
}

int somarVetorRecursivoCauda(int *vet, int tamanho, int soma){
	//Preenche o espa�o de mem�ria
	*vet = rand() % 100;
	printf("\n%d\n", *vet);

	if (tamanho == 0){
		return soma;
	} else{
		return somarVetorRecursivoCauda(vet+1, tamanho-1, soma + *vet);
	}
}




