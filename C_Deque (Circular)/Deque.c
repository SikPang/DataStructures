#include "Deque.h"

void initialize(deque *deq)
{
	deq->data = NULL;
	deq->size = 0;
	deq->capacity = 0;
	deq->head = -1;
	deq->tail = -1;
}

static void re_allocate(deque *deq, int capacity)
{
	if (capacity == 0)
		capacity = 1;

	int* new_data = (int*)malloc(capacity * sizeof(int));

	for (int i = 0; i <= deq->tail; ++i)
		new_data[i] = deq->data[i];
	
	if (deq->head > deq->tail)
	{
		for (int i = 0 ; i < deq->capacity - deq->head; ++i)
			new_data[capacity - 1 - i] = deq->data[deq->capacity - 1 - i];
		deq->head = capacity - (deq->capacity - deq->head);
	}
	free(deq->data);
	deq->data = new_data;
	deq->capacity = capacity;
}

void reserve(deque *deq, int capacity)
{
	if (capacity <= deq->capacity)
		return;
	
	re_allocate(deq, capacity);
}

void push_back(deque *deq, int data)
{
	if (deq->size == deq->capacity)
		re_allocate(deq, deq->capacity * 2);
	
	if (deq->head == -1)
	{
		deq->head = 0;
		deq->tail = 0;
	}
	else if (deq->tail == deq->capacity - 1)
		deq->tail = 0;
	else
		++deq->tail;
	deq->data[deq->tail] = data;
	++deq->size;
}

void push_front(deque *deq, int data)
{
	if (deq->size == deq->capacity)
		re_allocate(deq, deq->capacity * 2);

	if (deq->head == -1)
	{
		deq->head = 0;
		deq->tail = 0;
	}
	else if (deq->head == 0)
		deq->head = deq->capacity - 1;
	else
		--deq->head;
	deq->data[deq->head] = data;
	++deq->size;
}

void pop_back(deque *deq)
{
	if (deq->size == 0)
		return;
	
	if (deq->size == 1)
	{
		deq->head = -1;
		deq->tail = -1;
	}
	else if (deq->tail == 0)
		deq->tail = deq->capacity - 1;
	else
		--deq->tail;
	--deq->size;
	return;
}

void pop_front(deque *deq)
{
	if (deq->size == 0)
		return;
	
	if (deq->size == 1)
	{
		deq->head = -1;
		deq->tail = -1;
	}
	else if (deq->head == deq->capacity - 1)
		deq->head = 0;
	else
		++deq->head;
	--deq->size;
	return;
}

void clear(deque *deq)
{
	free(deq->data);
	initialize(deq);
}