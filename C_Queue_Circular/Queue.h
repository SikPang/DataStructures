#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct queue
{
	int* data;
	int size;
	int capacity;
	int head;
	int tail;
} queue;

void initialize(queue *que);
void reserve(queue *que, int capacity);
void push_back(queue *que, int data);
void pop_front(queue *que);
void clear(queue *que);

#endif