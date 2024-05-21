#ifndef LIST_H_
#define LIST_H_

# include "data.h"
# define True 1
# define False 0

typedef struct linkedListNode {
	Data *data; 					//data item
	struct linkedListNode *next; 	//Pointer to next node
} Node;

Node* create_node(Data *d, Node *n);
void destroy_node(Node **n);
void print_node(Node *n);
Node* copy_node(Node *n);

typedef struct {
	Node *head;
	int size;
} List;

//basic functions
List* create_list();
void destroy_list(List **list);
void print_list(List *list);
int is_empty_list(List *list);

//Getters
Data* ge_data_list(List *list, int index);
Node* get_node_list(List *list, int index);
Data* peek_list(List *list);
List* copy_list(List *list);
List* sub_list(List *list, int start, int end);

//Setters
void append_list(List *list, Data *d);
void insert_front_list(List *list, Data *d);
int insert_list(List *list, Data *d, int index);
void extend_list(List *list1, List *list2);

//Searching Functions
int index_list(List *list, Data *d);
int contains_list(List *list, Data *d);

//statistics functions
int count_list(List *list, Data *d);
Data* max_list(List *list);
Data* min_list(List *list);

//Remove Functions
Data* remove_rear_list(List *list);
Data* remove_front_list(List *list);
Data* pop_list(List *list, int index);
Data* remove_list(List *list, Data *d);
void remove_many_list(List *list, Data *d);
void clean_list(List *list);
List* split_list(List *list);
void cut_list(List *list, int start, int end);

//Conversion functions
List* array_to_list(Data *array, const int size);
Data* list_to_array(List *list);

//Ordering functions
void reverse_list(List *list);
void swap_list(List *list, int i, int j);
void sort_list(List *list);

//comparison functions
int identical_list(List *list1, List *list2);
List* union_list(List *list1, List *list2);
List* intersection_list(List *list1, List *list2);

#endif /* LIST_H_ */
