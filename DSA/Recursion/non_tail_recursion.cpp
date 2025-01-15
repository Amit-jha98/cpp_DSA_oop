/*...OUTPUT....

Enter The Number: 
9
Result: 362880

*/

#include <iostream>
using namespace std;

int factorial(int n) {
    if(n == 0) return 1;
    return n * factorial(n-1);
}

int main() {
    int n, result;
    cout << "Enter The Number: " << endl;
    cin >> n;
    result=factorial(n);

    cout << "Result: " << result;
    return 0;

}