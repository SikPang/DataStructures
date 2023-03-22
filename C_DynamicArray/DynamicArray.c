#include "DynamicArray.h"

void initialize(vector* vec)
{
	vec->data = NULL;
	vec->size = 0;
	vec->capacity = 0;
}

void reserve(vector* vec, int size)
{
	if (size <= vec->size)
		return;
	
	vec->data = (int*)malloc(size * sizeof(int));
	vec->size = size;
}

static void realloc_double(vector* vec)
{
	if (vec->capacity == 0)
		vec->capacity = 1;
	else
		vec->capacity *= 2;

	int* new_data = (int*)malloc(vec->capacity * sizeof(int));

	for (int i = 0; i < vec->size; ++i)
		new_data[i] = vec->data[i];

	free(vec->data);
	vec->data = new_data;
}

void push_back(vector* vec, int data)
{
	if (vec->size == vec->capacity)
		realloc_double(vec);
	
	vec->data[vec->size] = data;
	++vec->size;
}

void pop_back(vector* vec, int data)
{
	--vec->size;
}

void insert(vector* vec, int index, int data)
{
	if (index >= vec->size)
		return;

	if (vec->size == vec->capacity)
		realloc_double(vec);

	for (int i = vec->size - 1; i >= index; --i)
		vec->data[i + 1] = vec->data[i];
	
	vec->data[index] = data;
	++vec->size;
}

void erase(vector* vec, int index)
{
	if (index >= vec->size)
		return;

	for (int i = index + 1; i < vec->size; ++i)
		vec->data[i] = vec->data[i - 1];
	--vec->size;
}

void clear(vector* vec)
{
	free(vec->data);
	initialize(vec);
}