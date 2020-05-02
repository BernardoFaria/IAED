#ifndef ITEM_LIB_H
#define ITEM_LIB_H


#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Item NewItem(unsigned long int chave, int stock);
void deleteItem(Item a);
void showItem(Item a);
int cmpItem(Item a, Item b);


#endif