#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct stack
{
	int* data;
	int size;
	int capacity;
} stack;

void initialize_stack(stack* stack);
void reserve(stack* stack, int capacity);
void push(stack* stack, int data);
void pop(stack* stack);
void clear_stack(stack* stack);

#endif