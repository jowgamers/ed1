/*
 ============================================================================
 Name        : listaNovosTipos.c
 Author      : Amanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura
struct prod{
	char nomeProduto[40];
	int codigo;
	float preco;
	int quantidade;
};

typedef struct prod produto;

/* As linhas abaixo substituem o c�digo da linha 15 at� 22
typedef struct {
	char nomeProduto[40];
	int codigo;
	float preco;
	int quantidade;
} produto;
*/

//Prot�tipo
void menu();
int validaQtde(char *texto);
int cadastrarCodigo();
void cadastrarNome(produto *pProd);
void cadastrarPreco(float *valor);
void cadastrarQuantidade(produto *prod);
void cadastrar(int numero, produto *pProd);
void imprimirEstoque(int numero, produto *pProd);
void imprimirSemEstoque(int numero, produto *pProd);


//Fun��es
int main(void) {
	setbuf(stdout, NULL);
	menu();
	return 0;
}


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
				"\nDigite sua op��o: ");
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
			printf("\nOp��o inv�lida");
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
			printf("\nValor inv�lido.");
		}
	} while (numero <= 0);

	return numero;
}


int cadastrarCodigo(){
	int codigo;
	do{
		printf("\nDigite o c�digo: ");
		scanf("%d", &codigo);

		if (codigo < 0 || codigo > 50){
			printf("\nC�digo inv�lid.");
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
			printf("\nNome inv�lido.");
		}

	} while (strlen(pProd->nomeProduto) == 0);
}

void cadastrarPreco(float *valor){
	do{
		printf("\nDigite o pre�o do produto:");
		scanf("%f", valor);

		if (*valor < 0) {
			printf("\nValor inv�lido.");
		}
	} while (*valor < 0);
}


void cadastrarQuantidade(produto *prod){
	do {
		printf("\nDigite a quantidade em estoque do produto %s:", prod->nomeProduto);
		scanf("%d", &prod->quantidade);

		if (prod->quantidade < 0){
			printf("\nValor inv�lido.");
		}
	} while (prod->quantidade < 0);
}

void cadastrar(int numero, produto *pProd){
	int i;
	for (i = 0; i < numero; i++){
		printf("\nProduto %d", i+1);
		pProd->codigo = cadastrarCodigo();
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



