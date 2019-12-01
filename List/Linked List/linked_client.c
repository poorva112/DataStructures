#include "linked_header.h"

int main(){
    struct node *head;
    int ch, x;
    head = NULL;   //pointer to the head node of the list

    while(1){ 
        printf("\n");
        display(head);

        printf("\n\n1.  Insert Head\n");
        printf("2.  Insert Tail\n");
        printf("3.  Delete head\n");
        printf("4.  Delete Last\n");
        printf("5.  Delete a Node\n");
        printf("6.  Delete at a position\n");
        printf("7.  Reverse linked list\n");
        printf("Any other key to exit\n\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter the number: ");
                    scanf("%d", &x);
                    insert_head(&head, x);
                    break;

            case 2: printf("Enter the number: ");
                    scanf("%d", &x);
                    insert_tail(&head, x);
                    break;

            case 3: delete_first(&head);
                    break;

            case 4: delete_last(&head);
                    break;

            case 5: printf("Enter the value of the node to be deleted: ");
                    scanf("%d", &x);
                    delete_node(&head, x);
                    break;

            case 6: printf("Enter the position of the node to be deleted: ");
                    scanf("%d", &x);
                    delete_pos(&head, x);
                    break;

            case 7: reverse(&head);
                    break;

            default: exit(0);
        }
    }
}
