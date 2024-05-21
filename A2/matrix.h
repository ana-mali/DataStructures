/**
 -------------------------
 CP264 (Fall 2021)
 Assignment: A2
 Matrix Header File
 -------------------------
 **/
#ifndef MATRIX_H_
#define MATRIX_H_

# define SIZE 10
# define True 1;
# define False 0;
# define errorCode -99;

int matrix[SIZE][SIZE]; //global variable to store matrix

void initialize();
void clear();
void print(int, int);

int set_element(int, int, int);
void copy(int[10][10]);

void print(int, int);

int is_equal(int[10][10]);
int get_row_length(int);
int get_column_length(int);
int get_element(int, int);
int contains(int[100], int);

int is_empty();
int is_vector();
int is_matrix();

#endif /* MATRIX_H_ */
