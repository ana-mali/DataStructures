/**
 -------------------------
 CP264 (Fall 2021)
 Assignment: A2
 Matrix Source Code
 -------------------------
 **/

# include <stdio.h>
# include <stdlib.h>
# include "matrix.h"

/**
 * Parameters:  None
 * Return: 		void
 * Description:
 * 		initialize the master matrix to be an empty matrix
 * 		by making all elements = -1
 */
void initialize() {
	//since masterMatrix is global, it can be accessed here
	for (int i = 0; i < SIZE; i++) { 		//this loop is for rows
		for (int j = 0; j < SIZE; j++) { 	//this loop is for columns
			matrix[i][j] = -1; 	//set the element to -1
		} //end of second for loop
	} // end of first for loop
	return;
}
//---------------------------------------------------------------------
/**
 * Parameters:  None
 * Return: 		void
 * Description:
 * 		Another way to initialize the matrix
 * 		It simply calls initializeializeializeializeMatrix( )
 */
void clear() {
	initialize();
	return;
}

//----------------------------------------------------------------------
/**
 * Parameters:		r: number of rows (int)
 * 					c: number of columns (int)
 * Return:			void
 * Description:
 * 		print the sub-matrix rxc (r = rows, c = columns) from masterMatrix
 * 		if a value is -1, the symbol '-' is used in printing, indicating that it is empty
 *		Note: the actual matrix is not passed,
 *		instead the the given size is used to access elements in the global matrix
 */

void print(int r, int c) {
	//if values of r or c is out of range --> print error message and exist
	if ((r < 0 || c < 0) || (r > SIZE || c > SIZE)) {
		printf("Error(print): illegal matrix range");
		return;
	}

	for (int i = 0; i < r; i++) { 			//row loop
		for (int j = 0; j < c; j++) {			//column loop
			if (matrix[i][j] == -1) { // if empty slot --> print '-'
				printf("%-5s", "-");
			}  //end of if statement
			else {		//if non-empty slot --> print contents
				printf("%-5d", matrix[i][j]);
			} //end of else statement
		}	// end of column loops
		printf("\n"); //start a new line after end of each row
	} //end of row loops

	return;
}
//----------------------------------------------------------------------
/**
 * Parameters:		None
 * Return:			True(1)/False(0) [int]
 * Description:
 * 		check if global matrix is empty
 * 		if all elements in matrix == -1 --> empty (True)
 * 		otherwise --> not empty (False)
 */

int is_empty() {
	for (int i = 0; i < SIZE; i++) { 		//row loop
		for (int j = 0; j < SIZE; j++) {	//column loop
			if (matrix[i][j] != -1) {//if there is a single non-empty slot --> not empty
				return False;
			} // end of if statement
		} // end of column loop
	} //end of row loop

	return True; //all elements = -1 --> return True

}
//-----------------------------------------------------------------------
/**
 * Parameters:		r: row number (int)
 * 					c: column number (int)
 * Return			a matrix element (int)
 * Description:
 * 		 returns the masterMatrix element at position [r][c]
 * 		 returns -99 (errorCode) in case if r or c is out of range
 */

int get_element(int r, int c) {

	//if r or c is out of range --> return errorCode -99
	if ((r >= SIZE || c >= SIZE) || (r < 0 || c < 0)) {
		return errorCode; //-99
	}

	return matrix[r][c]; //return element
}

//----------------------------------------------------------------------
/**
 * Parameters:		r: row number (int)
 * 					c: column number (int)
 * 					value: (int)
 * Return			True(1)/False(0) [int]
 * Description:
 * 		 set element[r][c] in the masterMatrix to the given value
 * 		 returns True if correctly set, False otherwise
 */

int set_element(int r, int c, int value) {
	if ((r >= SIZE || c >= SIZE) || (r < 0 || c < 0)) {
		return False;
	}
	matrix[r][c] = value;
	return True;
}
//--------------------------------------------------------------------------
/**
 * Parameters:		r: row number  [0,SIZE-1] (int)
 * Return			row length [0,SIZE) (int)
 * Description:
 * 		 returns the number of consecutive non-negative integers for a given row
 * 		 starting from the first element
 * 		 if given row is out of range --> return errorCode -99
 * 		 Note that row length for any row in an empty matrix is 0
 */

int get_row_length(int r) {
	if (r >= SIZE || r < 0) {
		return errorCode;
	}

	int counter = 0;
	for (int i = 0; i < SIZE; i++) {
		if (matrix[r][i] == -1) {
			break;
		}
		counter++;
	}

	return counter;
}
//---------------------------------------------------------------------------
/**
 * Parameters:		int: column number (c) [0,SIZE-1]
 * Return			int: column length [0,SIZE)
 * Description:
 * 		 returns the number of consecutive non-negative integers for a given column
 * 		 starting from the first element
 * 		 if given column is out of range --> return errorCode -99
 * 		 Note that column length for any column in an empty matrix is 0
 */

