#include <stdio.h>
#include "BinarySearchTree.h"

void recursion_print(node* cur)
{
	if (cur == NULL)
		return ;
	
	recursion_print(cur->lchild);
	
	printf("%d, ", cur->data->key);
	
	recursion_print(cur->rchild);
}

void print_tree(tree* tree)
{
	if (tree->root == NULL)
	{
		printf("tree is empty\n");
		return;
	}

	printf("[size:%d] ", tree->size);
	recursion_print(tree->root);
	printf("\n");
}

int main()
{
	tree tree;

	initialize(&tree);
	print_tree(&tree);

	insert(&tree, make_pair(7, 0));
	print_tree(&tree);

	insert(&tree, make_pair(5, 0));
	print_tree(&tree);

	insert(&tree, make_pair(15, 0));
	print_tree(&tree);

	insert(&tree, make_pair(3, 0));
	print_tree(&tree);

	insert(&tree, make_pair(6, 0));
	print_tree(&tree);

	insert(&tree, make_pair(10, 0));
	print_tree(&tree);

	insert(&tree, make_pair(16, 0));
	print_tree(&tree);

	insert(&tree, make_pair(4, 0));
	print_tree(&tree);

	insert(&tree, make_pair(8, 0));
	print_tree(&tree);

	insert(&tree, make_pair(12, 0));
	print_tree(&tree);

	insert(&tree, make_pair(11, 0));
	print_tree(&tree);

	erase(&tree, 15);
	print_tree(&tree);

	erase(&tree, 12);
	print_tree(&tree);

	erase(&tree, 11);
	print_tree(&tree);

	erase(&tree, 10);
	print_tree(&tree);

	erase(&tree, 8);
	print_tree(&tree);

	erase(&tree, 16);
	print_tree(&tree);

	erase(&tree, 7);
	print_tree(&tree);

	erase(&tree, 5);
	print_tree(&tree);

	erase(&tree, 3);
	print_tree(&tree);

	erase(&tree, 6);
	print_tree(&tree);

	erase(&tree, 4);
	print_tree(&tree);

	clear(&tree);
}