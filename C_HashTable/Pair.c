#include "Pair.h"
#include <stdio.h>
pair* make_pair(char* key, int value)
{
	pair* new_pair = (pair*)malloc(sizeof(pair));

	new_pair->key = strdup(key);
	new_pair->value = value;

	return new_pair;
}