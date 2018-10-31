/*
 ============================================================================
 Name        : listaFuncoes.c
 Author      : Amanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Protótipos
void menu();
double validarReal();
int validarInteiro(int limiteInicial, char *frase);
void calcularSalario(int dias, float *salarioFinal);
double calcularNovoSalario(double *vetor, int tamanho);

//Funções
int main(void) {
	setbuf(stdout, NULL);
	menu();
	return 0;
}


void menu(){
	char menu;
	float salario;
	int tamanho;
	double *pSalario,
			media;

	for(;;){
		printf("\nA – Resultado do exercício 04"
				"\nB – Resultado do exercício 05"
				"\nC – Finalizar"
				"\nDigite sua opção: ");
		fflush(stdin);
		scanf("%c", &menu);

		if (menu == 'C') {
			printf("\nPrograma finalizado");
			break;
		} else if (menu == 'A'){
			printf("\nFunção 04");
			calcularSalario(validarInteiro(0, "\nDigite a quantidade de dias: "), &salario);
			printf("\nO salário final é R$%.2f", salario);
		} else if (menu == 'B') {
			printf("\nFunção 05");
			tamanho = validarInteiro(1, "\nQual o tamanho do vetor: ");
			pSalario = (double*) malloc (tamanho * sizeof(double));

			media = calcularNovoSalario(pSalario, tamanho);
			printf("\nA média dos salários é R$%.2f", media);
		} else {
			printf("\nIncorreto.");
		}
	}
}

double calcularNovoSalario(double *vetor, int tamanho){
	int i;
	double soma = 0;

	for(i = 0; i < tamanho; i++){
		//Receber salário inicial
		*vetor = validarReal();

		//Calcular aumento de salário
		if (*vetor <= 1500){
			*vetor *= 1.15;
		} else if (*vetor <= 5000){
			*vetor *= 1.1;
		} else if (*vetor <= 15000){
			*vetor *= 1.05;
		}

		//Somar para calcular a média
		soma += *vetor;

		//Próximo endereço de memória
		vetor++;
	}

	return soma / tamanho;
}

int validarInteiro(int limiteInicial, char *frase){
	int numero;
	do{
		printf("\n%s", frase);
		scanf("%d", &numero);

		if (numero < limiteInicial) {
			printf("\nInválido.");
		}
	} while (numero < limiteInicial);
	return numero;
}

double validarReal(){
	double numero;
	printf("\nDigite o valor: ");
	scanf("%lf", &numero);
	while (numero <= 0){
		printf("\nValor inválido.");
		printf("\nDigite o valor: ");
		scanf("%lf", &numero);
	}
	return numero;
}

void calcularSalario(int dias, float *salarioFinal){
	//30 * dias * 0.92
	*salarioFinal = 30 * dias * 0.92;
}






