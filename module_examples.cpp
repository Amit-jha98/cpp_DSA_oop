#include <iostream>
#include <vector>
using namespace std;

void arrayOperations() {
    int arr[5] = {1, 2, 3, 4, 5};
    int matrix[2][2] = {{1, 2}, {3, 4}};
    
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}

int fibonacci(int n) {
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while(left <= right) {
        int mid = left + (right - left)/2;
        if(arr[mid] == target) return mid;
        if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    arrayOperations();
    cout << "\nFibonacci(5): " << fibonacci(5) << endl;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Binary Search for 5: " << binarySearch(arr, 5) << endl;
    
    return 0;
}
