/*
 * Biblioteca.h
 *
 *  Created on: 22 de out de 2018
 *      Author: amanda.oliveira
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

//Estrutura
struct prod{
	char nomeProduto[40];
	int codigo;
	float preco;
	int quantidade;
};

typedef struct prod produto;

/* As linhas abaixo substituem o código da linha 15 até 22
typedef struct {
	char nomeProduto[40];
	int codigo;
	float preco;
	int quantidade;
} produto;
*/

//Macros e Constantes
#define COD rand() % 50
#define COD2(x) rand() % x

#define TAM 150


//Protótipo
void menu();
int validaQtde(char *texto);
int cadastrarCodigo();
void cadastrarNome(produto *pProd);
void cadastrarPreco(float *valor);
void cadastrarQuantidade(produto *prod);
void cadastrar(int numero, produto *pProd);
void imprimirEstoque(int numero, produto *pProd);
void imprimirSemEstoque(int numero, produto *pProd);



#endif /* BIBLIOTECA_H_ */
