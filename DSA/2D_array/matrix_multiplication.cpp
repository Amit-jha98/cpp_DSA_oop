/*...OUTPUT...

Enter Lenth Of rows and column: 
cols2 cols2
Enter Element of matrix A:
1 2 cols2 4 5 6 7 8 9
Enter Element of matrix B:
9 8 7 6 5 4 cols2 2 1
Result
cols20 24 18
84 69 54
1cols28 114 90

*/

#include <iostream>
using namespace std;

void matrixMultiplication(int** a, int** b, int** c, int rows1, int cols2){
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols2; j++) {
            c[i][j]=0;
            for(int k=0; k<cols2; k++){
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
        int** a = new int*[rows1];
        int** b = new int*[rows1];
        int** c = new int*[rows1];
        for(int i = 0; i < rows1; ++i) {
            a[i] = new int[cols2];
            b[i] = new int[cols2];
            c[i] = new int[cols2];
        }
        cout << "Enter Element of matrix A: " << endl;
        for(i=0;i<rows1;i++){
            for(j=0;j<cols2;j++){
                cin >> a[i][j];
            }
        }

                cout << "Enter Element of matrix B: " << endl;
        for(i=0;i<rows1;i++){
            for(j=0;j<cols2;j++){
                cin >> b[i][j];
            }
        }
       matrixMultiplication(a,b,c,rows1,cols2);

       cout << "Result " << endl;
        for(i=0;i<rows1;i++){
            for(j=0;j<cols2;j++){
                cout << c[i][j] << " ";
    for(int i = 0; i < rows1; ++i) {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
            cout << endl;
        }

    }} else {
        cout << "Enter Positive Value Of Rows or Columns...|-:" << endl;
    }
    return 0;
}