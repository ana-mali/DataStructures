# include <stdio.h>
# include <stdlib.h>
# include "data.h"
# include "process.h"
# include "pqueue.h"

void test_pqueue1(char mode); //unsorted insert
void test_pqueue2(char mode); //sorted insert

int main() {
	setbuf(stdout, NULL);
	test_pqueue1('H'); //unsorted insert, priority = H
	test_pqueue1('L'); //unsorted insert, priority = L
	test_pqueue2('H'); //sorted insert, priority = H
	test_pqueue2('L'); //sorted insert, priority = L
	return 0;
}

void test_pqueue1(char mode) {
	int size = 10;
	printf("------------------------------\n");
	printf("Start: Testing Priority Queue (Unsorted Insert, Priority = ");
	if (mode == 'H')
		printf("H):\n\n");
	else
		printf("L):\n\n");

	printf("Calling pQueue* q = create_pqueue(10), print_pqueue(q):\n");
	pQueue *q = create_pqueue(size, mode);
	print_pqueue(q);
	printf("\n");

	printf("Calling is_empty_pqueue(q): ");
	printf("%d\n", is_empty_pqueue(q));
	printf("Calling is_full_pqueue(q):");
	printf("%d\n", is_full_pqueue(q));
	printf("\n");

	printf("Calling d = peek_pqueue(q):\t");
	peek_pqueue(q);

	Data *d[15];
	int arrival = 1, time = 8, counter = 0;
	long pid = 1000010000;
	for (int i = 0; i < 15; i++) {
		d[i] = create_process(pid++, time, arrival);
		time = time % 4 + (i + 1) % 7;
		arrival = arrival + arrival % 3;
	}

	printf("Calling insert_pqueue:\n");
	printf("success = %d\n", insert_pqueue(q, d[counter++]));
	printf("Calling print_pqueue(q):\n");
	print_pqueue(q);
	printf("\n");

	printf("Calling is_empty_pqueue(q):");
	printf("%d\n", is_empty_pqueue(q));
	printf("Calling is_full_pqueue(q):");
	printf("%d\n", is_full_pqueue(q));
	printf("\n");

	printf("Adding 9 elements to pQueue:\n");
	int i;
	for (i = 0; i < size - 1; i++) {
		insert_pqueue(q, d[counter++]);
		print_pqueue(q);
		printf("\n");
	}

	printf("Calling is_full_pqueue(q):");
	printf("%d\n", is_full_pqueue(q));
	printf("Calling insert_pqueue: ");
	printf("success = %d\n", insert_pqueue(q, d[counter++]));
	printf("\n");

	printf("Calling d = peek_pqueue(q):\t");
	Data *temp = peek_pqueue(q);
	print_data(temp);
	printf("\n\n");

	printf("Calling d = remove_pqueue(q)\n");
	temp = remove_pqueue(q);
	printf("Printing removed data:\n");
	print_data(temp);
	destroy_data(&temp);
	printf("\n");
	printf("Printing pQueue: \n");
	print_pqueue(q);
	printf("\n");

	printf("remove another element:\n");
	temp = remove_pqueue(q);
	printf("Printing removed data:\n");
	print_data(temp);
	destroy_data(&temp);
	printf("\n");
	printf("Printing pQueue: \n");
	print_pqueue(q);
	printf("\n");

	printf("Calling insert_pqueue:\n");
	insert_pqueue(q, d[counter++]);
	print_pqueue(q);
	printf("\n");

	printf("remove 2 elements:\n");
	remove_pqueue(q);
	print_pqueue(q);
	remove_pqueue(q);
	print_pqueue(q);
	printf("\n");

	printf("Calling insert_pqueue 3 items:\n");
	for (i = 0; i < 3; i++) {
		insert_pqueue(q, d[counter++]);
		print_pqueue(q);
	}
	printf("\n");

	printf("remove all elements\n");
	while (!is_empty_pqueue(q)) {
		printf("peek: ");
		print_data(peek_pqueue(q));
		printf("\n");
		temp = remove_pqueue(q);
		printf("Printing removed data: ");
		print_data(temp);
		destroy_data(&temp);
		printf("\nPrinting pQueue: \n");
		print_pqueue(q);
		printf("\n");
	}

	printf("Calling destroy_pqueue(&q):\n");
	destroy_pqueue(&q);
	printf("Destroyed Successfully\n\n");

	printf("End: Testing Priority Queue (Unsorted Insert, Priority = ");
	if (mode == 'H')
		printf("H):\n");
	else
		printf("L):\n");
	printf("------------------------------\n\n");
	return;
}

