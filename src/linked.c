/****************************************************************/
/*              basic linked list implementation                */
 /***************************************************************/


#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "linked.h"

struct node *new_node(int mem_size, char *data){
	struct node *t;
	t = (struct node*) malloc(sizeof(struct node));

	t->data = data;
	t->mem_size = mem_size;
	// t->t_CPU = t_CPU;

	t->next = NULL;

	return t;
}

void del_node(struct node *tmp){
	tmp->next = NULL;
	tmp->data = NULL;
	tmp->mem_size = 0;
	free(tmp);
}

struct memory *new_memory(){
	struct memory *m = malloc(sizeof(struct node));
	m->head = NULL;
	return m;
}

void insert_node(struct node *n, struct memory *m){	
	struct node *tmp = m->head;
	if(!m->head){
		m->head = n;
	}
	else{
		while(tmp->next){
			tmp = tmp->next;
		}
		tmp->next = n;
	}
}

void del_memory(struct memory *m){
	struct node *tmp, *next;
	tmp = m->head;
	while(tmp){
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(m);
}

void show_memory(struct memory *m){
	struct node *tmp;
	tmp = m->head;
	while(tmp != NULL){
		printf("Space on chunk: %d mb, Data: \"%s\"\n", tmp->mem_size, tmp->data);
		tmp = tmp->next;
	}
	if (m->head != NULL) {
		return;
	}
}

bool is_empty(struct memory m){
	while (m.head != NULL){
		if (strcmp(m.head->data, "free!") == 0){
			return true;
		}
		else {
			break;
			return false;
		}
	}
}
