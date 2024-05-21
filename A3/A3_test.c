# include <stdio.h>
# include "A3.h"

void test_find_next();
void test_increment_element();
void test_find_avg_element();
void test_print_ptr_array();
void test_special_array_print();

void print(int *array, const int size);
void print2(double *array, const int size);

//-------------------------------------------------------------------
int main() {

	setbuf(stdout, NULL);

	test_find_next();
	test_increment_element();
	test_find_avg_element();
	test_print_ptr_array();
	test_special_array_print();

	return 0;
}

void test_find_next() {
	printf("------------------------------\n");
	printf("Start: Testing find_next:\n\n");

	int *result, *temp, i;
	int array[12] = { 10, 5, 15, 10, 2, 4, 16, 4, 8, 18, 3, 9 };
	int sizes[8] = { 9, 0, 6, 9, 2, 12, 5, 12 };
	int values[8] = { 5, 10, 5, 4, 11, 13, 2, 9 };

	for (i = 0; i < 8; i++) {
		temp = (i == 0) ? NULL : array;
		printf("Case %d:\n", i + 1);
		printf("find_next(");
		print(temp, sizes[i]);
		printf(", %d, %d) --> ", sizes[i], values[i]);
		result = find_next(temp, sizes[i], values[i]);
		if (result == NULL)
			printf("NULL\n");
		else
			printf("%d\n", *result);
	}

	printf("\n");
	printf("End: Testing find_next\n");
	printf("------------------------------\n\n");
	return;
}

