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
#include "A6.h"

void remove_largest(Process *process_array, const int size) {
	if (process_array == NULL) {
		printf("Error(remove_largest): given pointer is NULL\n");
		return;
	}
	if (size <= 0) {
		printf("Error(remove_largest): invalid array size\n");
		return;
	}
	Process max = process_array[0];
	int i, counter = 0;
//	if (sizeof(process_array) == 1) {
//		process_array[0].time = 0;
//		process_array[0].arrival = 0;
//		process_array[0].PID = get_UPID();
//		return;
//	}
	for (i = 0; i < size; i++) {
		if (process_array[i].time > max.time) {
			max = process_array[i];
			continue;
		}
		if (process_array[i].time == max.time && i != 0) {
			counter++;
		}
	}
	if (counter > 1) {
		for (i = 0; i < size; i++) {
			if (process_array[i].time == max.time) {
				if (process_array[i].arrival < max.arrival) {
					max = process_array[i];
				} else if (process_array[i].arrival == max.arrival) {
					if (process_array[i].PID < max.PID) {
						max = process_array[i];
					}
				}
			}
		}
	}
	for (i = 0; i < size; i++) {
		if (is_equal_process(process_array[i], max)) {
			process_array[i] = process_array[size - 1];
			process_array[size - 1].time = 0;
			process_array[size - 1].arrival = 0;
			process_array[size - 1].PID = 0;
		}
	}
	printf("Largest Process is: %d\n", max.PID);
//	size = size - 1;
	return;
}

void reverse_stack(Stack *s) {
	Data arr[10], *d;
//	Stack *point = s;
	int i;
	if (is_empty_stack(s)) {
		return;
	}
	int len = s->top;
	for (i = 0; i <= len; i++) {
		d = pop_stack(s);
		Data temp = *d;
		arr[i] = temp;
	}

	for (i = 0; i <= len; i++) {
		Data *val = &arr[i];
		push_stack(s, val);
	}
	return;
}

Stack* slice_stack(Stack *s1, int index) {
	Stack *s2 = create_stack(10);
	if (len_stack(s1) <= 0 || s1 == NULL) {
		printf("Error(slice_stack): cannot slice an empty stack\n");
		return s2;
	}
	if (index < 0) {
		printf("Error(slice_stack): invalid index\n");
		return s2;
	}
	Data *val;
	int i, len = s1->top;
	for (i = 0; i <= len; i++) {
		if (i >= index) {
			val = pop_stack(s1);
			push_stack(s2, val);
		}
	}
	reverse_stack(s2);

	return s2;
}

int resize_stack(Stack *s, int new_capacity) {
	if (new_capacity <= 0) {
		printf("Error(resize_stack): invalid capacity size.\n");
		return 0;
	}
	if (new_capacity == s->capacity) {
		return 0;
	}
	if (new_capacity < s->capacity) {
		int len = s->top;
		for (int i = 0; i <= len; i++) {
			if (i >= new_capacity) {
				pop_stack(s);
			}
		}
	}
	s->array = (Data*) realloc(s->array, sizeof(Data) * new_capacity);
	s->capacity = new_capacity;
	return 1;
}
Stack* concat_stack(Stack *s1, Stack *s2) {
	int cap = s1->capacity + s2->capacity, i;
	Stack *s3 = create_stack(cap);
	Data val;
	if (is_empty_stack(s1) && is_empty_stack(s2)) {
		return s3;
	}
	if (!is_empty_stack(s1)) {
		int len = s1->top;
		for (i = 0; i <= len; i++) {
			val = s1->array[i];
			push_stack(s3, &val);
		}
	}
	if (!is_empty_stack(s2)) {
		int len = s2->top;
		for (i = 0; i <= len; i++) {
			val = s2->array[i];
			push_stack(s3, &val);
		}
	}
	return s3;
}
