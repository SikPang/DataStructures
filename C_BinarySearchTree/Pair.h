#ifndef PAIR_H
#define PAIR_H

typedef struct pair
{
	int first;
	int second;
} pair;

pair* make_pair(int fisrt, int second);

#endif