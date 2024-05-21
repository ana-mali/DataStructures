/**
 * -------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student email: mali4700@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include <math.h>

double compute(double n, double p, double q) {
	double r, exp1, exp2, exp3;
	printf("n = %f\np = %f\nq = %f\n", n, p, q);
	exp1 = (double) abs(n + p) / (double) abs(p - q);
	exp2 = abs(n * q) / sqrt(p * q);
	exp3 = pow(M_PI, 6) / log2(q - n);
	r = exp1 + exp2 - exp3;
	printf("r = %f + %f - %f", exp1, exp2, exp3);
	return r;
}

int print_country(short code) {
	int result;
	if (code == 1) {
		printf("USA");
		result = 1;
	} else if (code == 2) {
		printf("Canada");
		result = 1;
	} else {
		printf("Undefined");
		result = 0;
	}

	return result;
}

int print_color(short code) {
	int result = 1;
	switch (code) {
	case 0:
		printf("Black");
		break;
	case 1:
		printf("Grey");
		break;
	case 2:
		printf("Brown");
		break;
	case 3:
		printf("Purple");
		break;
	case 4:
		printf("Blue");
		break;
	case 5:
		printf("Green");
		break;
	default:
		printf("Undefined");
		result = 0;

	}
	return result;
}

int print_size(short code) {
	int result = 1;
	switch (code) {
	case 0:
		printf("Tiny");
		break;
	case 1:
		printf("Small");
		break;
	case 2:
		printf("Medium");
		break;
	case 3:
		printf("Large");
		break;
	case 4:
		printf("Huge");
		break;
	default:
		printf("Undefined");
		result = 0;
	}
	return result;
}

short get_code(long serial_number, char type) {
	short result;
	char n[3];
	int nDigits = floor(log10(abs(serial_number))) + 1;
	printf("%d", nDigits);
	if (nDigits == 6) {
		char str[6];
		itoa(serial_number, str, 10);
		switch (type) {
		case 'y':
			n[0] = str[0];
			break;
		case 'r':
			n[0] = str[1];
			break;
		case 's':
			n[0] = str[2];
			break;
		case 'i':
			n[0] = str[3];
			n[1] = str[4];
			n[2] = str[5];
			break;
		default:

			strcpy(n, "-99");
		}
		result = (short) atoi(n);
	} else
		result = -99;
	printf("%d", result);
	return result;
}

void print_description(long serial_number) {
	char str[6];
	int size = get_code(serial_number, 's');
	int color = get_code(serial_number, 'r');
	int num = get_code(serial_number, 'i');
	int country = get_code(serial_number, 'y');
	printf("Serial number = %lf\n", serial_number);
	printf("country = ");
	print_country(country);
	printf("\ncolor = ");
	print_color(color);
	printf("\nsize = ");
	print_size(size);
	printf("\nitem = %d\n", num);
	if (country != -99 && size != -99 && color != -99) {
		printf("A Beautiful ");
		print_size(size);
		printf(" ");
		print_color(color);
		printf(" Box item# %f", num);
		printf("made in ");
		print_country(country);
		printf("\n");
	} else
		printf("Description not found\n");
	return;
}

char math_game(long lv, int lmf, int lsf, int lrf, long rv, int rmf, int rsf,
		int rrf) {
	printf("Starting Math Game: \n");
	printf("[%d,%d,%d,%d] vs [%d,%d,%d,%d]\n", lv, lmf, lsf, lrf, rv, rmf, rsf,
			rrf);
	int counter = 0;
	while (counter < 5 && lv < rv) {
		printf("Round = %d\n", counter + 1);
		int lcounter = 0;
		while (lcounter < lrf) {
			lv = lv * lmf - lsf;
			printf("L = %d\n", lv);
			lcounter += 1;
		}
		int rcounter = 0;
		while (rcounter < rrf) {
			rv = rv * rmf - rsf;
			printf("R = %d\n", rv);
			rcounter += 1;
		}
		counter += 1;
	}

	printf("Closing Math Game\n");
	char w = (counter == 5) ? 'R' : 'L';
	return w;
}

