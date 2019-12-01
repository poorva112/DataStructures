//Stack using linked list

#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

void push(int,struct node **);
int pop(struct node **);
int peek(struct node **);
void display(struct node *);

int main(){ 
    struct node *top;
    int ch, k, x;

    top = NULL;

    while(1){
        display(top);

        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Exit\n\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter the value: ");
                    scanf("%d",&x);
                    push(x,&top);
                    break;

            case 2: k = pop(&top);
                    if(k >= 0)
                        printf("Element popped = %d\n",k);
                    break;

            case 3: k = peek(&top);
                    if(k >= 0)
                        printf("Top element = %d\n",k);
                    break;

            default:exit(0); 

        } //end of switch
    }//end of while
}



void push(int x, struct node **p){      
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = *p;
    *p = temp;
}
//Unlike array implementation, no need to specify size of stack. As linked list can be extended dynamically.


int pop(struct node **p){
    int x;
    struct node *q;
    if(*p == NULL){
        printf("Empty Stack\n");
        return -1;
    }
    else{
        q = *p;
        x = q->data;
        *p = q->next;
        free(q);
        return(x);
    }
}


//returns top of the stacl
int peek(struct node **p){
    if(*p == NULL){
        printf("Empty Stack\n");
        return -1;
    }
    return (*p)->data;
}


void display(struct node *p){
    if(p == NULL)
        printf("Empty Stack\n");
    else{
        while(p != NULL){
            printf("%d->", p->data);
            p = p->next;
        }
    }
}
