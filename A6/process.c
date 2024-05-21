/*
 *---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */
#include "process.h"//double quotes mean file created by user
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Process* create_process(long p_pid, int p_time, int arrival_time) {
	Process *p = (Process*) malloc(sizeof(Process));
	if (p_time <= 0) {
		fprintf(stderr, "Error(create_process): invalid time - set to 0\n");
		p->time = 0;
	} else
		p->time = p_time;
	if (arrival_time < 0) {
		fprintf(stderr,
				"Error(create_process): invalid arrival time - set to 0\n");
		p->arrival = 0;
	} else
		p->arrival = arrival_time;
	if (p_pid <= 0) {
		fprintf(stderr, "Error(create_process): invalid pid - set to random\n");
		p->PID = get_UPID();
	} else
		p->PID = p_pid;
	return p;
}
void destroy_process(Process **p) {
	assert(*p!=NULL);
	(*p)->PID = 0;
	(*p)->time = 0;
	(*p)->arrival = 0;
//	free(*p);
	*p = NULL;
	return;
}
void print_process(Process *p) {
	assert(p!=NULL);
	char info[30];
	strcpy(info, "");
	get_process_info(p, info);
	printf("%s", info);
	return;
}
Process* copy_process(Process *p1) {
	assert(p1!=NULL);
	Process *p2 = (Process*) malloc(sizeof(Process));
	p2->PID = p1->PID;
	p2->arrival = p1->arrival;
	p2->time = p1->time;
	return p2;
}
void get_process_info(Process *p, char *info) {
	assert(p!=NULL);
	char process[30];
	sprintf(process, "[%u]{%lu,%u)", p->arrival, p->PID, p->time);
	strcpy(info, process);
	return;
}
int is_equal_process(Process *p1, Process *p2) {
	assert(p1!=NULL && p2!=NULL);
	if (p1->PID != p2->PID)
		return False;
	if (p1->time != p2->time)
		return False;
	return True;
}
unsigned long get_UPID() {
	static int counter = 100000;
	unsigned long higher5 = rand() % (39999 - 10000 + 1) + 10000;
	higher5 = higher5 * 100000;
	int lower5 = counter;
	counter++;
	return higher5 + lower5;
}
