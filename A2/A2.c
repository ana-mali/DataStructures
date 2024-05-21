/**
 * -------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student email: mali4700@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include "matrix.h"

//----------- Task 1: Matrix Checkers ------------

int _is_square() {
	return get_column_length == get_row_length;
}
/**
 * ----------------------------------------------------------------
 * Parameters:		no parameters
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid identity matrix
 * 		An identity matrix is a square matrix, all diagonal elements equal to 1,
 * 			all other elements are equal to 0
 * 		An empty matrix is NOT an identity matrix
 * ----------------------------------------------------------------
 */
int is_identity() {
	int r, c, row, col;
	row = get_row_length(0);
	col = get_column_length(0);
	if (is_empty())
		return 0;
	else
		for (r = 0; r < row; r++) {
			for (c = 0; c < col; c++) {
				if (c == r) {
					if (1 != get_element(r, c)) {
						return 0;
					}
				} else {
					if (get_element(r, c) != 0) {
						return 0;
					}

				}

			}
		}
	return 1;
}

/**
 * ----------------------------------------------------------------
 * Parameters:		no parameters
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid unique matrix
 * 		A unique matrix is a matrix in which all elements have unique values
 * 			i.e. no two elements have equal value
 * 		An empty matrix is NOT a unique matrix
 * ----------------------------------------------------------------
 */
int is_unique() {
	int c, r, count = 0, i, val, row, col;
	row = get_column_length(0);
	col = get_row_length(0);
	int dupl[row * col];
	if (is_empty()) {
		return 0;
	}

	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) {
			val = get_element(r, c);

			for (i = 0; i < count; i++) {
				if (val == dupl[i]) {
					return 0;
				}
			}
			dupl[count] = val;
			count++;
		}
	}
	return 1;

}

/**
 * ----------------------------------------------------------------
 * Parameters:		no parameters
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid uniform matrix
 * 		A uniform matrix is a matrix in which all elements are equal
 * 		An empty matrix is NOT a uniform matrix
 * ----------------------------------------------------------------
 */
int is_uniform() {
	int r, c, val;
	val = get_element(0, 0);
	int row, col;
	row = get_column_length(0);
	col = get_row_length(0);
	if (is_empty()) {
		return 0;
	}
	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) {
			if (val != get_element(r, c)) {
				return 0;
			}
		}
	}

	return 1;
}

//----------- Task 2: Matrix Classifier ------------

/**
 * ----------------------------------------------------------------
 * Parameters:		mode(char): s = size, c = content
 * return:			type(int)
 * Description:
 * 		inspect the current contents of matrix
 * 		Returns the classification of the matrix
 * 		General classification (works for both modes):
 * 			-1: not matrix
 * 			 0: empty matrix
 * 		Matrix classification by size:
 * 			 1: vector
 * 			 2: square
 * 			 3: rectangle
 * 		Matrix classification by content:
 * 			 1: identity
 * 			 2: unique
 * 			 3: uniform
 * 			 4: undefined
 * Errors:	 		invalid mode
 * ----------------------------------------------------------------
 */
int classify_matrix(char mode) {
	int row, col;
	if (!is_matrix()) {
		return -1;
	}
	if (is_empty()) {
		return 0;
	}
	if (mode == 's') {
		row = get_column_length(0);
		col = get_row_length(0);
		if (row == 1 || col == 1) {
			return 1;
		}
		if (row == col) {
			return 2;
		}
		if (row > col || col > row) {
			return 3;
		}
	} else if (mode == 'c') {
		if (is_identity()) {
			return 1;
		} else if (is_unique()) {
			return 2;
		} else if (is_uniform()) {
			return 3;
		}
	}
	return 4;
}

/**
 * ----------------------------------------------------------------
 * Parameters:	no parameters
 * return:		no returns
 * Description:
 * 		prints classification of the matrix based on current values
 * 		classification includes both size and content
 * 		see sample output for format
 * Errors:	 	invalid mode
 * ----------------------------------------------------------------
 */
