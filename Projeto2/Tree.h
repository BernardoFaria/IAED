/* Caso este ficheiro, quando for chamado, nao estiver definido, define-o */

#ifndef TREE_H
#define TREE_H




/* Os headers necessarios estao declarados. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/* Declaradas funcoes como diretivas */

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define eq(A,B) (key(A) == key(B))




/* Estrutura do tipo *Item, que e composto por uma chave e um numero de stock */

typedef struct produto {
	unsigned long int chave;
	int stock; 
} *Item;




/* Estrutura do tipo *link, que e formada por um item e nodos esquerdo (l) e direito (r) */

typedef struct node {
	Item item;
	struct node *l, *r;
} *link;




/* Prototipos das funcoes definidas para a estrutura da arvore binaria */

link NEW(Item item, link l, link r);
link search(link h, long unsigned int a);
link insert(link h, Item item);
link max(link h);
link min(link h);
link del(link h, unsigned long int chave);
int count(link h);
void visit (link i);
void traverse(link h);




#endif