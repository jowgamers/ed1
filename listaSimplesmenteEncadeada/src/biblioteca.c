/*
 * biblioteca.c
 *
 *  Created on: 6 de nov de 2018
 *      Author: amanda.oliveira
 */

#include "biblioteca.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void menu(){
	dados *lista = NULL;
	char op = 'G';

	while (op != 'F'){

		printf("\nA - Inserir pelo in�cio"
				"\nB - Inserir pelo fim"
				"\nC - Buscar por c�digo"
				"\nD - Remover elemento"
				"\nE - Imprimir lista"
				"\nF - Finalizar"
				"\nDigite sua op��o: ");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);

		switch (op) {
		case 'F' :
			printf("\nPrograma finalizado com sucesso.");
			break;
		case 'A':
			printf("\nInser��o pelo in�cio da lista.");
			lista = inserirInicio(lista);
			break;
		case 'B':
			printf("\nInser��o pelo fim da lista.");
			break;
		case 'C':
			printf("\nBuscar pelo c�digo indicado.");
			break;
		case 'D':
			printf("\nRemover pelo c�digo indicado.");
			break;
		case 'E':
			printf("\nPrograma finalizado com sucesso.");
			break;
		default :
			printf("\nOp��o inv�lida.");
			break;
		}
	}
}

dados* inserirInicio(dados *lista){
	dados *novo = (dados*) malloc (sizeof(dados));
	novo->codigo = RANDOMICO(1000);
	novo->proximo = lista;
	return novo;
}





