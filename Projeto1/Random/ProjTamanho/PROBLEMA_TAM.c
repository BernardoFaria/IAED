/* Grupo tg077 */
/* Bernardo Gonçalves de Faria   			 Nº87636 */
/* Martinho Rodrigues da Silva Fé Santos     Nº87686 */


/* Os headers necessarios estao declarados. */

#include <stdio.h>
#include <string.h>




/* Declaradas as diretivas de pre-processamento necessarias: 
									MAX e o numero maximo de mensagens possiveis
									TAM e o tamanho maximo de cada frase a contar com o \0
									USER_ID e o tamanho maximo de utilizadores possiveis */

#define MAX 10000
#define TAM 141
#define USER_ID 1000




/* Definida a estrutura Mensagem, que recebe o identificador do user e a frase. */

typedef struct {
	int user;
	char frase[TAM];
} Mensagem;




/* Declaradas as variaveis globais: num_mens e o número de mensagens introduzidas,
									v_num e o vetor de utilizadores cujos indices sao os identificadores de cada utilizador. 
 									v_mensagens[MAX] e o vetor de estruturas. */
int num_mens = 0;
int v_num[USER_ID];
Mensagem v_mensagens[MAX];




/* A funcao le o numero introduzido, utiliza a fgets para ler a frase do utilizador, 
introduz cada mensagem m no vetor de mensagens, e incrementa o seu indice.
Para alem disso, sempre que um dado utilizador introduz uma mensagem, o vetor de utilizadores é incrementado
na posicao relativa a esse utilizador. */

void executa_A() {

	scanf("%d", &v_mensagens[num_mens].user);
	v_num[v_mensagens[num_mens].user]++;                    
	getchar();  											// Le o espaco entre o numero e a frase.
	fgets(v_mensagens[num_mens].frase, TAM, stdin);     	// Recebe as frases do input com tamanho TAM.
	num_mens++;
}




/* A funcao le o indice do vetor de mensagens para saber o numero de mensagens que o forum tem.
De seguida, vai varrer o vetor enquanto existirem mensagens, imprimindo-as segundo o utilizador e a sua frase. */

void executa_L() {

	int i;

	printf("*TOTAL MESSAGES:%d\n", num_mens);
	for (i = 0; i < num_mens; i++)
		printf("%d:%s", v_mensagens[i].user, v_mensagens[i].frase);
}




/* A funcao le o identificador do utilizador dado, varre o vetor de mensagens, e sempre que uma mensagem 
tem o utilizador dado, ele imprime a frase desse utilizador. Imprime as frases pela ordem em que foram publicadas no forum. */

void executa_U() {

	int i, user;

	scanf("%d", &user);
	printf("*MESSAGES FROM USER:%d\n", user);
	for (i = 0; i < num_mens; i++)
		if (user == v_mensagens[i].user)
			printf("%s", v_mensagens[i].frase);
}




/* A funcao vai varrer o vetor de mensagens e procurar o maior comprimento das frases usando o strlen.
De seguida, vai varrer de novo o vetor, e sempre que encontrar uma frase com o comprimento máximo,
imprime o seu utilizador e essa frase. */

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




/* A funcao comeca por varrer o vetor de utilizadores e contar qual o maior numero de mensagens dos utilizadores,
guardando esse valor na variavel "a". De seguida, ele varre de novo o vetor, e sempre que uma posicao tenha o valor de "a",
ele imprime o numero desse utilizador. */


void executa_T() {

	int i, a = 0;

	for (i = 0; i < USER_ID; i++) {
		if (v_num[i] > a) {
			a = v_num[i];
		}
	}
	for (i = 0; i < USER_ID; i++) {
		if (v_num[i] == a) {
			printf("*MOST ACTIVE USER:%d:%d\n", i, v_num[i]);
		}
	}
}




/* A funcao le a palavra introduzida. Vai percorrer o vetor de mensagens, copiar cada frase atraves da funcao strcpy, 
e selecionar cada palavra das mensagens atraves da funcao strtok, que recebe a string que vai ser analisada 
e quais os carateres delimitadores. De seguida, vai usar a funcao strcmp que compara a palavra introduzida
pela palavra recolhida na string. Se o resultado for 0, significa que as palavras sao iguais, chamando de novo a funcao 
ao resto da string. No fim, imprime o numero de ocorrencias dessa palavra em todas as mensagens do forum. */


void executa_C() {

	char palavra[TAM], *word;
	char testPalavra[TAM];
	int i, cont = 0;

	scanf("%s", palavra);
	for (i = 0; i < num_mens; i++) {
		strcpy(testPalavra, v_mensagens[i].frase);
		word = strtok(testPalavra, " .,;\t\n\'\"\?%%\0");
		while(word != NULL) {
			if (strcmp(word, palavra) == 0) 
				cont++;
			word = strtok(NULL, " .,;\t\n\'\"\?%%\0");
		}
	}	
	printf("*WORD %s:%d\n", palavra, cont);
}




/* Utilizamos o algoritmo de ordenacao Insertion Sort. Definimos a funcao less
que, atraves da funcao strcmp, vai primeiro verificar se as frases sao iguais ou nao,
isto e, se estao alfabeticamente ordenadas. Se estiverem, vai ordenar os utilizadores
por ordem crescente. */


int less(int a, int b) {

	if(strcmp(v_mensagens[a].frase, v_mensagens[b].frase) < 0)
		return 1;
	else if ((strcmp(v_mensagens[a].frase, v_mensagens[b].frase) == 0) && 
		v_mensagens[a].user < v_mensagens[b].user)
		return 1;
	return 0;
}



void sort(int a[], int l, int r) {
	int i,j;
	for (i = l+1; i <= r; i++) {
		int v = a[i];
		j = i-1;
		while ( j>=l && less(v, a[j])) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
	}
}




/* A funcao cria um vetor de indices, que contem os indices dos utilizador. Aplica
o algorimo acima descrito para ordenar esses indices, e consequentemente as mensagens. */

void executa_S() {

	int i, indices[MAX];
	
	printf("*SORTED MESSAGES:%d\n", num_mens);
	for (i = 0; i < num_mens; i++)
		indices[i] = i;
	sort(indices, 0, num_mens-1);
	for (i = 0; i < num_mens; i++)
		printf("%d:%s", v_mensagens[indices[i]].user, v_mensagens[indices[i]].frase);

}




/* A funcao vai terminar o programa, imprimindo o numero total de utilizadores e o numero total de mensagens no sistema. */

void executa_X() {

	printf("%d\n", num_mens);
}




/* A funcao main tem o objetivo principal de ler o comando introduzido pelo utilizador atraves da funcao switch,
que dependendo do comando introduzido, executa as funcoes a ele associadas. */



int main() {
	char comando;

	while (1) {

		comando = getchar();     /* A funcao getchar vai ler o comando fornecido pelo utilizador */

		if (comando == '\n')     /* Para a funcao nao acionar sempre o default, temos de ignorar o \n */
			continue;

		switch(comando){         
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
				executa_X();
				return 0;               /* Return 0 termina o programa. */
				break;
			default:
				printf("ERRO: Comando desconhecido\n");     /* Caso nenhuma das letras for carregada, o programa da erro */
		}
	}
	return 0;
}



