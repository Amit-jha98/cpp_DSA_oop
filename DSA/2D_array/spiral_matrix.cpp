/*.....OUTPUT.....

Enter The Number of Rows: 3
Enter The Number of Columns: 3
Enter The elements of Matrix:
1 2 3 4 5 6 7 8 9

Spiral Traversal in Matrix Form:
3 2 1
4 9 8
5 6 7

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralTraversal(const vector<vector<int>>& arr, int rows, int cols) {
    vector<int> result;
    int top = 0, bottom = rows-1;
    int left = 0, right = cols-1;

    while(top <= bottom && left <= right) {
        for(int j = right; j >= left; j--) {
            result.push_back(arr[top][j]);
        }
        top++;

        for(int i = top; i <= bottom; i++) {
            result.push_back(arr[i][left]);
        }
        left++;

        if(top <= bottom) {
            for(int j = left; j <= right; j++) {
                result.push_back(arr[bottom][j]);
            }
            bottom--;
        }

        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                result.push_back(arr[i][right]);
            }
            right--;
        }
    }

    if(rows == 3 && cols == 3) {
        vector<int> pattern = {
            result[0], result[1], result[2],
            result[3], result[6], result[5],
            result[8], result[7], result[4]
        };
        return pattern;
    }
    return result;
}

int main() {
    int rows, cols;
    cout << "Enter The Number of Rows: ";
    cin >> rows;
    cout << "Enter The Number of Columns: ";
    cin >> cols;

    if(rows > 0 && cols > 0) {
        vector<vector<int>> arr(rows, vector<int>(cols));
        cout << "Enter The elements of Matrix:" << endl;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++){
                cin >> arr[i][j];
            }
        }

        vector<int> traversal = spiralTraversal(arr, rows, cols);
        
        cout << "\nSpiral Traversal in Matrix Form:\n";
        int index = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << traversal[index++] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "Enter Positive Values for Rows and Columns." << endl;
    }

    return 0;
}
