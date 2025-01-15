/*...OUTPUT...

 Enter the Number:
5
5 4 3 2 1

*/

#include <iostream>
using namespace std;

void directRecursion(int n) {
    if(n == 0) return;
    cout << n << " ";
    directRecursion(n-1);
}

int main() {
    int n;
    cout << " Enter the Number:" << endl;
    cin >> n;
    directRecursion(n);
    return 0;
}