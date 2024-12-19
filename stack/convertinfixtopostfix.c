#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 3;
}

void infixToPostfix(char* infix, char* postfix) {
    char *p = infix, *q = postfix;
    char ch;
    while (*p != '\0') {
        ch = *p;
        if (isalnum(ch)) {
            *q = ch;
            q++;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while ((ch = pop()) != '(') {
                *q = ch;
                q++;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                *q = pop();
                q++;
            }
            push(ch);
        }
        p++;
    }
    while (top != -1) {
        *q = pop();
        q++;
    }
    *q = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
