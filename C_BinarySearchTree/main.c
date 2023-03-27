#include <stdio.h>
#include "BinarySearchTree.h"

void recursion_print(node* cur)
{
	if (cur == NULL)
		return ;
	
	recursion_print(cur->lchild);
	
	printf("(%d:%d) ", cur->data->key, cur->data->value);
	
	recursion_print(cur->rchild);
}

void print_tree(tree* tree)
{
	printf("[size:%d] ", tree->size);

	recursion_print(tree->root);
	printf("\n");
}

int main()
{
	tree tree;

	printf("----- initialize -----\n");
	initialize(&tree);
	print_tree(&tree);

	printf("\n----- insert -----\n");
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

	printf("\n----- find -----\n");
	printf("%p\n", find(&tree, 16));
	printf("%p\n", find(&tree, 4));
	printf("%p\n", find(&tree, 7));
	printf("%p\n", find(&tree, 20));

	printf("\n----- erase -----\n");
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

	printf("\n----- clear -----\n");
	clear(&tree);
	print_tree(&tree);

	printf("\n----- edge cases -----\n");
	clear(&tree);		// double clear
	print_tree(&tree);

	insert(&tree, make_pair(1, 1));
	print_tree(&tree);

	insert(&tree, make_pair(1, 5));	// insert duplicate key
	print_tree(&tree);

	erase(&tree, 5);	// key not found when erase
	print_tree(&tree);

	erase(&tree, 1);
	print_tree(&tree);

	erase(&tree, 1);	// erase at empty tree
	print_tree(&tree);
}