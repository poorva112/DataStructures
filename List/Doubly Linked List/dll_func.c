#include"dll_header.h"


void insert_head(struct node **p,int x){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = temp->next = NULL;

    if(*p == NULL)               //list empty, first node
        *p = temp;
    else{
        temp->next = *p;        //link temp to first node
        (*p)->prev = temp;
        *p = temp;              //make temp as first node
    }
}


void insert_tail(struct node **p,int x){
    struct node *temp, *q;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = temp->next=NULL;

   
    if(*p == NULL)              //list empty, first node
        *p=temp;
    else{
                                //go to the end of the list
        q = *p;                 //copy first node address
        while(q->next != NULL)  //stop at the last node
            q=q->next;

        q->next=temp;
        temp->prev=q;
    }
}


void delete_node(struct node **p, int x){
    if(*p == NULL){
        printf("Empty List\n");
        return;
    }
    
    struct node *q;

    q = *p;                      //copy the first nodes address

    while((q != NULL) && (q->data != x))
        q = q->next;

    if(q != NULL){                  //data found
                                    //only one node
        if((q->next == NULL) && (q->prev == NULL))
            *p = NULL;
        else if(q->prev == NULL){    //if it is the first node
            *p = q->next;
            (*p)->prev = NULL;
        }      
        else if(q->next == NULL)    //if it is the last node  
            q->prev->next = NULL;
        else{                       //deleting a node somewhere in middle
            q->prev->next = q->next;
            q->next->prev = q->prev;
        }
    }
    else 
        printf("Node not found\n");
}


//Deletes node at a specified position x -- 1 to n
void delete_pos(struct node **p, int x){
    if(*p == NULL){
        printf("Empty List\n");
        return;
    }
    if(x < 1){
        printf("Invalid Position\n");
        return;
    }
    struct node *q;

    q = *p;                         //copy the first nodes address
    int i = 1;
    while((q != NULL) && (i < x)){
        i++;
        q = q->next;
    }

    if(q!=NULL){                  
    
        //only one node
        if((q->next == NULL) && (q->prev == NULL))
            *p = NULL;
        else if(q->prev == NULL){    //if it is the first position
            *p = q->next;
            (*p)->prev = NULL;
        }      
        else if(q->next == NULL)    //if it is the last position  
            q->prev->next = NULL;
        else{                       //deleting a node somewhere in middle
            q->prev->next=q->next;
            q->next->prev=q->prev;
        }
    }
    else 
        printf("Invalid Position\n");
}


//Inserts node at a specified position -- 1 to n
void insert_pos(struct node **p, int x, int pos){
    if(x < 1){
        printf("Invalid Position\n");
        return;
    } 
    struct node *q, *temp;
   
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = temp->next = NULL;
    temp->data = x;

    q = *p;
    int i = 1;
    while((q->next != NULL) && (i < pos)){
        i++;
        q = q->next;
    }
    if(q->next != NULL){
        if(q->prev == NULL){            //first position. Or if(pos == 1)
            temp->next = q;
            q->prev = temp;
            *p = temp;
        }
        else{
            q->prev->next = temp;      //somewhere in the middle
            temp->prev = q->prev;
            temp->next = q;
            q->prev = temp;
        }
    }
    else{
        if(i == pos){                  //second last position     
            q->prev->next = temp;
            temp->prev = q->prev;
            temp->next = q;
            q->prev = temp;
        }
        else if(i == pos-1){           //last position
            temp->prev = q;
            q->next = temp;
        }
        else
            printf("Invalid position\n");
    }
}


void display(struct node *p){
    if(p == NULL)
        printf("\nEmpty List\n");
    else{
        while(p->next != NULL){
            printf("%d <-> ",p->data);
            p = p->next;
        }
        printf("%d ",p->data);
    }
}

