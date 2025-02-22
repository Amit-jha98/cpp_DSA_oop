/*
(Q.2):- To Insert an Element in an array.

...OUTPUT....

Enter The size of array: 
5
Elements of array are: 2 4 6 8 10
Enter index where you want to add elements:
5
Enter the element you want to add:
9
Array after insertion is:
2 4 6 8 9
*/

#include<stdio.h>

void insert(int arr[], int n, int index, int element){
    if(index<=-1 || index>=n+1){
        printf("Invalid Index");
        return;
    }
    arr[index] = element;

    printf("Array after insertion is: \n");
    for(int i=1; i<=n; i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n,index,elemnt;
    printf("Enter The size of array: \n");
    scanf("%d",&n);

    if(n<0){
        printf("Please Enter a valid number");
        return 0;
    }
    int arr[n];

    printf("Elements of array are: ");
    for(int i=1; i<=n; i++){
        arr[i] = i+i;
        printf("%d ",arr[i]);
    }
    printf("\nEnter index where you want to add elements:\n");
    scanf("%d",&index);
    printf("Enter the element you want to add:\n");
    scanf("%d",&elemnt);
    insert(arr,n,index,elemnt);
    return 0;
}