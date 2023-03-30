#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Pair.h"

#define MAX_LOAD_FACTOR 0.5

typedef enum state
{
	EMPTY,
	USED,
	DELETED
} state;

typedef struct node
{
	pair* data;
	state state;
	unsigned int hash_value;
} node;

typedef struct hash
{
	node* bucket;
	int size;
	int capacity;
} hash;

void initialize(hash *hash);
void reserve(hash *hash, int size);
void insert(hash* hash, pair* data);
void erase(hash* hash, char* key);
pair* find(hash* hash, char* key);
void clear(hash* hash);

#endif