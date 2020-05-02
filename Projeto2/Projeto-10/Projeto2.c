#include "Tree.h"
#include "Item_lib.h"
#include "Projeto2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static link head;

void init() {
	head = NULL;
}



void executa_a() {

	link aux = NULL;

	long unsigned int chave;
	int stock;

	scanf("%lx%d", &chave, &stock);
	aux = search(head, chave);

	if(aux == NULL){
		head = insert(head, NewItem(chave, stock));
	} 
	else {
		if (aux->item->stock + stock > 0)
			aux->item->stock +=stock;
		else
			aux->item->stock = 0;
	}
}



void executa_l() {

	traverse(head);
}



void executa_r() {

	long unsigned int chave;
	link aux;

	scanf("%lx", &chave);
	aux = search(head, chave);
	if (aux != NULL)
		head = del(head,chave);
}



void executa_x() {

	int i;

	i = count(head);
	printf("%d\n", i);
}