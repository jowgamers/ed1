/*
 ============================================================================
 Name        : NovosTipos.c
 Author      : Amanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef int inteiro[4];

//defini um tipo e já declarei a struct ao mesmo tempo
typedef struct {
	int codigo;
	char nome[30];
	int idade;
}dep;

//Declarei a struct com seus membros
struct func {
	int matricula;
	char nome[30];
	double salario;
	dep dependentes[4];
};

//defini um tipo com as características da struct
typedef struct func funcionario;


int main(void) {
	setbuf(stdout, NULL);
	//inteiro numero;
	//printf("\n%d", numero);

	funcionario funcionarios[5];
	funcionarios[2].matricula = 15;
	funcionarios[2].dependentes[1].codigo = 26;

	int *x = (int*) malloc (sizeof(int));
	funcionario *px = (funcionario*) malloc (sizeof(funcionario));

	printf("\nInteiro = %i"
			"\nFuncionario = %i", sizeof(int), sizeof(funcionario));


	return 0;
}



