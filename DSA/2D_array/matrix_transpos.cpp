#include<iostream>
using namespace std;

void transpose(int arr[][3], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = i; j < 3; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void printMatrix(int arr[][3], int rows) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, 3);

    transpose(matrix, 3);

    cout << "Transposed Matrix:" << endl;
    printMatrix(matrix, 3);

    return 0;
}