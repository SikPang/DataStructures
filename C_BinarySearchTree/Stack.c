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

	pair** new_data = (pair**)malloc(capacity * sizeof(pair*));
	int i;

	for (i = 0; i < stack->size; ++i)
		new_data[i] = stack->data[i];

	clear_stack(stack);

	stack->data = new_data;
	stack->size = i;
	stack->capacity = capacity;
}

void reserve(stack* stack, int capacity)
{
	if (capacity <= stack->capacity)
		return;

	if (stack->data == NULL)
		initialize_stack(stack);
	
	re_allocate(stack, capacity);
}

void push(stack* stack, pair* data)
{
	if (stack->size == stack->capacity)
		re_allocate(stack, stack->capacity * 2);
	
	stack->data[stack->size] = data;
	++stack->size;
}

pair* pop(stack* stack)
{
	if (stack->size == 0)
		return NULL;
	
	--stack->size;

	return stack->data[stack->size + 1];
}

void clear_stack(stack* stack)
{
	while (stack->size > 0)
		free(pop(stack));
	
	free(stack->data);

	initialize_stack(stack);
}