# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "heap.h"

void test_heap_node();
void test_heap_basics();
void test_find_node();
void test_print_heap();
void test_contains_heap();
void test_node_level();
void test_is_full();
void test_max_min();

Heap* get_heap(int size, char *type);

int values1[16] = { 150, 130, 140, 100, 110, 70, 50, 15, 40, 80, 90, 60, 10, 20,
		30, 5 };
int values2[16] = { 5, 15, 20, 50, 30, 40, 60, 80, 70, 100, 90, 110, 120, 130,
		150, 140 };

int main() {
	setbuf(stdout, NULL);
	test_heap_node();
	test_heap_basics();
	test_find_node();
	test_print_heap();
	test_contains_heap();
	test_node_level();
	test_is_full();
	test_max_min();
	return 0;
}

void test_heap_node() {
	printf("------------------------------\n");
	printf("Start: Testing Heap Node:\n\n");

	int size = 3;
	Data *array = (Data*) malloc(sizeof(Data) * size);
	for (int i = 0; i < size; i++)
		array[i] = (i + 1) * 10;

	printf("Create node 1 with item = %d\n", array[0]);
	Node *n1 = create_node(&array[0], NULL, NULL, NULL);
	printf("Print node: ");
	print_node(n1);
	printf("\n\n");

	printf("Create node 2 with item = %d:\n", array[1]);
	Node *n2 = create_node(&array[1], NULL, NULL, NULL);
	print_node(n2);
	printf("\n\n");

	printf("Create node 3 with item = %d:\n", array[2]);
	Node *n3 = create_node(&array[2], NULL, NULL, NULL);
	print_node(n3);
	printf("\n\n");

	printf(
			"Make node 2 left child of node 1 and node 3 right child of node 1:\n");
	n1->left = n2;
	n1->right = n3;
	n2->parent = n1;
	n3->parent = n1;

	printf("Print left of node 1:\n");
	print_node(n1->left);
	printf("\n\n");

	printf("Print right of node 2:\n");
	print_node(n1->right);
	printf("\n\n");

	printf("Print parent of node 3:\n");
	print_node(n3->parent);
	printf("\n\n");

	printf("Copy node 1 to node 4:\n");
	Node *n4 = copy_node(n1);
	printf("Print node 4:\n");
	print_node(n4);
	printf("\n\n");

	printf("Print left of node 4:\n");
	print_node(n4->left);
	printf("\n\n");

	printf("Destroy four nodes\n");
	destroy_node(&n1);
	destroy_node(&n2);
	destroy_node(&n3);
	destroy_node(&n4);
	printf("Nodes destroyed successfully\n\n");

	printf("End: Testing Heap Node\n");
	printf("------------------------------\n\n");
	return;
}

void test_heap_basics() {
	printf("------------------------------\n");
	printf("Start: Testing heap basic functions:\n\n");

	Heap *h = NULL;
	Data *peek_data = NULL;

	printf("Case 1: NULL heap:\n");
	print_heap(h);
	printf("\n");

	printf("Case 2: Max heap:\n");
	h = create_heap("max");
	print_heap(h);
	printf("is_empty_heap(h)? %d\n", is_empty_heap(h));
	printf("h->size = %d\n", h->size);
	printf("h->root = ");
	print_node(h->root);
	printf("\n");
	printf("peek = ");
	peek_data = peek_heap(h);
	print_data(peek_data);
	destroy_heap(&h);
	printf("heap successfully destroyed\n\n");

	printf("Case 3: Min heap:\n");
	h = create_heap(" ");
	print_heap(h);
	printf("is_empty_heap(h)? %d\n", is_empty_heap(h));
	printf("h->size = %d\n", h->size);
	printf("h->root = ");
	print_node(h->root);
	printf("\n");
	printf("peek = ");
	peek_data = peek_heap(h);
	print_data(peek_data);
	destroy_heap(&h);
	printf("heap successfully destroyed\n\n");

	printf("Case 4: Treap heap:\n");
	h = create_heap("treap");
	print_heap(h);
	destroy_heap(&h);
	printf("heap successfully destroyed\n\n");

	printf("End: Testing heap basic functions\n");
	printf("------------------------------\n\n");
}

void test_find_node() {
	printf("------------------------------\n");
	printf("Start: Testing find_node_heap:\n\n");

	int values[9] = { 150, 130, 140, 100, 110, 70, 50, 15, 40 };
	int i, items = 9;
	Data *array = NULL;
	array = (int*) malloc(sizeof(int) * items);
	for (i = 0; i < items; i++)
		array[i] = values[i];

	Heap *h = get_heap(8, "max");
	print_heap(h);
	printf("\n");

	Node *node = NULL;
	for (i = 0; i < items; i++) {
		printf("find_node(%d): ", array[i]);
		node = find_node_heap(h, &array[i]);
		printf("data = ");
		print_node(node);
		if (node) {
			printf(" , parent = ");
			print_node(node->parent);
			printf(" , left = ");
			print_node(node->left);
			printf(" , right = ");
			print_node(node->right);
		}
		printf("\n\n");
	}

	free(array);
	array = NULL;

	printf("End: Testing find_node_heap\n");
	printf("------------------------------\n\n");
	return;
}

