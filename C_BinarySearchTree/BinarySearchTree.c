#include "BinarySearchTree.h"

void initialize(tree* tree)
{
	tree->root = NULL;
	tree->size = 0;
}

pair* find(tree* tree, int key)
{
	node* cur = tree->root;

	while (cur != NULL)
	{
		if (key > cur->data->key)
			cur = cur->rchild;
		else if (key < cur->data->key)
			cur = cur->lchild;
		else
			return cur->data;
	}

	return NULL;
}

static node* recursion_insert(tree* tree, node* cur, pair* data)
{
	if (cur == NULL)
	{
		node* new_node = (node*)malloc(sizeof(node));

		new_node->lchild = NULL;
		new_node->rchild = NULL;
		new_node->data = data;

		if (tree->size == 0)
			tree->root = new_node;
		++tree->size;

		return new_node;
	}

	if (data->key > cur->data->key)
		cur->rchild = recursion_insert(tree, cur->rchild, data);
	else if (data->key < cur->data->key)
		cur->lchild = recursion_insert(tree, cur->lchild, data);
	else
		free(data);

	return cur;
}

void insert(tree* tree, pair* data)
{
	recursion_insert(tree, tree->root, data);
}

static node* get_similar_node(node* cur)
{
	cur = cur->lchild;

	while (cur->rchild != NULL)
		cur = cur->rchild;
	
	return cur;
}

static node* recursion_erase(tree* tree, node* cur, int key)
{
	if (cur == NULL)
		return NULL;

	if (key == cur->data->key)
	{
		if (cur->lchild == NULL || cur->rchild == NULL)
		{
			node* temp;
			
			if (cur->lchild == NULL)
				temp = cur->rchild;
			else
				temp = cur->lchild;

			if (cur == tree->root)
				tree->root = temp;
			--tree->size;
			
			free(cur->data);
			free(cur);
			
			return temp;
		}
		else
		{
			node* next = get_similar_node(cur);

			free(cur->data);
			cur->data = make_pair(next->data->key, next->data->value);

			cur->lchild = recursion_erase(tree, cur->lchild, next->data->key);
		}
	}
	else if (key > cur->data->key)
		cur->rchild = recursion_erase(tree, cur->rchild, key);
	else if (key < cur->data->key)
		cur->lchild = recursion_erase(tree, cur->lchild, key);

	return cur;
}

void erase(tree* tree, int key)
{
	recursion_erase(tree, tree->root, key);
}

static void recursion_clear(node* cur)
{
	if (cur == NULL)
		return ;
	
	recursion_clear(cur->lchild);
	recursion_clear(cur->rchild);
	free(cur->data);
	free(cur);
}

void clear(tree* tree)
{
	recursion_clear(tree->root);
	initialize(tree);
}

void recursion_print(node* cur)
{
	if (cur == NULL)
		return ;
	
	recursion_print(cur->lchild);
	printf("(%d:%d) ", cur->data->key, cur->data->value);
	recursion_print(cur->rchild);
}

void print(tree* tree)
{
	printf("[size:%d] ", tree->size);
	recursion_print(tree->root);
	printf("\n");
}