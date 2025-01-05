#include <iostream>
#include <vector>
using namespace std;

// Function to display the matrix in matrix form
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to perform spiral traversal and return a new matrix in spiral order
vector<vector<int>> spiralMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return {};
    int cols = matrix[0].size();

    vector<vector<int>> spiral(rows, vector<int>(cols, 0)); // Resultant matrix
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    int valueIndex = 0;  // Keeps track of the next element to be placed
    vector<int> elements; // To store spiral order elements

    // Collect elements in spiral order
    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int j = left; j <= right; j++)
            elements.push_back(matrix[top][j]);
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++)
            elements.push_back(matrix[i][right]);
        right--;

        // Traverse bottom row (if any)
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                elements.push_back(matrix[bottom][j]);
            bottom--;
        }

        // Traverse left column (if any)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                elements.push_back(matrix[i][left]);
            left++;
        }
    }

    // Fill the resultant matrix row by row
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            spiral[i][j] = elements[valueIndex++];
        }
    }

    return spiral;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Dynamically create the matrix
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Display the matrix before traversal
    cout << "Matrix before spiral traversal:" << endl;
    displayMatrix(matrix);

    // Perform spiral traversal and get the resultant matrix
    vector<vector<int>> spiral = spiralMatrix(matrix);

    // Display the resultant spiral matrix
    cout << "Matrix in spiral order:" << endl;
    displayMatrix(spiral);

    return 0;
}
