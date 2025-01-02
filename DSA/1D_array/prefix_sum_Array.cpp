/*....OUTPUT.....

Enter the size: 
5
Enter The element of Array:
7 5 3 8 9
Result is: 7 12 15 23 32

*/

#include <iostream>
using namespace std;
 void buildPrefixSum(int arr[], int prefixSum[], int size){
    prefixSum[0] = arr[0];
    for(int i=0; i<size; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
 }

 int main() {
    int size,i;
    cout << "Enter the size: " << endl;
    cin >> size;
    int* prefixSum = new int[size];
    int* arr = new int[size];

    cout << "Enter The element of Array: " << endl;
    for(i=0; i<size; i++){
        cin >> arr[i];
    }
    buildPrefixSum(arr,prefixSum,size);
    cout << "Result is: ";
    for(i=0;i<size;i++) {
        cout << prefixSum[i] << " ";
    }

    delete[] arr;
    return 0;
 }