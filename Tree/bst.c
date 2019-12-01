#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int data;
    struct tnode *left;
    struct tnode *right;
};


void insert(struct tnode**,int);
struct tnode* rinsert(struct tnode *, int);

struct tnode* delete(struct tnode*, int);
struct tnode* rdelete(struct tnode*, int);
struct tnode * minNode(struct tnode* node);

void inorder(struct tnode*);
void preorder(struct tnode*);
void postorder(struct tnode*);


int internalNodesCount(struct tnode *t );
int countNodes(struct tnode *tree);
int leafCount(struct tnode *);

int sumNodes(struct tnode *t);
int sumLeaves(struct tnode * t);

int height(struct tnode *);


int main(){
    struct tnode *root;
    int ch, num, n;
    root = NULL;
    while(1){
        printf("\n1.  Insert");
        printf("\n2.  Traversals: Preorder, Postorder, Inorder");   
        printf("\n3.  Delete a node");
        printf("\n4.  Number of nodes, leaves, internal leaves");
        printf("\n5.  Sum of nodes, leaves");
        printf("\n6.  Height of the tree");
        printf("\n7.  Exit\n\n");
        
        scanf("%d",&ch);
       
        switch(ch){
            case 1: printf("Enter the element: ");
                    scanf("%d",&num);
                    root = rinsert(root,num);           //recursive
                    //insert(&root,num);                //iterative insertion
                    break;

            case 2: printf("Preorder:     ");
                    preorder(root);

                    printf("\nPostorder:    ");
                    postorder(root);

                    printf("\nInorder:      ");
                    inorder(root);
                    printf("\n");

                    break; 

            case 3: printf("Enter the node to be deleted: ");
                    scanf("%d", &num);
                    // root = delete(root, num);        //iterative deletion
                    root = rdelete(root, num);          //recursive
                    break;

            case 4: printf("\nNumber of nodes = %d", countNodes(root));
                    printf("\nNumber of leaf nodes = %d", leafCount(root));
                    printf("\nNumber of internal nodes = %d\n", internalNodesCount(root));
                    break;

            case 5: printf("\nSum of all the node elements : %d", sumNodes(root));
                    printf("\nSum of leaves : %d\n", sumLeaves(root));
                    break;

            case 6: printf("\nHeight of tree = %d\n", height(root));
                    break;    

            default: exit(0);
        }
    }
}    


//iterative function to insert a node in BST
void insert(struct tnode **t, int x){
    struct tnode *temp, *curr, *prev;

    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->data = x;
    temp->right = temp->left=NULL;

    curr = *t;
    prev = NULL;

    if(curr == NULL)                    //first node
        *t = temp;
    else{
        while(curr != NULL){
            prev = curr;
            if(x < curr->data)
                curr = curr->left;      //move left
            else
                curr = curr->right;     //move right
        }
        if(x < prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }
}


//recursive function to insert a node in BST
struct tnode* rinsert(struct tnode *t, int x){
    struct tnode* temp;
    if(t == NULL){
        temp = (struct tnode*)malloc(sizeof(struct tnode));
        temp->data = x;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(x < t->data)
        t->left = rinsert(t->left, x);
    else
        t->right = rinsert(t->right, x);
    return t;
}


//Finds node with minimum value
struct tnode * minNode(struct tnode* node) { 
    struct tnode* current = node; 
  
    // Find the leftmost leaf 
    while (current && current->left != NULL)            //Similarly, traverse to right subtree (current->right) 
        current = current->left;                        //to find largest node 
  
    return current; 
} 


//recursive function to delete a node
// Cases to consider
// 1. Deleting leaf node
// 2. Deleting node with single child
// 3. Deleting node with both children
struct tnode* rdelete(struct tnode* root, int key) { 

    if (root == NULL) {
        printf("Node not found\n");
        return root; 
    }
  
    // key lies in left subtree 
    if (key < root->data) 
        root->left = rdelete(root->left, key); 
  
    // keylies in right subtree 
    else if (key > root->data) 
        root->right = rdelete(root->right, key); 
  
    // if key is same as root's key
    else{ 
        if (root->left == NULL){                    //node with only one child or no child  
            struct tnode *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL){ 
            struct tnode *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children
        // Get the inorder successor (smallest in the right subtree) 
        struct tnode* temp = minNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = rdelete(root->right, temp->data); 
    } 
    return root; 
} 


//function to delete a given element
struct tnode *delete(struct tnode *root, int x){
    struct tnode *temp, *curr, *prev, *q;
    
    curr = root;
    prev = NULL;
     
    while((curr != NULL) && (curr->data != x)){
        prev = curr;
        if(x < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(curr == NULL)
        printf("Node not found\n");
    else{
        if(curr->left == NULL)
            q = curr->right;                //address of the right subtree
        else if(curr->right==NULL)
            q = curr->left;                 //address of the left subtree
        else{                               //both the subtrees are present
         
            //find the inorder successor
            temp = curr->right;
            while(temp->left != NULL)
                temp = temp->left;
            
            //inorder successor found(temp)     
            temp->left = curr->left;
            q = curr->right;
        }
        if(prev == NULL){                    //deleting root
            free(curr);
            return q;                        //new root
        }
        else if(curr == prev->left)
            prev->left = q;
        else
            prev->right = q;
        free(curr);
    }
    return root; 
}


//Preorder traversal
void preorder(struct tnode *t){
    if(t != NULL){
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
   }
}


//Postorder Traversal
void postorder(struct tnode *t){
    if(t != NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
   }
}


//Inorder traversal
void inorder(struct tnode *t){
    if(t != NULL){
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}


/*****************************************************************************************
        The following functions are applicable to both binary tree and BST.
******************************************************************************************/


//Count number of nodes in the tree
int countNodes(struct tnode *root){
    if (root ==NULL)                                           // Base case
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
    // root node + number of nodes in left subtree and right subtree
}


// Alternate code to count the number of nodes
// int countNodes(struct tnode *tree){
//     int c =  1;             //root itself should be counted
//     if (tree ==NULL)
//         return 0;
//     else{
//         c += countNodes(tree->left);
//         c += countNodes(tree->right);
//         return c;
//     }  
// }


//Number of leaf nodes
int leafCount(struct tnode *root){
    if(root == NULL)                                                // Base case
        return 0;
    if((root->left == NULL) && (root->right == NULL))
        return 1;

    return leafCount(root->left) + leafCount(root->right);
    //number of nodes in left subtree and right subtree
} 


// Number of internal nodes -- (other than leaf nodes)
int internalNodesCount(struct  tnode *root){
    if (root == NULL || (root->left == NULL && root->right == NULL))        // Base case
        return 0; 
  
    // If node has at least one child
    return 1 + internalNodesCount(root->left) + internalNodesCount(root->right); 
}


//Sum of all the tree elements
int sumNodes(struct tnode *root){   
    if(root == NULL)
        return 0;
    if(root->right == NULL && root->left == NULL)
        return root->data;
    return  root->data + sumNodes(root->left) + sumNodes(root->right);       
    //node value + sum of left tree + sum of right
}


//Sum of all the leaf nodes
int sumLeaves(struct tnode * root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    return sumLeaves(root->left) + sumLeaves(root->right);  
    //sum of left tree + sum of right  
}


//Height of the tree  
int height(struct tnode *root){
    if(root == NULL)                                        //-1 if tree doesn't exist
        return -1;
    if((root->left == NULL) && (root->right == NULL))       //height = 0 if there's only one(root) node 
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    if(l > r)                                               //find subtree with more height
        return (l + 1);
    return (r + 1);
}


