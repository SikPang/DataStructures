#include "Pair.h"

pair* make_pair(int key, int value)
{
	pair* new_pair = (pair*)malloc(sizeof(pair));

	new_pair->key = key;
	new_pair->value = value;

	return new_pair;
}