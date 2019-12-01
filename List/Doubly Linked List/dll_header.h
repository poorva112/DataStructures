#include<stdio.h>
#include<stdlib.h>

struct node{ 
	int data;
	struct node *prev, *next;
};

void insert_head(struct node**, int);
void insert_tail(struct node**, int);
void delete_node(struct node**, int);
void delete_pos(struct node**, int);
void insert_pos(struct node**, int, int);
void display(struct node*);