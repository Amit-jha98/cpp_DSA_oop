/*....OUTPUT....

Enter Size of Array: 
5
Enter The Element Of the array:
1 2 3 4 5
result is:
2 3 4 5 1

*/

#include <iostream>
using namespace std;

void leftRotate(int arr[], int size) {
    int temp = arr[0];

    for(int i = 0; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    arr[size-1] = temp;
}

int main() {
    int size,i;
    cout << "Enter Size of Array: " << endl;
    cin >> size;
    int* arr = new int[size];
    cout << "Enter The Element Of the array: " << endl;
    for(i=0;i<size;i++){
        cin >> arr[i];
    } 

    cout << "result is: " << endl;

    leftRotate(arr,size);
    
    for(i=0;i<size;i++){
        cout << arr[i] <<" ";
    }
    delete[] arr;
     return 0;
}