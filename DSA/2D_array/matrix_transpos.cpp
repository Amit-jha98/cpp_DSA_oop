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
    int arr[3][3];
    
    cout << "Enter elements of the 3x3 matrix: " << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Original matrix: " << endl;
    printMatrix(arr, 3);

    transpose(arr, 3);
    
    cout << "Transposed matrix: " << endl;
    printMatrix(arr, 3);

    return 0;
}
