// Queue(LIFO) implementation using linked list 

#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

void qinsert(int, struct node **, struct node **);
int qdelete(struct node **, struct node **);
int qfront(struct node *f);
void qdisplay(struct node*, struct node*);

int main(){
    int k, x, ch;
    struct node *front, *rear;
    front = rear = NULL;

    while(1){
        printf("\n");
        qdisplay(front, rear);

        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek/Front");
        printf("\n4. Exit\n\n");
        scanf("%d", &ch);
        
        switch(ch){
            case 1: printf("Enter the value: ");
                    scanf("%d", &x);
                    qinsert(x, &front, &rear);
                    break;

            case 2: k = qdelete(&front, &rear);                    
                    break;
            
            case 3: k = qfront(front);
                    if(k != -1){
                        printf("Front element = %d\n", k);                        
                    }
                    break;

            default: exit(0); 
        }
    }
}


void qinsert(int x, struct node **f, struct node **r){
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    //if this is the first node
    if(*f == NULL)
        *f = *r = temp;
    else{                       //insert at the end    
        (*r)->next = temp;
        *r = temp;
    }
}


int qdelete(struct node **f, struct node **r){
    struct node *q;
    int x;
    q = *f;
    if(q == NULL){
        printf("Empty queue\n");
        return -1;
    }
    
    x = q->data;
    if(*f == *r)            //only one node
        *f = *r = NULL;
    else
        *f = q->next;      
    free(q);
    return x;
}


int qfront(struct node *f){
    if(f == NULL){
        printf("Empty queue\n");
        return -1;
    }
    return f->data;
}


void qdisplay(struct node *f, struct node *r){
    if(f == NULL)
        printf("Empty queue\n");
    else{
        while(f != r){
            printf("%d -> ", f->data);
            f = f->next;
        }
        printf("%d ", f->data);
    }
} 
    
