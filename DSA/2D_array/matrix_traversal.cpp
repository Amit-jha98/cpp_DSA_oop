/*....OUTPUT....

Enter  rows Of Array: 
3
enter element of matrix: 
1 2 3 4 5 6 7 8 9
Row-Major traversal:
1 2 3
4 5 6
7 8 9
Column-Major traversal:
1 4 7
2 5 8
3 6 9

*/

#include <iostream>
using namespace std;

void  rowsMajorTraversal(int arr[][3],int  rows) {
    for(int i = 0; i <  rows; i++) {
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void columnMajorTraversal(int arr[][3],int  rows) {
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i <  rows; i++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main () {
    int  i,j, rows;
    cout << "Enter  rows Of Array: " << endl;
    cin >>  rows;
    int arr[rows][3];

    cout << "enter element of matrix: " << endl;
    for(i=0; i< rows; i++){
        for(j=0; j< 3; j++){
            cin >> arr[i][j];
        }
    }
    cout << "Row-Major traversal: " << endl;
    rowsMajorTraversal(arr,rows);

    cout << "Column-Major traversal: " << endl;
    columnMajorTraversal(arr,rows);

    return 0;
}