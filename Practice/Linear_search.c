/*
(Q.6):- Linear search an Element in an array.
.....OUTPUT....
Enter Size of array
7
Array is:
1 2 3 4 5 6 7
Enter an odd Number You want to search
5
Element found at index: 5

*/


#include<stdio.h>

void linear_search(int arr[], int n, int key){
    for(int i=1;i<=n;i++){
        if(arr[i]==key){
            printf("Element found at index: %d",arr[i]);   
            return;
        }

    } printf("Element Does not exist");
    
}

int main(){
    int n,key;
    printf("Enter Size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Array is: \n");
    for(int i=1;i<=n;i++){
        arr[i] = i;
        printf("%d ",arr[i]);
    }
    printf("\nEnter an odd Number You want to search\n");
    scanf("%d",&key);
    if(key%2!=0){
    linear_search(arr,n,key);
    }else{
        printf("Enter odd number only: ");
    }
    return 0;
}
