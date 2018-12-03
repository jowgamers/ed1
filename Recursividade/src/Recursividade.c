/*
 ============================================================================
 Name        : Recursividade.c
 Author      : Amanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Protótipos
int fatorialRecursivo(int n);
int fatorialIterativo(int n);
int fatorialRecursivoCauda(int n, int soma);

int fibonacciIterativo(int termo);
int fibonacciRecursivo(int termo);
int fibonaccitRecursivoCauda(int termo, int penultimo, int ultimo);


//Funções
int main(void) {
	setbuf(stdout, NULL);

	//Fatorial
	//printf("\nFatorial Iterativo - %d\n", fatorialIterativo(5));
	//printf("\nFatorial Recursivo - %d\n", fatorialRecursivo(5));
	//printf("\nFatorial Recursivo - %d\n", fatorialRecursivoCauda(5, 1));

	//Fibonacci
//	printf("\nFibonacci Iterativo - %d\n", fibonacciIterativo(50));
//	printf("\nFibonacci Recursivo - %d\n", fibonacciRecursivo(50));
	printf("\nFibonacci Recursivo Cauda - %d\n", fibonaccitRecursivoCauda(50, 0, 1));

	return EXIT_SUCCESS;
}

int fatorialIterativo(int n){
	int i, fatorial = 1;
	for (i = n; i >= 2; i--){
		fatorial *= i;
	}
	return fatorial;
}

int fatorialRecursivoCauda(int n, int fatorial){
	if (n <= 1){
		return fatorial;
	} else {
		return fatorialRecursivoCauda(n-1, fatorial * n);
	}
}

int fatorialRecursivo(int n){
	if (n <= 1){
		return 1;
	} else {
		return n * fatorialRecursivo(n-1);
	}
}


int fibonacciIterativo(int termo){
	if (termo <= 2)
		return termo-1;

	int 	penultimo = 0,
			ultimo = 1,
			soma,	i;

	for (i = 3; i <= termo; i++) {
		soma = ultimo + penultimo;
		penultimo = ultimo;
		ultimo = soma;
	}

	return soma;
}

int fibonaccitRecursivoCauda(int termo, int penultimo, int ultimo){
	if (termo == 1){
		return penultimo;
	} else {
		return fibonaccitRecursivoCauda(termo-1, ultimo, penultimo + ultimo);
	}
}

int fibonacciRecursivo(int termo){
	if (termo <= 2) {
		return termo - 1;
	} else {
		return fibonacciRecursivo(termo - 1) + fibonacciRecursivo(termo - 2);
	}

}

