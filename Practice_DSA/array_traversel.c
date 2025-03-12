/*
(Q.1):- To Traverse to Element in an array.
...OUTPUT....

 Enter the size of the array:
5
Enter the element of the array:
1 2 3 4 5
array in forward and revers traversal are respectively:
1 2 3 4 5
5 4 3 2 1

*/

#include <stdio.h>

void traversal(int arr[], int size) {
    int i;
    // Loop For Forward Traversal
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Loop For Backward Traversal
    for (i = size-1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int i, size;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);
    
    int arr[size];  // Variable Length Array (VLA)
    
    printf("Enter the element of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("array in forward and reverse traversal are respectively:\n");
    traversal(arr, size);
    
    return 0;
}