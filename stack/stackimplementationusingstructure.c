#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        // return -1;
    } else {
    (s->top)--;
    }
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        // return -1;
    } else {
        return s->data[s->top];
    }
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i =0; i <= s->top; i++) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60); // This should display "Stack overflow"

    display(&s);

    pop(&s);
    pop(&s);

    display(&s);

    printf("Peek element: %d\n", peek(&s));

    return 0;
}
