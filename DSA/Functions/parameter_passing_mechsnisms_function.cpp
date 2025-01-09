#include <iostream>
using namespace std;

// Pass by value
void modifyValue_1(int x) {
    x = x + 1;  // Original value unchanged
}

// Pass by reference
void modifyValue_2(int& x) {
    x = x + 1;  // Original value modified
}

// Pass by pointer
void modifyValue_3(int* x) {
    *x = *x + 1;  // Original value modified
}

int main() {
    int a = 5;
    int b = 5;
    int c = 5;

    cout << "Initial values: " << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    modifyValue_1(a);  // Pass by value
    modifyValue_2(b);  // Pass by reference
    modifyValue_3(&c); // Pass by pointer

    cout << "Values after modification: " << endl;
    cout << "a = " << a << " (unchanged)" << endl;
    cout << "b = " << b << " (modified)" << endl;
    cout << "c = " << c << " (modified)" << endl;

    return 0;
}