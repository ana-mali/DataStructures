/*
 * ---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

#ifndef PROCESS_H_
#define PROCESS_H_

#define True 1
#define False 0

typedef struct {
	unsigned long PID; //process ID (10 digit)
	unsigned int time;
	unsigned int arrival;
} Process;

Process* create_process(long p_pid, int p_time, int arrival_time);
void destroy_process(Process **p);
void print_process(Process *p);
Process* copy_process(Process *p);
void get_process_info(Process *p, char *info);
int is_eqaul_process(Process *p1, Process *p2);
unsigned long get_UPID();

#endif /* PROCESS_H_ */
