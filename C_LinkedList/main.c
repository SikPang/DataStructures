#include <stdio.h>
#include "LinkedList.h"

void print_list(list* list)
{
	node* cur = list->head;

	if (cur == NULL)
	{
		printf("list is empty\n");
		return;
	}

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

	printf("----- push_back -----\n");
	push_back(&list, 1);
	print_list(&list);

	push_back(&list, 2);
	print_list(&list);

	push_back(&list, 3);
	print_list(&list);

	printf("----- insert -----\n");
	insert(&list, list.head, 4);
	print_list(&list);

	for (node* i = list.head; i != NULL; i = i->next)
	{
		if (i->data == 2)
		{
			insert(&list, i, 5);
			break;
		}
	}
	print_list(&list);

	printf("----- pop_back -----\n");
	pop_back(&list);
	print_list(&list);

	pop_back(&list);
	print_list(&list);

	printf("----- push_front -----\n");
	push_front(&list, 7);
	print_list(&list);

	push_front(&list, 8);
	print_list(&list);

	push_front(&list, 9);
	print_list(&list);

	printf("----- pop_front -----\n");
	pop_front(&list);
	print_list(&list);

	pop_front(&list);
	print_list(&list);

	printf("----- erase -----\n");

	for (node* i = list.head; i != NULL; i = i->next)
	{
		if (i->data == 5)
		{
			erase_node(&list, i);
			break;
		}
	}
	print_list(&list);

	erase_node(&list, list.head);
	print_list(&list);

	erase_node(&list, list.tail);
	print_list(&list);
}