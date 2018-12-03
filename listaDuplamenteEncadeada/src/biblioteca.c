/*
 * biblioteca.c
 *
 *  Created on: 19 de nov de 2018
 *      Author: amanda.oliveira
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca.h"


void menu(){
	dados *lista = NULL,
			*ultimo = NULL;
	char op = 'G';

	while (op != 'E'){

		printf("\nA - Inserir pelo início"
				"\nB - Inserir pelo fim"
				"\nC - Remover elemento"
				"\nD - Imprimir lista completa"
				"\nE - Finalizar"
				"\nDigite sua opção: ");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);

		switch (op) {
		case 'E' :
			printf("\nPrograma finalizado com sucesso.");
			break;
		case 'A':
			printf("\nInserção pelo início da lista.");
			lista = inserirInicio(lista);
			break;
		case 'B':
			printf("\nInserção pelo fim da lista.");

			if (lista == NULL){
				lista = inserirFimUltimo(ultimo);
				ultimo = lista;
			} else {
				ultimo->proximo = inserirFimUltimo(ultimo);
				ultimo = ultimo->proximo;
			}

			break;
		case 'C':
			printf("\nRemover pelo código indicado.");
			int codigo = -1;
			while (codigo < 0) {
				printf("\nDigite o código a ser excluído: ");
				scanf("%d", &codigo);
			}
			lista = excluirRegistro(codigo, lista);

			break;
		case 'D':
			printf("\nImprimir lista completa.");
			imprimirLista(lista, 0);
			break;
		default :
			printf("\nOpção inválida.");
			break;
		}

	}
}

dados* inserirInicio(dados *lista){
	dados *novo = (dados*) malloc (sizeof(dados));
	novo->codigo = RANDOMICO;

	novo->anterior = NULL;
	novo->proximo = lista;

	if (lista != NULL){
		lista->anterior = novo;
	}

	return novo;
}

dados* inserirFim(dados *lista){
	dados *novo = (dados*) malloc (sizeof(dados));
	novo->codigo = RANDOMICO;

	novo->proximo = NULL;

	if (lista == NULL){
		novo->anterior = NULL;
		return novo;
	} else {
		dados *tmp = lista;
		while (tmp->proximo != NULL){
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		novo->anterior = tmp;
		return lista;
	}
}


void imprimirLista(dados *lista, int contador){
	if (contador == 0 && lista == NULL) {
		printf("\nLista Vazia.\n");
	} else if (lista != NULL){
		printf("\n%p\t%p\t%d\t%p\n",
				lista->anterior, lista, lista->codigo, lista->proximo);
		imprimirLista(lista->proximo, contador + 1);
	}
}

dados* inserirFimUltimo(dados *ultimo){
	dados *novo = (dados*) malloc (sizeof(dados));
	novo->codigo = RANDOMICO;
	novo->anterior = ultimo;
	novo->proximo = NULL;
	return novo;
}

dados* excluirRegistro(int codigo, dados *lista){
	dados *tmp = lista;

	while (tmp != NULL){
		if (tmp->codigo == codigo){
			if (tmp->anterior == NULL){
				lista = lista->proximo;
				if (lista != NULL){
					lista->anterior = NULL;
				}
				free(tmp);
			} else {
				tmp->anterior->proximo = tmp->proximo;
				if (tmp->proximo != NULL){
					tmp->proximo->anterior = tmp->anterior;
				}
				free(tmp);
			}
			return lista;
		}

		tmp = tmp->proximo;

	}
	printf("\nCódigo não encontrado.");
	return lista;

}












