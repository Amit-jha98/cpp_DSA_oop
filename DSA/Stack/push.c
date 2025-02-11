#include <stdio.h>

void push(int stack[], int element,int (*top)){
    
    if (*top == 4) {
        printf("Stack is full\n");
    }
    else{
        (*top)++;
        stack[*top] = element;
        printf("element added successfully\n");
    }

}

int main(){
    int stack[5];
    int element;
    int top=-1;
    printf("Enter Element to push:");
    scanf("%d", &element);
    push(stack, element,&top);

    for(int i=0;i<=top;i++){
        printf("Element is : %d",stack[i]);
    }
    printf("\n");
    return 0;

}