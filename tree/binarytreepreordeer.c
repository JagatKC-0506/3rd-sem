#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int);
struct node *insert(struct node *root,int val){
if(root == NULL)
    return getNewNode(val);
if(root->key<val)
    root->right = insert(root->right,val);
else if(root->key > val)root->left=insert(root->left,val);

return root;
}

struct node *getNewNode(int val){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key =val;
    newNode->left =NULL;
    newNode->right =NULL;
    return newNode;
}
void preorder(struct node *root){
    if(root == NULL) return;
    printf("\t %d",root -> key);
    preorder(root ->left);
    preorder(root->right);
}
 int main(){
    struct node *root = NULL;
    root = insert(root ,20);
    root = insert(root , 30);
    root = insert(root ,7);
    root = insert(root , 15);
     root = insert(root , 35);
      root = insert(root , 95);
       root = insert(root , 8);
        root = insert(root , 6);
         root = insert(root , 19);
          root = insert(root , 39);
    preorder(root);
    return 0;
 }