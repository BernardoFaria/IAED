#ifndef TREE_H
#define TREE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define eq(A,B) (key(A) == key(B))





typedef struct produto {
	unsigned long int chave;
	int stock; 
} *Item;



typedef struct node {
	Item item;
	struct node *l, *r;
} *link;



//void init();
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