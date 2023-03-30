#include "Hash.h"
#include <stdio.h>

void print_hash(hash* hash)
{
	printf("size: %d, cap: %d\n", hash->size, hash->capacity);
	for (int i = 0 ; i < hash->capacity; ++i)
	{
		switch (hash->bucket[i].state)
		{
		case 0:
			printf("[%d] EMPTY   , - : - (-)\n", i);
			break;
		case 1:
			printf("[%d] USED    , %s : %d (%u)\n", i, hash->bucket[i].data->key, hash->bucket[i].data->value, hash->bucket[i].hash_value % hash->capacity);
			break;
		case 2:
			printf("[%d] DELETED , - : - (-)\n", i);
			break;
		}
	}
	printf("\n");
}

void print_hash_find(pair* result)
{
	if (result == NULL)
		printf("key not found\n");
	else
		printf("%d\n", result->value);
}

void v()
{
	system("leaks a.out");
}

int main()
{
	hash hash;
	
	printf("----- initialize -----\n");
	initialize(&hash);
	print_hash(&hash);

	printf("----- insert -----\n");
	insert(&hash, make_pair("hello", 1));
	print_hash(&hash);

	insert(&hash, make_pair("world", 2));
	print_hash(&hash);

	insert(&hash, make_pair("my name", 3));
	print_hash(&hash);

	insert(&hash, make_pair("is sikpang", 4));
	print_hash(&hash);

	insert(&hash, make_pair("nice", 5));
	print_hash(&hash);

	insert(&hash, make_pair("to meet you", 6));
	print_hash(&hash);

	insert(&hash, make_pair("this is", 7));
	print_hash(&hash);

	insert(&hash, make_pair("hash_table", 8));
	print_hash(&hash);

	insert(&hash, make_pair("thank you", 9));
	print_hash(&hash);

	printf("\n----- find -----\n");
	print_hash_find(find(&hash, "hash_table"));
	print_hash_find(find(&hash, "thank you!"));
	print_hash_find(find(&hash, "thank you"));
	print_hash_find(find(&hash, "hash_tablee"));


	printf("\n----- erase -----\n");
	erase(&hash, "mmm");
	print_hash(&hash);

	erase(&hash, "this is");
	print_hash(&hash);

	erase(&hash, "is sikpang");
	print_hash(&hash);

	erase(&hash, "world");
	print_hash(&hash);

	erase(&hash, "hello");
	print_hash(&hash);


	printf("\n----- edge_case -----\n");
	print_hash_find(find(&hash, "hello"));	// find the erased key
	print_hash_find(find(&hash, "world"));
	print_hash_find(find(&hash, "nice"));	// pass DELETED node when find

	insert(&hash, make_pair("world", 1));	// insert to DELETED node
	print_hash(&hash);

	insert(&hash, make_pair("hello", 2));
	print_hash(&hash);


	printf("\n----- clear -----\n");
	clear(&hash);
	print_hash(&hash);

	//atexit(v);
}