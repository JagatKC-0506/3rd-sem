#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack[max];
int top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == max - 1);
}

void push(int value) {
    if (isFull()) {
        printf("Stack is full \n");
    } else {
        stack[++top] = value;
    }
}

void pop() {
    if (isEmpty()) {
        printf("stack underflow\n");
    } else {
        top--;
    }
}

void peek() {
    if (isEmpty()) {
        printf("stack is empty\n");
    } else {
        printf("the peek value is %d \n", stack[top]);
    }
}

void display() {
    if (isEmpty()) {
        printf("stack is empty\n");
    } else {
        printf("stack elements are: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60); // This should display "Stack is full"
    display();
    pop();
    pop();
    display();
    peek();
    return 0;
}
