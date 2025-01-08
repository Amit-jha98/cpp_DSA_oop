/*...OUTPUT....
.....if element exist....
enter Size of array: 
5
Enter the elemmnt of array
1 2 3 4 5
Enter the key you want to search:
4
Result (index of key): 3

....if element does not exist...

enter Size of array: 
5
Enter the elemmnt of array
1 2 3 4 5
Enter the key you want to search:
9
Element Does Not Exist

*/

#include <iostream>
using namespace std;
 int linearSearch(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i] ==key) return i;
    }
    return -1;
 }

 int main() {
    int size,key,i;
    cout << "enter Size of array: " << endl;
    cin >>size;
    int arr[size];
    cout << "Enter the elemmnt of array" << endl;++++++
    for (i=0; i < size; i++){
        cin >> arr[i];
    }
    cout << "Enter the key you want to search: " << endl;
    cin >> key;
    if (linearSearch(arr,size,key)== -1){
        cout << "Element Does Not Exist";
    } 
    else {
    cout << "Result (index of key): " <<linearSearch(arr,size,key);
    }
 }