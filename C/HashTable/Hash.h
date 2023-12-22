#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Pair.h"

#define MAX_LOAD_FACTOR 0.5
#define INITIAL_CAPACITY 7

typedef enum state
{
	EMPTY,
	USED,
	DELETED
} state;

typedef struct node
{
	pair* data;
	unsigned int hash_value;
	state state;
} node;

typedef struct hash
{
	node* bucket;
	int size;
	int capacity;
} hash;

void initialize(hash* hash);
void insert(hash* hash, pair* data);
void erase(hash* hash, char* key);
pair* find(hash* hash, char* key);
void clear(hash* hash);

#endif