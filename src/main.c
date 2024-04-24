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

void worst_fit(struct memory *m, struct node *proc, int n);
void free_worst(struct memory *m);

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
	struct node *n5 = new_node(19, "free!");
	struct node *n6 = new_node(12, "free!");

	insert_node(n1, m);
	insert_node(n2, m);
	insert_node(n3, m);
	insert_node(n4, m);
	insert_node(n5, m);
	insert_node(n6, m);


	show_memory(m);
 	

	for (int i = 0; i < MAX_PROCESS; i++){
		worst_fit(m, &procees[i], i);	
	}

 	printf("\n==========================\n");	
	show_memory(m);

	for (int i = 0; i < MAX_PROCESS; i++){
		free_worst(m);	
	}
 	
	printf("\n==========================\n");	
	
	show_memory(m);

	

	return EXIT_SUCCESS;
}

void worst_fit(struct memory *m, struct node *proc, int n){
	struct node *head = m->head;
	struct node *max_node = NULL;
	int max, mem_count = 0; 

	max = m->head->mem_size; 
	while (head) {
        if (strcmp(head->data, "free!") == 0) {
            if (head->mem_size >= proc->mem_size && head->mem_size > max) {
                max = head->mem_size;
                max_node = head;
            }
        }
        mem_count++;
        head = head->next;
    }
	if (max_node){
		max_node->data = proc->data;
	}

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