int get_column_length(int c) {
	if (c >= SIZE || c < 0) {
		return errorCode;
	}

	int counter = 0;
	for (int i = 0; i < SIZE; i++) {
		if (matrix[i][c] == -1) {
			break;
		}
		counter++;
	}

	return counter;
}
//-------------------------------------------------------------------
/**
 * Parameters:		array (int[SIZE][SIZE])
 * Return			void
 * Description:
 * 		 copy contents of a given matrix into masterMatrix, element by element
 */
void copy(int b[SIZE][SIZE]) {
	int i, j; //loop variables

	for (i = 0; i < 10; i++) { //row loop
		for (j = 0; j < 10; j++) { //column loop
			set_element(i, j, b[i][j]);
		} //end of column loop
	} // end of row loop

	return;
}

//---------------------------------------------------------
/**
 * Parameters:		array (int[SIZE][SIZE])
 * Return			True(1)/False(0) [int]
 * Description:
 * 		check if a given matrix is equal to the current contents of global matrix
 * 		if equal --> return True(1)
 * 		if not equal --> return False (0)
 */

int is_equal(int b[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (matrix[i][j] != b[i][j]) {
				return False;
			}
		}
	}
	return True;
}
//-------------------------------------------------------------------
/**
 * Parameters:		None
 * Return			True(1)/False(0) [int]
 * Description:
 * 		returns True (1) if the masterMatrix represents only ONE vector,
 * 		either on the first row or the first column
 * 		The following rules apply:
 * 			1- An empty matrix is a valid vector []
 * 			2- If the first row contains one up to SIZE positive elements,
 * 			      while the remainder of the matrix == -1 --> valid vector
 * 			3- If the first column contains one up to SIZE positive elements,
 * 			      while the remainder of the matrix == -1 --> valid vector
 * 			4- The start of the vector is always element[0][0]
 */

int is_vector() {
	int i, j; //loop variables
	int r0, c0; //first row and first column lengths

	if (is_empty()) { //Rule #1 - empty matrix is a vector
		return True;
	}

	r0 = get_row_length(0); //get length of first row
	c0 = get_column_length(0); // get length of first column

	if (r0 == 0 && c0 == 0 && !is_empty()) { //vector has to start at [0][0]
		return False;				  //see Rule #4
	}

	//check for row vector
	if (r0 > 0 && c0 == 1) {
		//verify that all elements in the tail of the vector == -1
		for (i = r0; i < SIZE; i++) {
			if (matrix[0][i] != -1) {
				return False;
			}
		}
		//verify that all elements in the other rows == -1
		for (j = 1; j < SIZE; j++) {
			if (get_row_length(j) != 0) {
				return False;
			}
		}
	}

	else if (c0 >= 2) { //check for column vector
		//verify that all elements in the tail of the vector == -1
		for (i = c0; i < SIZE; i++) {
			if (matrix[i][0] != -1) {
				return False;
			}
		}
		//verify that all elements in the other column == -1
		for (j = 1; j < SIZE; j++) {
			if (get_column_length(j) != 0) {
				return False;
			}
		}
	}

	return True; //valid vector
}

/**
 * Parameters:		matrix of size 100 (int[100])
 * 					value (int)
 * Return			True(1)/False(0) [int]
 * Description:
 * 		Performs linear search to check if given value is found in the array
 * 		returns True if found and False otherwise
 */
int contains(int m[100], int value) {
	for (int i = 0; i < 100; i++) {
		if (value == m[i]) {
			return True; //found
		}
	}
	return False; //not found
}

//--------------------------------------------------------------------------
/**
 * Parameters:		None
 * return:			int: True(1)/False(0)
 * Description:
 * 		inspect the current contents of masterMatrix
 * 		return True if the contents represent a matrix
 * 		 	1- (is_empty() == 1) --> True
 * 			2- (is_vector() == 1) --> True
 * 			3- if the following conditions apply --> True
 * 				3.1- A matrix starts at element[0][0] (i.e. element[0][0]!=-1)
 * 				3.2- All elements within matrix are non-negative integers
 * 				3.3- All elements outside matrix are -1
 * 			4- Otherwise --> False
 */

int is_matrix() {
	int i, j; //loop variables
	int empty = is_empty();
	int vector = is_vector();
	int r0, c0; //row 0 and colunm 0 lengths

	if (empty || vector) {
		return True; //Rule#1 and Rule#2
	}

	if (!empty && matrix[0][0] == -1) {
		return False; //violation of Rule #3.1
	}

	//get Matrix dimensions
	r0 = get_row_length(0);
	c0 = get_column_length(0);

	//verify Rule#3.2
	int counter = 0;
	for (i = 0; i < c0; i++) {
		for (j = 0; j < r0; j++) {
			if (matrix[i][j] < 0) {
				return False; //violation of Rule #3.2
			}
			counter++;
		}
	}

	//verify Rule#3.3
	for (i = c0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (matrix[i][j] != -1) {
				return False;
			}
		}
	}
	for (i = 0; i < c0; i++) {
		for (j = r0; j < SIZE; j++) {
			if (matrix[i][j] != -1) {
				return False;
			}
		}
	}
	return True;
}

