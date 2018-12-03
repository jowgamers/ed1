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
	dados *lista = NULL,
			*ultimo = NULL;
	char op = 'G';

	while (op != 'F'){

		printf("\nA - Inserir pelo in�cio"
				"\nB - Inserir pelo fim"
				"\nC - Remover elemento"
				"\nD - Imprimir lista completa"
				"\nE - Finalizar"
				"\nDigite sua op��o: ");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);

		switch (op) {
		case 'E' :
			printf("\nPrograma finalizado com sucesso.");
			break;
		case 'A':
			printf("\nInser��o pelo in�cio da lista.");
			lista = inserirInicio(lista);
			if (ultimo == NULL) {
				ultimo = lista;
			}
			break;
		case 'B':
			printf("\nInser��o pelo fim da lista.");
			//lista = inserirFim(lista);

			if (lista == NULL) { //lista vazia o �ltimo ser� igual ao primeiro
				lista = inserirFimUltimo();
				ultimo = lista;
			} else { //se j� existe algum registro na lista
				ultimo->proximo = inserirFimUltimo();
				ultimo = ultimo->proximo;
			}
			break;
		case 'C':
			printf("\nRemover pelo c�digo indicado.");
			int codigo = solicitarCodigo();
			//lista = excluirRegistro(codigo, lista);
			lista = excluirRegistroUltimo(codigo, lista, &ultimo);
			break;
		case 'D':
			printf("\nImprimir lista completa.");
			imprimirLista(lista);
			break;
		default :
			printf("\nOp��o inv�lida.");
			break;
		}
		printf("\n�ltimo registro - %p", ultimo);

	}
}

void imprimirLista(dados *lista){
	if (lista != NULL){
		printf("\n%p\t%d\t%p\n",lista, lista->codigo, lista->proximo);
		imprimirLista(lista->proximo);
	}
}

dados* inserirInicio(dados *lista){
	dados *novo = (dados*) malloc (sizeof(dados));
	novo->codigo = RANDOMICO(1000);
	novo->proximo = lista;
	return novo;
}


dados* inserirFim(dados *lista){
	dados *novo = (dados*) malloc (sizeof(dados));
	novo->codigo = RANDOMICO(1000);
	novo->proximo = NULL;

	//Se lista for nula, retorna o novo
	if (lista == NULL){
		return novo;
	} else {
		dados *tmp = lista;
		while (tmp->proximo != NULL){
			tmp = tmp->proximo;
		}

		tmp->proximo = novo;
		return lista;
	}

}

dados* inserirFimUltimo(){
	dados *novo = (dados*) malloc (sizeof(dados));
	novo->codigo = RANDOMICO(1000);
	novo->proximo = NULL;
	return novo;
}

dados* excluirRegistro(int codigo, dados *lista){
	dados 	*anterior = NULL,
			*tmp = lista;

	while (tmp != NULL) {
		if (tmp->codigo == codigo){ //Encontrei o registro
			//Apagar o registro
			if (anterior == NULL){ //Apagar o primeiro da lista
				anterior = tmp->proximo; //lista = lista->proximo;
				free(tmp);
				return anterior; //return lista;
			} else { //Tem anterior - registro do meio ou fim
				anterior->proximo = tmp->proximo;
				free(tmp);
				return lista;
			}
		}
		anterior = tmp;
		tmp = tmp->proximo;
	}

	printf("\nC�digo n�o encontrado.");
	return lista;

}

dados* excluirRegistroUltimo(int codigo, dados *lista, dados **ultimo){
	dados 	*anterior = NULL,
			*tmp = lista;

	while (tmp != NULL) {
		if (tmp->codigo == codigo){ //Encontrei o registro
			//Apagar o registro
			if (anterior == NULL){ //Apagar o primeiro da lista
				anterior = tmp->proximo; //lista = lista->proximo;
				free(tmp);

				//Verifica se o registro a ser exclu�do � o �ltimo da lista
				if (tmp->codigo == (*ultimo)->codigo) {
					*ultimo = NULL;
				}
				return anterior; //return lista;
			} else { //Tem anterior - registro do meio ou fim
				anterior->proximo = tmp->proximo;
				free(tmp);
				//Verifica se o registro a ser exclu�do � o �ltimo da lista
				if (tmp->codigo == (*ultimo)->codigo) {
					*ultimo = anterior;
				}
				return lista;
			}
		}
		anterior = tmp;
		tmp = tmp->proximo;
	}

	printf("\nC�digo n�o encontrado.");
	return lista;

}

int solicitarCodigo(){
	int codigo;
	do{
		printf("\nDigite o c�digo a ser exclu�do: ");
		scanf("%d", &codigo);

		if (codigo < 0){
			printf("\nC�digo inv�lido.");
		}
	} while (codigo < 0);
	return codigo;
}






