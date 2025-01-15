/*...OUTPUT.....

Enter Value of N: 
8
result is: 40320

*/

#include <iostream>
using namespace std;

int factorial(int n,int acc = 1) {
    if(n == 0) return acc;
    return factorial(n-1,n*acc);
}

int main() {
    int n,acc;

    cout << "Enter Value of N: " << endl;
    cin >> n;

    acc=factorial(n);
    cout << "result is: " << acc << endl;
    return 0;
}