#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

void infix_to_postfix(char *infix) {
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
    
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix);
    return 0;
}




// #include<stdio.h>

// // void postfix_converter(infix,n){
// //     char stack[n];
// //     int top=0;
// // }

// char get_infix(int (n)){
//     char stack[n];
//     char infix_stack[n];
//     printf("Enter the Infix Expression: \n");
//     for(int i = 0; i <=n; i++){
//         scanf("%c",&stack[i]);
//         infix_stack[i] = stack[i];
//     }

//     printf("Your Infix Expression is:");
//     for(int i = 0; i <=n; i++){
//         printf("%c",infix_stack[i]);
//     }
//     postfix_converter(infix_stack,n);
//     return stack;
// }



// void postfix_converter(char infix_stack[],int n){
    
//     int top=0;
//     char elements[n];
//     char symbols[n];
//     char opertor[20] = {"+-*/^**"};
//     while(top<=n) {
//         for(int i=0; i<=n;i++){
//             symbols[i] = infix_stack[i];
//             if(symbols[i] != opertor[i]){
//                 printf("%c",symbols[i]);
//                 return symbols;
//             }
//         }

//     }
// }

// // char write_symbols(char symbols,int n){
// //     char postfix_stack[n];
// // }

// // void post_infix(int n){
// //     char stack[n];
// //     printf("Your Infix Expression is: \n");
// //     for(int i = 0; i < n; i++){
// //         printf("%c",&stack);
// //     }
// // }

// int main(){
//     int n;
//     char infix_stack[n];
//     printf("Enter the lenght of Stack: \n");
//     scanf("%d",&n);
//     get_infix(n);
//     // for(int i = 0; i <=n; i++){
//     //     scanf("%c",&stack[i]);
//     //     infix_stack[i] = stack[i];
//     // }
//     // postfix_converter(infix_stack,n);
//     // post_infix(n);
//     return 0;
// }
    

