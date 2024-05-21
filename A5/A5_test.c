#include <stdio.h>
#include <string.h>
#include "A5.h"

void test_get_file_stats(FILE *fptr);
void test_format_file1(FILE *fptr);
void test_format_file2(FILE *fptr);
void test_filter_by_area(FILE *fptr);
void test_replace_two_chars(FILE *fptr);

void copy_file(const char *in_file, FILE *destination);
void copy_file2(const char *in_file, const char *out_file);
void wipe_files();

int main() {
	setbuf(stdout, NULL);

	wipe_files();

	char out_file[] = "my_output.txt";
	FILE *destination = NULL;
	destination = fopen(out_file, "w");
	if (out_file == NULL) {
		printf("Error(main): Could not open file %s\n", out_file);
		return 0;
	}
	test_get_file_stats(destination);
	test_format_file1(destination);
	test_format_file2(destination);
	test_filter_by_area(destination);
	test_replace_two_chars(destination);

	fclose(destination);
	printf("See file: \"my_output.txt\"");
	return 0;
}

void test_get_file_stats(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: get_file_stats:\n\n");

	char filename[30];

	strcpy(filename, "cIntro.txt");
	get_file_stats(filename, "get_file_stats_output.txt");

	strcpy(filename, "chistory.txt");
	get_file_stats(filename, "get_file_stats_output.txt");

	strcpy(filename, "nothing.txt");
	get_file_stats(filename, "get_file_stats_output.txt");

	copy_file("get_file_stats_output.txt", fptr);

	fprintf(fptr, "\nEnd Testing: get_file_stats\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}

void test_format_file1(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: format_file1:\n\n");

	char filename[30];

	strcpy(filename, "cIntro.txt");
	fprintf(fptr, "Case 1: formatting %s:\n\n", filename);
	format_file1(filename, "format_file1_output.txt");
	copy_file("format_file1_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	strcpy(filename, "chistory.txt");
	fprintf(fptr, "Case 2: formatting %s:\n\n", filename);
	format_file1(filename, "format_file1_output.txt");
	copy_file("format_file1_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	strcpy(filename, "nothing.txt");
	fprintf(fptr, "Case 3: formatting %s:\n\n", filename);
	format_file1(filename, "format_file1_output.txt");
	copy_file("format_file1_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	fprintf(fptr, "\nEnd Testing: format_file1\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}

void test_format_file2(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: format_file2:\n\n");

	char filename[30];

	strcpy(filename, "cIntro.txt");
	fprintf(fptr, "Case 1: formatting %s:\n\n", filename);
	format_file2(filename, "format_file2_output.txt");
	copy_file("format_file2_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	strcpy(filename, "chistory.txt");
	fprintf(fptr, "Case 2: formatting %s:\n\n", filename);
	format_file2(filename, "format_file2_output.txt");
	copy_file("format_file2_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	strcpy(filename, "nothing.txt");
	fprintf(fptr, "Case 3: formatting %s:\n\n", filename);
	format_file2(filename, "format_file2_output.txt");
	copy_file("format_file2_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	fprintf(fptr, "\nEnd Testing: format_file2\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}

void test_filter_by_area(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: filter_by_area:\n\n");

	char in_file[30], out_file[] = "filter_by_area_output.txt";

	strcpy(in_file, "ontario.txt");
	float area_threshold = 200.00;
	filter_by_area(in_file, out_file, area_threshold);

	area_threshold = 300.00;
	filter_by_area(in_file, out_file, area_threshold);

	area_threshold = 800.00;
	filter_by_area(in_file, out_file, area_threshold);

	strcpy(in_file, "Quebec.txt");
	area_threshold = 300.00;
	filter_by_area(in_file, out_file, area_threshold);

	area_threshold = 1300.00;
	filter_by_area(in_file, out_file, area_threshold);

	strcpy(in_file, "BC.txt");
	area_threshold = 200.00;
	filter_by_area(in_file, out_file, area_threshold);

	copy_file(out_file, fptr);

	fprintf(fptr, "\nEnd Testing: filter_by_area\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}

void test_replace_two_chars(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: replace_two_chars:\n\n");

	//create a copy of "ontario.txt" and "Quebec.txt" in order not to destroy original files
	char file1[] = "cIntro.txt", file2[] = "chistory.txt";
	char file11[] = "cIntro2.txt", file22[] = "chistory2.txt";
	copy_file2(file1, file11);
	copy_file2(file2, file22);

	fprintf(fptr, "Replacing \"to\" with \"**\" in file %s\n", file11);
	replace_two_chars(file11, "to", "**");
	copy_file(file11, fptr);
	fprintf(fptr, "\n");

	fprintf(fptr, "Replacing \"in\" with \"IN\" in file %s\n", file22);
	replace_two_chars(file22, "in", "IN");
	copy_file(file22, fptr);
	fprintf(fptr, "\n");

	fprintf(fptr, "End Testing: replace_two_chars\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}
//------------- utility functions --------------------
void copy_file(const char *in_file, FILE *destination) {
	FILE *source = NULL;
	source = fopen(in_file, "r");
	if (source == NULL) {
		fprintf("Error(copy_file): Could not open file %s\n", in_file);
		return;
	}
	char character = fgetc(source);
	while (character != EOF) {
		fprintf(destination, "%c", character);
		character = fgetc(source);
	}
	fclose(source);
	return;
}

void copy_file2(const char *in_file, const char *out_file) {
	FILE *source = NULL, *destination = NULL;
	source = fopen(in_file, "r");
	if (source == NULL) {
		printf("Error(copy_file2): Could not open file %s\n", in_file);
		return;
	}

	destination = fopen(out_file, "w");
	if (destination == NULL) {
		printf("Error (copy_file2): Could not open file %s\n", out_file);
		return;
	}

	char line[MAX];
	while (fgets(line, sizeof(line), source) != NULL)
		fprintf(destination, "%s", line);

	fclose(source);
	fclose(destination);
	return;
}
void wipe_files() {
	char filename[4][30] = { "get_file_stats_output.txt",
			"format_file1_output.txt", "format_file2_output.txt",
			"filter_by_area_output.txt" };
	FILE *fptr = NULL;
	for (int i = 0; i < 4; i++) {
		fptr = fopen(filename[i], "w");
		if (fptr == NULL) {
			printf("Error(wipe_files): Could not open file %s\n", filename[i]);
			return;
		}
		fclose(fptr);
		fptr = NULL;
	}
	return;
}
