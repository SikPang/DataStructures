#include "LinkedList.h"

void init_list(list* list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void push_back(list* list, int data)
{
	node* new_node = (node*)malloc(sizeof(node));

	new_node->data = data;
	new_node->next = NULL;
	if (list->size == 0)
	{
		list->head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		list->tail->next = new_node;
		new_node->prev = list->tail;
	}
	list->tail = new_node;
	++list->size;
}

void push_front(list* list, int data)
{
	node* new_node = (node*)malloc(sizeof(node));

	new_node->data = data;
	new_node->next = NULL;
	if (list->size == 0)
	{
		list->tail = new_node;
		new_node->prev = NULL;
	}
	else
	{
		list->head->prev = new_node;
		new_node->next = list->head;
	}
	list->head = new_node;
	++list->size;
}

void pop_back(list* list)
{
	node* temp = list->tail;

	if (list->size == 0)
		return;
	else if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;
	}
	free(temp);
	--list->size;
}

void pop_front(list* list)
{
	node* temp = list->head;

	if (list->size == 0)
		return;
	else if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->head->next->prev = NULL;
		list->head = list->head->next;
	}
	free(temp);
	--list->size;
}

node* find_node(list* list, node* target)
{
	node* cur_node = list->head;

	while (cur_node != NULL)
	{
		if (cur_node == target)
			return cur_node;
		cur_node = cur_node->next;
	}
	return NULL;
}

void insert(list* list, node* target, int data)
{
	if (list->size == 0 || !find_node(list, target))
		return;

	node* new_node = (node*)malloc(sizeof(node));

	new_node->data = data;
	new_node->next = target;
	new_node->prev = target->prev;
	if (target->prev != NULL)
		target->prev->next = new_node;
	target->prev = new_node;
	if (target == list->head)
		list->head = new_node;
	++list->size;
}

void erase_node(list* list, node* target)
{
	if (list->size == 0 || !find_node(list, target))
		return;
	else if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else if (target == list->head)
	{
		list->head->next->prev = NULL;
		list->head = list->head->next;
	}
	else if (target == list->tail)
	{
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;
	}
	else
	{
		target->prev->next = target->next;
		target->next->prev = target->prev;
	}
	free(target);
	--list->size;
}

void delete_list(list* list)
{
	node* cur_node = list->head;
	node* next_node;

	if (list == NULL)
		return;
	while (cur_node != NULL)
	{
		next_node = cur_node->next;
		free(cur_node);
		cur_node = NULL;
		cur_node = next_node;
	}
	free(list);
}