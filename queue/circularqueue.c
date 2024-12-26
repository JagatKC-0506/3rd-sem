#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct {
    int data[max];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return (q->front == -1);
}

int isFull(Queue *q) {
    return ((q->rear + 1) % max == q->front);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % max;
        q->data[q->rear] = value;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1; // Return an error code
    } else {
       // int value = q->data[q->front];
        if (q->front == q->rear) {
            // Reset queue after dequeuing last element
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % max;
        }
      //  return value;
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d\t", q->data[i]);
            i = (i + 1) % max;
        }
        printf("%d\n", q->data[i]);
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // This will trigger the overflow message
    display(&q);

    dequeue(&q);
    dequeue(&q);
    display(&q);

    return 0;
}
