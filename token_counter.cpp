#include <iostream>
#include "lexical_Analyzer.h"

int main() {
    // Put Your Code Here :-
    std::string code = R"(

#include <iostream>
using namespace std;

int main(){
    cout << "Hello World";
    return 0;
}

)";
//Code Bracket ke uper hi dalna he 
    lexicalAnalyzer(code);
    return 0;
}
