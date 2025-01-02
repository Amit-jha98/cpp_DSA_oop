/*....OUTPUT....

....when elememt exist...

Enter size of Array: 
5
 enter elemnt of the array:
1 2 3 4 5
enter element that You Want to search:
4
Elemnt Exist At Index: 3

.....When does not Exist....

5
 enter elemnt of the array:
1 2 3 4 5
enter element that You Want to search:
4
Elemnt Exist At Index: 3
PS C:\Users\Amitj\cpp_DSA_oops\DSA\1D_array\output> & .\'binary_search.exe'
Enter size of Array: 
6
 enter elemnt of the array:
1 2 3 4 5 6
enter element that You Want to search:
9
Element Does NoT Exist:

*/

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    for(int i = 0; i < size-1; i++) {
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}

int binarySearch(int arr[], int size, int key){
    int left = 0, right = size -1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid]==key) return mid;
        if(arr[mid]< key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(){
    int size,key;
    cout << "Enter size of Array: " << endl;
    cin >> size;
    int arr[size];

    cout << " enter elemnt of the array: " << endl;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    cout << "enter element that You Want to search: " << endl;
     cin >> key;

     if(isSorted(arr,size)== 1){
      int result = binarySearch(arr,size,key);
     if(result==-1){
        cout << "Element Does NoT Exist: ";
     } else{
        cout << "Elemnt Exist At Index: " << result;
     }}else{
        cout << "Array is not Sorted." << endl;
     }

     return 0;

}