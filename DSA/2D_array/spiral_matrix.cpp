#include <iostream>
#include <vector>
using namespace std;

// Function to print the spiral order of the matrix in matrix-like form
void printSpiralInMatrixForm(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Create a vector to store the spiral order
    vector<int> spiralOrder;

    // Variables to define the boundaries
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    // Spiral traversal
    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int j = left; j <= right; j++)
            spiralOrder.push_back(matrix[top][j]);
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++)
            spiralOrder.push_back(matrix[i][right]);
        right--;

        // Traverse bottom row (if any)
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                spiralOrder.push_back(matrix[bottom][j]);
            bottom--;
        }

        // Traverse left column (if any)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                spiralOrder.push_back(matrix[i][left]);
            left++;
        }
    }

    // Print the spiral order as a matrix
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << spiralOrder[index++];
        }
        cout << endl; // Move to the next row
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Input the matrix
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Print the spiral order in matrix form
    cout << "Spiral order in matrix-like form:" << endl;
    printSpiralInMatrixForm(matrix);

    return 0;
}
