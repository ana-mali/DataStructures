# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "A4.h"

void test_update_array();
void print_array(int*, const int);

void test_format_cities();
void test_format_str();
void test_multiples1();
void test_multiples2();

int main() {
	setbuf(stdout, NULL);
	test_update_array();
	test_format_cities();
	test_format_str();
	test_multiples1();
	test_multiples2();
	return 0;
}

void test_update_array() {
	int i, j, size = 0, multiplier = 0, *array = NULL;
	printf("--------------Testing update_array --------------\n\n");

	int cases[4][2] = { { 6, 2 }, { 4, 3 }, { 10, 1 }, { 5, 0 } };
	for (j = 0; j < 4; j++) {
		size = cases[j][0];
		multiplier = cases[j][1];
		printf("Case %d: size = %d, multiplier = %d\n", (j + 1), size,
				multiplier);
		array = (int*) malloc(sizeof(int) * (size));
		for (i = 0; i < size; i++)
			array[i] = (i + 1) * 10;
		printf("Array Before update:\n");
		print_array(array, size);
		update_array(&array, size, multiplier);
		printf("Array after update:\n");
		if (multiplier > 0)
			size = size * multiplier;
		print_array(array, size);
		free(array);
		printf("\n");
	}
	printf("--------------End of Testing update_array --------------\n\n");
	return;
}
void test_format_cities() {
	printf("------------------------------\n");
	printf("Start: Testing format_cities:\n\n");

	char cityList[3][MAX];
	int i;
	strcpy(cityList[0], "chicago");
	strcpy(cityList[1], "new york");
	strcpy(cityList[2], "las vegas");
	printf("Case 1:\n");
	printf("Cities before format: \n");
	for (i = 0; i < 3; i++)
		printf("\t%s\n", cityList[i]);
	format_cities(cityList, 3);
	printf("Cities after format: \n");
	for (i = 0; i < 3; i++)
		printf("\t%s\n", cityList[i]);
	printf("\n");

	char cityList2[5][MAX];
	strcpy(cityList2[0], "waterloo");
	strcpy(cityList2[1], "north bay");
	strcpy(cityList2[2], "");
	strcpy(cityList2[3], "thunder bay");
	strcpy(cityList2[4], "Sarnia");
	printf("Case 2:\n");
	printf("Cities before format: \n");
	for (i = 0; i < 5; i++)
		printf("\t%s\n", cityList2[i]);
	format_cities(cityList2, 5);
	printf("Cities after format: \n");
	for (i = 0; i < 5; i++)
		printf("\t%s\n", cityList2[i]);
	printf("\n");

	printf("Case 3:\n");
	format_cities(NULL, 5);
	format_cities(cityList2, 0);
	printf("\n");

	printf("End: Testing format_cities\n");
	printf("------------------------------\n\n");
	return;

}

