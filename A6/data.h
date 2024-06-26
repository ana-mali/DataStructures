/*
 *---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

#ifndef DATA_H_
#define DATA_H_

#include "process.h"

typedef Process Data;
void print_data(Data *d);
void destroy_data(Data **d);
Data* copy_data(Data *d);

#endif /* DATA_H_ */