void test_print_heap() {
	printf("------------------------------\n");
	printf("Start: Testing print_heap:\n\n");

	print_heap(NULL);
	printf("\n");

	for (int i = 0; i < 9; i++) {
		print_heap(get_heap(i, "max"));
		printf("\n");
	}

	printf("End: Testing print_heap\n");
	printf("------------------------------\n\n");
}

void test_contains_heap() {
	printf("------------------------------\n");
	printf("Start: Testing contains_heap:\n\n");

	int values[9] = { 150, 130, 140, 100, 110, 70, 50, 15, 40 };
	int i, items = 9;
	Data *array = NULL;
	array = (int*) malloc(sizeof(int) * items);
	for (i = 0; i < items; i++)
		array[i] = values[i];

	Heap *h = get_heap(8, "max");
	print_heap(h);
	printf("\n");

	for (i = 0; i < items; i++)
		printf("contains_heap(h,%d)? = %d\n\n", array[i],
				contains_heap(h, &array[i]));

	free(array);
	array = NULL;

	printf("End: Testing contains_heap\n");
	printf("------------------------------\n\n");
	return;
}

void test_node_level() {
	printf("------------------------------\n");
	printf("Start: Testing find_node_level_heap:\n\n");

	int values[9] = { 150, 130, 140, 100, 110, 70, 50, 15, 40 };
	int i, items = 9;
	Data *array = NULL;
	array = (int*) malloc(sizeof(int) * items);
	for (i = 0; i < items; i++)
		array[i] = values[i];

	Heap *h = get_heap(8, "max");
	print_heap(h);
	printf("\n");

	Node *node = NULL;
	for (i = 0; i < items; i++) {
		printf("Level for %d = ", array[i]);
		node = find_node_heap(h, &array[i]);
		printf("%d\n", find_node_level_heap(h, node));
		node = find_node_heap(h, &array[i]);
	}
	printf("\n");

	free(array);
	array = NULL;

	printf("End: Testing find_node_level_heap\n");
	printf("------------------------------\n\n");
	return;
}

void test_is_full() {
	printf("------------------------------\n");
	printf("Start: Testing is_full_heap:\n\n");

	for (int i = 0; i < 9; i++) {
		Heap *h = get_heap(i, "max");
		print_heap(h);
		printf("is full? = %d\n\n", is_full_heap(h));
	}

	printf("End: Testing is_full_heap\n");
	printf("------------------------------\n\n");
}

void test_max_min() {
	printf("------------------------------\n");
	printf("Start: Testing max_min:\n\n");

	printf("Testing max-heap:\n");
	for (int i = 0; i < 9; i++) {
		Heap *h = get_heap(i, "max");
		print_heap(h);
		if (!is_empty_heap(h))
			printf("max = ");
		print_data(find_max_heap(h));
		if (!is_empty_heap(h))
			printf(" , min = ");
		print_data(find_min_heap(h));
		printf("\n");
		if (!is_empty_heap(h))
			printf("\n");
	}

	printf("Testing min-heap:\n");
	for (int i = 0; i < 9; i++) {
		Heap *h = get_heap(i, "min");
		print_heap(h);
		if (!is_empty_heap(h))
			printf("max = ");
		print_data(find_max_heap(h));
		if (!is_empty_heap(h))
			printf(" , min = ");
		print_data(find_min_heap(h));
		printf("\n");
		if (!is_empty_heap(h))
			printf("\n");
	}

	printf("End: Testing max_min\n");
	printf("------------------------------\n\n");
}

Heap* get_heap(int size, char *type) {
	Heap *h = NULL;
	if (strcmp(type, "max") == 0)
		h = create_heap("max");
	else
		h = create_heap("min");
	if (size <= 0)
		return h;

	int i, items = 16;
	Data *array = NULL;
	array = (int*) malloc(sizeof(int) * items);
	for (i = 0; i < items; i++) {
		if (strcmp(type, "max") == 0)
			array[i] = values1[i];
		else
			array[i] = values2[i];
	}

	int counter = 0;
	Node *n1 = create_node(&array[counter++], NULL, NULL, NULL);
	h->root = n1;
	h->size++;
	if (size == 1)
		return h;

	Node *n2 = create_node(&array[counter++], n1, NULL, NULL);
	n1->left = n2;
	h->size++;
	if (size == 2)
		return h;

	Node *n3 = create_node(&array[counter++], n1, NULL, NULL);
	n1->right = n3;
	h->size++;
	if (size == 3)
		return h;

	Node *n4 = create_node(&array[counter++], n2, NULL, NULL);
	n2->left = n4;
	h->size++;
	if (size == 4)
		return h;

	Node *n5 = create_node(&array[counter++], n2, NULL, NULL);
	n2->right = n5;
	h->size++;
	if (size == 5)
		return h;

	Node *n6 = create_node(&array[counter++], n3, NULL, NULL);
	n3->left = n6;
	h->size++;
	if (size == 6)
		return h;

	Node *n7 = create_node(&array[counter++], n3, NULL, NULL);
	n3->right = n7;
	h->size++;
	if (size == 7)
		return h;

	Node *n8 = create_node(&array[counter++], n4, NULL, NULL);
	n4->left = n8;
	h->size++;
	if (size == 8)
		return h;

	return h;
}
