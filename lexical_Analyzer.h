#include <cctype>
#include <string>
#include <unordered_set>

void lexicalAnalyzer(const std::string &code) {
    // Define sets for keywords, operators, and delimiters You can update it if find anything missing
    std::unordered_set<std::string> keywords = {
        "int", "float", "double", "char", "bool", "void", "short", "long", "return",
        "if", "else", "while", "for", "do", "switch", "case", "default", "break",
        "continue", "true", "false", "namespace", "using", "class", "struct",
        "public", "private", "protected", "static", "const", "sizeof", "new", "delete",
        "try", "catch", "throw", "include", "define", "undef", "ifdef", "ifndef", "endif"};

    std::unordered_set<std::string> multi_char_operators = {
        "==", "!=", "<=", ">=", "&&", "||", "++", "--", "+=", "-=", "*=", "/=", "%=", "::", "->", ".*"};
    std::unordered_set<char> single_char_operators = {'+', '-', '*', '/', '%', '=', '<', '>', '!', '&', '|', '^', '~', '?'};
    std::unordered_set<char> delimiters = {';', '(', ')', '{', '}', ',', '[', ']'};

    int tokenCount = 0;
    std::string token = "";

    std::cout << "Tokens:\n";

    for (size_t i = 0; i < code.length(); ++i) {
        char ch = code[i];

        // Skip whitespaces (space, tab)
        if (std::isspace(ch)) {
            continue;
        }

        // Detect preprocessing directives
        if (ch == '#') {
            token += ch;
            while (i + 1 < code.length() && std::isalnum(code[i + 1])) {
                token += code[++i];
            }
            tokenCount++;
            std::cout << "Preprocessor directive: " << token << "\n";
            token = "";
            continue;
        }

        // Check for multi-character operators
        if (i + 1 < code.length()) {
            std::string potential_operator = std::string(1, ch) + code[i + 1];
            if (multi_char_operators.count(potential_operator)) {
                tokenCount++;
                std::cout << "Operator: " << potential_operator << "\n";
                i++;
                continue;
            }
        }

        // Check for single-character operators
        if (single_char_operators.count(ch)) {
            tokenCount++;
            std::cout << "Operator: " << ch << "\n";
            continue;
        }

        // Check for identifiers and keywords
        if (std::isalpha(ch) || ch == '_') {
            token += ch;
            while (i + 1 < code.length() && (std::isalnum(code[i + 1]) || code[i + 1] == '_')) {
                token += code[++i];
            }
            tokenCount++;
            if (keywords.count(token)) {
                std::cout << "Keyword: " << token << "\n";
            } else {
                std::cout << "Identifier: " << token << "\n";
            }
            token = "";
            continue;
        }

        // Check for numbers (integer and floating point)
        if (std::isdigit(ch)) {
            token += ch;
            while (i + 1 < code.length() && (std::isdigit(code[i + 1]) || code[i + 1] == '.')) {
                token += code[++i];
            }
            tokenCount++;
            std::cout << "Number: " << token << "\n";
            token = "";
            continue;
        }

        // Check for delimiters
        if (delimiters.count(ch)) {
            tokenCount++;
            std::cout << "Delimiter: " << ch << "\n";
            continue;
        }

        // Handle invalid characters
        std::cout << "Invalid character: " << ch << "\n";
    }

    std::cout << "Total tokens: " << tokenCount << "\n";
}
