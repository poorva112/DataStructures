//Data Structure: Hash Table
//Collision handling using seperate chaining

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int key;
    char name[100];
    struct node *next;
};

struct hash{
    struct node *head;
    int count;
};

void display(struct hash *, int);
void insert(struct hash *,int, int, char *);
void delete(struct hash*, int, int);
void search(struct hash *ht, int size, int key);


int main(){
    struct hash *hashtable;
    int i, n, key, ch;
    char name[100];
    int tableSize;
    printf("Enter table size: ");
    scanf("%d", &tableSize);
    
    //create hash table
    hashtable = (struct hash*)malloc(tableSize * sizeof(struct hash));
    for(i = 0; i < tableSize; i++){
        hashtable[i].head = NULL;
        hashtable[i].count = 0;
    }

    while(1){
        printf("------------------------\n");
        display(hashtable,tableSize);

        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Exit\n\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter key: ");
                    scanf("%d", &key);
                    printf("Enter name: ");
                    scanf("%s", name);
                    insert(hashtable, tableSize, key, name);
                    break;

            case 2: printf("Enter the key for deletion: ");
                    scanf("%d", &key);
                    delete(hashtable, tableSize, key);
                    break;

            case 3: printf("Enter the key to search: ");
                    scanf("%d", &key);
                    search(hashtable, tableSize, key);
                    break;

            default: exit(0);
        }
    }
}
  

void search(struct hash *ht, int size, int key){
    struct node *temp;
    int index = key %size;

    temp = ht[index].head;
    // prev = NULL;
    while((temp != NULL) && (temp->key != key)){
        // prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("------------------------\n");
        printf("Key not found\n");
    }
    
    else{
        printf("------------------------\n");
        printf("\nKey: %d\n", key);
        printf("Name: %s\n\n", temp->name);
    }
}


void insert(struct hash* ht, int size, int key, char* name){
    struct node *temp;
    int index;
    index = key % size;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;
    strcpy(temp->name, name);
    temp->next = NULL;

    temp->next = ht[index].head;
    ht[index].head = temp;
    ht[index].count++;

    /*
    Doesn't check for existing key and thus deletes the first occurrence of a key.
    Can be tailored to check if key doesn't exist in hash table and only then insert (key,value) 
    to the hash table.
    Refer to search function for that.
    */
}


void delete(struct hash *ht, int size, int key){
    struct node *prev, *temp;
    int index = key %size;

    temp = ht[index].head;
    prev = NULL;
    while((temp != NULL) && (temp->key != key)){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("------------------------\n");
        printf("Key not found\n");
    }
    else{
        if(prev == NULL)
            ht[index].head = temp->next;
        else
            prev->next = temp->next;
        free(temp);
        ht[index].count--;
    }
}


void display(struct hash *ht, int size){
    int i;
    struct node* temp;
    for(i = 0; i < size; i++){
        printf("%d :",i);

        if(ht[i].head != NULL){
            temp = ht[i].head;
            while(temp != NULL){
                printf("%d ", temp->key);
                printf("%s ->", temp->name);
                temp = temp->next;
            }
        }
        printf("\n");
    }//end of for loop
}


