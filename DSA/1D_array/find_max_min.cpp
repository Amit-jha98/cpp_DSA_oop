/*...OUTPUT...
Enter The Size Of The Array: 
8
 Enter The Element Of the Array:
8 4 32 6 3 99 4 99
Max Element is: 99
Min Element is: 3

*/

#include <iostream>
using namespace std;
 int findmax(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
 }

     int findmin(int arr[], int size) {
    int min = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) min = arr[i];
    }
    return min;
 }

 int main() {
    int size,i,result;

    cout << "Enter The Size Of The Array: " << endl;
    cin >> size;

    int* arr = new int[size];
     cout << " Enter The Element Of the Array: " << endl;
     for(i=0; i<size; i++) {
        cin >> arr[i];
     }
      result = findmax(arr,size);
      cout << "Max Element is: " << result << endl;

      result = findmin(arr,size);

      cout << "Min Element is: " << result << endl;

      delete[] arr;
      return 0;
 }