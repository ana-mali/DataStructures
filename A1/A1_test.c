#include <stdio.h>
#include "A1.h"

void test_compute();
void test_prints();
void test_get_code();
void test_print_description();
void test_math_game();

int main(){
	setbuf(stdout,NULL);
	test_compute();
	test_prints();
	test_get_code();
	test_print_description();
	test_math_game();
	return 0;
}

void test_compute(){
	printf("------------------------------\n");
	printf("Start: Testing compute:\n\n");

	double r;
	r = compute(11.4,127.245,66.7991);
	printf("r = %.3lf\n",r);
	printf("\n");

	r = compute(92.34, 29.01, 142.863);
	printf("r = %.3lf\n",r);
	printf("\n");

	printf("End: Testing compute\n");
	printf("------------------------------\n\n");
	return;
}

void test_prints(){
	printf("------------------------------\n");
	printf("Start: Testing print_country, print_color and print_size:\n\n");

	short cases[7]={0,1,2,3,4,5,6};
	int success, i;

	printf("Testing print_country:\n");
	for(i=0;i<4;i++){
		printf("print_country(%hi) = ",cases[i]);
		success = print_country(cases[i]);
		printf(", success = %d\n",success);
	}
	printf("\n");

	printf("Testing print_color:\n");
	for(i=0;i<7;i++){
		printf("print_color(%hi) = ",cases[i]);
		success = print_color(cases[i]);
		printf(", success = %d\n",success);
	}
	printf("\n");

	printf("Testing print_size:\n");
	for(i=0;i<6;i++){
		printf("print_size(%hi) = ",cases[i]);
		success = print_size(cases[i]);
		printf(", success = %d\n",success);
	}
	printf("\n");

	printf("End: Testing print_country, print_color and print_size\n");
	printf("------------------------------\n\n");
	return;
}

void test_get_code(){
	printf("------------------------------\n");
	printf("Start: Testing get_code:\n\n");

	long serial_number[4]={210653,101349, 13577, 6248910};
	char types[5] = {'y','r','s','i','m'};
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<5;j++)
			printf("get_code(%ld,%c) = %hd\n",serial_number[i],
					types[j],get_code(serial_number[i],types[j]));
		printf("\n");
	}
	printf("End: Testing get_code\n");
	printf("------------------------------\n\n");
	return;
}

void test_print_description(){
	printf("------------------------------\n");
	printf("Start: Testing print_description:\n\n");

	int i;
	long serial_number[10]={210653, 141349, 322459, 237903, 188140, 398225, 283767,
			494660, 556103, 13577};

	for (i=0;i<10;i++){
		printf("Serial number = %ld\n",serial_number[i]);
		print_description(serial_number[i]);
		printf("\n");
	}

	printf("End: Testing print_description\n");
	printf("------------------------------\n\n");
	return;
}

void test_math_game(){
	printf("------------------------------\n");
	printf("Start: Testing math_game:\n\n");
	char winner;

    int cases[3][8] = {{10, -1, 30, 4, 20, 2, 40, 3},
    		{10, 2, -30, 2, 18, 5, 50, 3},
			{10, 2, -30, 2, 1800, 1, -100, 5}
    };

    for(int i=0;i<3;i++){
        winner = math_game(cases[i][0],cases[i][1],cases[i][2],cases[i][3],
        		cases[i][4],cases[i][5],cases[i][6],cases[i][7]);
        printf("Winner is: %c\n\n",winner);
    }
	printf("End: Testing math_game\n");
	printf("------------------------------\n\n");
	return;
}
