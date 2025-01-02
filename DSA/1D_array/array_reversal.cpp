/*....OUTPUT...
Enter Size of Array: 
5
Enter The Element of the Array:
1 2 3 4 5
Reversed Array is: 5 4 3 2 1

*/

#include <iostream>
using namespace std;

void reversal(int arr[], int size) {
    int start=0, end = size-1;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int size,i;
    cout << "Enter Size of Array: " << endl;
    cin >> size;
    int* arr = new int[size];
    cout << "Enter The Element of the Array: " << endl;
    for (i=0; i<size; i++){
        cin >> arr[i];
    }

    reversal(arr,size);

    cout << "Reversed Array is: ";

    for(i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}