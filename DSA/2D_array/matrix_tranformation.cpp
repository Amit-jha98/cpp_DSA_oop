#include <iostream>
using namespace std;

// Rotate Matrix 90 degrees clockwise
void rotateMatrix(int arr[][3], int n) {
    // Step 1: Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(arr[i][j], arr[i][n - 1 - j]);
        }
    }
}


void printMatrix(int arr[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[3][3];

    cout << "Enter elements of the 3x3 matrix: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Original matrix: " << endl;
    printMatrix(arr, 3);

    rotateMatrix(arr, 3);

    cout << "Matrix after rotating 90 degrees clockwise: " << endl;
    printMatrix(arr, 3);

    return 0;
}
