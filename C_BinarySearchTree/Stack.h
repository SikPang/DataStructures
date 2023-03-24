#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "Pair.h"

typedef struct stack
{
	pair** data;
	int size;
	int capacity;
} stack;

void initialize_stack(stack* stack);
void reserve(stack* stack, int capacity);
void push(stack* stack, pair* data);
pair* pop(stack* stack);
void clear_stack(stack* stack);

#endif