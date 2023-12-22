#include <stdio.h>
#include "LinkedList.h"

// Test for Linkedmy_list.c

void print_list(list* my_list)
{
	node* cur = my_list->head;

	printf("[size:%d] ", my_list->size);
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	list my_list;

	printf("----- initialize -----\n");
	initialize(&my_list);
	print_list(&my_list);


	printf("\n----- push_back -----\n");
	push_back(&my_list, 1);
	print_list(&my_list);

	push_back(&my_list, 2);
	print_list(&my_list);

	push_back(&my_list, 3);
	print_list(&my_list);

	push_back(&my_list, 4);
	print_list(&my_list);


	printf("\n----- insert -----\n");
	for (node* i = my_list.head; i != NULL; i = i->next)
	{
		if (i == my_list.head)
			insert(&my_list, my_list.head, 10);
		if (i->data == 3)
			insert(&my_list, i, 20);
		else
			continue;
		print_list(&my_list);
	}
	print_list(&my_list);


	printf("\n----- pop_back -----\n");
	pop_back(&my_list);
	print_list(&my_list);

	pop_back(&my_list);
	print_list(&my_list);


	printf("\n----- push_front -----\n");
	push_front(&my_list, 5);
	print_list(&my_list);

	push_front(&my_list, 6);
	print_list(&my_list);

	push_front(&my_list, 7);
	print_list(&my_list);

	push_front(&my_list, 8);
	print_list(&my_list);


	printf("\n----- find -----\n");
	node* find1 = my_list.head->next->next; 
	printf("%p\n", find(&my_list, find1));

	node* find2 = (node*)malloc(sizeof(node));
	printf("%p\n", find(&my_list, find2));
	free(find2);

	list test_list;
	initialize(&test_list);
	push_back(&test_list, 3);
	node* find3 = test_list.head;
	printf("%p\n", find(&my_list, find3));
	pop_back(&test_list);


	printf("\n----- pop_front -----\n");
	pop_front(&my_list);
	print_list(&my_list);

	pop_front(&my_list);
	print_list(&my_list);


	printf("\n----- erase -----\n");
	for (node* i = my_list.head; i != NULL; )
	{
		if (i->data == 10 || i->data == 20)
		{
			i = erase(&my_list, i);
			print_list(&my_list);
		}
		else
			i = i->next;
	}

	erase(&my_list, my_list.head);
	print_list(&my_list);

	erase(&my_list, my_list.tail);
	print_list(&my_list);


	printf("\n----- clear -----\n");
	clear(&my_list);
	print_list(&my_list);


	printf("\n----- edge cases -----\n");
	clear(&my_list);			// double clear
	pop_back(&my_list);			// pop_back at empty list
	pop_front(&my_list);		// pop_front at empty list
	insert(&my_list, NULL, 3);	// insert 3 before "NULL" node
	erase(&my_list, NULL);		// erase "NULL" node at list
	find(&my_list, NULL);		// find "NULL" node at list

	push_back(&my_list, 1);		// use list after clear
	print_list(&my_list);
	pop_back(&my_list);			// just pop
	print_list(&my_list);
}