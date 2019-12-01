#include"dll_header.h"

int main(){
    struct node *first;
    first = NULL;
    int x, ch, pos;
    while(1){
        printf("\n");
        display(first);

        printf("\n\n1  Insert Head\n");
        printf("2  Insert Tail\n");
        printf("3  Delete node\n");
        printf("4  Delete at position\n");
        printf("5  Insert at position\n");
        printf("6  Display\n");
        printf("7  Exit\n\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("Enter the value: ");
                    scanf("%d",&x);
                    insert_head(&first,x);
                    break;

            case 2: printf("Enter the value: ");
                    scanf("%d",&x);
                    insert_tail(&first,x);
                    break;


            case 3: printf("Enter the value: ");
                    scanf("%d",&x);
                    delete_node(&first,x);
                    break;

            case 4: printf("Enter the position: ");
                    scanf("%d",&x);
                    delete_pos(&first,x);
                    break;

            case 5: printf("Enter the value and position: ");
                    scanf("%d %d",&x,&pos);
                    insert_pos(&first,x,pos);
                    break;

            case 6: display(first);
                    break;

            default : exit(0);          
        }
    }
}