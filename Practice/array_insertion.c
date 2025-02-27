/*
(Q.2):- To Insert an Element in an array.

...OUTPUT....
Enter The size of array:
8
Elements of array are: 2 4 6 8 10 12 14 16
Enter index where you want to add element (0 to 7):
6
Enter the element you want to add:
98
Array after insertion is:
2 4 6 8 10 12 98 14 16
*/

#include <stdio.h>

void insert(int arr[], int n, int index, int element) {
    // Check for valid index
    if (index < 0 || index >= n) {
        printf("Invalid Index\n");
        return;
    }

    // Shift elements to make space for new element
    for (int i = n - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the element
    arr[index] = element;

    // Print the updated array
    printf("Array after insertion is:\n");
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, index, element;
    
    printf("Enter The size of array:\n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please Enter a valid number\n");
        return 0;
    }

    // Declare array with extra space for insertion
    int arr[n + 1];

    printf("Elements of array are: ");
    // Initialize array starting from index 0
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 2;  // Generate even numbers
        printf("%d ", arr[i]);
    }

    printf("\nEnter index where you want to add element (0 to %d):\n", n - 1);
    scanf("%d", &index);
    
    printf("Enter the element you want to add:\n");
    scanf("%d", &element);
    
    insert(arr, n, index, element);
    
    return 0;
}