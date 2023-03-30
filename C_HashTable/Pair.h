#ifndef PAIR_H
#define PAIR_H

#include <stdlib.h>
#include <string.h>

typedef struct pair
{
	char* key;
	int value;
} pair;

pair* make_pair(char* key, int value);

#endif