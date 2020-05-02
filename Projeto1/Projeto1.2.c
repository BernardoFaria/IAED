/* Bernardo Gonçalves de Faria   Nº87636 */
/* Martinho */



#include <stdio.h>
#include <string.h>

/* Declaradas as diretivas de preprocessamento necessarias */

#define MAX 10000
#define TAM 140
#define USER_ID 1000


/* Definido o tipo Mensagem, que recebe o identificador do user e a frase */

typedef struct {
	int user;
	char frase[TAM+1];
} Mensagem;



/* Declaradas as variaveis globais */

int num_mens = 0;
Mensagem v_mensagens[MAX];



/* A funcao le o ñúmero introduzido, utiliza a fgets para ler a frase do utilizador, 
introduz cada mensagem m no vetor de mensagens, e incrementa o seu indice */

void executa_A() {

	Mensagem m;

	scanf("%d", &m.user);
	getchar();
	fgets(m.frase, TAM, stdin);
	v_mensagens[num_mens] = m;
	num_mens++;
}



/* A funcao le o indice do vetor de mensagens para saber o numero de mensagens que o forum tem.
De seguida, vai varrer o vetor enquanto existirem mensagens, imprimindo-as segundo o user e a sua frase */

void executa_L() {

	int i;

	printf("*TOTAL MESSAGES:%d\n", num_mens);
	for (i = 0; i < num_mens; i++)
		printf("%d:%s\n", v_mensagens[i].user, v_mensagens[i].frase);
}



/* A funcao le o identificador do user dado, varre o vetor de mensagens, e sempre que uma mensagem tem o user dado, ele imprime
a frase desse user. Imprime as frases pela ordem em que foram publicadas no forum. */

void executa_U() {

	int i, user;

	scanf("%d", &user);
	printf("*MESSAGES FROM USER:%d\n", user);
	for (i = 0; i < num_mens; i++)
		if (user == v_mensagens[i].user)
			printf("%s", v_mensagens[i].frase);
}



/* A funcao vai varrer o vetor de mensagens e procurar o maior comprimento das frases usando o strlen. De seguida, vai varrer de novo o vetor, 
e sempre que encontrar uma frase com o comprimento máximo, imprime o seu user e essa frase */

void executa_O() {

	int i, s_len;

	s_len = strlen(v_mensagens[0].frase);
	for (i = 0; i < num_mens; i++) 
		if (strlen(v_mensagens[i+1].frase) > s_len)
			s_len = strlen(v_mensagens[i+1].frase);
	for (i = 0; i < num_mens; i++)
		if(strlen(v_mensagens[i].frase) == s_len)
			printf("*LONGEST SENTENCE:%d:%s", v_mensagens[i].user, v_mensagens[i].frase);
}



/* FALTAM OS COMENTARIOS !!!!!!!!!!!! */


void executa_T() {
	int i, a = 0, user, n = 0;

	for (user = 0; user < USER_ID; user++) {
		for (i = 0; i < num_mens; i++) {
			if (user == v_mensagens[i].user) {
				a++;
			}
		}
		if (a > n) {
			n = a;
		}
		a = 0;
	}
	for (user = 0; user < USER_ID; user++) {
		for (i = 0; i < num_mens; i++) {
			if (user == v_mensagens[i].user) {
				a++;
			}
		}
		if (a == n) {
			printf("*MOST ACTIVE USER:%d:%d\n", user, n);
		}
		a = 0;
	}
}



/* A funcao le a palavra introduzida. Vai percorrer o vetor de mensagens, e selecionar cada palavra das mensagens atraves
da funcao strtok, que recebe a string que vai ser analisada e quais os carateres delimitadores. De seguida, vai usar a funcao
strcmp que compara a palavra introduzida pela palavra recolhida na string. Se o resultado for 0, significa que as palavras
sao iguais, chamando de novo a funcao ao resto da string. No fim, imprime o numero de ocorrencias dessa palavra em todas
as mensagens do forum. */


void executa_C() {

	char palavra[TAM], *word;
	int i, cont = 0;

	scanf("%s", palavra);
	for (i = 0; i < num_mens; i++) {
		word = strtok(v_mensagens[i].frase, " .,;\t\n\'\"\?%%\0");
		while(word != NULL) {
			if (strcmp(word, palavra) == 0) cont++;
			word = strtok(NULL, " .,;\t\n\'\"\?%%\0");
		}
	}	
	printf("*WORD %s:%d\n", palavra, cont);
}







void executa_S() {
	int a, i, j, aux_i;
	char aux_f[TAM+1];

	for (i = 0; i < num_mens - 1; i++) {
		for (j = (i + 1); j < num_mens; j++) {
			a = strcmp(v_mensagens[i].frase, v_mensagens[j].frase);
			if (a > 0) {
				strcpy(aux_f, v_mensagens[i].frase);
				aux_i = v_mensagens[i].user;
				strcpy(v_mensagens[i].frase, v_mensagens[j].frase);
				v_mensagens[i].user = v_mensagens[j].user;
				strcpy(v_mensagens[j].frase, aux_f);
				v_mensagens[j].user = aux_i;
			}
			if (a == 0) {
				if (v_mensagens[i].user > v_mensagens[j].user) {
					strcpy(aux_f, v_mensagens[i].frase);
					aux_i = v_mensagens[i].user;
					strcpy(v_mensagens[i].frase, v_mensagens[j].frase);
					v_mensagens[i].user = v_mensagens[j].user;
					strcpy(v_mensagens[j].frase, aux_f);
					v_mensagens[j].user = aux_i;
				}
			}
		}
	}
	printf("*SORTED MESSAGES:%d\n", num_mens);
	for (i = 0; i < num_mens; i++) {
		printf("%d:%s", v_mensagens[i].user, v_mensagens[i].frase);
	}
	
}







int main() {
	char comando;

	while (1) {

		comando = getchar();     /* A funcao getchar vai ler o comando fornecido pelo utilizador */

		if (comando == '\n')     /* Para a funcao nao acionar sempre o default, temos de ignorar o \n */
			continue;

		switch(comando){         /* A funcao switch vai selecionar qual o comando a ser acionado */
			case 'A':
				executa_A();
				break;
			case 'L':
				executa_L();
				getchar();
				break;
			case 'U':
				executa_U();
				getchar();
				break;
			case 'O':
				executa_O();
				getchar();
				break;
			case 'T':
				executa_T();
				getchar();
				break;
			case 'S':
				executa_S();
				getchar();
				break;
			case 'C':
				executa_C();
				break;
			case 'X':
				printf("%d\n", num_mens);
				return 0;
				break;
			default:
				printf("ERRO: Comando desconhecido\n");     /* Caso nenhuma das letras for carregada, o programa da erro */
		}
	}
	return 0;
}



