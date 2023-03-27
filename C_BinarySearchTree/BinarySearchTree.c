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
		if (key > cur->data->key)
			cur = cur->rchild;
		else if (key < cur->data->key)
			cur = cur->lchild;
		else
			return (cur->data);
	}
	return (NULL);
}

static node* get_new_node(pair* data)
{
	node* new_node = (node*)malloc(sizeof(node));

	new_node->lchild = NULL;
	new_node->rchild = NULL;
	new_node->data = data;

	return new_node;
}

static node* recursion_insert(tree* tree, node* cur, pair* data)
{
	if (cur == NULL)
	{
		node* new_node = get_new_node(data);

		if (tree->size == 0)
			tree->root = new_node;
		++tree->size;

		return new_node;
	}
	else if (data->key > cur->data->key)
		cur->rchild = recursion_insert(tree, cur->rchild, data);
	else if (data->key < cur->data->key)
		cur->lchild = recursion_insert(tree, cur->lchild, data);

	return cur;
}

void insert(tree* tree, pair* data)
{
	recursion_insert(tree, tree->root, data);
}

static node* get_simillar_node(node* cur)
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
			node* next = get_simillar_node(cur);

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
// 1. 들어온 key로 데이터 찾기
// 2-1. 찾은 노드의 자식이 없다면, 그 노드 지우고 NULL로 바꾸기
// 2-2. 찾은 노드의 자식이 하나라면, 그 노드 지우고 자식으로 바꾸기
// 2-3. 찾은 노드의 자식이 둘이라면
//		제일 차가 적은 자식 찾기
//		그 자식의 자식이 몇개인지에 따라 또 재귀적 반복

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