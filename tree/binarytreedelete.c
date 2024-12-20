#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int val) {
    struct node *newNode = malloc(sizeof(struct node));
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

struct node *findMin(struct node *root) {
    if (root == NULL)
        return NULL;
    else {
        if (root->left == NULL) {
            return root;
        } else {
            return findMin(root->left);
        }
    }
}

struct node *delete1(int x, struct node *root) {
    struct node *temp;
    if (root == NULL) {
        printf("Element not found\n");
        return root;
    } else if (x < root->key) {
        root->left = delete1(x, root->left);
    } else if (x > root->key) {
        root->right = delete1(x, root->right);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        temp = findMin(root->right);
        root->key = temp->key;
        root->right = delete1(temp->key, root->right);
    }
    return root;
}

void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("\t%d", root->key);
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

    printf("Inorder traversal before deletion:\n");
    inorder(root);
    printf("\n");

    int x;
    printf("Enter the value you want to delete: ");
    scanf("%d", &x);
    root = delete1(x, root);

    printf("Inorder traversal after deletion:\n");
    inorder(root);
    printf("\n");

    return 0;
}
