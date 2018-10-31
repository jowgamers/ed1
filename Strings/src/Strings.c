/*
 ============================================================================
 Name        : Strings.c
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


	//Char comum
	char letra = 'B';
	printf("\n%c - %d", letra, letra);

	//Strings
	char string[50];
	int tamanho;
	printf("\nDigite a string: ");
	fflush(stdin);
	gets(string);
	printf("\n%s", string);

	tamanho = strlen(string);
	printf("\nTamanho da string %d", tamanho);
	printf("\nTamanho da string %d", strlen(string));

	//lexicográfica
	printf("\n%d", strcmp("Carla","Carlos"));
	return 0;
}
