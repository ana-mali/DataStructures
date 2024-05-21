/**
 * -------------------------
 * Student Name:
 * Student ID:
 * Student email:
 * -------------------------
 */

# include <stdio.h>
# include <math.h>
# include "A3.h"

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of integers (int*)
 * 	  size: size of an array (const int)
 * 	  value: some value to search for in the array (int)
 * returns:
 * 	  ptr: pointer to some element in the array (int*)
 * Description:
 *    Searches for the "value" in the array and identifies the first occurrence
 *    There are four scenarios:
 *    	1- if value is found at the last element --> ptr should point to last element
 *    	2- if value is found at any other location --> ptr should point to the next element
 *    	3- if value is not found --> ptr should point to the first element
 *      4- if the array pointer is NULL or the size is invalid --> ptr point to NULL
 * -------------------------------------------------------------------
 */
int* find_next(int *array, const int size, int value) {
	int i, *result;
	if (array == NULL || size <= 0) {
		return NULL;
	} else {
		for (i = 0; i < size; i++) {
			if (array[i] == value) {
				if (i == size - 1) {
					result = &array[i];
					return result;
				} else {
					result = &array[i + 1];
					return result;
				}
			}
		}
	}
	result = &array[0];
	return result;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of unknown data type (void*)
 * 	  size: size of the array (const int)
 * 	  indx: array index of the element to increment (int)
 * 	  char: array mode which controls the data type of the array. Defined types:
 * 	  		'i': integer
 * 	  		'l': long
 * 	  		'f': float
 * 	  		'd': double
 * returns: no returns
 * Description:
 *    Increments the value of the element at array[indx]
 *    Prints the value before increment
 *    The function should handle arrays of types: integer, long, float and double
 *    Before incrementing the function should print the current value at array[indx]
 *    There are four error scenarios:
 *    	1- array pointer is NULL
 *    	2- invalid array size
 *    	3- invalid value for indx
 *      4- invalid mode
 *    Whenever an error is detected, an error msg is printed
 * -------------------------------------------------------------------
 */
void increment_element(void *array, const int size, int indx, char mode) {
	if (size < 0) {
		printf("Error(increment_element): invalid size\n");
		return;
	} else if (indx < 0 || indx >= size) {
		printf("Error(increment_element): invalid indx\n");
		return;
	} else if (array == NULL) {
		printf("Error(increment_element): NULL array\n");
		return;
	} else if (mode != 'i' && mode != 'l' && mode != 'f' && mode != 'd') {
		printf("Error(increment_element): invalid mode\n");
		return;
	} else {
		if (mode == 'i') {
			int *tmp = (int*) array;
			printf("Value before increment = %d\n", tmp[indx]);
			tmp[indx] = tmp[indx] + 1;
		} else if (mode == 'l') {
			long *tmp = (long*) array;
			printf("%lu\n", tmp[indx]);
			tmp[indx] = tmp[indx] + 1;
		} else if (mode == 'f') {
			float *tmp = (float*) array;
			printf("%f\n", tmp[indx]);
			tmp[indx] = tmp[indx] + 1;
		} else {
			double *tmp = (double*) array;
			printf("%lf\n", tmp[indx]);
			tmp[indx] = tmp[indx] + 1;
		}
	}
	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of integers (int*)
 * 	  size: size of an array (const int)
 * 	  ptr:  double pointer to store location of average element
 * returns:
 * 	  no returns
 * Description:
 *    1- Finds the average of the values within the array and print it to the console.
 *    	Use 1 decimal point.
 *    2- The average is "ceiled", i.e. rounded to the upper integer value.
 *    3- Search the array for an element that is equal to the average,
 *      	and sets avg_pointer to that element
 *    	If there are multiple values equal to the average, a pointer to the
 *      	first element that equals to average is used
 *    	If no value is equal to the average, a pointer to the value
 *      	closest to the average is returned.
 *    4- prints an error message if
 *    		array pointer is NULL, invalid size or avg_ptr is NULL
 * -------------------------------------------------------------------
 */
void find_avg_element(int *array, const int size, int **avg_ptr) {
	int i, idx = 0;
	double total, avg;
	if (array == NULL) {
		printf("Error(find_avg_element): NULL pointer\n");
		return;
	} else if (size <= 0) {
		printf("Error(find_avg_element): invalid array size\n");
		return;
	} else if (avg_ptr == NULL) {
		printf("Error(find_avg_element): invalid pointer\n");
		return;
	} else {
		for (i = 0; i < size; i++) {
			total = total + array[i];
		}
		avg = total / (double) size;
		printf("Average = %.1lf\n", avg);
		double distance = 100000000000;
		for (i = 0; i < size; i++) {
			double cdistance = abs((double) array[i] - ceil(avg));
			if (cdistance < distance) {
				idx = i;
				distance = cdistance;
			}
		}
	}
	*avg_ptr = &array[idx];
	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of floats (float*)
 * 	  ptrs: an array of float pointers (float* [])
 * returns:
 * 	  No returns
 * Description:
 * 	  An array of float items is passed. The size of the array is unknown
 *    The pointer array stores some pointers to elements in the array
 *	  The size of the pointer array is unknown, but the maximum possible size is MAX
 *	  When iterating through the pointer array, if you encounter a NULL, then this is the end
 *    Access the pointer array to print the following:
 *    1-	The value of the element it points to
 *    2-	The index of that element in the array
 *    3-	The value of the previous element
 *    			If the pointer points to the first element, previous value is 0
 *    Assume that both array and ptrs are not NULL
 *    All printing follow a format space of 13 digits, and 2 decimal places
 * -------------------------------------------------------------------
 */
void print_ptr_array(double *array, double *ptrs[]) {
	printf("Value        Index        Previous\n");
	int i, j, p_i;
	double prev;
	for (i = 0; i < MAX; i++) {
		if (ptrs[i] == NULL) {
			break;
		} else {
			double val = *ptrs[i];
			printf("%-13.2f", *ptrs[i]);
			for (j = 0; j < MAX; j++) {
				if (&array[j] == NULL) {
					break;
				}
				if (array[j] == val) {
					if (j == 0) {
						prev = 0.00;
						p_i = j;
					} else {
						prev = array[j - 1];
						p_i = j - 1;
					}
					printf("%-13d", j);
					printf("%-13.2f", prev);
					printf("\n");
					break;
				}

			}
		}
	}

	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of shorts (short*)
 * 	  ptr: a pointer to an item in the array (short*)
 * returns:
 * 	  No returns
 * Description:
 * 	  An array of shorts is given, and you do not know its size
 * 	  However, you know the following about the array:
 * 	  	1- the minimum length is 3 items
 * 	  	2- The first element has a value of 1
 * 	  	3- The last element has a value of 1
 *    You are given some pointer to an element in the array.
 *    The pointer points to some item other than the first and last items
 *	  Your job is to print all the items in the array in the following format:
 *	  	[items before pointer]-->[items after pointer]
 *	  The printing ignores the first and last items which have the value of 1
 *    The function should print an error message if the array or the pointer is NULL
 * -------------------------------------------------------------------
 */
void special_array_print(short *array, short *ptr) {
	if (array == NULL) {
		printf("Error(special_array_print): NULL pointer\n");
	} else if (ptr == NULL) {
		printf("Error(special_array_print): invalid pointer\n");
	} else {
		int i, break_point = ptr - array, first = 0, last = 0;
		for (i = 0; i < break_point; i++) {
			if (array[i] == 1) {
				first = i;
				break;
			}
		}
		for (i = break_point; i < MAX; i++) {
			if (array[i] == 1) {
				last = i;
				break;
			}
		}
		printf("[");
		for (i = first + 1; i < break_point; i++) {
			if (i != first + 1)
				printf(", ");
			printf("%i", array[i]);
		}
		printf("]-->[");
		for (i = break_point + 1; i < last; i++) {
			if (i != break_point + 1) {
				printf(", ");
			}
			printf("%i", array[i]);
		}
		printf("]\n");

	}
	return;
}
