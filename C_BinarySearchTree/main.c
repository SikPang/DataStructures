#include "BinarySearchTree.h"

int main()
{
	tree tree;

	printf("----- initialize -----\n");
	initialize(&tree);
	print(&tree);

	printf("\n----- insert -----\n");
	insert(&tree, make_pair(7, 0));
	print(&tree);

	insert(&tree, make_pair(5, 0));
	print(&tree);

	insert(&tree, make_pair(15, 0));
	print(&tree);

	insert(&tree, make_pair(3, 0));
	print(&tree);

	insert(&tree, make_pair(6, 0));
	print(&tree);

	insert(&tree, make_pair(10, 0));
	print(&tree);

	insert(&tree, make_pair(16, 0));
	print(&tree);

	insert(&tree, make_pair(4, 0));
	print(&tree);

	insert(&tree, make_pair(8, 0));
	print(&tree);

	insert(&tree, make_pair(12, 0));
	print(&tree);

	insert(&tree, make_pair(11, 0));
	print(&tree);

	printf("\n----- find -----\n");
	printf("%p\n", find(&tree, 16));
	printf("%p\n", find(&tree, 4));
	printf("%p\n", find(&tree, 7));
	printf("%p\n", find(&tree, 20));

	printf("\n----- erase -----\n");
	erase(&tree, 15);
	print(&tree);

	erase(&tree, 12);
	print(&tree);

	erase(&tree, 11);
	print(&tree);

	erase(&tree, 10);
	print(&tree);

	erase(&tree, 8);
	print(&tree);

	erase(&tree, 16);
	print(&tree);

	erase(&tree, 7);
	print(&tree);

	erase(&tree, 5);
	print(&tree);

	erase(&tree, 3);
	print(&tree);

	printf("\n----- clear -----\n");
	clear(&tree);
	print(&tree);

	printf("\n----- edge cases -----\n");
	clear(&tree);		// double clear
	print(&tree);

	insert(&tree, make_pair(1, 1));
	print(&tree);

	insert(&tree, make_pair(1, 5));	// insert duplicate key
	print(&tree);

	erase(&tree, 5);	// key not found when erase
	print(&tree);

	erase(&tree, 1);
	print(&tree);

	erase(&tree, 1);	// erase at empty tree
	print(&tree);
}