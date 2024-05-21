#ifndef A4_H_
#define A4_H_

# define MAX 25
# define NUM 10

void update_array(int** array, const int size, int multiplier);

void format_city(char *city);
void format_cities(char city_array[][MAX], const int size);

void format_str(const char *inStr, char *outStr);

void print_multiples1(int *array, const int size);
void print_multiples2(int **array, const int size);
int* get_multiples_array1(int *multiples, const int size);
int** get_multiples_array2(int *multiples, const int size);

#endif /* A4_H_ */
