/*.....OUTPUT....
Enter the number of elements: 10
Total Odd Number are:
1 3 5 7 9
And their sum is 25
*/

#include<stdio.h>

void traversel(int arr[],int n){
    int sum=0;
    printf("Total Odd Number are: \n");
    for(int i=0; i<=n;i++){
        arr[i]=i;
        if(i%2!=0){
            printf("%d ",arr[i]);
            sum = sum +arr[i];
        } 
    }
    printf("\nAnd their sum is %d",sum);
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr
    [n];
    if(n>=1){
   traversel(arr,n);
    }
 else{
        printf("Please Enter a valid number");
    }
    return 0;
}