/*.....output.....

Enter the number of rows: 3
Enter the number of columns: 3
Enter the elements of the matrix row by row:
1 2 3 4 5 6 7 8 9
Spiral order in matrix-like form:
123
698
745

*/

#include <iostream>
#include <vector>
using namespace std;

void printSpiralInMatrixForm(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<int> spiralOrder;
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            spiralOrder.push_back(matrix[top][j]);
        top++;

        for (int i = top; i <= bottom; i++)
            spiralOrder.push_back(matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                spiralOrder.push_back(matrix[bottom][j]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                spiralOrder.push_back(matrix[i][left]);
            left++;
        }
    }

    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << spiralOrder[index++];
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Spiral order in matrix-like form:" << endl;
    printSpiralInMatrixForm(matrix);

    return 0;
}
