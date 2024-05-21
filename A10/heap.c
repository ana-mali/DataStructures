/*
 * ---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include <math.h>
# include "heap.h"
# include "queue_array.h"
# include "stack_array.h"

Node* find_node_heap_aux(Node *n, Data *d);
int contains_heap_aux(Heap *h, Node *n, Data *d);
int is_full_heap_aux(Node *root);
Data* find_min_heap_aux(Node *n, Data *min);
Data* find_max_heap_aux(Node *n, Data *max);

//------------------------ A10 Task 1 -------------------------
/**
 * ------------------------------------------------------------
 * Parameters: 	d - 	a data item (Data*)
 * 				parent- pointer to parent (Node*)
 * 				left - 	pointer to left child (Node*)
 * 				right - pointer to right child (Node*)
 * Returns: 	node -	new heap node (Node*)
 * Description:	Creates a new heap node using the given data and pointers
 * Asserts:		data is not NULL
 * ------------------------------------------------------------
 */
Node* create_node(Data *d, Node *parent, Node *left, Node *right) {
	Node *h = (Node*) malloc(sizeof(Node));
	assert(d);
	h->parent = parent;
	h->left = left;
	h->right = right;
	h->data = d;
	return h;
}

/**
 * -------------------------------------------------------
 * Parameters: 	n - a node (Node*)
 * Returns: 	none
 * Description:	prints the contents of a heap node
 * 				invokes print_data, does not print parent, left and right
 * 				if node is NULL prints <NULL Node>
 * Assert:		None
 * -------------------------------------------------------
 */
void print_node(Node *n) {
	if (!n)
		printf("<NULL Node>");
	else
		print_data(n->data);
	return;
}

/**
 * --------------------------------------------------------
 * Parameters: 	n - 	a node (Node*)
 * Returns: 	n2 -	a copy node (Node*)
 * Description:	Creates a copy of the given heap node
 * 				The new node has a duplicate copy of data and
 * 				same parent, left and right child
 * Assert:		given node is not NULL
 * --------------------------------------------------------
 */
Node* copy_node(Node *n) {
	assert(n);
	Node *n2 = create_node(n->data, n->parent, n->left, n->right);
	return n2;
}

/**
 * ---------------------------------------------------
 * Parameters:  n - a node (Node**)
 * Returns: 	none
 * Description:	destroys a heap node by:
 * 				- destroy the encompassed data
 * 				- setting parent, left and right to NULL
 * 				- free the node pointer, and set it to NULL
 * Assert:		n and *n are not NULL
 * --------------------------------------------------
 */
void destroy_node(Node **n) {
	assert(n && *n);
	(*n)->parent = NULL;
	(*n)->left = NULL;
	(*n)->right = NULL;
	(*n)->data = NULL;
	free(*n);
	*n = NULL;
	n = NULL;
	return;
}

//------------------------ A10 Task 2 -------------------------

/**
 * ------------------------------------------------------------
 * Parameters: 	type - heap type (max or min) (char*)
 * Returns: 	h - new heap (Heap*)
 * Description:	Creates a new heap of given type
 * 				Heap root is set to NULL and size to 0
 * 				if type is not "max" or "min" print error msg, set to "max"
 * Asserts:		none
 * ------------------------------------------------------------
 */
Heap* create_heap(char *type) {
	Heap *h = (Heap*) malloc(sizeof(Heap));
	char max[4];
	max[0] = 'm';
	max[1] = 'a';
	max[2] = 'x';
	char min[4];
	min[0] = 'm';
	min[1] = 'i';
	min[2] = 'n';
//	for (int i = 0; i < 4; i++) {
//		printf("%c*", type[i]);
//	}
	if (strcmp(type, min) == 0 || strcmp(type, max) == 0) {
		h->type[0] = type[0];
		h->type[1] = type[1];
		h->type[2] = type[2];
		h->type[3] = type[3];
	} else {
		printf("Error(create_heap): invalid type, set to max\n");
		h->type[0] = max[0];
		h->type[1] = max[1];
		h->type[2] = max[2];
		h->type[3] = max[3];
	}

	h->root = NULL;		//heap root
	h->size = 0;	//number of items

	return h;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap**)
 * Returns: 	none
 * Description:	destroys a heap by:
 * 				- removing all items
 * 				- setting root to NULL and size to 0 and type to empty string
 * 				- free the heap pointer, and set it to NULL
 * Assert:		h and *h are not NULL
 * --------------------------------------------------
 */
