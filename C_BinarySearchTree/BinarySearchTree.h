#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdlib.h>

typedef struct data
{
	int key;
	int value;
} data;

typedef struct node
{
	struct node* l_child;
	struct node* r_child;
	data data;
} node;

typedef struct tree
{
	node *root;
	int size;
}	tree;


#endif