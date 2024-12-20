#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int val) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int val) {
    if (root == NULL)
        return getNewNode(val);
    if (root->key < val)
        root->right = insert(root->right, val);
    else if (root->key > val)
        root->left = insert(root->left, val);

    return root;
}

struct node *findMax(struct node *root) {
    if (root == NULL)
        return NULL;
    else {
        if (root->right == NULL) {
            return root;
        } else {
            return findMax(root->right);
        }
    }
}

void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("\t %d", root->key);
    inorder(root->right);
}

int main() {
    struct node *root = NULL;
    root = insert(root, 75);
    root = insert(root, 95);
    root = insert(root, 65);
    root = insert(root, 68);
    root = insert(root, 35);
    root = insert(root, 39);
    root = insert(root, 40);
    root = insert(root, 7);
    root = insert(root, 13);
    root = insert(root, 15);
    root = insert(root, 100);
    inorder(root);
    printf("\nthe minimum value is: %d\n", findMax(root)->key);
    return 0;
}
