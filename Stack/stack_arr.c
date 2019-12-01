#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *s;
    int top;
    int size;
}STACK;
 
int push(STACK*,int);
int pop(STACK *p);
int peek(STACK *p);
void display(STACK);

int main(){
    int top, size, ch, k, x;
    STACK stk;
    printf("Enter the size of the stack: ");
    scanf("%d",&stk.size);
    
    stk.s = (int*)malloc(sizeof(int)*stk.size);
    stk.top = -1;                                   //Initialize top to -1 (empty stack)
    
    while(1){
        printf("\n");
        display(stk);

        printf("\n\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter data: ");
                    scanf("%d", &x);
                    k = push(&stk, x);
                    if(k > 0)
                        printf("\nElement pushed successfully\n");
                    break;

            case 2: k = pop(&stk);
                    if(k > 0)
                        printf("Element popped = %d\n", k);
                    break;

            case 3: k = peek(&stk);
                    if(k > 0)
                        printf("Top element = %d\n", k);
                    break;

            default: exit(0);
        }
    }
}



int push(STACK *p, int x){
    if(p->top == p->size-1){                //check if stack is full               
        printf("\nStack overflow\n");   
        return -1;
    }
 
    ++p->top;           //or p->top++
    p->s[p->top] = x;
    return 1;
}


int pop(STACK *p){
    int x;
    if(p->top == -1){
        printf("Stack empty\n");
        return -1;
    }
    x = p->s[p->top];
    --p->top;
    return x;
}


int peek(STACK *p){
    if(p->top == -1){
        printf("Stack empty\n");
        return -1;
    }
    return p->s[p->top];
}


void display(STACK p){
    int i;
    if(p.top == -1)
        printf("\nStack empty\n");
    else{
        for(i = p.top; i >= 0; --i)
            printf("%d  ",p.s[i]);

        printf("\n");
    }
}



