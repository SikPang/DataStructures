#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#include "Pair.h"

typedef struct node
{
	struct node* lchild;
	struct node* rchild;
	pair* data;
} node;

typedef struct tree
{
	node *root;
	int size;
}	tree;

void initialize(tree* tree);
pair* find(tree* tree, int key);
void insert(tree* tree, pair* data);
void erase(tree* tree, int key);
void clear(tree* tree);

#endif