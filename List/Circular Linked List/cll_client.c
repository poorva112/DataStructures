#include "cll_header.h"


int main(){
    struct node *last;
    int ch, x, pos;
    last = NULL;                  //pointer to the last node of the list

    while(1){ 
        display(last);
        printf("\n\n1  Insert Head\n");
        printf("2  Insert Tail\n");
        printf("3  Delete a Node\n");
        printf("4  Display\n");
        printf("5  Exit\n\n");
        scanf("%d",&ch);
        
        switch(ch){
            case 1: printf("Enter the number: ");
                    scanf("%d",&x);
                    insert_head(&last,x);
                    break;

            case 2: printf("Enter the number: ");
                    scanf("%d",&x);
                    insert_tail(&last,x);
                    break;
         
            case 3: printf("Enter the value of the node to be deleted: ");
                    scanf("%d",&x);
                    delete_node(&last,x);
                    break;

            case 4: display(last);
                    break;

            default:exit(0);
        }
    }  
}