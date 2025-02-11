/*....OUTPUT.....

Old stck is: 
1 2 3 4 5 Element popped is : 5
After poping new stack is:
1 2 3 4

*/

#include <stdio.h>

void pop(int stack[], int (*top)){
    if (*top == -1){
        printf("stack is empty\n");
    }else{
        printf("Element popped is : %d\n",stack[*top]);
        (*top)--;
    }
}

int main() {
    int stack[5]={1,2,3,4,5};
    int top=4;
    printf("Old stck is: \n");
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
    pop(stack,&top);
    printf("After poping new stack is:\n");
    for(int i=0;i<=top;i++){
    printf("%d ",stack[i]);
}
    return 0;
}