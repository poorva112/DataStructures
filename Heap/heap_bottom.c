//Program to create a max heap using bottom up approach

#include<stdio.h>

void bottom_up(int*, int);

int main(){
    int h[100];             //heap size
    int i, n;               
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    
    printf("Enter the elements: \n");
    for(i = 0; i < n; i++)
    scanf("%d", &h[i]);
    bottom_up(h, n);

    printf("Max heap created: \n");
    for(i = 0; i < n; i++)
        printf("%d ", h[i]);
    printf("\n");
}


void bottom_up(int *h, int n){
    int i, j, k, key;

    //start with the last parental node: (n-2)/2
    //Remember: In a heap, first half of the nodes are parent nodes.
    for(k = (n - 2) / 2; k >= 0; k--){
        j = k;
        key = h[j];                 //key -> parent node value
        i = 2 * j + 1;              //get left child of last parent node

        while(i < n){               //if left child exists
            if((i + 1) < n){        //check whether right child exists               
                if(h[i+1] > h[i])
                i++;                //get the position of the largest child
            }
            if(key < h[i]){         //if key is less than the child node            
                h[j] = h[i];        //move child up
                j = i;
                i = 2 * j + 1;      //find the position of left child
            }
            else
                break;
        }
        h[j] = key;//insert the key at correct position
    }
}


