/*....OUTPUT....
Enter The Size Of The Array: 
5
Element Of The Array:
1 2 3 4 5
Result is: 16
*/

#include <iostream>
#include <climits>
using namespace std;

int maxSubArraySum(int arr[], int size){
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];

    for(int i = 0; i < size; i++){
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
    }

    int main() {
        int size,i,result;
        cout << "Enter The Size Of The Array: " << endl;
        cin >> size;

        int* arr = new int[size];
        cout << "Element Of The Array: " << endl;
        for(i=0; i<size; i++){
            cin >> arr[i];
        }
        result = maxSubArraySum(arr,size);

        cout << "Result is: " << result << endl;

        delete[] arr;
        return 0;
    }
