#include "cll_header.h"


void insert_head(struct node **p, int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = temp;

    //if list is empty
    if(*p == NULL)
        *p = temp;
    else{
        temp->next = (*p)->next;        //link the new node to first node
        (*p)->next = temp;              //link the last node to the new node
    }
}


void insert_tail(struct node **p, int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = temp;

    //if list empty
    if(*p == NULL)
        *p = temp;
    else{
        temp->next = (*p)->next;        //link the new node to first node
        (*p)->next = temp;              //link the last node to the new node
        *p = temp;                      //point to the last node
    }
}


//Deletes specified node with value x
void delete_node(struct node **p, int x){
    if(*p == NULL){
        printf("Empty circular list\n");
        return;
    }
    struct node *prev, *q, *r;
    q = *p;                               //copy the last node's address 
    prev = q;
    r = q->next;                          //point to first node

    //traverse until you find the node to be deleted

    while((r != q) && (r->data != x)){
        prev = r;
        r = r->next;
    }

    if(r != q)                             //data found
        prev->next = r->next;
    else{                                  //r==q,last node    
        if(r->data == x){
            if(r->next == r)               //only one node
                *p = NULL;
            else{                          //deleting last node           
                prev->next=r->next;
                *p=prev;
            }
        }
        else
            printf("Node not found\n");
    }
    free(r);
 }

    
void display(struct node *p){
    struct node *q;
    if(p == NULL)
        printf("\nEmpty List\n");
    else{
        q = p->next;
    
        //traverse till you reach the last node
        while(q != p){
            printf("%d->",q->data);
            q = q->next;
        }
    
        //print the last node
        printf("%d ",q->data);
    }
}