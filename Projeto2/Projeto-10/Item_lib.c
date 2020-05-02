#include "Item_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Item NewItem(unsigned long int chave, int stock) {

	Item a = (Item)malloc(sizeof(struct node));
	a->chave = chave;
	a->stock = stock;
	return a;
}


void deleteItem(Item a) {

	free(a);
}


void showItem(Item a) {

	printf("%lx %d", a->chave, a->stock);
}


int cmpItem(Item a, Item b) {

	if (a->chave < b->chave)
		return -1;
	else if (a->chave == b->chave)
		return 0;
	else
		return 1;
}


