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
			if (ultimo == NULL) {
				ultimo = lista;
			}
			break;
		case 'B':
			printf("\nInserção pelo fim da lista.");
			//lista = inserirFim(lista);

			if (lista == NULL) { //lista vazia o último será igual ao primeiro
				lista = inserirFimUltimo();
				ultimo = lista;
			} else { //se já existe algum registro na lista
				ultimo->proximo = inserirFimUltimo();
				ultimo = ultimo->proximo;
			}
			break;
		case 'C':
			printf("\nRemover pelo código indicado.");
			int codigo = solicitarCodigo();
			//lista = excluirRegistro(codigo, lista);
			lista = excluirRegistroUltimo(codigo, lista, &ultimo);
			break;
		case 'D':
			printf("\nImprimir lista completa.");
			imprimirLista(lista);
			break;
		default :
			printf("\nOpção inválida.");
			break;
		}
		printf("\nÚltimo registro - %p", ultimo);

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

	printf("\nCódigo não encontrado.");
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

				//Verifica se o registro a ser excluído é o último da lista
				if (tmp->codigo == (*ultimo)->codigo) {
					*ultimo = NULL;
				}
				return anterior; //return lista;
			} else { //Tem anterior - registro do meio ou fim
				anterior->proximo = tmp->proximo;
				free(tmp);
				//Verifica se o registro a ser excluído é o último da lista
				if (tmp->codigo == (*ultimo)->codigo) {
					*ultimo = anterior;
				}
				return lista;
			}
		}
		anterior = tmp;
		tmp = tmp->proximo;
	}

	printf("\nCódigo não encontrado.");
	return lista;

}

int solicitarCodigo(){
	int codigo;
	do{
		printf("\nDigite o código a ser excluído: ");
		scanf("%d", &codigo);

		if (codigo < 0){
			printf("\nCódigo inválido.");
		}
	} while (codigo < 0);
	return codigo;
}






