#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "linked.h"

#define MAX_PROCESS 6

struct node procees[MAX_PROCESS] = {
// mem, t_CPU, rest, data, *next
	{ 4,   51,	0, "WORD", 								NULL},
	{ 8,   12,	0, "EXCEL", 							NULL},
	{ 3,    4,	0, "GCC main.c -o main", 				NULL},
	{ 4,    3,	0, "namp -np 10.10.10.1 -p- -sV", 		NULL},
	{ 8,  100,	0, "metasploit", 						NULL},
	{ 5,   12,	0, "dotnet run --project main.csproj",	NULL}
};

void free_worst(struct memory *m);
int find_max_node(struct memory m);

void worst_fit(struct memory **m, struct node *proc){	
	struct node *tmp = (*m)->head;
	struct node *bkp = (*m)->head;
	int max = 0;
	int pos_node = 0;

	while(tmp != NULL){
		if (max < tmp->mem_size){
			if (strcmp(tmp->data, "free!") == 0){
				max = tmp->mem_size;
				pos_node++;
			}
			else{
				pos_node++;
			}
		}
		tmp = tmp->next;
	}

	tmp = bkp;
	for (int i = 0; i < pos_node; i++){
		if (strcmp(tmp->data, "free!") == 0){
			if (tmp->mem_size == max){
				if (tmp->mem_size >= proc->mem_size){
					tmp->data = proc->data;
				}
			}
		}
		tmp = tmp->next;
	}


}


int main(int argc, char *argv[]) {

	struct memory *m = new_memory();
	

	// for (int i = 0; i < 5; i++)
	// {
	// 	struct node *n = new_node(rand() % (40 - 3) + 2,  "free!", 0);
	// 	insert_node(n, m);
	// }
	struct node *n1 = new_node(9, "free!");
	struct node *n2 = new_node(24, "free!");
	struct node *n3 = new_node(11, "free!");
	struct node *n4 = new_node(21, "free!");

	n1->t_CPU = 2003;
	n2->t_CPU = 77;
	n4->t_CPU = 122;

	insert_node(n1, m);
	insert_node(n2, m);
	insert_node(n3, m);
	insert_node(n4, m);


	show_memory(m);
 	

	// for (int i = 0; i < MAX_PROCESS; i++){
		worst_fit(&m, &procees[0]);	
		worst_fit(&m, &procees[1]);	
		worst_fit(&m, &procees[2]);	
		worst_fit(&m, &procees[3]);	
	// }

 	printf("\n==========================\n");	
	show_memory(m);

	for (int i = 0; i < MAX_PROCESS; i++){
		free_worst(m);	
	}
 	
	printf("\n==========================\n");	
	
	show_memory(m);


	del_memory(m);

	return EXIT_SUCCESS;
}

int find_max_node(struct memory m){
	struct node *tmp = m.head;
	int max = 0, count = 0;
	
	if (tmp == NULL) {
		printf("[!] :0!!!!\n");
	}
	else{
		max = tmp->mem_size;
		while (tmp){
			if (strcmp(tmp->data, "free!") == 0){
				if (max < tmp->mem_size){
					max = tmp->mem_size;
					count++;
				}
			}
			tmp = tmp->next;
		}
		tmp = m.head;
	}

	return count;
}

void free_worst(struct memory *m){
	struct node *tmp = m->head;
	int max = 0;

	if (tmp == NULL){
		printf("[!] The memory is empty!\n");
		return;
	}
	else{
		max = tmp->mem_size;
		while (tmp){
			if (strcmp(tmp->data, "free!") != 0){
				if (tmp->mem_size > max){
					max = tmp->mem_size;
				}
			}
			tmp = tmp->next;
		}
	}
	tmp = m->head;
	while(tmp){
		if (tmp->mem_size == max){
			tmp->data = "free!";
		}
		tmp = tmp->next;
	}
}

