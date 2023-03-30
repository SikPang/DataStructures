#include "Hash.h"

static int get_next_prime(int num)
{
	while (1)
	{
		long i = 2;
		bool is_prime = true;

		while (i * i <= num) 
		{
			if (num % i == 0)
			{
				is_prime = false;
				break;
			}
			++i;
		}
		if (is_prime)
			return (num);
		++num;
	}
}

static unsigned int get_hash(unsigned char *str)
{
	unsigned int hash = 5381;
	int i = 0;

    while (str[i] != '\0')
	{
        hash = hash * 33 + str[i];
		++i;
	}
    return hash;
}

static node get_new_bucket(pair* data, state state, int hash_value)
{
	node new_node;

	new_node.data = data;
	new_node.state = state;
	new_node.hash_value = hash_value;

	return new_node;
}

static unsigned int get_index(hash* hash, char* key)
{
	unsigned int hash_value = get_hash((unsigned char*)key);
	unsigned int idx = hash_value;
	
	while (hash->bucket[idx % hash->capacity].state != EMPTY)
	{
		if (hash->bucket[idx % hash->capacity].state == USED
			&& strcmp(hash->bucket[idx % hash->capacity].data->key, key) == 0)
			break ;
		++idx;
		if (idx % hash->capacity == hash_value % hash->capacity)
			return -1;
	}
	if (hash->bucket[idx % hash->capacity].state == EMPTY)
		return -1;
	return idx % hash->capacity;
}

void initialize(hash *hash)
{
	hash->bucket = NULL;
	hash->capacity = 0;
	hash->size = 0;
}

static void re_allocate(hash* hash, int size)
{
	int prev = hash->capacity;

	if (size == 0)
		hash->capacity = 7;
	else
		hash->capacity = get_next_prime(size);

	node* new_bucket = (node*)malloc(hash->capacity * sizeof(node));
	for (int i = 0; i < hash->capacity; ++i)
		new_bucket[i].state = EMPTY;

	for (int i = 0; i < prev; ++i)
	{
		if (hash->bucket[i].state != USED)
			continue;
		unsigned int idx = hash->bucket[i].hash_value;

		while (new_bucket[idx % hash->capacity].state == USED)
		{
			if (strcmp(new_bucket[idx % hash->capacity].data->key, hash->bucket[i].data->key) == 0)
				return;
			++idx;
		}

		new_bucket[idx % hash->capacity] =
			get_new_bucket(hash->bucket[i].data, USED, hash->bucket[i].hash_value);
	}
	free(hash->bucket);
	hash->bucket = new_bucket;
}

void insert(hash* hash, pair* data)
{
	if (hash->capacity == 0
		|| (double)hash->size / hash->capacity > MAX_LOAD_FACTOR)
		re_allocate(hash, hash->capacity * 2);
	
	unsigned int hash_value = get_hash((unsigned char*)data->key);
	unsigned int idx = hash_value;

	while (hash->bucket[idx % hash->capacity].state == USED)
	{
		if (strcmp(hash->bucket[idx % hash->capacity].data->key, data->key) == 0)
			return;
		++idx;
	}

	hash->bucket[idx % hash->capacity] = get_new_bucket(data, USED, hash_value);
	++hash->size;
}

void erase(hash* hash, char* key)
{
	int idx = get_index(hash, key);
	if (idx == -1)
		return ;
	
	free(hash->bucket[idx].data->key);
	free(hash->bucket[idx].data);
	hash->bucket[idx].state = DELETED;
	--hash->size;
}

pair* find(hash* hash, char* key)
{
	int idx = get_index(hash, key);
	if (idx == -1)
		return NULL;
	
	return hash->bucket[idx % hash->capacity].data;
}

void clear(hash* hash)
{
	for (int i = 0; i < hash->capacity; ++i)
	{
		if (hash->bucket[i].state == USED)
		{
			free(hash->bucket[i].data->key);
			free(hash->bucket[i].data);
		}
	}
	free(hash->bucket);
	initialize(hash);
}