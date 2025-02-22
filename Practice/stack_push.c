/*...OUTPUT...
Enter the size of stack
5
stack is:
2 4 6 8 10
Enter the element to be pushed
9
pushed element is 9
New stack is:
2 4 6 8 10 9
*/

#include<stdio.h>

void push(int stack[],int *top, int element){
    if(stack[*top]==-1){
        printf("Stack is empty\n");
    }else{
        (*top)++;
        stack[*top]=element;
        printf("pushed element is %d\n",stack[*top]);
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
    int stack[n];
    int top=n;
    int element;

    printf("stack is: \n");
    for(int i=1;i<=top;i++){
        stack[i]=(i+i);
       
        printf("%d ",stack[i]);
    }
    printf("\n");
    printf("Enter the element to be pushed\n");
    scanf("%d",&element);
    push(stack,&top,element);
    return 0;
}
    
