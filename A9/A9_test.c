# include <stdio.h>
# include <stdlib.h>
# include "data.h"
#include "list.h"
# include "process.h"

void test_insert();
void test_pop();
void test_sub_list();
void test_cut_list();
void test_swap();
void test_intersection();

int main() {
	setbuf(stdout, NULL);

	test_insert();
	test_pop();
	test_sub_list();
	test_cut_list();
	test_swap();
	test_intersection();
	return 0;

	return 0;
}

void test_insert() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List insert:\n\n");

	int successInsert;
	printf("-------- Testing Insert_List ------- \n");
	List *list = create_list();
	printf("Creating an empty linked list\n");
	print_list(list);
	printf("\n");

	Data *d1 = create_process(1000010001, 10, 1);

	printf("Inserting first element at index 0\n");
	successInsert = insert_list(list, d1, 0);
	printf("Successful Insertion? %d\n", successInsert);
	print_list(list);
	printf("\n");

	printf("Inserting second element at index 1\n");
	d1 = create_process(1000010002, 20, 2);
	successInsert = insert_list(list, d1, 1);
	printf("Successful Insertion? %d\n", successInsert);
	print_list(list);
	printf("\n");

	printf("Inserting third element at index 1\n");
	d1 = create_process(1000010003, 30, 3);
	successInsert = insert_list(list, d1, 1);
	printf("Successful Insertion? %d\n", successInsert);
	print_list(list);
	printf("\n");

	printf("Inserting fourth element at index 2\n");
	d1 = create_process(1000010004, 40, 4);
	successInsert = insert_list(list, d1, 2);
	printf("Successful Insertion? %d\n", successInsert);
	print_list(list);
	printf("\n");

	printf("Inserting fifth element at index 0\n");
	create_process(1000010005, 50, 5);
	successInsert = insert_list(list, d1, 0);
	printf("Successful Insertion? %d\n", successInsert);
	print_list(list);
	printf("\n");

	printf("Inserting sixth element at index 2\n");
	d1 = create_process(1000010006, 60, 6);
	successInsert = insert_list(list, d1, 2);
	printf("Successful Insertion? %d\n", successInsert);
	print_list(list);
	printf("\n");

	printf("Inserting seventh element at index 6\n");
	d1 = create_process(1000010007, 70, 7);
	successInsert = insert_list(list, d1, 6);
	printf("Successful Insertion? %d\n", successInsert);
	print_list(list);
	printf("\n");

	printf("Inserting at invalid index (index = 100)\n");
	successInsert = insert_list(list, d1, 100);
	printf("Successful Insertion? %d\n", successInsert);
	print_list(list);
	printf("\n");

	printf("destroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing Linked List insert\n");
	printf("------------------------------\n\n");
	return;
}

void test_pop() {
	printf("------------------------------\n");
	printf("Start: Testing List pop function:\n\n");

	int i, arrival = 10, time = 1;
	long long pid = 1000010000;

	List *list = create_list();
	printf("Create Linked list with 10 elements\n");
	for (i = 0; i < 10; i++)
		append_list(list, create_process(pid++, time++, arrival++));
	print_list(list);
	printf("\n");

	printf("Deleting Element 0:\n");
	pop_list(list, 0);
	print_list(list);
	printf("\n");

	printf("Deleting Element 5:\n");
	pop_list(list, 5);
	print_list(list);
	printf("\n");

	printf("Deleting Element 1:\n");
	pop_list(list, 1);
	print_list(list);
	printf("\n");

	printf("Deleting last element (index = 6):\n");
	pop_list(list, 6);
	print_list(list);
	printf("\n");

	printf("Deleting using invalid index (index = 6)\n");
	pop_list(list, 6);
	print_list(list);
	printf("\n");

	printf("Calling delete (index = 0) six times\n");
	for (i = 0; i < 6; i++)
		pop_list(list, 0);
	print_list(list);
	printf("\n");

	printf("delete from an empty list (index = 0)\n");
	pop_list(list, 0);
	print_list(list);
	printf("\n");

	printf("destroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing List pop function\n");
	printf("------------------------------\n\n");
	return;
}

void test_sub_list() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List sub_list function:\n\n");

	List *list = create_list();
	List *newList = NULL;
	int i, arrival = 10, time = 1;
	long long pid = 1000010000;

	printf("Case 1: An Empty List - Get List [0:5]\n");
	newList = sub_list(list, 0, 5);
	printf("Original List: \n");
	print_list(list);
	printf("New List: \n");
	print_list(newList);
	destroy_list(&newList);
	printf("\n");

	printf("Create a linked list with 10 random processes:\n");
	for (i = 0; i < 10; i++)
		append_list(list, create_process(pid++, time++, arrival++));
	print_list(list);
	printf("\n");

	printf("Case 2: illegal start values:\n");
	printf("getList[-1,5]:\n");
	newList = sub_list(list, -1, 5);
	print_list(newList);
	destroy_list(&newList);
	printf("getList[10,15]:\n");
	newList = sub_list(list, 10, 15);
	print_list(newList);
	destroy_list(&newList);
	printf("\n");

	printf("Case 3: illegal end values:\n");
	printf("getList[2,-1]:\n");
	newList = sub_list(list, 2, -1);
	print_list(newList);
	destroy_list(&newList);
	printf("getList[2,10]:\n");
	newList = sub_list(list, 2, 10);
	print_list(newList);
	destroy_list(&newList);
	printf("getList[4,2]:\n");
	newList = sub_list(list, 4, 2);
	print_list(newList);
	destroy_list(&newList);
	printf("\n");

	printf("Case 3: partial List: getList[2,5]:\n");
	newList = sub_list(list, 2, 5);
	print_list(newList);
	destroy_list(&newList);
	printf("\n");

	printf("Case 4: single item list: getList[2,2]:\n");
	newList = sub_list(list, 2, 2);
	print_list(newList);
	destroy_list(&newList);
	printf("\n");

	printf("Case 5: full list: getList[0,9]:\n");
	newList = sub_list(list, 0, 9);
	print_list(newList);
	destroy_list(&newList);
	printf("\n");

	printf("destroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing sub_list function\n");
	printf("------------------------------\n\n");
	return;
}

