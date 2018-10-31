/*
 ============================================================================
 Name        : listaString.c
 Author      : Amanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);

	char str1[60], str2[30]; //Declarar dois vetores do tipo char

	//Exerc�cio 01
	printf("\nDigite a primeira string: ");
	//fflush(stdin);
	gets(str1);

	printf("\nDigite a segunda string: ");
	//fflush(stdin);
	gets(str2);

	//Exerc�cio 02 - Concatenar
	strcat(str1, " ");
	strcat(str1, str2);
	printf("\n\nExerc�cio 02"
			"\nString 1 = %s"
			"\nString 2 = %s", str1, str2);

	//Exerc�cio 03 - Ordem lexogr�fica
	printf("\n\nExerc�cio 03");
	int aux = strcmp(str1, str2);
	if (aux == -1) {
		printf("\nString 1 = %s \nString 2 = %s", str1, str2);
	} else if (aux == 1){
		printf("\nString 2 = %s \nString 1 = %s", str2, str1);
	} else {
		printf("\nStrings id�nticas = %s", str2);

	}

	//Exerc�cio 04 - Copiar
	strcpy(str2, str1);
	printf("\n\nExerc�cio 04"
			"\nString 1 = %s"
			"\nString 2 = %s", str1, str2);

	//Exerc�cio 05 - Alterar caracter na string
	char caracter;
	int i;
	aux = strlen(str1);
	printf("\n\nDigite o caracter: ");
	//fflush(stdin);
	scanf("%c", &caracter);

	for (i = 0; i < aux ;i++){
		if (caracter == str1[i]){
			str1[i] = '*';
		}
	}

	printf("\n\nExerc�cio 05"
			"\nString 1 = %s", str1);

	//Exerc�cio 06 - Tamanho
	printf("\n\nExerc�cio 06"
		   "\nTamanho da string 1 %s � %d.", str1, aux);

	//Exerc�cio 07 - Strlen sem utilizar string.h
	for (i = 0; str2[i] !=  '\0' ;i++);
	//for (i = 0; str2[i] ;i++); //Avalia se a posi��o � diferente de \0

	printf("\n\nExerc�cio 07"
		   "\nTamanho da string 2 %s � %d.", str2, i);


	return 0;

}
