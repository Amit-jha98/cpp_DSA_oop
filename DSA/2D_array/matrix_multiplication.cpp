/*...OUTPUT...

Enter Lenth Of rows and column: 
3 3
Enter Element of matrix A:
1 2 3 4 5 6 7 8 9
Enter Element of matrix B:
9 8 7 6 5 4 3 2 1
Result
30 24 18
84 69 54
138 114 90

*/

#include <iostream>
using namespace std;

void matrixMultiplication(int a[][3], int b[][3], int c[][3], int rows1,int cols2){
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols2; j++) {
            c[i][j]=0;
            for(int k=0; k<3; k++){
            c[i][j] +=a[i][k]*b[k][j];
            }
        }
    }
}

int main() {
    int rows1,cols2,i,j;
    cout << "Enter Lenth Of rows and column: " << endl;
    cin >> rows1 >> cols2;
    if(rows1>0 && cols2>0){
        int a[rows1][3],b[rows1][3],c[rows1][3];
        cout << "Enter Element of matrix A: " << endl;
        for(i=0;i<rows1;i++){
            for(j=0;j<3;j++){
                cin >> a[i][j];
            }
        }

                cout << "Enter Element of matrix B: " << endl;
        for(i=0;i<rows1;i++){
            for(j=0;j<3;j++){
                cin >> b[i][j];
            }
        }
       matrixMultiplication(a,b,c,rows1,cols2);

       cout << "Result " << endl;
        for(i=0;i<rows1;i++){
            for(j=0;j<3;j++){
                cout << c[i][j] << " ";
            }
            cout << endl;
        }

    } else {
        cout << "Enter Positive Value Of Rows or Columns...|-:" << endl;
    }
    return 0;
}