void test_cut_list() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List cut_list function:\n\n");

	List *list = create_list();
	int arrival = 10, time = 1;
	long long pid = 1000010000;

	printf("Case 1: An Empty List -  cut [0:5]\n");
	cut_list(list, 0, 5);
	print_list(list);
	printf("\n");

	printf("Create a linked list with 10 random processes:\n");
	for (int i = 0; i < 10; i++)
		append_list(list, create_process(pid++, time++, arrival++));
	print_list(list);
	printf("\n");

	printf("Case 2: illegal start values:\n");
	printf("cut[-1,5]:\n");
	cut_list(list, -1, 5);
	print_list(list);
	printf("cut[10,15]:\n");
	cut_list(list, 10, 15);
	print_list(list);
	printf("\n");

	printf("Case 2: illegal end values:\n");
	printf("cut[2,-1]:\n");
	cut_list(list, 2, -1);
	print_list(list);
	printf("cut[2,10]:\n");
	cut_list(list, 2, 10);
	print_list(list);
	printf("cut[4,2]:\n");
	cut_list(list, 4, 2);
	print_list(list);
	printf("\n");

	printf("Case 3: cut[2,5]:\n");
	cut_list(list, 2, 5);
	print_list(list);
	printf("\n");

	printf("Case 4: cut[2,2]:\n");
	cut_list(list, 2, 2);
	print_list(list);
	printf("\n");

	printf("Case 5: cut[0,4]:\n");
	cut_list(list, 0, 4);
	print_list(list);
	printf("\n");

	printf("destroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing List cut function\n");
	printf("------------------------------\n\n");
	return;
}

void test_swap() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List swap_list function:\n\n");

	List *list = create_list();
	int arrival = 10, time = 1;
	long long pid = 1000010000;

	print_list(list);
	printf("swap_list(list,1,2):\n");
	swap_list(list, 1, 2);
	printf("\n");

	printf("Create a linked list with 10 random processes:\n");
	for (int i = 0; i < 10; i++)
		append_list(list, create_process(pid++, time++, arrival++));
	print_list(list);
	printf("\n");

	printf("swap_list(list,-1,5):\n");
	swap_list(list, -1, 5);
	print_list(list);
	printf("\n");

	printf("swap_list(list,2,2):\n");
	swap_list(list, 2, 2);
	print_list(list);
	printf("\n");

	printf("swap_list(list,1,2):\n");
	swap_list(list, 1, 2);
	print_list(list);
	printf("\n");

	printf("swap_list(list,1,3):\n");
	swap_list(list, 1, 3);
	print_list(list);
	printf("\n");

	printf("swap_list(list,0,1):\n");
	swap_list(list, 0, 1);
	print_list(list);
	printf("\n");

	printf("swap_list(list,0,5):\n");
	swap_list(list, 0, 5);
	print_list(list);
	printf("\n");

	printf("swap_list(list,6,9):\n");
	swap_list(list, 6, 9);
	print_list(list);
	printf("\n");

	printf("swap_list(list,8,9):\n");
	swap_list(list, 8, 9);
	print_list(list);
	printf("\n");

	printf("destroy linked list\n");
	destroy_list(&list);
	printf("\n");

	printf("End: Testing List swap_list function\n");
	printf("------------------------------\n\n");
	return;
}

void test_intersection() {
	printf("------------------------------\n");
	printf("Start: Testing Linked List intersection_list function:\n\n");

	List *list1 = create_list(), *list2 = create_list(), *list3 = NULL;
	int arrival = 10, time = 1, i = 0;
	long long pid = 1000010000;
	do {
		printf("list1 = ");
		print_list(list1);
		printf("list2 = ");
		print_list(list2);
		list3 = intersection_list(list1, list2);
		printf("list3 = ");
		print_list(list3);
		destroy_list(&list3);
		if (i != 0)
			append_list(list1, create_process(pid, time, arrival));
		if (i % 2 == 0)
			append_list(list2, create_process(pid, time, arrival));
		pid++;
		time++;
		arrival++;
		i++;
		printf("\n");
	} while (i < 11);

	destroy_list(&list1);
	destroy_list(&list2);
	printf("\n");

	printf("End: Testing List intersection_list function\n");
	printf("------------------------------\n\n");
	return;
}