void test_increment_element() {
	printf("------------------------------\n");
	printf("Start: Testing increment_element:\n\n");

	int array1[5] = { 10, 20, 30, 40, 50 }, i, size;

	printf("Case 1: Error cases:\n");
	increment_element(NULL, 10, 3, 'i');
	increment_element(array1, -3, 1, 'i');
	increment_element(array1, 5, -1, 'i');
	increment_element(array1, 5, 5, 'i');
	increment_element(array1, 5, 4, 'r');
	printf("\n");

	printf("Case 2: array of integers:\n");
	printf("Before: ");
	print(array1, 5);
	printf("\n");
	increment_element(array1, 5, 3, 'i');
	printf("After: ");
	print(array1, 5);
	printf("\n\n");

	printf("Case 3: array of longs:\n");
	long array2[6] = { 200, 345, 679, 501, 449, 912 };
	size = 6;
	printf("Before: [200, 345, 679,501,449,912]\n");
	increment_element(array2, size, 4, 'l');
	printf("After: ");
	printf("[");
	for (i = 0; i < size; i++) {
		printf("%ld", array2[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("]\n\n");

	printf("Case 4: array of floats:\n");
	float array3[4] = { 20.5, 3.45, 6.79, 5.01 };
	size = 4;
	printf("Before: [20.5, 3.45, 6.79, 5.01]\n");
	increment_element(array3, size, 1, 'f');
	printf("After: ");
	printf("[");
	for (i = 0; i < size; i++) {
		printf("%.2lf", array3[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("]\n\n");

	printf("Case 5: array of doubles:\n");
	double array4[4] = { 20.5, 3.45, 6.79, 5.01 };
	size = 4;
	printf("Before: [20.5, 3.45, 6.79, 5.01]\n");
	increment_element(array4, size, 0, 'd');
	printf("After: ");
	printf("[");
	for (i = 0; i < size; i++) {
		printf("%.2lf", array4[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("]\n\n");

	printf("End: Testing increment_element\n");
	printf("------------------------------\n\n");
	return;
}

void test_find_avg_element() {
	printf("------------------------------\n");
	printf("Start: Testing find_avg_element:\n\n");

	int array1[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int *ptr = NULL;
	int **p = NULL;

	printf("Case 1: Error Cases\n");
	find_avg_element(NULL, MAX, &ptr);
	find_avg_element(array1, 0, &ptr);
	find_avg_element(array1, 3, p);
	printf("\n");

	printf("Case 2: {1,2,3,4,5,6,7}\n");
	find_avg_element(array1, 7, &ptr);
	printf("The Average Element is %d which is at index: %d\n", *ptr,
			(ptr - array1));

	printf("\nCase 3: {1,2,3,4,5,6,7,8}\n");
	find_avg_element(array1, 8, &ptr);
	printf("The Average Element is %d which is at index: %d\n", *ptr,
			(ptr - array1));

	printf("\nCase 4: {5,5,5,5,5}\n");
	int intList2[5] = { 5, 5, 5, 5, 5 };
	find_avg_element(intList2, 5, &ptr);
	printf("The Average Element is %d which is at index: %d\n", *ptr,
			(ptr - intList2));

	printf("\nCase 5: {100,10} \n");
	int intList4[2] = { 100, 10 };
	find_avg_element(intList4, 2, &ptr);
	printf("The Average Element is %d which is at index: %d\n", *ptr,
			(ptr - intList4));

	printf("\nCase 6: {1,7,9,23,44}\n");
	int intList3[5] = { 1, 7, 9, 23, 44 };
	find_avg_element(intList3, 5, &ptr);
	printf("The Average Element is %d which is at index: %d\n", *ptr,
			(ptr - intList3));
	printf("\n");

	printf("End: Testing find_avg_element\n");
	printf("------------------------------\n\n");
	return;
}

void test_print_ptr_array() {
	printf("------------------------------\n");
	printf("Start: Testing print_ptr_array:\n\n");

	double *ptrs[MAX];

	printf("Case 1:\n");
	double array1[MAX] = { 10.09, -4.18, 20.27, -4.36, 30.45, 40.54, 50.63,
			-4.72, 60.81, 70.90 };
	print2(array1, MAX);
	ptrs[0] = &array1[1];
	ptrs[1] = &array1[3];
	ptrs[2] = &array1[7];
	ptrs[3] = NULL;
	print_ptr_array(array1, ptrs);
	printf("\n");

	printf("Case 2:\n");
	print2(array1, MAX - 2);
	ptrs[0] = &array1[2];
	ptrs[1] = &array1[3];
	ptrs[2] = &array1[4];
	ptrs[3] = &array1[6];
	ptrs[4] = &array1[4];
	ptrs[5] = &array1[7];
	ptrs[6] = NULL;
	print_ptr_array(array1, ptrs);
	printf("\n");

	double array2[MAX] = { 1.90, 2.81, 3.72, 1.63, 5.54, 6.45, 1.36, 7.27, 8.18,
			1.09 };
	printf("Case 3:\n");
	print2(array2, MAX);
	ptrs[0] = &array2[0];
	ptrs[1] = &array2[3];
	ptrs[2] = &array2[6];
	ptrs[3] = &array2[9];
	ptrs[4] = NULL;
	print_ptr_array(array2, ptrs);
	printf("\n");

	printf("Case 4:\n");
	print2(array2, MAX);
	ptrs[0] = NULL;
	print_ptr_array(array2, ptrs);
	printf("\n");

	printf("End: Testing print_ptr_array\n");
	printf("------------------------------\n\n");
	return;
}

void test_special_array_print() {
	printf("------------------------------\n");
	printf("Start: Testing special_array_print:\n\n");

	short *p = NULL;
	short array[10] = { 1, 13, 48, 91, 95, 74, 66, 12, 1, 14 };

	printf("Case 1: Error cases:\n");
	special_array_print(NULL, p);
	special_array_print(array, p);
	printf("\n");

	printf("Case 2:\n");
	p = &array[4];
	special_array_print(array, p);
	printf("\n");

	printf("Case 3:\n");
	array[0] = 13;
	array[1] = 1;
	array[8] = 10;
	array[7] = 1;
	p = &array[3];
	special_array_print(array, p);
	printf("\n");

	printf("Case 4:\n");
	array[0] = 1;
	array[1] = 21;
	array[5] = 1;
	array[7] = 13;
	p = &array[3];
	special_array_print(array, p);
	printf("\n");

	printf("Case 5:\n");
	p = &array[4];
	special_array_print(array, p);
	printf("\n");

	printf("Case 6:\n");
	p = &array[1];
	special_array_print(array, p);
	printf("\n");

	printf("Case 7:\n");
	array[2] = 1;
	p = &array[1];
	special_array_print(array, p);
	printf("\n");

	printf("End: Testing special_array_print\n");
	printf("------------------------------\n\n");
	return;
}

void print(int *array, const int size) {
	if (!array) {
		printf("NULL");
		return;
	}
	int i;
	printf("[");
	for (i = 0; i < size; i++) {
		printf("%d", array[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("]");
	return;
}

void print2(double *array, const int size) {
	if (!array) {
		printf("NULL");
		return;
	}
	int i;
	printf("[");
	for (i = 0; i < size; i++) {
		printf("%.2lf", array[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("]\n");
	return;
}

