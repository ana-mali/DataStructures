/*
 * ---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>
# include "A4.h"

//-------------------------Task 1 ----------------------------
void update_array(int **array, const int size, int multiplier) {
	int temp, x = 0;
	int *arr; //[size * multiplier];
	arr = (int*) malloc(sizeof(int) * size * multiplier);
	if (multiplier == 1) {
		return;
	} else if (multiplier < 1) {
		printf("Error (update_array): invalid multiplier\n");
		return;
	} else {
		for (int i = 0; i < size; i++) {
			temp = (*array)[i];
			for (int j = 0; j < multiplier; j++) {
				arr[x] = temp;
				x++;
			}
		}
	}
//	for (int i = 0; i < (size * multiplier); i++)
//		(*array)[i] = arr[i];
	free(*array);
	*array = arr;
	return;
}

//-------------------------Task 2 ----------------------------
void format_city(char *city) {
	int i, j, count = 0;
	int len = strlen(city);
	if (islower(city[0])) {
		city[0] = toupper(city[0]);
	}
	for (i = 0; i < len; i++) {
		if (!isalpha(city[i]))
			if (isspace(city[i])) {
				city[i + 1] = toupper(city[i + 1]);
			}
	}
	for (i = 0; i < len; i++) {
		if (isspace(city[i])) {
			count++;
			for (j = i + 1; j < len; j++) {
				city[j - 1] = city[j];
			}
		}
	}
	city[len - count] = '\0';
	return;
}

void format_cities(char city_array[][MAX], const int size) {
	int i;
	char *city;
	if (city_array == NULL) {
		printf("Error(format_cities): array is NULL");
		return;
	} else if (size < 0) {
		printf("Error(format_cities): invalid size");
		return;
	}
	for (i = 0; i < size; i++) {
		city = city_array[i];
		format_city(city);
	}
	return;
}

//-------------------------Task 3 ----------------------------

void format_str(const char *inStr, char *outStr) {
	int length = strlen(inStr), i, temp;
	for (i = 0; i < length; i++) {
		if (i == 0 || i == length - 1) {
			outStr[i] = inStr[i];
		} else {
			outStr[i] = toupper(inStr[i]);
		}
	}
	printf("String Length = %d\n", length);
	printf("After middle caps = %s\n", outStr);
	int mid = length / 2, left = 1;
	temp = outStr[mid];
	outStr[mid] = ' ';
	for (i = mid + 1; i <= length; i++) {
		char x = outStr[i];
		outStr[i] = temp;
		temp = x;
	}

	printf("After split = %s\n", outStr);
	char s, e;
	for (i = 0; i < mid / 2; i++) {
		s = outStr[i];
		outStr[i] = outStr[mid - i - 1];
		outStr[mid - i - 1] = s;

	}
//	for (i = 1; i < mid; i++) {
//		s = outStr[i - 1];
//		e = outStr[mid - i];
//		outStr[i - 1] = e;
//		outStr[mid - i] = s;
//	}
	printf("After First half reverse = %s\n", outStr);
	char *o1 = &outStr[mid + 1];
	int n = strlen(o1);
	for (i = 0; i < n / 2; i++) {
		e = o1[i];
		o1[i] = o1[n - i - 1];
		o1[n - i - 1] = e;
	}
	printf("After Second half reverse = %s\n", outStr);
	return;
}

//-------------------------Task 4 ----------------------------

int* get_multiples_array1(int *multiples, const int size) {
	if (multiples == NULL) {
		printf("Error(get_multiples_array1): invalid array\n");
		return NULL;
	}
	if (size <= 0) {
		printf("Error(get_multiples_array1): invalid size\n");
		return NULL;
	}
	int r, c = 10, i, j, temp;
	int **ptr = (int*) malloc(size * sizeof(int));
	r = size;
	for (i = 0; i < r; i++)
		ptr[i] = (int*) malloc(c * sizeof(int));
	for (i = 0; i < r; i++) {
		temp = multiples[i];
		for (j = 0; j < c; j++) {
			if (temp + (temp * j) >= 1000)
				ptr[i][j] = 0;
			else
				ptr[i][j] = temp + (temp * j);
		}
	}
	return ptr;
}

void print_multiples1(int *array, const int size) {
	if (array == NULL) {
		printf("Error(print_multiples1): invalid array\n");
		return;
	}
	if (size <= 0) {
		printf("Error(print_multiples1): invalid size\n");
		return;
	}
	int **ptr = array;
	int i, j, r, c = 10;
	r = size;
	for (i = 0; i < r; i++) {
		if (i != 0)
			printf("\n");
		for (j = 0; j < c; j++) {
			printf("%4d", ptr[i][j]);
		}
	}
	printf("\n");
	return;
}

//-------------------------Task 5 ----------------------------
int** get_multiples_array2(int *multiples, const int size) {
	if (multiples == NULL) {
		printf("Error(get_multiples_array2): invalid array\n");
		return NULL;
	}
	if (size <= 0) {
		printf("Error(get_multiples_array2): invalid size\n");
		return NULL;
	}
	int r = size, c = 10, i, j, temp;
	int **arr = (int**) malloc(r * sizeof(int*));
	for (i = 0; i < r; i++)
		arr[i] = (int*) malloc(c * sizeof(int));
	for (i = 0; i < r; i++) {
		temp = multiples[i];
		for (j = 0; j < c; j++) {
			if (temp + (temp * j) >= 1000)
				arr[i][j] = 0;
			else
				arr[i][j] = temp + (temp * j);
		}
	}
	return arr;
}

void print_multiples2(int **array, const int size) {
	if (array == NULL) {
		printf("Error(print_multiples2): invalid array\n");
		return;
	}
	if (size <= 0) {
		printf("Error(print_multiples2): invalid size\n");
		return;
	}
	int i, j, r = size, c = 10;
	for (i = 0; i < r; i++) {
		if (i != 0) {
			printf("\n");
		}
		for (j = 0; j < c; j++) {
			printf("%4d", array[i][j]);
		}
	}
	printf("\n");
	return;
}
