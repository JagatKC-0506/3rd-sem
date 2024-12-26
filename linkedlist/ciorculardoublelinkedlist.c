#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Circular Doubly Linked List structure
typedef struct CircularDoublyLinkedList {
    Node* head;
} CircularDoublyLinkedList;

void initCircularDoublyLinkedList(CircularDoublyLinkedList* list) {
    list->head = NULL;
}

// Insert a node at the beginning
void insertAtBeginning(CircularDoublyLinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (list->head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->head = newNode;
    } else {
        Node* tail = list->head->prev;
        newNode->next = list->head;
        newNode->prev = tail;
        tail->next = newNode;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// Insert a node at the end
void insertAtEnd(CircularDoublyLinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (list->head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->head = newNode;
    } else {
        Node* tail = list->head->prev;
        newNode->next = list->head;
        newNode->prev = tail;
        tail->next = newNode;
        list->head->prev = newNode;
    }
}

// Delete a node from the beginning
int deleteFromBeginning(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return -1; // Return an error code
    }
    Node* temp = list->head;
    int value = temp->data;
    if (temp->next == list->head) { // Only one element
        list->head = NULL;
        free(temp);
        return value;
    }
    Node* tail = list->head->prev;
    list->head = temp->next;
    list->head->prev = tail;
    tail->next = list->head;
    free(temp);
    return value;
}

// Delete a node from the end
int deleteFromEnd(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return -1; // Return an error code
    }
    Node* tail = list->head->prev;
    int value = tail->data;
    if (tail->next == list->head) { // Only one element
        list->head = NULL;
        free(tail);
        return value;
    }
    Node* newTail = tail->prev;
    newTail->next = list->head;
    list->head->prev = newTail;
    free(tail);
    return value;
}

// Traverse the list forward
void traverseForward(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->head;
    printf("Circular Doubly Linked List elements (forward): ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n");
}

// Traverse the list backward
void traverseBackward(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = list->head->prev;
    printf("Circular Doubly Linked List elements (backward): ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != list->head->prev);
    printf("\n");
}

int main() {
    CircularDoublyLinkedList list;
    initCircularDoublyLinkedList(&list);

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
