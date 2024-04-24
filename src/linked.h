/*=================================================
	  Basic implemntation of queues (FIFO)
				by NinjagoRT
===================================================*/

/*

*/


#ifndef LINKED_H
#define LINKED_H

#include <stdbool.h>


struct node{
	int mem_size;
	int rests_size;
	int t_CPU;
	char *data;
	struct node *next;
};

struct memory{
	struct node *head;
};


void __eprintf (const char *fmt, const char *expr, int line, const char *file);

struct node *new_node(int mem_size, char *data);
void del_node(struct node *tmp);
void insert_node(struct node *n, struct memory *m);	

struct memory *new_memory();
void del_memory(struct memory *m);
void show_memory(struct memory *m);

bool is_empty(struct memory m);


#endif // LINKED_H






