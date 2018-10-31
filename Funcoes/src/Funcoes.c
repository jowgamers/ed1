/*
 ============================================================================
 Name        : Funcoes.c
 Author      : Amanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Protótipos
int somarNumerosValor(int numero1, int numero2); //int somarNumeros(int, int);
int somarNumerosReferencia(int *numero1, int numero2);

//Funções
int main(){
	//Passagem de parâmetro por valor
	printf("%d", somarNumerosValor(somarNumerosValor(2, 3), 56));

	//Passagem de parâmetro por referência
	int resultado, numero1 = 5, numero2 = 56;
	resultado = somarNumerosReferencia(&numero1, numero2);
	printf("O resultado é %d\n", resultado);


	return 0;
}

//Passagem de parâmetro por referência
int somarNumerosReferencia(int *numero1, int numero2){
	*numero1 *= 2;
	numero2 +=150;
	printf("Número1 = %d e Número2 = %d\n", *numero1, numero2);
	return *numero1 + numero2;
}

//Passagem de parâmetro por valor
int somarNumerosValor(int numero1, int numero2){
	return numero1 + numero2;
}

