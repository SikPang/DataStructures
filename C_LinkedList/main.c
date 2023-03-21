#include <stdio.h>
#include "LinkedList.h"

// Test for LinkedList.c

void print_list(list* list)
{
	node* cur = list->head;

	printf("[size:%d] ", list->size);
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	list list;

	printf("----- init -----\n");
	init_list(&list);
	print_list(&list);

	printf("\n----- push_back -----\n");
	push_back(&list, 1);
	print_list(&list);

	push_back(&list, 2);
	print_list(&list);

	push_back(&list, 3);
	print_list(&list);

	push_back(&list, 4);
	print_list(&list);

	printf("\n----- insert -----\n");
	for (node* i = list.head; i != NULL; i = i->next)
	{
		if (i == list.head)
			insert(&list, list.head, 10);
		if (i->data == 3)
			insert(&list, i, 20);
		else
			continue;
		print_list(&list);
	}
	print_list(&list);

	printf("\n----- pop_back -----\n");
	pop_back(&list);
	print_list(&list);

	pop_back(&list);
	print_list(&list);

	printf("\n----- push_front -----\n");
	push_front(&list, 5);
	print_list(&list);

	push_front(&list, 6);
	print_list(&list);

	push_front(&list, 7);
	print_list(&list);

	push_front(&list, 8);
	print_list(&list);

	printf("\n----- find -----\n");
	node* find1 = list.head->next->next;
	printf("%p\n", find(&list, find1));
	node* find2 = (node*)malloc(sizeof(node));
	printf("%p\n", find(&list, find2));
	free(find2);
	node* find3 = NULL;
	printf("%p\n", find(&list, find3));

	printf("\n----- pop_front -----\n");
	pop_front(&list);
	print_list(&list);

	pop_front(&list);
	print_list(&list);

	printf("\n----- erase -----\n");

	for (node* i = list.head; i != NULL; )
	{
		if (i->data == 10 || i->data == 20)
		{
			i = erase(&list, i);
			print_list(&list);
		}
		else
			i = i->next;
	}

	erase(&list, list.head);
	print_list(&list);

	erase(&list, list.tail);
	print_list(&list);

	printf("\n----- clear -----\n");
	clear(&list);
	print_list(&list);
}