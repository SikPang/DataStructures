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
void reserve(vector* vec, int size);

#endif