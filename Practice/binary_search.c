/*
(Q.1):- Binary search an Element in an array.
.....OUTPUT....
Enter Size of array
6
Array is:
1 2 3 4 5 6
Enter an even Number You want to search
6
Elemnt Found at 6

*/


#include<stdio.h>

void linear_search(int arr[], int n, int key){
    int mid=0;
    int low=0;
    int high=n;
    while(low<=high){
        mid = low + (high-low)/2;
        if(arr[mid]==key){
            printf("Element Found at %d",arr[mid]);
            return;
        }else if(arr[mid]>key){
            high=mid-1;
        }else{
             low=mid+1;
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
    printf("\nEnter an even Number You want to search\n");
    scanf("%d",&key);
    if(key%2==0){
    linear_search(arr,n,key);
    }else{
        printf("Enter even number only: ");
    }
    return 0;
}
