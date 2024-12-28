#include <iostream>
using namespace std;

int main() {
    // Integer types
    int a = 10;
    short s = 5;
    long l = 1000000;
    long long ll = 1000000000;

    // Floating point types
    float f = 3.14f;
    double d = 3.14159;

    // Character types
    char c = 'A';
    wchar_t w = L'β';

    // Boolean type
    bool isTrue = true;

    // Display all variables
    cout << "Integer types:" << endl;
    cout << "int: " << a << endl;
    cout << "short: " << s << endl;
    cout << "long: " << l << endl;
    cout << "long long: " << ll << endl;

    cout << "\nFloating point types:" << endl;
    cout << "float: " << f << endl;
    cout << "double: " << d << endl;

    cout << "\nCharacter types:" << endl;
    cout << "char: " << c << endl;
    cout << "wchar_t: " << w << endl;

    cout << "\nBoolean type:" << endl;
    cout << "bool: " << isTrue << endl;

    return 0;
}
