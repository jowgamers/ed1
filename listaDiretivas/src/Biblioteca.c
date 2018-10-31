/*
 * Biblioteca.c
 *
 *  Created on: 22 de out de 2018
 *      Author: amanda.oliveira
 */

#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void menu(){
	char menu = ' ';
	produto *pProd;
	int numero = 0;

	while (menu != 'E') {

		//Receber o menu
		printf("\nA - Criar estrutura"
				"\nB - Cadastrar produtos"
				"\nC - Exibir produtos com estoque zerado"
				"\nD - Exibir todos os produtos em estoque"
				"\nE - Finalizar"
				"\nDigite sua opção: ");
		fflush(stdin);
		scanf("%c", &menu);

		switch(menu){
		case 'A' :
			numero = validaQtde("Digite a quantidade de produtos: ");
			pProd = (produto*) malloc (numero * sizeof(produto));
			break;
		case 'B':
			if (numero > 0) {
				cadastrar(numero, pProd);
			}
			break;
		case 'C':
			if (numero > 0) {
				imprimirSemEstoque(numero, pProd);
			}
			break;
		case 'D':
			if (numero > 0) {
				imprimirEstoque(numero, pProd);
			}
			break;
		case 'E':
			printf("\nPrograma finalizado");
			break;
		default:
			printf("\nOpção inválida");
			break;
		}

	}
}

int validaQtde(char *texto){
	int numero;
	do{
		printf("\n%s", texto);
		scanf("%d", &numero);

		if (numero <= 0) {
			printf("\nValor inválido.");
		}
	} while (numero <= 0);

	return numero;
}


int cadastrarCodigo(){
	int codigo;
	do{
		printf("\nDigite o código: ");
		scanf("%d", &codigo);

		if (codigo < 0 || codigo > 50){
			printf("\nCódigo inválid.");
		}
	} while (codigo < 0 || codigo > 50);
	return codigo;
}

void cadastrarNome(produto *pProd){
	do{
		printf("\nDigite o nome do produto: ");
		fflush(stdin);
		gets(pProd->nomeProduto);

		if (strlen(pProd->nomeProduto) == 0) {
			printf("\nNome inválido.");
		}

	} while (strlen(pProd->nomeProduto) == 0);
}

void cadastrarPreco(float *valor){
	do{
		printf("\nDigite o preço do produto:");
		scanf("%f", valor);

		if (*valor < 0) {
			printf("\nValor inválido.");
		}
	} while (*valor < 0);
}


void cadastrarQuantidade(produto *prod){
	do {
		printf("\nDigite a quantidade em estoque do produto %s:", prod->nomeProduto);
		scanf("%d", &prod->quantidade);

		if (prod->quantidade < 0){
			printf("\nValor inválido.");
		}
	} while (prod->quantidade < 0);
}

void cadastrar(int numero, produto *pProd){
	int i;
	for (i = 0; i < numero; i++){
		printf("\nProduto %d", i+1);
		//pProd->codigo = cadastrarCodigo(); //Utilizando a função
		//pProd->codigo = COD; //cadastrarCodigo(); //Utilizando a macro, gerando de 0 até 50
		pProd->codigo = COD2(100); //cadastrarCodigo(); //Utilizando a macro, gerando de 0 até o parâmetro indicado
		cadastrarNome(pProd);
		cadastrarPreco(&pProd->preco);
		cadastrarQuantidade(pProd);
		pProd++;
	}
}

void imprimirEstoque(int numero, produto *pProd){
	int i;
	for (i = 0; i < numero; i++){
		printf("\n%d\t%s\tR$%.2f\t%d", pProd->codigo,
							   pProd->nomeProduto,
							   pProd->preco,
							   pProd->quantidade);
		pProd++;
	}
}

void imprimirSemEstoque(int numero, produto *pProd){
	int i;
	for (i = 0; i < numero; i++){
		if (pProd->quantidade == 0){
			printf("\n%d\t%s\tR$%.2f\t%d", pProd->codigo,
								   pProd->nomeProduto,
								   pProd->preco,
								   pProd->quantidade);
		}
		pProd++;
	}
}

