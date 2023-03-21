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
	if (list->size == 0)
		return;
	
	node* temp = list->tail;

	if (list->size == 1)
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
	if (list->size == 0)
		return;

	node* temp = list->head;

	if (list->size == 1)
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

node* find(list* list, node* target)
{
	node* cur = list->head;

	while (cur != NULL)
	{
		if (cur == target)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void insert(list* list, node* target, int data)
{
	if (list->size == 0 || !find(list, target))
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
	return;
}

node* erase(list* list, node* target)
{
	if (list->size == 0 || !find(list, target))
		return NULL;

	node* next = target->next;

	if (list->size == 1 || target == list->head)
		pop_front(list);
	else if (target == list->tail)
		pop_back(list);
	else
	{
		target->prev->next = target->next;
		target->next->prev = target->prev;
		free(target);
		--list->size;
	}
	return next;
}

void clear(list* list)
{
	node* cur = list->head;
	node* next;

	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	init_list(list);
}