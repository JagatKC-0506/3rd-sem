#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Doubly Linked List structure
typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

void initDoublyLinkedList(DoublyLinkedList* list) {
    list->head = NULL;
}

// Insert a node at the beginning
void insertAtBeginning(DoublyLinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    newNode->prev = NULL;
    if (list->head != NULL) {
        list->head->prev = newNode;
    }
    list->head = newNode;
}

// Insert a node at the end
void insertAtEnd(DoublyLinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        return;
    }
    Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node from the beginning
int deleteFromBeginning(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return -1; // Return an error code
    }
    Node* temp = list->head;
    int value = temp->data;
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    }
    free(temp);
    return value;
}

// Delete a node from the end
int deleteFromEnd(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return -1; // Return an error code
    }
    Node* temp = list->head;
    if (temp->next == NULL) { // Only one element
        int value = temp->data;
        list->head = NULL;
        free(temp);
        return value;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    int value = temp->data;
    temp->prev->next = NULL;
    free(temp);
    return value;
}

// Traverse the list forward
void traverseForward(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->head;
    printf("Doubly Linked List elements (forward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Traverse the list backward
void traverseBackward(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Doubly Linked List elements (backward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    DoublyLinkedList list;
    initDoublyLinkedList(&list);

    insertAtBeginning(&list, 10);
    insertAtEnd(&list, 20);
    insertAtBeginning(&list, 5);
    insertAtEnd(&list, 30);

    traverseForward(&list);
    traverseBackward(&list);

    printf("Deleted from beginning: %d\n", deleteFromBeginning(&list));
    printf("Deleted from end: %d\n", deleteFromEnd(&list));

    traverseForward(&list);
    traverseBackward(&list);

    return 0;
}
