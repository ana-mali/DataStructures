/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "A8.h"

/*---------------------Task 1 -----------------------------*/
void schedule(char *type, Data *processes, const int size) {
	pQueue *pQ = create_pqueue(size * 2, 'L');
	int i;
	if (processes != NULL) {
		for (i = 0; i < size; i++) {
			Data *dat = &processes[i];
			insert_pqueue2(pQ, dat);
		}
	}
	if (strcmp(type, "FIFO") == 0) {
		schedule_FIFO(pQ);
	} else if (strcmp(type, "SJF") == 0) {
		schedule_SJF(pQ);
	} else if (type[0] == 'R' && type[1] == 'R') {
		int num = strlen(type), k;
		char st[num - 2];
		for (k = 0; k < num; k++) {
			st[k] = type[2 + k];
		}
		int period = atoi(st);
		schedule_RR(pQ, period);
	} else if (type[0] == 'D' && type[1] == 'R' && type[2] == 'R') {
		int num = strlen(type), k;
		char st[num - 3];
		for (k = 0; k < num; k++) {
			st[k] = type[3 + k];
		}
		int period = atoi(st);
		schedule_DRR(pQ, period);
	} else {
		printf("Error(schedule): Unsupported scheduler type\n");
	}
	return;
}

/*---------------------Task 2 -----------------------------*/
void schedule_FIFO(pQueue *q) {
	assert(q!=NULL);
	int counter = 0, i, num = -1;
	i = q->front;
	while (1) {
		Data dat = q->array[i];
//		printf("\n[Timer:%d]:", counter);
		if (counter == 0) {
			printf("[Timer:%d]: Starting FIFO Scheduler\n", counter);
		} else if (dat.arrival > counter) {
			printf("[Timer:%d]: Idle\n", counter);
		} else {
			if (num == -1) {
				printf("Fetching Process:");
				print_process(&dat);
				printf("\n");
				num = dat.time;
				continue;
			} else if (num == 0) {
				num = -1;
				i++;
				if (i == len_pqueue(q)) {
					printf("[Timer:%d]: Closing FIFO Scheduler\n", counter);
					break;
				} else {
					printf("Fetching Process:");
					dat = q->array[i];
					print_process(&dat);
					printf("\n");
					num = dat.time;
					continue;
				}
			} else {
				printf("[Timer:%d]: ", counter);
				print_process(&dat);
				printf("\n");
				num--;
			}
		}
		counter++;
	}
	return;
}
int compare_data3(Data *d1, Data *d2) {
	assert(d1!=NULL);
	assert(d2!=NULL);
	if (d1->time > d2->time) {
		return 1;
	} else if (d2->time > d1->time) {
		return 2;
	} else if (d1->time == d2->time) {
		if (d1->arrival > d2->arrival) {
			return 1;
		} else if (d1->arrival < d2->arrival) {
			return 2;
		} else if (d1->arrival == d2->arrival) {
			if (d1->PID > d2->PID) {
				return 1;
			} else if (d1->PID < d2->PID) {
				return 2;
			}
		}
	}
	return 0;
}
int insert_pqueue3(pQueue *q, Data *d) {
	assert(q!=NULL && d!=NULL);
	if (is_full_pqueue(q)) {
		printf("Error(insert_pqueue): pqueue is full\n");
		return 0;
	}
	if (is_empty_pqueue(q)) {
		q->front = 0;
		q->rear = 0;
		q->array[q->rear] = *d;
		return 1;
	}
	int i, found = 0;
	Data t = q->array[q->front], temp, *arr;
	for (i = q->front; i <= q->rear; i++) {
		if (q->priority == 'H') {
			if (found) {
				t = q->array[i + 1];
				q->array[i + 1] = temp;
				temp = t;
				continue;
			}
			arr = &(q->array[i]);
			if (compare_data3(d, arr) == 1) {
				found = 1;
				t = q->array[i];
				temp = q->array[i + 1];
				q->array[i] = *d;
				q->array[i + 1] = t;
			}
		} else if (q->priority == 'L') {
			if (found) {
				t = q->array[i + 1];
				q->array[i + 1] = temp;
				temp = t;
				continue;
			}
			arr = &(q->array[i]);
			if (compare_data3(d, arr) == 2) {
				found = 1;
				t = q->array[i];
				temp = q->array[i + 1];
				q->array[i] = *d;
				q->array[i + 1] = t;
			}
		}
	}
	q->rear++;
	if (!found) {
		q->array[q->rear] = *d;
	}
	return 1;
}
Data* searcher(pQueue *q, int counter) {
	int i, len = len_pqueue(q);
	pQueue *pQ = create_pqueue(len, 'L');
	for (i = q->front; i <= q->rear; i++) {
		if (q->array[i].arrival <= counter) {
			Data *dat = remove_pqueue2(q);
			insert_pqueue3(pQ, dat);
		}
	}
	if (is_empty_pqueue(pQ)) {
		destroy_pqueue(&pQ);
		return NULL;
	}
	Data *dat = remove_pqueue2(pQ);
	if (len_pqueue(pQ) > 0) {
		for (i = pQ->front; i <= pQ->rear; i++) {
			Data *temp = remove_pqueue2(pQ);
			insert_pqueue2(q, temp);
		}
	}
	dat = copy_data(dat);
	destroy_pqueue(&pQ);
	return dat;
}
/*---------------------Task 3 -----------------------------*/
void schedule_SJF(pQueue *q) {
	int count = 0;
	printf("[Timer:%d]: Starting FIFO Scheduler\n", count);
	count++;
	Data *data = NULL;
	while (1) {
		if (is_empty_pqueue(q)) {
			break;
		}
		printf("len q: %d\n", len_pqueue(q));
		data = searcher(q, count);

		if (data == NULL) {
			printf("[Timer:%d]: Idle\n", count);
			count++;
			continue;
		} else {

			printf("Fetching Process:");
			print_process(data);
			printf("\n");
			for (int j = 0; j < data->time; j++) {
				printf("[Timer:%d]: ", count);
				print_process(data);
				printf("\n");
				count++;
			}
			count--;
			destroy_data(&data);
			data = NULL;
		}
		count++;
	}
	printf("[Timer:%d]: Closing SJF Scheduler\n", count);

	return;
}

