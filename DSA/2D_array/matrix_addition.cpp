/*....OUTPUT.....

Enter Number of Rows: 
3
Enter Element of matrix A:
1 2 3 4 5 6 7 8 9 
Enter Element of matrix B:
9 8 7 6 5 4 3 2 1
Matrix addition is:
10 10 10 
10 10 10
10 10 10

*/

#include <iostream>
using namespace std;

void matrixAddition(int a[][3], int b[][3],int c[][3], int rows) {
    for(int i=0; i<rows;i++) {
        for(int j=0; j<3; j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}


int main() {
    int rows;
    cout << "Enter Number of Rows: " << endl;
    cin >> rows;
    if(rows>0){
    cout << "Enter Element of matrix A: " << endl;
    
    int a[rows][3], b[rows][3], c[rows][3] ;
    
    for(int i=0;i<rows;i++){
        for(int j=0; j<3; j++){
            cin >> a[i][j];
        }
    }

        cout << "Enter Element of matrix B: " << endl;

    for(int i=0;i<rows;i++){
        for(int j=0; j<3; j++){
            cin >> b[i][j];
        }
    }

   cout << "Matrix addition is: " << endl;
    matrixAddition(a,b,c,rows);
        for(int i=0;i<rows;i++){
        for(int j=0; j<3; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    }else{
        cout << "Enter Posetive Number...|-: " << endl;
    }

    return 0;
}