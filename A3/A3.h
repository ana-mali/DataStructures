/**
 -------------------------
 CP264 (Spring 2020)
 Assignment: A3
 Header File
 -------------------------
 **/

#ifndef A3_H_
#define A3_H_

# define MAX 10

int* find_next(int* array, const int size, int value);
void increment_element(void* array, const int size, int indx, char mode);
void find_avg_element(int *array, const int size, int** avg_ptr);
void print_ptr_array(double *array, double *ptrs[]);
void special_array_print(short* array, short* ptr);

#endif /* A3_H_ */
