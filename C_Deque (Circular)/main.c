#include <stdio.h>
#include "Deque.h"

// Test for Deque.c

void print_deque(deque* deq)
{
	printf("[size:%d, cap:%d, head: %d, tail: %d] ", deq->size, deq->capacity, deq->head, deq->tail);
	for (int i = 0; i < deq->capacity; ++i)
	{
		if (deq->data[i] == 0)
			printf("- ");
		else
			printf("%d ", deq->data[i]);
	}
	
	printf("\n");
}

int main()
{
	deque deq;

	printf("----- initialize -----\n");
	initialize(&deq);
	print_deque(&deq);

	printf("\n----- push_back -----\n");
	for (int i=1; i<5; ++i)
	{
		push_back(&deq, i);
		print_deque(&deq);
	}

	printf("\n----- pop_back -----\n");
	for (int i=1; i<3; ++i)
	{
		pop_back(&deq);
		print_deque(&deq);
	}

	printf("\n----- push_front -----\n");
	for (int i=5; i<9; ++i)
	{
		push_front(&deq, i);
		print_deque(&deq);
	}

	printf("\n----- push_back again! -----\n");
	for (int i=10; i<13; ++i)
	{
		push_back(&deq, i);
		print_deque(&deq);
	}

	printf("\n----- pop_front -----\n");
	for (int i=1; i<3; ++i)
	{
		pop_front(&deq);
		print_deque(&deq);
	}

	printf("\n----- reserve -----\n");
	reserve(&deq, 25);
	print_deque(&deq);

	printf("\n----- clear -----\n");
	clear(&deq);
	print_deque(&deq);

	printf("\n----- edge cases -----\n");
	clear(&deq);					// double clear
	print_deque(&deq);

	reserve(&deq, -1);				// reserve by lower than size
	print_deque(&deq);

	pop_back(&deq);					// pop at empty deqtor
	print_deque(&deq);

	push_back(&deq, 1);			// use after clear
	print_deque(&deq);

	push_front(&deq, 2);			// use after clear
	print_deque(&deq);

	reserve(&deq, 10);
	print_deque(&deq);

	push_back(&deq, 3);			// use after clear
	print_deque(&deq);

	push_front(&deq, 4);			// use after clear
	print_deque(&deq);
	clear(&deq);
}