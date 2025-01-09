#include <iostream>
using namespace std;

// Pass by value
void modifyValue_1(int x) {
    x = x + 1;  
}

// Pass by reference
void modifyValue_2(int& x) {
    x = x + 1;  
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

    modifyValue_1(a);  
    modifyValue_2(b);  
    modifyValue_3(&c); 

    cout << "Values after modification: " << endl;
    cout << "a = " << a << " (unchanged)" << endl;
    cout << "b = " << b << " (modified)" << endl;
    cout << "c = " << c << " (modified)" << endl;

    return 0;
}