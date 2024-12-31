/*.....OUTPUT.....
Enter The Size Of Array: 
5
Enter the Element Of The Array:
1 2 3 4 5
Enter The Index Where You Want to change the Value:
4
Enter the value that You Want to Insert:
9
Array is:
1 2 3 4 9
*/


#include <iostream>
using namespace std;
// function for inserting value on index
void insert(int arr[], int size,int index, int value){
    if(index<0 || index>=size){
    cout << "Error Index Value is Equal or greater than Size of array" <<endl;
    return;
}
for(int i=size-1;i>index;i--){
    arr[i]=arr[i-1];
};
arr[index]=value;
}

int main(){
    int i,size,index,value;
    cout << "Enter The Size Of Array: " << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the Element Of The Array: " << endl;
    for(i=0; i<size; i++){
        cin >> arr[i];
    }
    cout << "Enter The Index Where You Want to change the Value: " << endl;
    cin >> index;
    cout << "Enter the value that You Want to Insert: " << endl;
    cin >> value;

   // caling insertion function in main body
    insert(arr,size,index,value);

    cout << "Array is: " << endl;
    for(i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
