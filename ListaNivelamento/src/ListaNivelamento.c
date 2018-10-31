/*
 ============================================================================
 Name        : ListaNivelamento.c
 Author      : Amanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	setbuf(stdout, NULL);
	//Variáveis
	char menu;
	int termos,
		n = 1;
	float resultado = 0;

	//Processamento
	for(;;){ //Loop infinito

		printf("\nA - Série A"
				"\nB - Série B"
				"\nC - Série C"
				"\nD - Finalizar"
				"\nDigite sua opção: ");
		fflush(stdin);
		scanf("%c", &menu);

		if (menu == 'D') {
			printf("\nPrograma finalizado.");
			break;
		} else if (menu >= 'A' && menu <= 'C'){
			//Solicitar qtde de termos.
			do{
				printf("\nDigite a quantidade de termos a calcular: ");
				scanf("%d", &termos);

				if (termos <= 0) {
					printf("\nNúmero inválido.");
				}
			} while (termos <= 0);

			//Inicializo para cada execução.
			n = 1;
			resultado = 0;
			//Executar código específico
			switch(menu){
			case 'A':
						while (n <= termos){
							resultado += (n + (n-1)) / pow(n,2);
							//resultado += (n + (n-1)) / (float) n * n;
							n++;
						}
						break;
			case 'B':
						do{
							resultado += pow(n, 3) / pow(10, n-1);
							n++;
						} while (n <= termos);

						break;
			case 'C':
						for(n = 1; n <= termos; n++) {
							resultado += n / (float) (3 * n * 2);
						}
						break;
			}

			//Resultado final
			printf("\nO cálculo de %d termo(s) da série %c é %.2f.", termos, menu, resultado);

		} else {
			printf("\nOpção inválida. Digite novamente.");
		}
	}
	return 0;
}
