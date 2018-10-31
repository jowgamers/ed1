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

//Prot�tipos
int somarNumerosValor(int numero1, int numero2); //int somarNumeros(int, int);
int somarNumerosReferencia(int *numero1, int numero2);

//Fun��es
int main(){
	//Passagem de par�metro por valor
	printf("%d", somarNumerosValor(somarNumerosValor(2, 3), 56));

	//Passagem de par�metro por refer�ncia
	int resultado, numero1 = 5, numero2 = 56;
	resultado = somarNumerosReferencia(&numero1, numero2);
	printf("O resultado � %d\n", resultado);


	return 0;
}

//Passagem de par�metro por refer�ncia
int somarNumerosReferencia(int *numero1, int numero2){
	*numero1 *= 2;
	numero2 +=150;
	printf("N�mero1 = %d e N�mero2 = %d\n", *numero1, numero2);
	return *numero1 + numero2;
}

//Passagem de par�metro por valor
int somarNumerosValor(int numero1, int numero2){
	return numero1 + numero2;
}

