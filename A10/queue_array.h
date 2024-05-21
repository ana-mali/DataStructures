/*
 * ---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

#ifndef QUEUE_ARRAY_H_
#define QUEUE_ARRAY_H_
#include "data.h"
#include "heap.h"

typedef struct {
	Node **array;
	int front;
	int rear;
	int capacity;
} Queue;

Queue* create_queue(int capacity);
int is_empty_queue(Queue *q);
int len_queue(Queue *q);
int is_full_queue(Queue *q);
int insert_queue(Queue *q, Node *d);
Node* peek_queue(Queue *q);
Node* remove_queue(Queue *q);
void destroy_queue(Queue **q);
void print_queue(Queue *q);
int get_capacity_queue(Queue *q);

#endif /* QUEUE_ARRAY_H_ */
