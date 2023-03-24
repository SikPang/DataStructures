#include "BinarySearchTree.h"

void print_tree(node* cur)
{
	if (cur == NULL)
		return ;
	
	print_all(cur->lchild);
	
	printf("%s=%s\n", cur->data->key, cur->data->value);
	
	print_all(cur->rchild);
}

int main()
{
	
}