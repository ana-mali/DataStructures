/*
 *---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

#include "data.h"

void print_data(Data *d) {
	print_process(d);
	return;
}
void destroy_data(Data **d) {
	destroy_process(d);
	return;
}
Data* copy_data(Data *d) {
	return copy_process(d);
}
