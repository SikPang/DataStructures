#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdlib.h>

typedef struct vector
{
	int* data;
	int size;
	int capacity;
} vector;

void initialize(vector* vec);
void reserve(vector* vec, int capacity);
void push_back(vector* vec, int data);
void pop_back(vector* vec);
void insert(vector* vec, int index, int data);
void erase(vector* vec, int index);
void clear(vector* vec);

#endif