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

	//Exercício 01
	printf("\nDigite a primeira string: ");
	//fflush(stdin);
	gets(str1);

	printf("\nDigite a segunda string: ");
	//fflush(stdin);
	gets(str2);

	//Exercício 02 - Concatenar
	strcat(str1, " ");
	strcat(str1, str2);
	printf("\n\nExercício 02"
			"\nString 1 = %s"
			"\nString 2 = %s", str1, str2);

	//Exercício 03 - Ordem lexográfica
	printf("\n\nExercício 03");
	int aux = strcmp(str1, str2);
	if (aux == -1) {
		printf("\nString 1 = %s \nString 2 = %s", str1, str2);
	} else if (aux == 1){
		printf("\nString 2 = %s \nString 1 = %s", str2, str1);
	} else {
		printf("\nStrings idênticas = %s", str2);

	}

	//Exercício 04 - Copiar
	strcpy(str2, str1);
	printf("\n\nExercício 04"
			"\nString 1 = %s"
			"\nString 2 = %s", str1, str2);

	//Exercício 05 - Alterar caracter na string
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

	printf("\n\nExercício 05"
			"\nString 1 = %s", str1);

	//Exercício 06 - Tamanho
	printf("\n\nExercício 06"
		   "\nTamanho da string 1 %s é %d.", str1, aux);

	//Exercício 07 - Strlen sem utilizar string.h
	for (i = 0; str2[i] !=  '\0' ;i++);
	//for (i = 0; str2[i] ;i++); //Avalia se a posição é diferente de \0

	printf("\n\nExercício 07"
		   "\nTamanho da string 2 %s é %d.", str2, i);


	return 0;

}