void test_pqueue2(char mode) {
	int size = 10;
	printf("------------------------------\n");
	printf("Start: Testing Priority Queue (Sorted Insert, Priority = ");
	if (mode == 'H')
		printf("H):\n\n");
	else
		printf("L):\n\n");

	printf("Calling pQueue* q = create_pqueue(10), print_pqueue(q):\n");
	pQueue *q = create_pqueue(size, mode);
	print_pqueue(q);
	printf("\n");

	printf("Calling is_empty_pqueue(q): ");
	printf("%d\n", is_empty_pqueue(q));
	printf("Calling is_full_pqueue(q):");
	printf("%d\n", is_full_pqueue(q));
	printf("\n");

	printf("Calling d = peek_pqueue(q):\t");
	peek_pqueue2(q);

	Data *d[15];
	int arrival = 1, time = 8, counter = 0;
	long pid = 1000010000;
	for (int i = 0; i < 15; i++) {
		d[i] = create_process(pid++, time, arrival);
		time = time % 4 + (i + 1) % 7;
		arrival = arrival + arrival % 3;
	}

	printf("Calling insert_pqueue:\n");
	printf("success = %d\n", insert_pqueue2(q, d[counter++]));
	printf("Calling print_pqueue(q):\n");
	print_pqueue(q);
	printf("\n");

	printf("Calling is_empty_pqueue(q):");
	printf("%d\n", is_empty_pqueue(q));
	printf("Calling is_full_pqueue(q):");
	printf("%d\n", is_full_pqueue(q));
	printf("\n");

	printf("Adding 9 elements to pQueue:\n");
	int i;
	for (i = 0; i < size - 1; i++) {
		insert_pqueue2(q, d[counter++]);
		print_pqueue(q);
		printf("\n");
	}

	printf("Calling is_full_pqueue(q):");
	printf("%d\n", is_full_pqueue(q));
	printf("Calling insert_pqueue: ");
	printf("success = %d\n", insert_pqueue2(q, d[counter++]));
	printf("\n");

	printf("Calling d = peek_pqueue(q):\t");
	Data *temp = peek_pqueue2(q);
	print_data(temp);
	printf("\n\n");

	printf("Calling d = remove_pqueue(q)\n");
	temp = remove_pqueue2(q);
	printf("Printing removed data:\n");
	print_data(temp);
	destroy_data(&temp);
	printf("\n");
	printf("Printing pQueue: \n");
	print_pqueue(q);
	printf("\n");

	printf("remove another element:\n");
	temp = remove_pqueue2(q);
	printf("Printing removed data:\n");
	print_data(temp);
	destroy_data(&temp);
	printf("\n");
	printf("Printing pQueue: \n");
	print_pqueue(q);
	printf("\n");

	printf("Calling insert_pqueue:\n");
	insert_pqueue2(q, d[counter++]);
	print_pqueue(q);
	printf("\n");

	printf("remove 2 elements:\n");
	remove_pqueue2(q);
	print_pqueue(q);
	remove_pqueue2(q);
	print_pqueue(q);
	printf("\n");

	printf("Calling insert_pqueue 3 items:\n");
	for (i = 0; i < 3; i++) {
		insert_pqueue2(q, d[counter++]);
		print_pqueue(q);
	}
	printf("\n");

	printf("remove all elements\n");
	while (!is_empty_pqueue(q)) {
		printf("peek: ");
		print_data(peek_pqueue2(q));
		printf("\n");
		temp = remove_pqueue2(q);
		printf("Printing removed data: ");
		print_data(temp);
		destroy_data(&temp);
		printf("\nPrinting pQueue: \n");
		print_pqueue(q);
		printf("\n");
	}

	printf("Calling destroy_pqueue(&q):\n");
	destroy_pqueue(&q);
	printf("Destroyed Successfully\n\n");

	printf("End: Testing Priority Queue (Sorted Insert, Priority = ");
	if (mode == 'H')
		printf("H):\n");
	else
		printf("L):\n");
	printf("------------------------------\n\n");
	return;
}
