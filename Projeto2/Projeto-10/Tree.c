#include "Tree.h"
#include "Item_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Item NovoProduto(unsigned long int chave, int stock) {

	Item a= (Item)malloc(sizeof(struct produto));
	a->chave = chave;
	a->stock = stock;
	return a;
}


/* Novo item */
link NEW(Item item, link l, link r) {

	link a = (link)malloc(sizeof(struct node));
	a->item = item;
	a->l = l;
	a->r = r;
	return a;
}





/* Pesquisa de uma chave */
link search(link h, long unsigned int chave) {


	if (h == NULL)
		return NULL;
	if (eq(chave, h->item->chave))
		return h;
	if (less(chave, h->item->chave))
		return search(h->l, chave);
	else
		return search(h->r, chave);
}





/* Insercao de um novo elemento */
link insert(link h, Item item) {

	Item v = item;
	if (h == NULL) {
		if (h->item->chave < 0)
			h->item->chave = 0;
		return NEW(item, NULL, NULL);
	}
	if (v->chave == h->item->chave)
		h->item->stock += v->stock;
	else if (less(v->chave, h->item->chave))
		h->l = insert(h->l, item);
	else
		h->r = insert(h->r, item);
	return h;
}







/* Encontrar o maior elemento abaixo de um nodo */
link max(link h) {

	if (h==NULL || h->r==NULL) return h;
	else return max(h->r);
}


/* Encontrar o menor elemento abaixo de um nodo */
link min(link h) {

	if (h==NULL || h->l==NULL) return h;
	else return min(h->l);
}


/* Remocao de um elemento */
link del(link h, unsigned long int chave) {

	link aux;
	if (h==NULL) return h;
	else if (less(chave, h->item->chave)) h->l=del(h->l,chave);
	else if (less(h->item->chave, chave)) h->r=del(h->r,chave) ;
	else {
		if (h->l != NULL && h->r != NULL) { 			/*nodo interno*/
			aux = max(h->l);
			{Item x = h->item; h->item = aux->item; aux->item = x;}
			h->l=del(h->l, aux->item->chave);
		}
		else {										/*nodo sem filhos/nodo com filho unico*/
			aux = h;
			if (h->l == NULL && h->r == NULL ) h=NULL;
			else if (h->l == NULL) h = h->r;
			else h = h->l;
			deleteItem(aux->item);
			free(aux);
		}
	}
	return h;
}




/* Numero de elementos */
int count(link h) {

	if (h == NULL) return 0;
	else
		return count(h->r) + count(h->l) + 1;
}



/* Funcao visit */
void visit (link a) {
	printf("%08lx %d\n",a->item->chave, a->item->stock);
}


/* Travessia em In-Order (sorted) */
void traverse(link h) {

	if (h == NULL)
		return;
	traverse(h->l);
	visit(h);
	traverse(h->r);
}


