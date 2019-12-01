#include "linked_header.h"


void insert_head(struct node **p, int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    
    temp->next = *p;
    *p = temp;

    // Alternate code:
    /* if(*p == NULL)
        *p = temp;
    else{
       temp->next = *p;
       *p = temp;
    }*/
}


void insert_tail(struct node **p, int x){
    struct node *temp, *q;
    
    //create a node
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    //if head/first node is null => empty linked list
    if(*p == NULL){
        *p = temp;
        return;
    }    

    q = *p;                     //copy address of the first node of the list in q
                                //traverse to the last node
    while(q->next != NULL){
        q = q->next;
    }
    q->next = temp;             //point last node to temp (x)
    return;
}


//delete first/head node
void delete_first(struct node **p){
    if(*p == NULL){
        printf("\nEmpty list\n");
        return;
    }
    struct node *q;
    q = *p;                     //copy first node's address
    *p = q->next;               //make first point to the second node
                                //Alternate code:  *p = (*p)->next;
    free(q);                    //free the first node
}


//delete last/tail node
void delete_last(struct node **p){
    if(*p == NULL){
        printf("\nEmpty list\n");
        return;
    }

    struct node *q, *prev;
    prev = NULL;
    q = *p;                     //copy first node's address

    //go to the last node
    while(q->next != NULL){
        prev = q;
        q = q->next;            //move forward
    }

    if(prev == NULL)            //only node in the list
        *p = NULL;
    else
        prev->next = NULL;      //delink the last node

    free(q);
}


void display(struct node *q){
    if(q == NULL)
        printf("Empty List\n");
    else{
        while(q != NULL){
            printf("%d-> ",q->data);
            q = q->next;
        }
    }//end of else block
}


//Deletes only first occurrence of that element
void delete_node(struct node **p, int x){
    struct node *prev,*q;

    q = *p;                         //copy the address of first node
    prev = NULL;                    //keeps track of previous  node

    //keep moving forward till you find the node to be deleted
    //or you go beyond the last node
  
    while((q != NULL) && (q->data != x)){
        prev = q;                   //keep the track of previous node
        q = q->next;                //move forward
    }
    if(q == NULL)                   //end of the list
        printf("Node not found.\n");
    else if(prev == NULL)           //first node to be deleted
        *p = q->next;               //copy the address of second node into first
        //*p = (*p)->next;
    else
        prev->next = q->next;       //delink the node to be deleted

    free(q);
 }

   
//Delete node at a specified position 'pos'- 1 to n
void delete_pos(struct node **p, int pos){
    if(pos < 1){
        printf("Invalid Position\n");
        return;
    }

    struct node *prev, *q;
  
    q = *p;                         //copy the address of first node
    prev = NULL;                    //keeps track of previous  node

    //keep moving forward till you find the position of node to be deleted
    //or you go beyond the last node  

    int i = 1;
    while( (q != NULL) && (i < pos)){
        i++;
        prev = q;
        q = q->next;
    }
    if(q == NULL)                   //end of the list
        printf("Invalid Position\n");
    else if(prev == NULL)           //first position 
        *p=q->next;
    else
        prev->next=q->next;         //middle or last position
    free(q);
 } 


void reverse(struct node **p){
    struct node *prev, *current, *nextNode;
    prev  = NULL; 
    current = *p; 
    nextNode = NULL;     
    
    while (current != NULL) { 
        nextNode = current->next; 
  
        // Reverse current node's pointer 
        current->next = prev; 
  
        // Move pointers one position ahead. 
        prev = current; 
        current = nextNode; 
    } 
    *p = prev; 

}


