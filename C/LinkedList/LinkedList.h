#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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

void initialize(list* list);
void push_back(list* list, int data);
void push_front(list* list, int data);
void pop_back(list* list);
void pop_front(list* list);
node* find(list* list, node* target);
void insert(list* list, node* target, int data);
node* erase(list* list, node* target);
void clear(list* list);
void clear_recur(list* list, node* cur);

#endif