/*...OUTPUT...

....When array is sorted....

Enter The Size Of The Array: 
5
Enter The Element Of The Array:
1 2 3 4 5
Array is Sorted.. (-:

....When array is not sorted....

Enter The Size Of The Array: 
5
Enter The Element Of The Array: 
2 3 1 4 5
Array is not Sorted... )-:

*/

#include <iostream>
using namespace std;

bool isSorted(int arr[], int size){
    for(int i=0; i<size-1; i++){
        if(arr[i]> arr[i+1]) return false;
    }
    return true;
}

int main() {
    int size,i,result;
    cout << "Enter The Size Of The Array: " << endl;
    cin >> size;

    int* arr = new int[size];

    cout << "Enter The Element Of The Array: " <<  endl;
    
    for(i=0; i<size; i++){
        cin >> arr[i];
    }
     result = isSorted(arr,size);

     if(result==1){
        cout << "Array is Sorted.. (-:" << endl;
     }else{
        cout << "Array is not Sorted... )-:" << endl;
     }
   delete[] arr;
   return 0;
}