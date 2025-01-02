/*....OUTPUT....

Enter the Lenght of Rows and Columns
3 4
Enter The elements of the Array: 1 2 3 4 5 6 7 8 9 11 22 33
your Array is: 
1 2 3 4
5 6 7 8
9 11 22 33

*/

#include <iostream>
using namespace std;

int main(){
    int x,y,i,j;
    cout << "Enter the Lenght of Rows and Columns" << endl;
    cin >> x >> y;

    int arr[x][y];

    cout << "Enter The elements of the Array: ";

    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            cin >> arr[i][j];
        }
    } 

    cout << "your Array is: " << endl;

    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}