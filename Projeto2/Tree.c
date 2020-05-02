/* Os headers necessarios estao declarados. */

#include "Tree.h"
#include "Item_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/* A funcao cria um novo link, alocando memoria para ele; e composto pelo item e pelos nodos l e r */

link NEW(Item item, link l, link r) {

	link a = (link)malloc(sizeof(struct node));
	a->item = item;
	a->l = l;
	a->r = r;
	return a;
}




/* A funcao faz a pesquisa de uma chave na arvore binaria. Recebe um link e uma chave, e vai procurar 
(enquanto o link nao for NULL) se essa chave existe na arvore */

link search(link h, long unsigned int chave) {

	if (h == NULL)
		return NULL;
	if (eq(chave, h->item->chave))		/* Compara as chaves para ver se ja existe */
		return h;
	if (less(chave, h->item->chave))	/* Vai escolher por que lado da arvore vai procurar */
		return search(h->l, chave);
	else
		return search(h->r, chave);
}




/* A funcao insere um novo item: caso o link for NULL, vai criar ai o novo link, pondo o stock a 0 caso seja negativo;
caso a chave ja exista, vai adicionar apenas o novo stock; se nao existir, vai escolher o lado da arvore a percorrer
ate encontrar um link a NULL para poder inserir o novo item. */

link insert(link h, Item item) {

	Item v = item;
	if (h == NULL) {
		if (h->item->chave < 0)
			h->item->chave = 0;
		return NEW(item, NULL, NULL);	/* Cria um novo link */
	}
	if (v->chave == h->item->chave)
		h->item->stock += v->stock;
	else if (less(v->chave, h->item->chave))
		h->l = insert(h->l, item);		/* Usa recorrencia para voltar a procurar na arvore */
	else
		h->r = insert(h->r, item);		/* Usa recorrencia para voltar a procurar na arvore */
	return h;
}




/* A funcao vai encontrar o maior numero abaixo de um dado nodo */

link max(link h) {

	if (h==NULL || h->r==NULL) return h;
	else return max(h->r);
}



/* A funcao vai encontrar o menor elemento abaixo de um dado nodo */

link min(link h) {

	if (h==NULL || h->l==NULL) return h;
	else return min(h->l);
}




/* A funcao vai remover um item, procurando-o pela arvore atraves da chave. */

link del(link h, unsigned long int chave) {

	link aux;
	if (h==NULL) return h;
	else if (less(chave, h->item->chave)) h->l=del(h->l,chave);
	else if (less(h->item->chave, chave)) h->r=del(h->r,chave) ;
	else {
		if (h->l != NULL && h->r != NULL) { 				/* Caso seja um nodo interno*/
			aux = max(h->l);
			{Item x = h->item; h->item = aux->item; aux->item = x;}
			h->l=del(h->l, aux->item->chave);
		}
		else {												/* Caso seja um nodo sem filhos ou um nodo com filho unico*/
			aux = h;
			if (h->l == NULL && h->r == NULL ) h=NULL;
			else if (h->l == NULL) h = h->r;
			else h = h->l;
			deleteItem(aux->item);
			free(aux);		/* Libertacao da memoria alocada */
		}
	}
	return h;
}




/* A funcao vai contar o numero total de items existentes na arvore */

int count(link h) {

	if (h == NULL) return 0;
	else
		return count(h->r) + count(h->l) + 1;
}




/* A funcao imprime um item(chave e stock) */

void visit (link a) {
	printf("%08lx %d\n",a->item->chave, a->item->stock);	/* %08: requerido para a chave apresentar sempre 8 careteres */
}




/* A funcao faz uma travessia em In-Order sorted (navega a arvore binaria imprimindo os itens por ordem crescente da chave),
indo primeiro ao lado esquerdo onde estao os menores elementos e depois ao lado direito onde estao os maiores */

void traverse(link h) {

	if (h == NULL)
		return;
	traverse(h->l);
	visit(h);
	traverse(h->r);
}


