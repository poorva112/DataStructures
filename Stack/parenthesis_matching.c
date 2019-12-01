//parenthesis matching using stack
#include<stdio.h>

void push(char*, int*, char);
int pop(char*, int*);
int match(char*);
int isEmpty(int);

int main(){
    char expr[100];
    printf("Enter an expression: ");   
    scanf("%s",expr);
    int result = match(expr);

    if(result)
        printf("\nMatching succeeds\n");
    else
        printf("\nMatching fails..\n");
}  


int match(char *expr){
    char s[50], in, ch;                 //stack
    int top = -1;
    int i = 0;
    while(expr[i] != '\0'){
        ch = expr[i];

        switch(ch){
            case '(':
            case '{':
            case '[':   push(s, &top, ch);
                        break;

            case ')':   if(!isEmpty(top)){
                            in = pop(s, &top);
                            if(in == '(')
                                break;
                            else
                                return 0;
                        }
                        else
                            return 0;
  
            case '}':   if(!isEmpty(top)){
                            in = pop(s,&top);
                            if(in == '{')
                                break;
                            else
                                return 0;
                        }
                        else
                            return 0;

            case ']':   if(!isEmpty(top)){
                            in = pop(s,&top);
                            if(in == '[')
                                break;
                            else
                                return 0;
                        }
                        else
                            return 0;

            default: return 0;
        }   //end of switch
        i++;

    }//end of while

    if(isEmpty(top))
        return 1;
    return 0;
}

   
void push(char *s, int *t, char x){          
    ++*t;
    s[*t] = x;

    //adviced to maintain stack size and check for overflow condition
    // as done in stack_arr.c
}


int pop( char *s, int *t){
    if(*t == -1){
        // printf("empty stack");
        return -1;
    }
    char x;
    x = s[*t];
    --*t;
    return x;

   
} 


//check if stack is empty
int isEmpty(int top){
    if(top == -1)
        return 1;
    return 0;
}




 

  



