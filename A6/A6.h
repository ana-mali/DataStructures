#ifndef A6_H_
#define A6_H_

#include "stack_array.h"

#define MAX 100

void remove_largest(Process *process_array, const int size);
void reverse_stack(Stack *s);
int resize_stack(Stack *s, int new_capacity);
Stack* concat_stack(Stack *s1, Stack *s2);
Stack* slice_stack(Stack *s1, int index);

#endif /* A6_H_ */
