/*
 * ---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "A5.h"

//---------------------- Task 1 ---------------------------------
void get_file_stats(const char *filename, const char *filename2) {
	FILE *read_file;
	read_file = fopen(filename, "r");
	char letter, prev;
	FILE *out_file;
	int para, line, word, space, chars, up, low, other;
	para = line = word = space = chars = up = low = other = 0;
	out_file = fopen(filename2, "a");

	while (fscanf(read_file, "%c", &letter) != EOF) {
		chars++;
		if (isalpha(letter)) {
			if (isupper(letter)) {
				up++;
			} else if (islower(letter)) {
				low++;
			}
		}
		if (isalnum(letter) || ispunct(letter)) {
			other++;
		}
		if (isspace(letter) || letter == "\t") {
			space++;
		}
		if ((letter == '\n' || letter == '\0')) {
			line++;
		}
		if (letter == ' ' || letter == '\t' || letter == '\n'
				|| letter == '\0') {
			word++;
		}
		if (letter == '\n' && prev == '\n') {
			para++;
		}
		prev = letter;
	}
	if (!read_file == NULL) {
		fprintf(out_file, "#Paragraphs = %d\n", para);
		fprintf(out_file, "#lines = %d\n", line);
		fprintf(out_file, "#words = %d\n", word);
		fprintf(out_file, "#characters = %d\n", chars);
		fprintf(out_file, "\t#lowers = %d\n", low);
		fprintf(out_file, "\t#uppers = %d\n", up);
		fprintf(out_file, "\t#others = %d\n", other);
		fprintf(out_file, "#spaces = %d\n", space);
		fprintf(out_file, "\n");
	} else {
		fprintf(out_file, "Error(get_file_stats): Could not open file %s\n",
				filename);
	}

	fclose(out_file);
	fclose(read_file);
	return;
}

//---------------------- Task 2 ---------------------------------
void format_file1(const char *in_file, const char *out_file) {
	FILE *read_file;
	read_file = fopen(in_file, "r");
	FILE *write_file;
	write_file = fopen(out_file, "w");
	char buffer[1000];
	char ch[1000];
	int i;
	if (read_file == NULL) {
		fprintf(write_file, "Error(format_file1): Could not open file %s\n",
				in_file);
		fclose(read_file);
		fclose(write_file);
		return;
	}
	while ((fgets(ch, 1000, read_file)) != NULL) {
		int is_empty = 1;
		for (i = 0; i < strlen(ch); i++) {
			if (ch[i] == '\n') {
				continue;
			}
			if (!(ch[i] == '\n' || ch[i] == ' ' || ch[i] == '\t'
					|| ch[i] == '\0')) {
				is_empty = 0;
				break;
			}
			if (ch[i] == '.') {
				fprintf(write_file, "\n");
			}
		}
		if (!is_empty) {
			fprintf(write_file, "%s", ch);
		}
	}

	fclose(read_file);
	fclose(write_file);
	return;
}

//---------------------- Task 3 ---------------------------------
void format_file2(const char *in_file, const char *out_file) {
	FILE *read_file;
	read_file = fopen(in_file, "r");
	FILE *write_file;
	write_file = fopen(out_file, "w");
	char letter, ch[1000], *token;
	int l = 1, i, check = 0;
	if (read_file == NULL) {
		fprintf(write_file, "Error(format_file2): Could not open file %s\n",
				in_file);
		fclose(write_file);
		fclose(read_file);
		return;
	}
	while (fgets(ch, 1000, read_file) != NULL) {
		fprintf(write_file, "%d ", l);
		l++;
		token = strtok(ch, " ");
		while (token != NULL) {
			if (isdigit(token[0])) {
				fprintf(write_file, "[");
			}
			for (i = 0; i < strlen(token); i++) {
				if (token[i] == '\n') {
					check = 1;
				} else if (!ispunct(token[i])) {
					fprintf(write_file, "%c", token[i]);
				}
			}
			if (isdigit(token[0])) {
				fprintf(write_file, "]");
			}
			if (check) {
				fprintf(write_file, "\n");
				check = 0;
			} else {
				fprintf(write_file, " ");
			}
			token = strtok(NULL, " ");
		}
	}

	fclose(read_file);
	fclose(write_file);
	return;
}

//---------------------- Task 4 ---------------------------------
void filter_by_area(const char *in_file, const char *out_file,
		float area_threshold) {
	FILE *read_file;
	read_file = fopen(in_file, "r");
	FILE *write_file;
	write_file = fopen(out_file, "a");
	char cities[100][100], *token, *city, ch[1000], *num;
	float code[100];
	int check = 0, fcheck = 0, i = 0;
	if (read_file == NULL) {
		fprintf(write_file, "Error(filter_by_area): Could not open file %s\n",
				in_file);
		fclose(read_file);
		fclose(write_file);
		return;
	}
	fprintf(write_file, "Cities with area >= %.2f\n", area_threshold);
//	fputs(("Cities with area >= %f\n", area_threshold), write_file);
	while ((fgets(ch, 1000, read_file)) != NULL) {
		token = strtok(ch, " ");
		check = 0;
		while (token != NULL) {
			if (strcmp(token, "of") == 0) {
				check = 1;
			} else if (strcmp(token, "is") == 0) {
				fcheck = 1;
			} else if (check) {
				city = token;
				check = 0;
			} else if (fcheck) {
				num = token;
				fcheck = 0;
			}
			token = strtok(NULL, " ");
		}
		if (atof(num) >= area_threshold) {
			fprintf(write_file, "%s = %s", city, num);
		}
	}

	fprintf(write_file, "\n");
	fclose(read_file);
	fclose(write_file);
	return;
}

//---------------------- Task 5 ---------------------------------
void replace_two_chars(const char *filename, char *str1, char *str2) {
	FILE *in;
	in = fopen(filename, "r+");
//char *str, n_file[20];
//str = strtok(filename, ".");
	FILE *out;
//sprintf(n_file, "%s2.txt", str);
	out = fopen(filename, "r+");
//out = stdout;
	char letter;
	int found = 0;
	while (fscanf(in, "%c", &letter) != EOF) {
		if (letter == str1[0]) {
			found = 1;
			continue;
		}
		if (found) {
			if (letter == str1[1]) {
				fprintf(out, "%s", str2);
			} else {
				fprintf(out, "%c%c", str1[0], letter);
			}
			found = 0;
		} else {
			fprintf(out, "%c", letter);
		}
	}
	fclose(in);
	fclose(out);
	return;
}

