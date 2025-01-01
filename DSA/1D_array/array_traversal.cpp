/*...OUTPUT....

 Enter the size of the array:
5
Enter the element of the array:
1 2 3 4 5
array in forward and revers traversal are respectively:
1 2 3 4 5
5 4 3 2 1

*/

#include <iostream>
using namespace std;

void traversal(int arr[],int size){ 
    int i;
    //Loop For Forward Traversal
    for (i=0; i<size; i++){
        cout << arr[i] << " ";
      }
      cout << endl;
  //Loop For Backward Traversal
  for(i= size-1 ; i>=0; i--){
    cout << arr[i] << " ";
  }
return ;
}

int main (){
    int i,size;
    cout <<" Enter the size of the array: " << endl;
    cin >> size;
    int arr[size];

    cout << "Enter the element of the array: " << endl;

    for(i=0; i<size; i++){
        cin >> arr[i];
    }
    cout << "array in forward and revers traversal are respectively: " << endl;
    traversal(arr,size);
    return 0;
}