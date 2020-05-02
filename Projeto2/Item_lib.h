/* Caso este ficheiro, quando for chamado, nao estiver definido, define-o */

#ifndef ITEM_LIB_H
#define ITEM_LIB_H




/* Os headers necessarios estao declarados. */

#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/* Prototipos das funcoes associadas aos itens */

Item NewItem(unsigned long int chave, int stock);
void deleteItem(Item a);
int cmpItem(Item a, Item b);
int cmpItem_stock(Item a, Item b);
int verifica_stock(link a);
void print_max(link a);
void not_traverse(link h);
void confirma(link h);




#endif