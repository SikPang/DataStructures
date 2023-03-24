#include "BinarySearchTree.h"

void initialize(tree* tree)
{
	tree->root = NULL;
	tree->size = 0;
}

pair* find(tree* tree, int key)
{
	node* cur;

	cur = tree->root;
	while (cur != NULL)
	{
		if (key > cur->data->first)
			cur = cur->rchild;
		else if (key < cur->data->first)
			cur = cur->lchild;
		else
			return (cur->data);
	}
	return (NULL);
}

// void insert(tree* tree, pair* data)
// {
// 	bool is_lchild;
// 	node* cur = tree->root;
// 	node* new_node = (node*)malloc(sizeof(node));

// 	new_node->data = data;
// 	new_node->lchild = NULL;
// 	new_node->rchild = NULL;

// 	while (cur != NULL)
// 	{
// 		if (data->first > cur->data->first)
// 		{
// 			if (cur->rchild == NULL)
// 			{
// 				is_lchild = false;
// 				break;
// 			}
// 			cur = cur->rchild;
// 		}
// 		else if (data->first < cur->data->first)
// 		{
// 			if (cur->lchild == NULL)
// 			{
// 				is_lchild = true;
// 				break;
// 			}
// 			cur = cur->lchild;
// 		}
// 		else
// 			return;
// 	}

// 	if (cur == NULL)
// 		tree->root = new_node;
// 	else if (is_lchild)
// 		cur->lchild = new_node;
// 	else
// 		cur->rchild = new_node;
// 	++tree->size;
// }

void insert(tree* tree, pair* data)
{
	
}

// static pair* get_min_data(node* cur)
// {
// 	while (cur->lchild != NULL)
// 		cur = cur->lchild;
	
// 	return (cur->data);
// }

// static node* terminate(tree* tree, node* cur)
// {
// 	node* temp;

// 	if (tree->size == 1)
// 		tree->root = NULL;

// 	if (cur->rchild == NULL)
// 		temp = cur->lchild;
// 	else
// 		temp = cur->rchild;

// 	if (cur == tree->root)
// 		tree->root = temp;

// 	free(cur->data);
// 	free(cur);
// 	--(tree->size);
// 	return (temp);
// }

// static node* recursion_erase(tree* tree, node* cur, int key)
// {
// 	if (cur == NULL)
// 		return (NULL);
	
// 	pair* temp;

// 	if (key > cur->data->first)
// 		cur->rchild = recursion_erase(tree, cur->rchild, key);
// 	else if (key < cur->data->first)
// 		cur->lchild = recursion_erase(tree, cur->lchild, key);
// 	else
// 	{
// 		if (cur->lchild == NULL || cur->rchild == NULL)
// 			return (terminate(tree, cur));
// 		temp = get_min_data(cur->rchild);
// 		free(cur->data);
// 		cur->data = temp;
// 		cur->rchild = recursion_erase(tree, cur->rchild, temp->first);
// 	}
// 	return (cur);
// }

// void erase(tree* tree, int first)
// {
// 	recursion_erase(tree, tree->root, first);
// }

void erase(tree* tree, int first)
{
	stack stack;

	node* cur = tree->root;
	while (cur != NULL)
	{

	}
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
}