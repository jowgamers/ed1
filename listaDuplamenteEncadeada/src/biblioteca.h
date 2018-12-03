/*
 * biblioteca.h
 *
 *  Created on: 19 de nov de 2018
 *      Author: amanda.oliveira
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
//Macros e constantes
#define RANDOMICO rand()

//Estruturas e novos tipos
struct dados{
	int codigo;
	struct dados *anterior;
	struct dados *proximo;
};

typedef struct dados dados;

//Protótipos
void menu();
dados* inserirInicio(dados *lista);
void imprimirLista(dados *lista, int contador);
dados* inserirFimUltimo(dados *ultimo);
dados* inserirFim(dados *lista);
dados* excluirRegistro(int codigo, dados *lista);


#endif /* BIBLIOTECA_H_ */
