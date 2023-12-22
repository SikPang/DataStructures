#include <stdio.h>
#include "DynamicArray.h"

// Test for DynamicArray.c

void print_vector(vector* vec)
{
	printf("[size:%d, cap:%d] ", vec->size, vec->capacity);
	
	for (int i = 0; i < vec->size; ++i)
		printf("%d ", vec->data[i]);

	printf("\n");
}

int main()
{
	vector vec;

	printf("----- initialize -----\n");
	initialize(&vec);
	print_vector(&vec);

	printf("\n----- push_back -----\n");
	for (int i=1; i<5; ++i)
	{
		push_back(&vec, i);
		print_vector(&vec);
	}

	printf("\n----- insert -----\n");
	insert(&vec, vec.size / 2, 5);
	print_vector(&vec);

	insert(&vec, 0, 6);
	print_vector(&vec);

	insert(&vec, vec.size, 7);
	print_vector(&vec);

	printf("\n----- erase -----\n");
	erase(&vec, 0);
	print_vector(&vec);

	erase(&vec, vec.size - 1);
	print_vector(&vec);

	erase(&vec, vec.size / 2);
	print_vector(&vec);

	printf("\n----- pop_back -----\n");
	for (int i=1; i<3; ++i)
	{
		pop_back(&vec);
		print_vector(&vec);
	}

	printf("\n----- reserve -----\n");
	reserve(&vec, 100);
	print_vector(&vec);

	printf("\n----- clear -----\n");
	clear(&vec);
	print_vector(&vec);

	printf("\n----- edge cases -----\n");
	clear(&vec);					// double clear
	print_vector(&vec);

	reserve(&vec, -1);				// reserve by lower than size
	print_vector(&vec);

	pop_back(&vec);					// pop at empty vector
	print_vector(&vec);

	insert(&vec, -1, 3);			// insert at lower than 0
	print_vector(&vec);

	insert(&vec, vec.size + 1, 3);	// insert at higher than size
	print_vector(&vec);

	erase(&vec, -1);				// erase at lower than 0
	print_vector(&vec);

	erase(&vec, vec.size);			// erase at lower than index
	print_vector(&vec);

	for (int i=1; i<3; ++i)
	{
		push_back(&vec, i);			// use after clear
		print_vector(&vec);
	}

	reserve(&vec, 10);
	print_vector(&vec);

	for (int i=3; i<5; ++i)
	{
		push_back(&vec, i);			// use after reserve
		print_vector(&vec);
	}
}