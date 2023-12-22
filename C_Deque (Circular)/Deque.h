#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>

typedef struct deque
{
	int* data;
	int size;
	int capacity;
	int head;
	int tail;
} deque;

void initialize(deque *deq);
void reserve(deque *deq, int capacity);
void push_back(deque *deq, int data);
void push_front(deque *deq, int data);
void pop_back(deque *deq);
void pop_front(deque *deq);
void clear(deque *deq);

#endif