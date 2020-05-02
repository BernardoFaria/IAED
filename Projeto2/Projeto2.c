/* Os headers necessarios estao declarados. */

#include "Tree.h"
#include "Item_lib.h"
#include "Projeto2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/* Variavel global */

static link head;
//static Item maximo;



/* A funcao inicializa a arvore */

void init() {
	head = NULL;
}




/* A funcao incrementa ou reduz o numero de unidades associadas ao produto com a chave
dada; se a chave nao existir, devera ser criado um novo item com essa chave */

void executa_a() {

	link aux = NULL;

	long unsigned int chave;
	int stock;

	scanf("%lx%d", &chave, &stock);
	aux = search(head, chave);		/* Verifica se a chave existe */

	if(aux == NULL){
		head = insert(head, NewItem(chave, stock));		/* Se nao existir, cria um novo item */
	} 
	else {												/* Se existir, atualiza o stock */
		if (aux->item->stock + stock > 0)
			aux->item->stock +=stock;
		else
			aux->item->stock = 0;
	}
}




/* A funcao lista alfabeticamente todos os produtos */

void executa_l() {

	traverse(head);		/* Chama a funcao traverse, que percorre a arvore ordenadamente pelas chaves */
}




/* A funcao retorna o item que tem o maior numero de stock */

void executa_m() {
	not_traverse(head);
	confirma(head);
}



/*
void traverse_maximus(link h, Item* j) {

	if (h == NULL)
		return;
	traverse_maximus(h->l,j);
	traverse_maximus(h->r,j);
	if (*j == NULL || cmpItem_stock(head->item,*j))
		*j = h->item;
}



void executa_m() {
	Item j = NULL;
	traverse_maximus(head, &j);
	//j = maximo;
	printf("%lx %d\n", j->chave, j->stock);
}
*/




/* A funcao remove o produto com a chave dada */

void executa_r() {

	long unsigned int chave;
	link aux;

	scanf("%lx", &chave);
	aux = search(head, chave);		/* Verifica se a chave ja existe */
	if (aux != NULL)
		head = del(head,chave);
	//if (aux->item->chave == chave)
	//	executa_m();
}




/* A funcao faz free da arvore, isto e, liberta toda a memoria alocada */

void apaga_arvore(link h) {
	if (h == NULL)
		return;
	apaga_arvore(h->l);
	apaga_arvore(h->r);
	deleteItem(h->item);
	free(h);
}




/* A funcao termina o programa, imprimindo o numero de chaves diferentes guardados no sistema */

void executa_x() {

	int i;

	i = count(head);
	apaga_arvore(head);
	printf("%d\n", i);
}