void print_matrix_classification() {
	int si = classify_matrix('s');
	int co = classify_matrix('c');
	if (si == -1 && co == -1) {
		printf("invalid mtatrix\n");
	} else if (si == 0 && co == 0) {
		printf("empty matrix");
	} else if (si == 1 && co == 1) {
		printf("identity vector matrix\n");
	} else if (si == 1 && co == 2) {
		printf("unique vector matrix\n");
	} else if (si == 1 && co == 3) {
		printf("uniform vector matrix\n");
	} else if (si == 1 && co == 4) {
		printf("undefined vector matrix\n");
	} else if (si == 2 && co == 1) {
		printf("identity square matrix\n");
	} else if (si == 2 && co == 2) {
		printf("unique sqaure matrix\n");
	} else if (si == 2 && co == 3) {
		printf("uniform square matrix\n");
	} else if (si == 2 && co == 4) {
		printf("undefined square matrix\n");
	} else if (si == 3 && co == 1) {
		printf("identity rectangle matrix\n");
	} else if (si == 3 && co == 2) {
		printf("unique rectangle matrix\n");
	} else if (si == 3 && co == 3) {
		printf("uniform rectangle matrix\n");
	} else if (si == 3 && co == 4) {
		printf("undefined rectangle matrix\n");
	}
	return;
}
//----------- Task 3: Triangular Matrix  ------------
/**
 * ----------------------------------------------------------------
 * Parameters:	length(int): square side length
 * 				corner(char): 'T'= top corner, 'B' = bottom corner
 * 				side(char): 'L' = left side, 'R' = right side
 * 				fill(int): number to fill the matrix with
 * return:		no returns
 * Description:
 * 		Initialize a matrix then fill it in a triangular manner
 * 		The corner and side determine the position of the triangle right angle
 * 		All cells in the triangle are set to "fill", and the other cells to 0
 * Errors: 		invalid length, invalid corner, invalid side
 * ----------------------------------------------------------------
 */
void fill_triangle(int length, char corner, char side, int fill) {
	initialize();
	int r, c;
	if (length <= 0 || length > 10) {
		printf("Error(fill_triangle): invalid length\n");
		return;
	}
	for (r = 0; r < length; r++) {
		for (c = 0; c < length; c++) {
			if (side == 'R') {
				if (corner == 'T') {
					if (r <= c) {
						set_element(r, c, fill);
					} else {
						set_element(r, c, 0);
					}
				} else if (corner == 'B') {
					if (r >= c) {
						set_element(r, length - c - 1, fill);
					} else {
						set_element(r, length - c - 1, 0);
					}
				} else {
					printf("Error(fill_triangle): invalid corner\n");
					return;
				}
			} else if (side == 'L') {
				if (corner == 'B') {
					if (r >= c) {
						set_element(r, c, fill);
					} else {
						set_element(r, c, 0);
					}
				} else if (corner == 'T') {
					if (r <= c) {
						set_element(r, length - c - 1, fill);
					} else {
						set_element(r, length - c - 1, 0);
					}
				} else {
					printf("Error(fill_triangle): invalid corner\n");
					return;
				}
			} else {
				printf("Error(fill_triangle): invalid side\n");
				return;
			}
		}
	}
	return;
}
//----------- Task 4: Flip Matrix  ------------
/**
 * ----------------------------------------------------------------
 * Parameters:	mode(char): 'h': horizontal, 'v': vertical
 * return:		no returns
 * Description:
 * 		flips the contents of the global matrix
 * 		For horizontal flip, the first row is swapped with the last row
 * 			the second row is swapped with the second to last row, and so forth
 * 		For vertical flip, the first column is swapped with the last column
 * 			the second column is swapped with the second to last column, and so forth
 * Errors: 	invalid mode, invalid matrix
 * ----------------------------------------------------------------
 */

void flip(char mode) {
	int r, c, row, col, v1, v2;
	row = get_column_length(0);
	col = get_row_length(0);
	if (!is_matrix()) {
		printf("Error(flip): invalid matrix\n");
		return;
	}
	if (mode == 'h') {
		for (r = 0; r < row / 2; r++) {
			for (c = 0; c < col; c++) {
				v1 = get_element(r, c);
				v2 = get_element(row - r - 1, c);
				set_element(r, c, v2);
				set_element(row - r - 1, c, v1);
			}
		}
	} else if (mode == 'v') {
		for (r = 0; r < row; r++) {
			for (c = 0; c < col / 2; c++) {
				v1 = get_element(r, c);
				v2 = get_element(r, col - c - 1);
				set_element(r, c, v2);
				set_element(r, col - c - 1, v1);
			}
		}

	} else {
		printf("Error(flip): invalid mode\n");
		return;
	}
	return;
}
