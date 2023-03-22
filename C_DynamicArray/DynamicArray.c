#include "DynamicArray.h"

void initialize(vector* vec)
{
	vec->data = NULL;
	vec->size = 0;
	vec->capacity = 0;
}

static void re_allocate(vector* vec, int capacity)
{
	if (capacity == 0)
		capacity = 1;

	int* new_data = (int*)malloc(capacity * sizeof(int));

	for (int i = 0; i < vec->size; ++i)
		new_data[i] = vec->data[i];

	free(vec->data);
	vec->data = new_data;
	vec->capacity = capacity;
}

void reserve(vector* vec, int capacity)
{
	if (capacity <= vec->capacity)
		return;
	
	re_allocate(vec, capacity);
	vec->capacity = capacity;
}

void push_back(vector* vec, int data)
{
	if (vec->size == vec->capacity)
		re_allocate(vec, vec->capacity * 2);
	
	vec->data[vec->size] = data;
	++vec->size;
}

void pop_back(vector* vec)
{
	if (vec->size == 0)
		return;
	
	--vec->size;
}

void insert(vector* vec, int index, int data)
{
	if (index < 0 || index > vec->size)
		return;

	if (vec->size == vec->capacity)
		re_allocate(vec, vec->capacity * 2);

	for (int i = vec->size - 1; i >= index; --i)
		vec->data[i + 1] = vec->data[i];
	
	vec->data[index] = data;
	++vec->size;
}

void erase(vector* vec, int index)
{
	if (index < 0 || index >= vec->size)
		return;

	for (int i = index + 1; i < vec->size; ++i)
		vec->data[i - 1] = vec->data[i];
	
	--vec->size;
}

void clear(vector* vec)
{
	free(vec->data);
	initialize(vec);
}