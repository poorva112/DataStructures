//Circular queue

#include<stdlib.h>
#include<stdio.h>

int enqueue(int*, int*, int*, int, int);
int dequeue(int *, int *, int*, int);
void display(int *, int, int, int);

int main(){
  
    int *q;
    int ch, k, x;
    int f, r, size;
    f = r = -1;
    printf("Enter the size of the size: ");
    scanf("%d", &size);

    q = (int*)malloc(sizeof(int)*size);
    while(1){
        printf("\n");
        display(q, f, r, size);
        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Exit\n\n");
        
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter the value: ");
                    scanf("%d", &x);
                    k = enqueue(q, &f, &r, size, x);   
                    break;

            case 2: k = dequeue(q, &f, &r, size);
                    if(k >= 0)
                        printf("Element deleted = %d\n", k);
                    break;

            default:exit(0);
        }
    }//end of while
}


int enqueue(int *q, int *f, int *r , int size, int x){
    if(((*r + 1) % size) == *f){
        printf("Queue overflow\n");
        return -1;
    }
    *r = (*r + 1) % size;
    q[*r] = x;
    
    if(*f == -1)      //first element
        *f = 0;
    return 1;
}


int dequeue(int *q, int *f, int *r, int size){
    int x;

    //check for underflow
    if(*f == -1){
        printf("Queue Underflow\n");
        return -1;
    }
    x = q[*f];
    if(*f == *r)        //only one element    
        *f = *r = -1;
    else
        *f = (*f + 1) % size;
    return x;
}


void display(int *q, int f, int r, int size){
    int i;
    if(f == -1)
        printf("\nEmpty Queue\n");
    else{
        while(f != r){
           printf("%d ", q[f]);
           f = (f + 1) % size;
        }
        printf("%d ", q[f]);        //last element  
    }
}