void test_format_str() {

	printf("------------------------------\n");
	printf("Start: Testing format_str:\n");

	char input[2 * MAX] = "";
	char output[2 * MAX + 1] = "";

	printf("\nCase 0: Empty String:\n");
	printf("Before:\n\tinStr = %s\n\toutStr = %s\n", input, output);
	printf("Inside format_str function:\n");
	format_str(input, output);
	printf("After:\n\tinStr = %s\n\toutStr = %s\n", input, output);

	printf("\nCase 1: One Character:\n");
	strcpy(input, "a");
	strcpy(output, "");
	printf("Before:\n\tinStr = %s\n\toutStr = %s\n", input, output);
	printf("Inside format_str function:\n");
	format_str(input, output);
	printf("After:\n\tinStr = %s\n\toutStr = %s\n", input, output);

	printf("\nCase 2: Two Characters:\n");
	strcpy(input, "ab");
	strcpy(output, "");
	printf("Before:\n\tinStr = %s\n\toutStr = %s\n", input, output);
	printf("Inside format_str function:\n");
	format_str(input, output);
	printf("After:\n\tinStr = %s\n\toutStr = %s\n", input, output);

	printf("\nCase 3: Three Characters:\n");
	strcpy(input, "abc");
	strcpy(output, "");
	printf("Before:\n\tinStr = %s\n\toutStr = %s\n", input, output);
	printf("Inside format_str function:\n");
	format_str(input, output);
	printf("After:\n\tinStr = %s\n\toutStr = %s\n", input, output);

	printf("\nCase 4: Four Characters:\n");
	strcpy(input, "abcd");
	strcpy(output, "");
	printf("Before:\n\tinStr = %s\n\toutStr = %s\n", input, output);
	printf("Inside format_str function:\n");
	format_str(input, output);
	printf("After:\n\tinStr = %s\n\toutStr = %s\n", input, output);

	printf("\nCase 5: Seven Characters:\n");
	strcpy(input, "abcdefg");
	strcpy(output, "");
	printf("Before:\n\tinStr = %s\n\toutStr = %s\n", input, output);
	printf("Inside format_str function:\n");
	format_str(input, output);
	printf("After:\n\tinStr = %s\n\toutStr = %s\n", input, output);

	printf("\nCase 6: 19 Characters: \n");
	strcpy(input, "ABCDEFGHIJKLMNOPQRS");
	strcpy(output, "");
	printf("Before:\n\tinStr = %s\n\toutStr = %s\n", input, output);
	printf("Inside format_str function:\n");
	format_str(input, output);
	printf("After:\n\tinStr = %s\n\toutStr = %s\n", input, output);
	printf("\n");

	printf("End: Testing format_str\n");
	printf("------------------------------\n\n");
	return;
}
void test_multiples1() {
	printf("------------------------------\n");
	printf("Start: Testing get_multiples_array1:\n\n");

	int multiples1[3] = { 11, 14, 250 };
	int *ptr = NULL;
	ptr = get_multiples_array1(multiples1, 3);
	print_multiples1(ptr, 3);
	free(ptr);
	ptr = NULL;
	printf("\n");

	int multiples2[5] = { 3, 14, 25, 36, 47 };
	ptr = get_multiples_array1(multiples2, 5);
	print_multiples1(ptr, 5);
	free(ptr);
	ptr = NULL;
	printf("\n");

	int multiples3[1] = { 299 };
	ptr = get_multiples_array1(multiples3, 1);
	print_multiples1(ptr, 1);
	free(ptr);
	ptr = NULL;
	printf("\n");

	ptr = get_multiples_array1(NULL, 6);
	print_multiples1(ptr, 6);
	printf("\n");

	int multiples4[2] = { 1, 2 };
	ptr = get_multiples_array1(multiples4, 0);
	print_multiples1(multiples4, 0);
	printf("\n");

	printf("End: Testing get_multiples_array1\n");
	printf("------------------------------\n\n");
	return;
}

void test_multiples2() {
	printf("------------------------------\n");
	printf("Start: Testing get_multiples_array2:\n\n");

	int multiples1[3] = { 11, 14, 250 };
	int **ptr = NULL;
	ptr = get_multiples_array2(multiples1, 3);
	print_multiples2(ptr, 3);
	for (int i = 0; i < 3; i++)
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
	printf("\n");

	int multiples2[5] = { 3, 14, 25, 36, 47 };
	ptr = get_multiples_array2(multiples2, 5);
	print_multiples2(ptr, 5);
	for (int i = 0; i < 5; i++)
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
	printf("\n");

	int multiples3[1] = { 299 };
	ptr = get_multiples_array2(multiples3, 1);
	print_multiples2(ptr, 1);
	for (int i = 0; i < 1; i++)
		free(ptr[i]);
	free(ptr);
	ptr = NULL;
	printf("\n");

	ptr = get_multiples_array2(NULL, 6);
	print_multiples2(ptr, 6);
	printf("\n");

	int multiples4[2] = { 1, 2 };
	int *ptr1 = &multiples4[0], **ptr2 = &ptr1;
	ptr2 = get_multiples_array2(ptr1, 0);
	print_multiples2(ptr2, 0);
	printf("\n");

	printf("End: Testing get_multiples_array2\n");
	printf("------------------------------\n\n");
	return;

}

void print_array(int *array, const int size) {
	int i;
	printf("[ ");
	for (i = 0; i < size - 1; i++)
		printf("%d , ", array[i]);
	printf("%d ]\n", array[i]);
	return;
}
