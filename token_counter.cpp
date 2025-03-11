#include <iostream>
#include "lexical_Analyzer.h"

int main() {
    // Put Your Code Here :-
    std::string code = R"(

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    short s = 5;
    long l = 1000000;
    long long ll = 1000000000;

    float f = 3.14f;
    double d = 3.14159;

    char c = 'A';
    wchar_t w = L'β';

    bool isTrue = true;

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


    return 0;
}

)";
    lexicalAnalyzer(code);
    return 0;
}
