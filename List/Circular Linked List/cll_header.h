#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insert_head(struct node**, int);
void insert_tail(struct node**, int);
void delete_node(struct node**, int);
void display(struct node*);