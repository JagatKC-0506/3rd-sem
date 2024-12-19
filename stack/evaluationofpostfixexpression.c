#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 100
typedef struct { // s structure
int data[MAX];
int top;
} Stack;
void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX - 1; }
void push(Stack *s, int value) {
if (isFull(s)) {
printf("Stack Overflow\n");
exit(1);
}
s->data[++(s->top)] = value;
}
int pop(Stack *s) {
if (isEmpty(s)) {
printf("Stack Underflow\n");
exit(1);
}
return s->data[(s->top)--];
}
int evaluatePostfix(char *expression) {
Stack s;
initStack(&s);
for (int i = 0; expression[i] != '\0'; i++) {
char ch = expression[i];
// if the character is a digit, push it onto the s
if (isdigit(ch)) { push(&s, ch - '0'); }
// if the character is an operator, pop two elements and perform the operation
else {
int val2 = pop(&s);
int val1 = pop(&s);
switch (ch) {
case '+':
push(&s, val1 + val2);
break;
case '-':
push(&s, val1 - val2); break;
case '*':
push(&s, val1 * val2); break;
case '/':
if (val2 == 0) {
printf("Division by zero error\n"); exit(1);
}
push(&s, val1 / val2); break;
case '^':
push(&s, pow(val1, val2)); break;
default:
printf("Invalid operator: %c\n", ch); exit(1);
}
}
}
// the final result is on the top of the s
return pop(&s);
}
// main program to demonstrate the use of evaluation
int main() {
char postfix[MAX];
printf("Enter a postfix expression (e.g., 53+62/*): ");
scanf("%s", &postfix);
int result = evaluatePostfix(postfix);
printf("The result of the postfix expression is: %d\n", result);
return 0;
}