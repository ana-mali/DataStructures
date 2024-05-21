/*
 * ---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "list.h"

/**
 * ------------------------------------------------------------
 * Parameters: 	d - a data item (Data*)
 * 				n - pointer to next node (Node*)
 * Returns: 	new node (Node*)
 * Description:	Creates a new node using the given data
 * Asserts:		data is not NULL
 * ------------------------------------------------------------
 */
Node* create_node(Data *d, Node *n) {
	assert(d);
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = copy_data(d);
	node->next = n;
	return node;

}

/**
 * -------------------------------------------------------
 * Parameters: 	a node (Node*)
 * Returns: 	none
 * Description:	prints the contents of a node
 * 				invokes print_data
 * 				does not print next pointer
 * Assert:		n is not NULL
 * -------------------------------------------------------
 */
void print_node(Node *n) {
	assert(n);
	print_data(n->data);
	return;
}

/**
 * --------------------------------------------------------
 * Parameters: 	a node (Node*)
 * Returns: 	a copy node (Node*)
 * Description:	Creates a copy of the given node
 * 				The new copy has a copy version of the data
 * 				the next pointer points to the same node as the original node's next
 * Assert:		given node is not NULL
 * --------------------------------------------------------
 */
Node* copy_node(Node *n) {
	assert(n);
	return create_node(n->data, n->next);
}

/**
 * ---------------------------------------------------
 * Parameters:  a node (Node**)
 * Returns: 	none
 * Description:	destroys a node by:
 * 				- destroy the encompassed data
 * 				- setting next to NULL
 * 				- free the node pointer
 * Assert:		n and *n are not NULL
 * --------------------------------------------------
 */
void destroy_node(Node **n) {
	assert(n && *n);
	destroy_data(&(*n)->data);
	(*n)->data = NULL;
	(*n)->next = NULL;
	free(n);
	return;
}

//-----------------------------------------------------------
/**
 * Parameters: 	None
 * Returns: 	A pointer to linked list (List*)
 * Description:	Creates an empty linked list
 * 				head is set to NULL and size to 0
 * 				Returns a pointer to the newly created linked list
 * -----------------------------------------------------------
 */
List* create_list() {
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->size = 0;
	return list;
}
/**
 * -------------------------------------------------------------------
 * Parameters: 	Pointer to a linked list (List*)
 * Returns: 	None
 * Description:	traverse through all nodes
 * 				uses print_node(Node*) to print contents of nodes
 * 				starting from list head to tail
 * 				node1-->node2-->node3-->...-->NULL
 * 				prints <NULL> if empty list
 * Assert:		list is not NULL
 * -------------------------------------------------------------------
 */
void print_list(List *list) {
	assert(list);
	Node *current_node = list->head;
	while (current_node != NULL) {
		print_node(current_node);
		printf("-->");
		current_node = current_node->next;
	}
	printf("NULL\n");
	return;
}

/**
 * ---------------------------------------------------------------
 * Parameters: 	A linked list (List*)
 * 				A data item (Data*)
 * Returns: 	None
 * Description:	appends the given data item to the tail of the linked list
 * 				updates size and may update head
 * Assert		list and d are not NULL
 * ---------------------------------------------------
 */
