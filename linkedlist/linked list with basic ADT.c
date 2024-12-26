#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Linked list structure
typedef struct LinkedList {
    Node* head;
} LinkedList;

void initLinkedList(LinkedList* list) {
    list->head = NULL;
}

void insertAtBeginning(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtEnd(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int deleteFromBeginning(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return -1; // Return an error code
    }
    Node* temp = list->head;
    int value = temp->data;
    list->head = list->head->next;
    free(temp);
    return value;
}

int deleteFromEnd(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return -1; // Return an error code
    }
    Node* temp = list->head;
    if (temp->next == NULL) { // Only one element
        int value = temp->data;
        free(temp);
        list->head = NULL;
        return value;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node* lastNode = temp->next;
    int value = lastNode->data;
    temp->next = NULL;
    free(lastNode);
    return value;
}

void traverse(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->head;
    printf("Linked List elements are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int search(LinkedList* list, int value) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->data == value) {
            return 1; // Value found
        }
        temp = temp->next;
    }
    return 0; // Value not found
}

void update(LinkedList* list, int oldValue, int newValue) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list\n", oldValue);
}

int main() {
    LinkedList list;
    initLinkedList(&list);

    insertAtBeginning(&list, 10);
    insertAtEnd(&list, 20);
    insertAtBeginning(&list, 5);
    insertAtEnd(&list, 30);

    traverse(&list);

    printf("Deleted from beginning: %d\n", deleteFromBeginning(&list));
    printf("Deleted from end: %d\n", deleteFromEnd(&list));

    traverse(&list);

    if (search(&list, 20)) {
        printf("Value 20 found in the list\n");
    } else {
        printf("Value 20 not found in the list\n");
    }

    update(&list, 20, 25);

    traverse(&list);

    return 0;
}
