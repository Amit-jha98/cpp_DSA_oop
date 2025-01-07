/*....OUTPUT....

Enter the number of rows: 3
Enter the number of columns: 3
Enter the elements of the matrix:
1 2 4 3 5 6 8 9 7
Sorted matrix (row-wise):
1 2 3
4 5 6
7 8 9
Enter the target element to search: 6
Element found at index (1, 2).

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//.....Functions........

//Allocating 2D array dynamically

int** createMatrix(int rows, int cols) {
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    return arr;
}

//sorting Matrix

void sortMatrix(int** arr, int rows, int cols) {
    vector<int> elements;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            elements.push_back(arr[i][j]);
        }
    }

    sort(elements.begin(), elements.end());

    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = elements[index++];
        }
    }
}

//searching in sorted matrix

bool searchMatrix(int** arr, int rows, int cols, int target, int& foundRow, int& foundCol) {
    int i = 0, j = cols - 1;
    while (i < rows && j >= 0) {
        if (arr[i][j] == target) {
            foundRow = i;
            foundCol = j;
            return true;
        }
        if (arr[i][j] > target) j--;
        else i++;
    }
    return false;
}

//deallocating 2D array

void deleteMatrix(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** matrix = createMatrix(rows, cols);

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    sortMatrix(matrix, rows, cols);

    cout << "Sorted matrix (row-wise):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    int foundRow = -1, foundCol = -1; 

    if (searchMatrix(matrix, rows, cols, target, foundRow, foundCol)) {
        cout << "Element found at index (" << foundRow << ", " << foundCol << ")." << endl;
    } else {
        cout << "Element not found in the matrix." << endl;
    }

    deleteMatrix(matrix, rows);

    return 0;
}
