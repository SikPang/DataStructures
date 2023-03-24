#include <stdio.h>
#include "BinarySearchTree.h"

void print_tree(node* cur)
{
	if (cur == NULL)
		return ;
	
	print_tree(cur->lchild);
	
	printf("%d : %d\n", cur->data->first, cur->data->second);
	
	print_tree(cur->rchild);
}

int main()
{
	
}