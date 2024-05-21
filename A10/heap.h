#ifndef HEAP_H_
#define HEAP_H_

#include "data.h"

# define True 1
# define False 0

typedef struct heapNode {
	Data *data; 			//data item
	struct heapNode *parent; //pointer to parent
	struct heapNode *left; 	//Pointer to left child
	struct heapNode *right; //pointer to right child
} Node;

Node* create_node(Data *d, Node *parent, Node *left, Node *right);
void destroy_node(Node **n);
void print_node(Node *n);
Node* copy_node(Node *n);

typedef struct {
	Node *root;		//heap root
	int size;		//number of items
	char type[4];	//max or min
} Heap;

Heap* create_heap(char *type);
void destroy_heap(Heap **h);
int is_empty_heap(Heap *h);
void insert_heap(Heap *h, Data *d);
Data* peek_heap(Heap *h);
void remove_heap(Heap *h);
Node* find_node_heap(Heap *h, Data *d);
int contains_heap(Heap *h, Data *d);
void print_heap(Heap *h);
void heap_sort(Data *array, const int size);
Data* find_max_heap(Heap *h);
Data* find_min_heap(Heap *h);
int find_node_level_heap(Heap *h, Node *node);
int is_full_heap(Heap *h);

#endif /* HEAP_H_ */
