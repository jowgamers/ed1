/*
 * biblioteca.h
 *
 *  Created on: 6 de nov de 2018
 *      Author: amanda.oliveira
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

//Macro e Constante
#define RANDOMICO(x) rand() % x

//Estruturas e novos tipos
struct dados{
	int codigo; //Itens de cadastramento
	struct dados *proximo; //Item de apontamento
};

typedef struct dados dados;

//Protótipos
void menu();
dados* inserirInicio(dados *lista);


#endif /* BIBLIOTECA_H_ */
