#include "Queue.h"

void initialize(queue* que)
{
	que->data = NULL;
	que->size = 0;
	que->capacity = 0;
	que->head = -1;
	que->tail = -1;
}

static void re_allocate(queue* que, int capacity)
{
	if (capacity == 0)
		capacity = 1;

	int* new_data = (int*)malloc(capacity * sizeof(int));

	for (int i = 0; i <= que->tail; ++i)
		new_data[i] = que->data[i];
	
	if (que->head > que->tail)
	{
		for (int i = 0 ; i < que->capacity - que->head; ++i)
			new_data[capacity - 1 - i] = que->data[que->capacity - 1 - i];
		que->head = capacity - (que->capacity - que->head);
	}
	free(que->data);
	que->data = new_data;
	que->capacity = capacity;
}

void reserve(queue* que, int capacity)
{
	if (capacity <= que->capacity)
		return;
	
	re_allocate(que, capacity);
}

void push(queue* que, int data)
{
	if (que->size == que->capacity)
		re_allocate(que, que->capacity * 2);
	
	if (que->head == -1)
	{
		que->head = 0;
		que->tail = 0;
	}
	else if (que->tail == que->capacity - 1)
		que->tail = 0;
	else
		++que->tail;
	que->data[que->tail] = data;
	++que->size;
}

void pop(queue* que)
{
	if (que->size == 0)
		return;
	
	if (que->size == 1)
	{
		que->head = -1;
		que->tail = -1;
	}
	else if (que->head == que->capacity - 1)
		que->head = 0;
	else
		++que->head;
	--que->size;
	return;
}

void clear(queue* que)
{
	free(que->data);
	initialize(que);
}