void append_list(List *list, Data *d) {
	assert(list && d);
	Node *new_node = create_node(d, NULL);
	if (is_empty_list(list))
		list->head = new_node;
	else {
		Node *current_node = list->head;
		while (current_node->next != NULL) {
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}
	list->size++;
	return;
}

/**
 * ---------------------------------------------------------------
 * Parameters: 	a linked list (List**)
 * Returns: 	None
 * Description:	Destroys a given linked list
 * 				Deletes all nodes (which takes care of destroying data)
 * 				set head to NULL and size to 0
 * 				free list pointer
 * Assert:		**list and *list are is not Null
 * ---------------------------------------------------------------
 */
void destroy_list(List **list) {
	while (!is_empty_list(*list)) {
		remove_rear_list(*list);
	}
	(*list)->head = NULL;
	(*list)->size = 0;
	free(*list);
	*list = NULL;
	return;
}
Data* remove_rear_list(List *list) {
	assert(list);
	if (is_empty_list(list)) {
		printf("Error(remove_rear_list): list is empty\n");
		return NULL;
	}
	Node *previous = NULL;
	Node *current = list->head;
	while (current->next != NULL) {
		previous = current;
		current = current->next;
	}
	Data *item = copy_data(current->data);
	if (list->size == 1)
		list->head = NULL;
	else
		previous->next = NULL;

	destroy_node(&current);
	list->size--;
	return item;
}
int is_empty_list(List *list) {
	assert(list);
	return list->head == NULL;
}
int compare_data(Data *d1, Data *d2) {
	assert(d1!=NULL);
	assert(d2!=NULL);
	if (d1->arrival > d2->arrival) {
		return 1;
	} else if (d2->arrival > d1->arrival) {
		return 2;
	} else if (d1->arrival == d2->arrival) {
		if (d1->time > d2->time) {
			return 1;
		} else if (d1->time < d2->time) {
			return 2;
		} else if (d1->time == d2->time) {
			if (d1->PID > d2->PID) {
				return 1;
			} else if (d1->PID < d2->PID) {
				return 2;
			} else {
				return 3;
			}
		}
	}
	return 0;
}
//------------------------- Assignment -------------------------
/**
 * -------------------------------------------------------------------------
 * Parameters: 	a linked list (List*)
 * 				a data item (Data*)
 * 				an index (int)
 * Returns: 	True/False
 * Description:	Inserts the given data item at position (index) at the linked list
 * 				if given index is out of range --> print an error and return NULL
 * 				returns True if insertion is successful, False otherwise
 * Assert:		given array and data pointers are not Null
 * -------------------------------------------------------------------------
 */
int insert_list(List *list, Data *d, int index) {
	assert(list && d);
	if (index < 0 || index > list->size) {
		printf("Error(insert_list): index out of range\n");
		return 0;
	}

	if (is_empty_list(list)) {
		Node *new_node = create_node(d, NULL);
		list->head = new_node;
	} else {
		Node *current = list->head;
		if (index == 0) {
			Node *new_node = create_node(d, current);
			list->head = new_node;
		} else if (index == list->size) {
			for (int i = 0; i < list->size; i++)
				if (current->next != NULL) {
					current = current->next;
				}
			Node *new_node = create_node(d, NULL);
			current->next = new_node;
		} else {
			for (int i = 0; i < list->size; i++) {
				Node *previous = current;
				current = current->next;
				if (i + 1 == index) {
					Node *new_node = create_node(d, current);
					previous->next = new_node;
					break;
				}
			}
		}
	}
	list->size++;
	return 1;
}

/**
 * -----------------------------------------------------------------
 * Parameters: 	list - a linked list (List*)
 * 				i - an index (int)
 * Returns: 	True/False
 * Description:	deletes the node at position (index) at the linked list
 * 				A copy of the data in the removed node is returned.
 * 				if given index is out of range --> print an error and return NULL
 * 				if given linked list is empty --> print an error and return NULL
 * Asserts:		given linked list is not NULL
 * ------------------------------------------------------------------
 */
Data* pop_list(List *list, int index) {
	assert(list);
	if (index < 0 || index >= list->size) {
		printf("Error(pop_list): index out of range\n");
		return NULL;
	}
	if (is_empty_list(list)) {
		printf("Error(pop_list): list is empty\n");
		return NULL;
	}
	Data *result;
	if (list->size == 1) {
		result = copy_data(list->head->data);
		list->head = NULL;
		list->size = 0;
		return result;
	}
	Node *current = list->head;
	if (index == 0) {
		result = copy_data(current->data);
		list->head = current->next;
		current = current->next;
		list->head->next = current->next;
//		destroy_node(&current);
	} else if (index + 1 == list->size) {
		Node *previous = current;
		for (int i = 0; i < list->size; i++)
			if (current->next != NULL) {
				previous = current;
				current = current->next;
			}
		result = copy_data(current->data);
		previous->next = NULL;
//		destroy_node(&current);
	} else {
		for (int i = 0; i < list->size; i++) {
			Node *previous = current;
			current = current->next;
			if (i + 1 == index) {
				result = copy_data(current->data);
				previous->next = current->next;
//				destroy_node(&current);
				break;
			}
		}
	}
	list->size--;
	return result;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a linked List (List*)
 * 				start index (int)
 * 				end index  (int)
 * Returns: 	None
 * Description:	deletes items from the list from index start to end (inclusive both ends)
 * 				Updates head and size as necessary
 * 				if given list is empty, print error and return
 *				if given start or end indices are out of range --> print error msg and return
 * Assert:		linked list is not NULL
 * ---------------------------------------------------------------------
 */
void cut_list(List *list, int start, int end) {
	assert(list);
	if (is_empty_list(list)) {
		printf("Error(cut_list): Linked List is empty\n");
		return;
	}
	if (start < 0 || start >= list->size) {
		printf("Error(cut_list): Invalid start index\n");
		return;
	}
	if (end < 0 || end >= list->size || end < start) {
		printf("Error(cut_list): Invalid end index\n");
		return;
	}
	Node *current = list->head;
	int i;
	if (start == 0) {
		for (i = 0; i < list->size; i++) {
			current = current->next;
			if (i == end) {
				list->head = current;
				break;
			}
		}
	} else {
		Node *t1, *t2;
		for (i = 0; i < list->size; i++) {
			Node *previous = current;
			current = current->next;
			if (i + 1 == start) {
				t1 = previous;
			}
			if (i == end) {
				t2 = current;
				break;
			}
		}
		t1->next = t2;
	}
	list->size = list->size - (end - start);
	return;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a linked list (List*)
 * 				start index (int)
 * 				end index  (int)
 * Returns: 	a linkedList (List*)
 * Description:	Constructs and returns a new linked list.
 * 				The new list contains elements from start to end (inclusive both ends)
 * 				if list is empty, print error msg and return empty list
 * 				if start/end is out of scope, print error msg and return empty list
 * 				Check if end index is greater than or requal to start index
 * Asserts:		list is not NULL
 * ---------------------------------------------------------------------
 */
List* sub_list(List *list, int start, int end) {
	assert(list);
	List *new = create_list();
	if (is_empty_list(list)) {
		printf("Error(sub_list): Linked list is empty\n");
		return new;
	}
	if (start < 0 || start >= list->size) {
		printf("Error(sub_list): Invalid start index\n");
		return new;
	}
	if (end < 0 || end >= list->size || end < start) {
		printf("Error(sub_list): Invalid end index\n");
		return new;
	}
	int i;
	Node *current = list->head;

	if (start == 0) {
		for (i = 0; i < (end - start + 1); i++) {
			append_list(new, current->data);
			current = current->next;
		}
	} else {
		Node *t1, *t2;
		for (i = 0; i < list->size; i++) {
			Node *previous = current;
			current = current->next;
			if (i == start) {
				t1 = previous;
			}
			if (i == end) {
				t2 = previous;
				break;
			}
		}
		for (i = 0; i < (end - start + 1); i++) {
			append_list(new, t1->data);
			t1 = t1->next;
		}
	}
	return new;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a pointer to a linked list (List*)
 * 				i - index of first item (int)
 * 				j - index of second item (int)
 * Returns: 	None
 * Description:	swaps items i and j in the list
 * 				if invalid i and j, print error msg and return
 * Asserts:		asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
void swap_list(List *list, int i, int j) {
	assert(list);
	if (is_empty_list(list)) {
		printf("Error(swap_list): list is empty\n");
		return;
	}
	if (i < 0 || j < 0 || i >= list->size || j >= list->size) {
		printf("Error (swap_list): Invalid value of i or j\n");
		return;
	}
	if (i == j) {
		return;
	}
	int k;
	Node *current = list->head, *previous, *n1, *n2, *p1, *p2;
	if (i == 0) {
		for (k = 0; k < list->size; k++) {
			previous = current;
			current = current->next;
			if (k + 1 == j) {
				p2 = previous;
				n2 = current;
				break;
			}
		}
		Data *temp = n2->data;
		n2->data = list->head->data;
		list->head->data = temp;
	} else if (j == 0) {
		for (k = 0; k < list->size; k++) {
			previous = current;
			current = current->next;
			if (k + 1 == i) {
				p2 = previous;
				n2 = current;
				break;
			}
		}
		Data *temp = n2->data;
		n2->data = list->head->data;
		list->head->data = temp;
	} else {
		for (k = 0; k < list->size; k++) {
			previous = current;
			current = current->next;
			if (k + 1 == i) {
				p1 = previous;
				n1 = current;
			}
			if (k + 1 == j) {
				p2 = previous;
				n2 = current;
				break;
			}
		}
		p1->next = n2;
		p2->next = n1;
		Node *temp = n1->next;
		n1->next = n2->next;
		n2->next = temp;
	}
	return;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	first linked list (List*)
 * 				second linked list (List*)
 * Returns: 	new list (List*)
 * Description:	Creates a new list that contains items which appear in both lists
 * 				No duplicates allowed
 * Assert:		both linked lists are not NULL
 * ---------------------------------------------------------------------
 */
List* intersection_list(List *list1, List *list2) {
	assert(list1 && list2);
	List *new = create_list();
	if (is_empty_list(list1) || is_empty_list(list2)) {
		return new;
	}
	Data arr1[list1->size], arr2[list2->size];
	int i;
	Node *current = list1->head;
	for (i = 0; i < list1->size; i++) {
		arr1[i] = *current->data;
		current = current->next;
	}
	current = list2->head;
	for (i = 0; i < list2->size; i++) {
		arr2[i] = *current->data;
		current = current->next;
	}
//	printf("arr1: ");
//	for (i = 0; i < list1->size; i++) {
//		print_data(&arr1);
//		printf("\n");
//	}
	int j, counter = 0;
	Data final[list1->size + list2->size];
	for (i = 0; i < list1->size; i++) {
		for (j = 0; j < list2->size; j++) {
			if (compare_data(&arr1[i], &arr2[j]) == 3) {
				final[counter] = arr1[i];
				counter++;
				break;
			}
		}
	}
	for (i = 0; i < counter; i++) {
		append_list(new, &final[i]);
	}
	return new;
}
