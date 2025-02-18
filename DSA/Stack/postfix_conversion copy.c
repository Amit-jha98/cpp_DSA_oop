#include<stdio.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char operator) {
    switch(operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void postfix_converter(char infix[]){
    char stack[MAX];
    int top=0;
    char postfix[MAX];
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);

}

int main(){
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    postfix_converter(infix);
    return 0;
}