/*---------------------Task 4 -----------------------------*/
void schedule_RR(pQueue *q, int period) {
	int counter = 1, i = q->front;
	printf("[Timer:0]: Starting RR%d Scheduler\n", period);
	Data *dat;
	while (1) {
		dat = &q->array[i];
		if (i == len_pqueue(q)) {
			break;
		}
		if (dat->arrival > counter) {
			printf("[Timer:%d]: Idle\n", counter);
		} else {
			printf("Fetching Process: ");
			print_process(dat);
			printf("\n");
			if (dat->time < period) {
				for (int j = 0; j < dat->time; j++) {
					printf("[Timer:%d]: ", counter);
					print_process(dat);
					printf("\n");
					counter++;
				}
			} else {
				for (int j = 0; j < period; j++) {
					printf("[Timer:%d]: ", counter);
					print_process(dat);
					printf("\n");
					counter++;
				}
			}
			i++;
			counter--;
		}
		counter++;
	}
	printf("[Timer:%d]: Closing RR%d Scheduler\n", counter, period);
	return;
}

/*---------------------Task 5 -----------------------------*/
void schedule_DRR(pQueue *q, int period) {
	int counter = 1;
	printf("[Timer:0]: Starting DRR%d Scheduler\n", period);
	Data *dat;
	while (1) {
		if (is_empty_pqueue(q)) {
			break;
		}
		dat = peek_pqueue2(q);
		if (dat->arrival > counter) {
			printf("[Timer:%d]: Idle\n", counter);
		} else {
			printf("Fetching Process: ");
			print_process(dat);
			printf("\n");
			if (dat->time == 4 || dat->time < period) {
				for (int j = 0; j < dat->time; j++) {
					printf("[Timer:%d]: ", counter);
					print_process(dat);
					printf("\n");
					counter++;
				}
			} else {
				for (int j = 0; j < period; j++) {
					printf("[Timer:%d]: ", counter);
					print_process(dat);
					printf("\n");
					counter++;
				}
			}
			Data *temp = remove_pqueue2(q);
			if (temp->time > period) {
				temp->time = temp->time - period;
				temp->arrival = temp->arrival + period;
				insert_pqueue2(q, temp);
			}
			counter--;
		}
		counter++;
	}
	printf("[Timer:%d]: Closing DRR%d Scheduler\n", counter, period);
	return;
}
