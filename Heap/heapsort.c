//Heapsort
//Uses top down approach to create initial heap

#include <stdio.h>
 
void bottom_up(int*, int);
void top_down(int*, int);
void heapsort(int*, int);
void heapify(int*, int);

int main(){
    int h[100];     //heap size;
    int i, n;       //no of elements
    printf("Enter the no of elements: \n");
    scanf("%d", &n);
    
    printf("Enter the elements: \n");
    
    for(i = 0; i < n; i++)
        scanf("%d", &h[i]);

    heapsort(h,n);

    printf("After sorting: \n");
    for(i = 0; i < n; i++)
        printf("%d ", h[i]);
    printf("\n\n");
}


void heapsort(int *h, int n){
    int i,t;
    top_down(h, n);                             //create initial heap

    for(i = n-1; i > 0; i--){                   //swap first and last element
        t = h[0];
        h[0] = h[i];
        h[i] = t;
        heapify(h, i);                          //recreate heap for remaining elements
    }                                           // i specifies remaining number of elements
}


void heapify(int *h, int n){                    
    int i, j, key;

    j = 0;                      //start with the root
    key = h[j];
    i = (2 * j) + 1;            //left child index value

    while(i < n){               //if left child exists
        if((i + 1) < n){        //check whether right child exists       
            if(h[i+1] > h[i])
            i++;                //position of the largest child
        }
        if(key < h[i]){         //if key is less than the child node
            h[j] = h[i];        //move child up -- swap
            j = i;
            i = 2 * j + 1;      //find position of left child
        }
        else
            break;
    }
    h[j] = key;                 //insert the key at correct position
}
       

//top down approach to create heap
void top_down(int *h, int n){
    int i, j, key, k;

    for(k = 1; k < n; k++){
        i = k;
        key = h[i];
        j = (i - 1) / 2;

        //repeat until the value of the parent
        //is less than the key 
        //or root is reached
        while((i > 0) && (h[j] < key)){
            h[i] = h[j];            //move the parent down
            i = j;
            j = (i - 1) / 2;        //find new parent
        }
        h[i] = key;                 //insert key at proper position
    }
}       

