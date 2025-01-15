/*....OUTPUT.....

Enter The Value of Number: 
5
Result of 1st Function is:
5 4 3 2 1
Result of 2nd Function is:
5 4 3 2 1

*/

#include <iostream>
using namespace std;
//Decleration of function ...very very important
void functionA (int n);
void functionB (int n);

void functionA(int n) {
    if(n <= 0) return;
    cout << n << " ";
    functionB(n-1); // function A call function B
}

void functionB(int n) {
    if(n <= 0) return;
    cout << n << " ";
    functionA(n-1); // Function B call function A
}

int main() {
    int n;
    cout << "Enter The Value of Number: " << endl;
    cin >> n;

    cout << "Result of 1st Function is: " << endl;
    functionA(n);
    cout << endl;

    cout << "Result of 2nd Function is: " << endl;
    functionB(n);

    return 0;
}