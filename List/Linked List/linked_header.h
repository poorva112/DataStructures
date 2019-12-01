#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insert_head(struct node**, int);
void insert_tail(struct node**, int);
void delete_first(struct node**);
void delete_last(struct node**);
void display(struct node*);
void delete_node(struct node**, int);
void delete_pos(struct node**, int);
void reverse(struct node **);