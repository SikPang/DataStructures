#include "Pair.h"

pair* make_pair(int fisrt, int second)
{
	pair* new_pair = (pair*)malloc(sizeof(pair));

	new_pair->first = fisrt;
	new_pair->second = second;

	return new_pair;
}