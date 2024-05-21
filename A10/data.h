#ifndef DATA_H_
#define DATA_H_

typedef int Data;

void print_data(Data *d);
void print_data_array(Data *array, const int size);
void swap_data(Data *d1, Data *d2);
Data* copy_data(Data *d);
int compare_data(Data *d1, Data *d2);
void destroy_data(Data **d);

#endif /* DATA_H_ */
