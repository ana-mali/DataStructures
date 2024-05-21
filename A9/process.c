/*
 * ---------------------------------
 * Student Name: Anastasia Malinovski
 * Student ID: 200694700
 * Student Email: mali4700@mylaurier.ca
 * ---------------------------------
 */

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <assert.h>

# include "process.h"

/**
 * ------------------------------------------------------------
 * Parameters:  process pid (long)
 * 				process time (int)
 * 				arrival time (int)
 * Return:		a Process pointer (Process*)
 * Description:	create a new Process through given parameters
 * 				if processTime <= 0 --> error, set to 0
 * 				if arrivalTime < 0  --> error, set to 0
 * 				if PID <= 0 --> error, set using get_UPID()
 * ------------------------------------------------------------
 */
Process* create_process(long pid, int p_time, int arrival_time) {
	Process *p = (Process*) malloc(sizeof(Process));

	//set process time
	if (p_time <= 0) {
		fprintf(stderr, "Error(create_process): invalid time - set to 0\n");
		p->time = 0;
	} else
		p->time = p_time;

	//set arrival time
	if (arrival_time < 0) {
		fprintf(stderr,
				"Error(create_process): invalid arrival time - set to 0\n");
		p->arrival = 0;
	} else
		p->arrival = arrival_time;

	//set PID
	if (pid <= 0) {
		fprintf(stderr, "Error(create_process): invalid pid - set to random\n");
		p->PID = get_UPID();
	} else
		p->PID = pid;

	return p;
}

/**
 * ------------------------------------------------------------
 * Parameters:  A pointer to a Process Pointer (Process **)
 * Return:		None
 * Description:	destroys given Process
 * 				sets PID, arrival and time to 0
 * 				frees memory allocated to given process and set to NULL
 * 				asserts given Process is not NULL
 * ------------------------------------------------------------
 */
void destroy_process(Process **p) {
	assert(*p != NULL);
	(*p)->PID = 0;
	(*p)->time = 0;
	(*p)->arrival = 0;
	free(*p);
	*p = NULL;
	return;
}

/**
 * ------------------------------------------------------------
 * Parameters:  None
 * Return:		Unique PID (unsigned long)
 * Description:	Generates a 10 digit unique PID
 * 				Range: 1000010000 to 3999999999
 * 				higher five digits are random
 * 				lower five digits are counter
 * 				Can generate up to 2,999,989,999 UPIDs
 * ------------------------------------------------------------
 */
unsigned long get_UPID() {
	//Note: MAX for unsigned long is 4294967295

	static int counter = 100000;

	//Get higher 5 digits
	//random number between 10000 to 39999
	unsigned long higher5 = rand() % (39999 - 10000 + 1) + 10000;
	higher5 = higher5 * 100000;

	//Get lower 5 digits
	//sequential number between 10000 to 99999
	int lower5 = counter;
	counter++;

	return higher5 + lower5;
}

/**
 * ------------------------------------------------------------
 * Parameters:  A pointer to a Process (Process*)
 * Return:		A pointer to a Process (Process*)
 * Description:	Creates a copy of the given process
 * 				The copy has same data values as the original Process
 * 				asserts given Process is not NULL
 * ------------------------------------------------------------
 */
Process* copy_process(Process *p1) {
	assert(p1!=NULL);
	Process *p2 = (Process*) malloc(sizeof(Process));
	p2->PID = p1->PID;
	p2->time = p1->time;
	p2->arrival = p1->arrival;
	return p2;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	p: Pointer to a process (Process*)
 * 				info: String to store process info (Char*)
 * Return:		None
 * Description:	asserts: process pointer is not NULL
 * 				Constructs a string: "[arrival](PID,time)"
 * 				Stores the above string at info
 * ------------------------------------------------------------
 */
void get_process_info(Process *p, char *info) {
	assert(p!=NULL);
	char process[30] = "";
	sprintf(process, "[%u](%lu,%u)", p->arrival, p->PID, p->time);
	strcpy(info, process);
	return;
}

/**
 * ------------------------------------------------------------
 * Parameters: 	Pointer to a process (Process*)
 * Return:		None
 * Description:	Print process info as "[arrival](PID,time)"
 * 				asserts: pointer is not NULL
 * ------------------------------------------------------------
 */
void print_process(Process *p) {
	assert(p!=NULL);
	char info[30];
	strcpy(info, "");
	get_process_info(p, info);
	printf("%s", info);
	return;
}

/**
 * ------------------------------------------------------------
 * Parameters:  Pointer to process 1 (Process*)
 * 				Pointer to process 2 (Process*)
 * Return:		True/False
 * Description:	compares two processes for equality
 * 				A process is equal if both have equal PID and processTime
 * 				(ignores arrival time)
 * 				returns True if equal, False otherwise
 * 				asserts both processes are not NULL
 * ------------------------------------------------------------
 */
int is_equal_process(Process *p1, Process *p2) {
	assert(p1 != NULL && p2 != NULL);
	if (p1->PID != p2->PID)
		return False;
	if (p1->time != p2->time)
		return False;
	return True;
}

