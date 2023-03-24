#include "Stack.h"

void initialize_stack(stack* stack)
{
	stack->data = NULL;
	stack->size = 0;
	stack->capacity = 0;
}

static void re_allocate(stack* stack, int capacity)
{
	if (capacity == 0)
		capacity = 1;

	int* new_data = (int*)malloc(capacity * sizeof(int));

	for (int i = 0; i < stack->size; ++i)
		new_data[i] = stack->data[i];

	free(stack->data);
	stack->data = new_data;
	stack->capacity = capacity;
}

void reserve(stack* stack, int capacity)
{
	if (capacity <= stack->capacity)
		return;
	
	re_allocate(stack, capacity);
}

void push(stack* stack, int data)
{
	if (stack->size == stack->capacity)
		re_allocate(stack, stack->capacity * 2);
	
	stack->data[stack->size] = data;
	++stack->size;
}

void pop(stack* stack)
{
	if (stack->size == 0)
		return;
	
	--stack->size;
}

void clear_stack(stack* stack)
{
	free(stack->data);
	initialize(stack);
}