void destroy_heap(Heap **h) {
	assert(h && *h);
	(*h)->root = NULL;
	(*h)->size = 0;
	for (int i = 0; i < 4; i++) {
		(*h)->type[i] = '\0';
	}
	free(*h);
	*h = NULL;
	h = NULL;
	return;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	True/False
 * Description:	check if heap is empty
 * Assert:		h is not NULL
 * --------------------------------------------------
 */
int is_empty_heap(Heap *h) {
	assert(h);
	return h->size == 0;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	copy of data at the heap root
 * Description:	Returns a duplicate copy of the data item at the root
 * 				if heap is empty prints error msg, returns NULL
 * Assert:		h is not NULL
 * --------------------------------------------------
 */
Data* peek_heap(Heap *h) {
	assert(h);
	if (is_empty_heap(h)) {
		printf("Error(peek_heap): heap is empty\n");
		return NULL;
	}
	Data *d = copy_data(h->root->data);
	return d;
}

//------------------------ A10 Task 3 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				d - a data item (Data*)
 * Returns: 	pointer to a node
 * Description:	Returns a pointer to the node that contains given data
 * 				if not found returns NULL
 * Assert:		h and d are not NULL
 * --------------------------------------------------
 */
Node* find_node_heap(Heap *h, Data *d) {
	assert(h && d);
	if (is_empty_heap(h)) {
		printf("Error(find_node_heap): empty heap\n");
		return NULL;
	}
	Node *n = h->root;
	if (*n->data == *d)
		return n;
	else {
		n = find_node_heap_aux(n, d);
	}
	return n;
}

/**
 * ---------------------------------------------------
 * Parameters:  n - a node (Node*)
 * Returns: 	a pointer to  a node
 * Description:	private helper function for find_node_heap
 * 				Uses recursion.
 * 				Search through given node and recurse to other nodes
 * Assert:		None
 * --------------------------------------------------
 */
Node* find_node_heap_aux(Node *n, Data *d) {
	if (*n->data == *d) {
		return n;
	}
	if (n->left != NULL) {

		Node *p = find_node_heap_aux(n->left, d);

		if (p != NULL) {
			return p;
		}
	}
	if (n->right != NULL) {
		Node *p = find_node_heap_aux(n->right, d);
		if (p != NULL) {
			return p;
		}
	}
	return NULL;
}

//------------------------ A10 Task 4 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	None
 * Description:	Prints contents of a heap
 * 				if heap is empty prints <empty heap>
 * 				if heap is NULL prints <NULL Heap>
 * 				prints type and size of heap, then prints items in levelorder
 * 				Uses a queue.
 * 				items are separated by a space
 * Asserts:		None
 * --------------------------------------------------
 */
void print_heap(Heap *h) {
	if (h == NULL) {
		printf("<NULL Heap>\n");
		return;
	}
	printf("heap type = %s, size = %d\n", h->type, h->size);
	if (is_empty_heap(h)) {
		printf("<empty heap>");
	} else {
		Queue *q = create_queue(h->size);
		insert_queue(q, (Data*) h->root);
		while (!is_empty_queue(q)) {
			Node *d = (Node*) peek_queue(q);
			printf("%d ", *d->data);
			if (d->left != NULL)
				insert_queue(q, (Data*) d->left);
			if (d->right != NULL)
				insert_queue(q, (Data*) d->right);
			remove_queue(q);
		}
	}
	printf("\n");
	return;
}

//------------------------ A10 Task 5 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				d - data to search for (Data*)
 * Returns: 	True/False
 * Description:	Check if a heap contains a data item
 * 				recurse through all nodes to check
 * 					if any node contains the data
 * 				returns True if found and False otherwise
 * Asserts:		h and d are not NULL
 * --------------------------------------------------
 */
int contains_heap(Heap *h, Data *d) {
	assert(h && d);
	int result;
	if (is_empty_heap(h)) {
		return 0;
	}
	if (strcmp(h->type, "max") == 0) {
		if (*h->root->data < *d) {
			return 0;
		} else {
			result = contains_heap_aux(h, h->root, d);
		}
	} else if (strcmp(h->type, "min") == 0) {
		if (*h->root->data > *d) {
			return 0;
		} else {
			result = contains_heap_aux(h, h->root, d);
		}
	}
	return result;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				n - current node to check if it contains the data (Node*)
 * 				d - data to search for (Data*)
 * Returns: 	True/False
 * Description:	Private helper function for contains_heap
 * 				recurse through all nodes to check if node contains data
 * 				returns True if found and False otherwise
 * Asserts:		None
 * --------------------------------------------------
 */
int contains_heap_aux(Heap *h, Node *n, Data *d) {
	if (*n->data == *d) {
		return 1;
	}
	if (n->left != NULL) {
		int p = contains_heap_aux(h, n->left, d);
		if (p != 0) {
			return p;
		}
	}
	if (n->right != NULL) {
		int p = contains_heap_aux(h, n->right, d);
		if (p != 0) {
			return p;
		}
	}
	return 0;
}
//------------------------ A10 Task 6 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				start - a node for starting the search, normally the root (Node*)
 * 				node - the node to search for its level (Node*)
 * 				level - keeps track for level so far (int)
 * Returns: 	node_level - level of "node" in the heap (int)
 * Description:	Private helper method. Uses recursion.
 * 				Finds the level of a given node in a heap
 * 				if not found returns -1
 * Asserts:		heap is not NULL
 * --------------------------------------------------
 */
int find_node_level_heap_aux(Node *start, Node *node, int level) {
	int result;
	if (start == node) {
		return level;
	} else {
		level++;
		if (start->left != NULL) {
			result = find_node_level_heap_aux(start->left, node, level);
			if (result != -1) {
				return result;
			}
		}
		if (start->right != NULL) {
			result = find_node_level_heap_aux(start->right, node, level);
			if (result != -1) {
				return result;
			}
		}
	}
	return -1;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				node - the node to search for its level (Node*)
 * Returns: 	node_level - level of "node" in the heap (int)
 * Description:	Finds the level of a given node in a heap
 * 				if not found returns -1
 * 				Root is assumed to be at level 1
 * Asserts:		heap is not NULL
 * --------------------------------------------------
 */
int find_node_level_heap(Heap *h, Node *node) {
	assert(h);
	int result;
	if (is_empty_heap(h)) {
		return -1;
	}
	if (h->root == node) {
		return 1;
	} else {
		result = find_node_level_heap_aux(h->root, node, 1);
	}
	return result;
}

//------------------------ A10 Task 7 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  root - pointer to root node (Node*)
 * Returns: 	True/False
 * Description:	A private helper function for is_full_heap function
 * 				Uses recursion
 * 				Returns True if heap is full and False otherwise
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
int is_full_heap_aux(Node *root) {
	assert(root);
	int r, l;
	if (root->right == NULL && root->left != NULL) {
		return 0;
	}
	if (root->left == NULL && root->right != NULL) {
		return 0;
	}
	if (root->right != NULL && root->left != NULL) {
		r = is_full_heap_aux(root->right);
		l = is_full_heap_aux(root->left);
		if (r == 0) {
			return 0;
		} else if (l == 0) {
			return 0;
		}
	}
	return 1;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - pointer to a heap (Heap*)
 * Returns: 	True/False
 * Description:	Returns True if heap is full and False otherwise
 * 				A full heap is a heap in which each node has 0 or 2 children
 * 				An empty heap is considered a full heap
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
int is_full_heap(Heap *h) {
	assert(h);
	int result;
	if (is_empty_heap(h)) {
		return 1;
	} else {
		result = is_full_heap_aux(h->root);
	}
	return result;
}

//------------------------ A10 Task 8 -------------------------
/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	d - copy of data with max data
 * Description:	Returns a duplicate copy of maximum item in heap
 * 				steps are different depending on max/min heap
 * 				if heap is empty, print error msg and return NULL
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
Data* find_max_heap(Heap *h) {
	assert(h);
	if (is_empty_heap(h)) {
		printf("Error(find_max_heap): empty heap\n");
		return NULL;
	}

	Data max = *h->root->data;

	if (strcmp(h->type, "max") == 0) {
		return copy_data(h->root->data);
	} else
		find_max_heap_aux(h->root, &max);

	return copy_data(&max);
}
Data* find_max_heap_aux(Node *n, Data *max) {
	if (*n->data > *max) {
		*max = *n->data;
	}
	if (n->right != NULL) {
		find_max_heap_aux(n->right, max);

	}
	if (n->left != NULL) {
		find_max_heap_aux(n->left, max);
	}
	return max;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	d - copy of data with min data
 * Description:	Returns a duplicate copy of minimum item in heap
 * 				steps are different depending on max/min heap
 * 				if heap is empty, print error msg and return NULL
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
Data* find_min_heap(Heap *h) {
	assert(h);
	if (is_empty_heap(h)) {
		printf("Error(find_min_heap): empty heap\n");
		return NULL;
	}
	Data min = *h->root->data;
	if (strcmp(h->type, "min") == 0) {
		return copy_data(h->root->data);
	} else
		find_min_heap_aux(h->root, &min);
	return copy_data(&min);
}
Data* find_min_heap_aux(Node *n, Data *min) {
	if (*n->data < *min) {
		*min = *n->data;
	}
	if (n->right != NULL) {
		find_min_heap_aux(n->right, min);
	}
	if (n->left != NULL) {
		find_min_heap_aux(n->left, min);
	}
	return min;
}

//------------------------ Do not change these -------------------------
void insert_heap(Heap *h, Data *d) {
	return;
}

void remove_heap(Heap *h) {
	return;
}
