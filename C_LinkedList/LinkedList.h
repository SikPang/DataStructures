#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
	struct node* prev;
	struct node* next;
	int data;
}node;

typedef struct list
{
	node* head;
	node* tail;
	int size;
}list;

void init_list(list* list);
void push_back(list* list, int data);
void push_front(list* list, int data);
void pop_back(list* list);
void pop_front(list* list);
node* find_node(list* list, node* target);
void insert(list* list, node* target, int data);
void erase_node(list* list, node* target);
void delete_list(list* list);

#endif