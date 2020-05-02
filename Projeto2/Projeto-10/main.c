/* Bernardo Gonçalves de Faria   			 Nº87636 */
/* Martinho Rodrigues da Silva Fé Santos     Nº87686 */



#include <stdio.h>
#include <stdlib.h>
#include "Projeto2.h"


int main() {
	char comando;
	init();

	while (1) {

		comando = getchar();     /* A funcao getchar vai ler o comando fornecido pelo utilizador */

		if (comando == '\n')     /* Para a funcao nao acionar sempre o default, temos de ignorar o \n */
			continue;

		switch(comando){         
			case 'a':
				executa_a();
				getchar();

				break;
			case 'l':
				executa_l();
				getchar();

				break;
			case 'm':
				//executa_m();
				//getchar();
				break;
			case 'r':
				executa_r();
				getchar();
				break;
			case 'x':
				executa_x();
				return EXIT_SUCCESS;         /* Return 0 termina o programa. */
				break;
			default:
				printf("ERRO: Comando desconhecido\n");     /* Caso nenhuma das letras for carregada, o programa da erro */
		}
	}
	return EXIT_FAILURE;
}
