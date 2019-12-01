#include<stdio.h>
#include<stdlib.h>

void insert(int *, int);
void preorder(int*, int);
void postorder(int*, int);
void inorder(int*, int);
int min(int *t);
int max(int *t);

int main(){
    int t[100];             //array to store tree elements
    int ch, num, k, i;
    for(i = 0; i < 100; i++)
        t[i] = 0;           //Initialise array elements to 0
 
    while(1){
        printf("\n1. Insert");
        printf("\n2. Traversals: Preorder, Postorder, Inorder");   
        printf("\n3. Smallest & Largest element");
        printf("\n4. Exit\n\n");
        scanf("%d",&ch);
       
        switch(ch){
            case 1: printf("Enter the element: ");
                    scanf("%d", &num);
                    insert(t, num);
                    break;

            case 2: printf("\nPreorder:   ");
                    preorder(t,0);

                    printf("\nPostorder:  ");
                    postorder(t,0);

                    printf("\nInorder:    ");
                    inorder(t,0);
                    printf("\n");
                    break; 
            
            case 3: printf("Min: %d \n", min(t));
                    printf("Max: %d \n", max(t));
                    break;


            default: exit(0);
        }
    }
}    

  
void insert(int *t, int x){
    int i;
    i = 0;
    while(t[i] != 0){
        if(x < t[i])
            i = (2*i) + 1;      //left branch
        else 
            i = (2*i) + 2;      //right branch 
    }
    t[i] = x;
}


void preorder(int *t, int i){
    if(t[i] != 0){
        printf("%d ", t[i]);
        preorder(t, 2*i + 1);       //left subtree
        preorder(t, 2*i + 2);       //right subtree
    }
}


void postorder(int *t, int i){
    if(t[i] != 0){
        postorder(t, 2*i + 1);      //left subtree
        postorder(t, 2*i + 2);      //right subtree
        printf("%d ", t[i]);
    }
}


void inorder(int *t, int i){
    if(t[i] != 0){
        inorder(t, 2*i + 1);        //left subtree
        printf("%d ", t[i]);
        inorder(t, 2*i + 2);        //right subtree
    }
}


int min(int *t){
    int i;
    i = 0;
    while(t[2*i + 1] != 0)
        i = 2*i + 1;                //branch left
    return t[i];
}


int max(int *t){
    int i;
    i = 0;
    while(t[2*i + 2] != 0)
        i = 2*i + 2;                //branch right
    return t[i];
}