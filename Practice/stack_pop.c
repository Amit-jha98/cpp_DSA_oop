/*...OUTPUT...
Enter the size of stack
5
stack is:
2 4 6 8 10
Popped element is 10
New stack is:
2 4 6 8
*/

#include<stdio.h>

void pop(int stack[],int *top){
    if(stack[*top]==-1){
        printf("Stack is empty\n");
    }else{
        printf("Popped element is %d\n",stack[*top]);
        (*top)--;
    }
    printf("New stack is: \n");
    for(int i=1;i<=*top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the size of stack\n");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid size\n");
        return 0;
    }
    int stack[n];
    int top=n;
    printf("stack is: \n");
    for(int i=1;i<=top;i++){
        stack[i]=(i+i);
       
        printf("%d ",stack[i]);
    }
    printf("\n");
    pop(stack,&top);
    return 0;
}
    
