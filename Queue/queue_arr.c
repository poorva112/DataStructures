//Queue implentation using array

#include<stdlib.h>
#include<stdio.h>

int enqueue(int*, int*, int*, int, int);
int dequeue(int *, int *, int*);
int front(int *, int);
void display(int *, int, int);

//Can use global variables for front and rear variables

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
        display(q, f, r);
        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek/Front");
        printf("\n4. Exit\n\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the value: ");
                    scanf("%d", &x);
                    k = enqueue(q, &f, &r, size, x);
                    break;

            case 2: k = dequeue(q, &f, &r);
                    if(k >= 0)
                        printf("Element deleted = %d\n", k);
                    break;

            case 3: k = front(q, f);
                    if(k >=0)
                        printf("Front element = %d\n", k);
                    break;                    

            default: exit(0); 
        } 
    }//end of while
}


int enqueue(int *q, int *f, int *r , int size, int x){
    //check for queue overflow
    if(*r == size -1){
        printf("Queue overflow\n");
        return -1;
    }
    (*r)++;         //++*r
    q[*r] = x;
    if(*f == -1)    //first element
        *f = 0;
    return 1;
}


int dequeue(int *q, int *f, int *r){
    //check for underflow
    if(*f == -1){
        printf("Queue Underflow\n");
        return -1;
    }
    int x = q[*f];
    if(*f == *r)    //only one element in the queue     
        *f = *r = -1;
    else
        (*f)++;
    return x;
}


int front(int *q, int f){
    if(f == -1){
        printf("Empty Queue\n");
        return -1;
    }
    return q[f];
}


void display(int *q, int f, int r){
    int i;
    if(f == -1)
        printf("\nEmpty Queue\n");
    else{
        for(i = f; i <= r; ++i)
            printf("%d ", q[i]);
        printf("\n");
    }
}

/*
Why do we pass front "f" variable by reference to Enqueue and Dequeue operations?? 
The front variable has to be incremented or decremented accordingly 
and thus the changes in the function should be reflected on the variable. 
-- pass address of f 

Whereas in display and front functions, 
we just want the value of "f" to get the front element or check for underflow condition. 
Pass by value is sufficient. 
*/





