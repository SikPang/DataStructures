#ifndef PAIR_H
#define PAIR_H

#include <stdlib.h>

typedef struct pair
{
	int key;
	int value;
} pair;

pair* make_pair(int fisrt, int value);

#endif