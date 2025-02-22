/*.....OUTPUT....
Enter The size of array: 
5
Elements of array are: 2 4 6 8 10
Enter index where you want to add elements:
5
Array after deleteion is:
2 4 6 8

*/

//no need to write comments (bas output or code likhe)

#include<stdio.h>

void delete(int arr[], int *n, int index){
    //check for valid index value 
    if(index<=-1 || index>=*n+1){
        printf("Invalid Index");
        return;
    }
   //shift and remove element 
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;


    printf("Array after deleteion is: \n");
    for(int i=1; i<=*n; i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n,index;
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

    //here we will pass adress of size of matrix 
    delete(arr,&n,index);
    return 0;
}