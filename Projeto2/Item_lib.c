/* Os headers necessarios estao declarados. */

#include "Item_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/* Variaveis associadas a este ficheiro */

int maximo;
int cont;




/* A funcao cria um novo item, alocando memoria para ele, e guardadndo a chave e o stock */

Item NewItem(unsigned long int chave, int stock) {

	Item a = (Item)malloc(sizeof(struct node));
	a->chave = chave;
	a->stock = stock;
	return a;
}




/* A funcao remove um item, libertando a memoria alocada para esse item */

void deleteItem(Item a) {

	free(a);
}




/* A funcao compara as chaves de dois itens, retornando -1 caso a chave do primeiro seja menor que a do segundo,
0 caso haja igualdade, e 1 caso contrario */

int cmpItem(Item a, Item b) {

	if (a->chave < b->chave)
		return -1;
	else if (a->chave == b->chave)
		return 0;
	else
		return 1;
}




/* A funcao compara o stock de dois itens, retornando 1 caso o stock do primeiro seja maior que o do segundo, 
ou no caso os stocks serem iguais compara as chaves de cada um; retorna 0 caso contrario */

int cmpItem_stock(Item a, Item b) {

	if (a->stock > b->stock)
		return 1;
	else if (a->stock == b->stock && a->chave > b->chave)
		return 1;
	else
		return 0;
}




/* A funcao verifica se existe stock */
int verifica_stock(link a) {
	int n = 0;
	if (a->item->stock > n) {
		n = a->item->stock;
	}
	return n;
}




/* A funcao imprime o maximo*/

void print_max(link a) {
	if (a->item->stock == maximo) {
		visit(a);
		cont = 0;
	}
}




/* A funcao se o que imprime e o maximo */

void confirma(link h) {
	if (h == NULL)
		return;
	confirma(h->l);
	if (cont == 1) {
	print_max(h);
	}
	confirma(h->r);
}




/* A funcao percorre a arvore, e caso exista stock, imprime o maximo */

void not_traverse(link h) {
	if (h == NULL)
		return;
	not_traverse(h->l);
	maximo = verifica_stock(h);
	not_traverse(h->r);
	cont = 1;
}