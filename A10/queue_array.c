/*
 * ---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue_array.h"
#include "heap.h"

void adjust_queue(Queue *q);
Queue* create_queue(int capacity) {
	Queue *q = (Queue*) malloc(sizeof(Queue));
	if (capacity < 1) {
		printf("Error(create_queue): invalid queue capacity, set to 10\n");
		capacity = 10;
	}
	q->capacity = capacity;
	q->array = (Node**) malloc(sizeof(Node*) * capacity);
	q->front = -1;
	q->rear = -1;
	return q;
}

int is_empty_queue(Queue *q) {
	assert(q!=NULL);
	return (len_queue(q) == 0);
}
int len_queue(Queue *q) {
	assert(q != NULL);
	if (q->front == -1)
		return 0;
	return q->rear - q->front + 1;
}
int is_full_queue(Queue *q) {
	assert(q!=NULL);
	return (len_queue(q) == q->capacity);
}
int insert_queue(Queue *q, Node *d) {
	assert(q!=NULL && d!=NULL);
	if (is_full_queue(q)) {
		printf("Error(insert_queue): queue is full\n");
		return 0;
	}
	if (is_empty_queue(q))
		q->front = 0;
	else if (q->rear == q->capacity - 1) {
		adjust_queue(q);
	}
	q->rear++;
	q->array[q->rear] = d;
	return 1;
}
void adjust_queue(Queue *q) {
	assert(q!=NULL);
	int length = len_queue(q), i;
	for (i = 0; i < length; i++) {
		q->array[i] = q->array[i + q->front];
	}
	q->front = 0;
	q->rear = length - 1;
	return;
}
Node* peek_queue(Queue *q) {
	assert(q!=NULL);
	if (is_empty_queue(q)) {
		printf("Error(peek_queue): Queue is empty\n");
		return NULL;
	}
	return q->array[q->front];
}
Node* remove_queue(Queue *q) {
	assert(q!=NULL);
	Node *d = NULL;
	if (is_empty_queue(q)) {
		printf("Error(remove_queue): queue is empty\n");
		return d;
	}
	d = q->array[q->front];
//	d = copy_data(&q->array[q->front]);
//	Data *temp = &q->array[q->front];
//	destroy_data(&temp);
	q->front++;
	if (len_queue(q) == 0) {
		q->front = -1;
		q->rear = -1;

	}
	return d;
}
void destroy_queue(Queue **q) {
	assert(q!=NULL);
//	Node *d = NULL;
//	while (!is_empty_queue(*q)) {
//		d = remove_queue(*q);
//		destroy_data(&d);
//	}
	free((*q)->array);
	(*q)->array = NULL;
	(*q)->capacity = 0;
	(*q)->front = 0;
	(*q)->rear = 0;
	free(*q);
	*q = NULL;
	return;
}
void print_queue(Queue *q) {
	assert(q!=NULL);
	int i;
	printf("Capacity = %d, Size = %d, front = %d, rear = %d\n", q->capacity,
			len_queue(q), q->front, q->rear);
	if (is_empty_queue(q))
		printf("<empty_queue>\n");
	else {
		int counter = 0;
		for (i = q->front; i <= q->rear; i++) {
			print_data(&q->array[i]);
			if ((counter + 1) % 5 == 0 && counter != len_queue(q) - 1) {
				printf("\n");
			} else {
				printf("\t");
			}
			counter++;
		}
	}
	return;
}
int get_capacity_queue(Queue *q) {
	assert(q!=NULL);
	return q->capacity;
}
