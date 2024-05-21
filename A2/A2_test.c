/**
 -------------------------
 CP264 (Fall 2021)
 Assignment: A2
 Testing File
 -------------------------
 **/
# include <stdio.h>
# include "A2.h"
# include "matrix.h"
# define SIZE 10

void test_task1();
void test_task2();
void test_task3();
void test_task4();

void test_is_identity();
void test_is_uniform();
void test_is_unique();

//-------------------------------------------------------------------
int main() {

	setbuf(stdout, NULL);
	test_task1();
	test_task2();
	test_task3();
	test_task4();
	return 0;
}

//-------------------------------------------------------------------------
// some matrices for testing

//Matrix (a) is a valid matrix with numbers 1 to 10
int a[10][10] = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8,
		9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9,
		10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, {
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } };

//Matrix (s3) is a valid square and symmetric matrix of size 3x3
int s3[10][10] = { { 1, 7, 3, -1, -1, -1, -1, -1, -1, -1 }, { 7, 4, 8, -1, -1,
		-1, -1, -1, -1, -1 }, { 3, 8, 6, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

//Matrix (i2) is a valid square and identity matrix of size 2x2
int i2[10][10] = { { 1, 0, -1, -1, -1, -1, -1, -1, -1, -1 }, { 0, 1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, {
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1 }, };

//Matrix (i3) is a valid square and identity matrix of size 2x2
int i3[10][10] = { { 1, 0, 0, -1, -1, -1, -1, -1, -1, -1 }, { 0, 1, 0, -1, -1,
		-1, -1, -1, -1, -1 }, { 0, 0, 1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

//Matrix (vr) is a valid vector matrix of size 1x8
int vr[10][10] = { { 1, 2, 3, 4, 5, 6, 7, 8, -1, -1 }, { -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

//Matrix (vc) is a valid column matrix of size 10x1
int vc[10][10] = { { 1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 2, -1, -1, -1,
		-1, -1, -1, -1, -1, -1 }, { 3, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, {
		4, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 5, -1, -1, -1, -1, -1, -1,
		-1, -1, -1 }, { 6, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 7, -1, -1,
		-1, -1, -1, -1, -1, -1, -1 }, { 8, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 9, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 10, -1, -1, -1, -1, -1, -1,
				-1, -1, -1 }, };

//Matrix (vx) represent an invalid row vector
int vx[10][10] = { { -1, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };



void test_task1(){
	printf("------------------------------\n");
	printf("Testing Task 1:\n\n");

	test_is_identity();
	test_is_unique();
	test_is_uniform();

	printf("End of Task 1 Testing\n\n");
	printf("------------------------------\n");
	return;
}

void test_task2(){
	printf("------------------------------\n");
	printf("Testing Task 2:\n\n");

	int type1, type2, i;

	for(i=0;i<13;i++){
		printf("Case %d:\n",i);
		clear();
		if (i==0)
			matrix[1][1] = 10;
		if (i==2)
			matrix[0][0] = 1;
		else if (i == 3){
			set_element(0, 0, 8); set_element(0, 1, 6);
			set_element(0, 2, 4); set_element(0, 3, 2);
		}
		else if(i == 4){
			set_element(0, 0, 5);
			set_element(1, 0, 5);
			set_element(2, 0, 5);
		}
		else if(i == 5){
			set_element(0, 0, 14); set_element(0, 1, 15);
			set_element(0, 2, -3); set_element(0, 3, 15);
		}
		else if (i == 6)
			copy(i3);
		else if (i == 7){
			set_element(0,0,6); set_element(0,1,6); set_element(0,2,6);
			set_element(1,0,6); set_element(1,1,6); set_element(1,2,6);
			set_element(2,0,6); set_element(2,1,6); set_element(2,2,6);
		}
		else if(i == 8){
			set_element(0, 0, 14); set_element(0, 1, 15);
			set_element(1, 0, 24); set_element(1, 1, 25);
		}
		else if (i == 9){
			copy(i3);
			set_element(2, 2, 2);
		}
		else if(i == 10){
			set_element(0,0,5); set_element(0,1,5); set_element(0,2,5);
			set_element(1,0,5); set_element(1,1,5); set_element(1,2,5);
			set_element(2,0,5); set_element(2,1,5); set_element(2,2,5);
			set_element(3,0,5); set_element(3,1,5); set_element(3,2,5);
		}
		else if(i == 11){
			set_element(0,0,5); set_element(0,1,6); set_element(0,2,7);
			set_element(1,0,1); set_element(1,1,3); set_element(1,2,4);
		}
		else if(i == 12){
			set_element(0,0,5); set_element(0,1,6); set_element(0,2,7);
			set_element(1,0,1); set_element(1,1,3); set_element(1,2,7);
		}
		type1 = classify_matrix('s');
		type2 = classify_matrix('c');
		print(5,5);
		printf("Classification by size = %d\n",type1);
		printf("Classification by content = %d\n",type2);
		print_matrix_classification();
		printf("\n");
	}

	printf("End of Task 2 Testing\n\n");
	printf("------------------------------\n");
	return;
}

void test_task3(){
	printf("------------------------------\n");
	printf("Testing Task 3: fill_triangle\n\n");

	//error cases
	printf("Error cases:\n");
	fill_triangle(0,'T','L',5);
	fill_triangle(11,'T','L',5);
	fill_triangle(5,'R','L',5);
	fill_triangle(5,'B','M',5);
	printf("\n");

	int lengths[10] = {2,3,4,5,6,7,8,9};
	char corners[10] = {'T','T','T','T','B','B','B','B'};
	char sides[10] = {'L','L','R','R','L','L','R','R'};
	int fills[10] = {10,5,2,-6,1,7,3,4};
	for (int i=0;i<8;i++){
		printf("fill_triangle(%d,%c,%c,%d):\n",lengths[i],corners[i],sides[i],fills[i]);
		fill_triangle(lengths[i],corners[i],sides[i],fills[i]);
		print(lengths[i],lengths[i]);
		printf("\n");
	}

	printf("End of Task 3 Testing\n\n");
	printf("------------------------------\n");
	return;
}

void test_task4(){
	printf("------------------------------\n");
	printf("Testing Task 4: flip\n\n");

	int i;
	int r[10] = {3,4,3,10,10,10,10};
	int c[10] = {3,4,3,10,10,10,10};
	for(i=0;i<7;i++){
		printf("Case %d:\n",i);
		clear();
		if(i== 0)
			set_element(1,1,0);
		if(i == 2)
			copy(i3);
		if(i == 3)
			copy(a);
		if(i == 4)
			copy(vc);
		if(i == 5)
			copy(vr);
		if(i == 6)
			copy(s3);
		printf("Before:\n");
		print(r[i],c[i]);
		flip('h');
		printf("Flip horizontal:\n");
		print(r[i],c[i]);
		flip('v');
		printf("Flip vertical:\n");
		print(r[i],c[i]);
		printf("\n");
	}

	printf("End of Task 4 Testing\n\n");
	printf("------------------------------\n");
	return;
}
void test_is_identity() {
	printf("------------------------------\n");
	printf("Testing is_identity\n");
	printf("------------------------------\n\n");

	printf("Case 1: Empty Matrix:\n");
	printf("create Empty Matrix\n");
	clear();
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("Case 2: I1:\n");
	printf("set first element to 1\n");
	set_element(0, 0, 1);
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("Case 3: invalid I1:\n");
	printf("set first element to 0\n");
	set_element(0, 0, 0);
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("Case 4: I2:\n");
	printf("use global matrix (i2)\n");
	copy(i2);
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("Case 5: I3:\n");
	printf("use global matrix (i3)\n");
	copy(i3);
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("Case 6: invalid I3:\n");
	printf("Modify last identity matrix\n");
	set_element(2, 2, 2);
	print(SIZE, SIZE);
	printf("is_identity = %d\n\n", is_identity());

	printf("\n");
	return;
}

void test_is_uniform() {
	printf("------------------------------\n");
	printf("Testing is_uniform\n");
	printf("------------------------------\n\n");

	printf("Case 1: Empty Matrix:\n");
	clear();
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 2: Single Element Matrix:\n");
	set_element(0, 0, 5);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 3: Uniform Vector:\n");
	set_element(0, 1, 5);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 4: Invalid Matrix:\n");
	set_element(1, 0, 5);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 5: Uniform Square Matrix 2x2\n");
	set_element(1, 1, 5);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 6: Uniform non-square Matrix 2x3\n");
	set_element(0, 2, 5);
	set_element(1, 2, 5);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	printf("Case 7: Non uniform 2x3 matrix\n");
	set_element(0, 2, 8);
	print(SIZE, SIZE);
	printf("is_uniform = %d\n\n", is_uniform());

	return;
}

void test_is_unique() {
	printf("------------------------------\n");
	printf("Testing is_unique\n");
	printf("------------------------------\n\n");

	printf("Case 1: Empty Matrix:\n");
	clear();
	print(SIZE, SIZE);
	printf("is_unique = %d\n\n", is_unique());

	printf("Case 2: Single Element Matrix:\n");
	set_element(0, 0, 8);
	print(SIZE, SIZE);
	printf("is_unique = %d\n\n", is_unique());

	printf("Case 3: Unique Vector:\n");
	set_element(0, 1, 6);
	set_element(0, 2, 4);
	set_element(0, 3, 2);
	print(SIZE, SIZE);
	printf("is_unique = %d\n\n", is_unique());

	printf("Case 4: Non-unique Vector:\n");
	set_element(0, 4, 8);
	print(SIZE, SIZE);
	printf("is_unique = %d\n\n", is_unique());

	printf("Case 5: Invalid Matrix:\n");
	set_element(1, 0, 5);
	print(SIZE, SIZE);
	printf("is_unique = %d\n", is_unique());
	printf("--------------------\n\n");

	printf("Case 6: Full Unique Matrix:\n");
	int counter = 1;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			set_element(i, j, counter++);
	print(SIZE, SIZE);
	printf("is_unique = %d\n\n", is_unique());

	printf("Case 7: Full Non-Unique Matrix:\n");
	set_element(1, 9, 100);
	print(SIZE, SIZE);
	printf("is_unique = %d\n", is_unique());

	printf("\n");
	return;
}
