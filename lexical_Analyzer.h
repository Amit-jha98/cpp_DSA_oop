#include <iostream>
#include <cctype>
#include <string>
#include <unordered_set>

void lexicalAnalyzer(const std::string &code) {
    // Define sets for keywords, operators, and delimiters
    std::unordered_set<std::string> keywords = {
        "int", "float", "double", "char", "bool", "void", "short", "long", "return",
        "if", "else", "while", "for", "do", "switch", "case", "default", "break",
        "continue", "true", "false", "namespace", "using", "class", "struct",
        "public", "private", "protected", "static", "const", "sizeof", "new", "delete",
        "try", "catch", "throw", "include", "define", "undef", "ifdef", "ifndef", "endif"};

    std::unordered_set<std::string> multi_char_operators = {
        "==", "!=", "<=", ">=", "&&", "||", "++", "--", "+=", "-=", "*=", "/=", "%=", 
        "<<", ">>", "<<=", ">>=", "::", "->", ".*"};
    std::unordered_set<char> single_char_operators = {
        '+', '-', '*', '/', '%', '=', '<', '>', '!', '&', '|', '^', '~', '?'};
    std::unordered_set<char> delimiters = {';', '(', ')', '{', '}', ',', '[', ']', '"', '\''};

    int tokenCount = 0;
    std::string token = "";

    std::cout << "Tokens:\n";

    for (size_t i = 0; i < code.length(); ++i) {
        char ch = code[i];

        // Skip whitespace
        if (std::isspace(ch)) {
            continue;
        }

        // Recognize '#' as a preprocessor symbol
        if (ch == '#') {
            tokenCount++;
            std::cout << "Preprocessor symbol: " << ch << "\n";
            token = "";
            continue;
        }

        // Detect multi-character operators
        if (i + 1 < code.length()) {
            std::string potential_operator = std::string(1, ch) + code[i + 1];
            if (multi_char_operators.count(potential_operator)) {
                tokenCount++;
                std::cout << "Operator: " << potential_operator << "\n";
                i++;
                continue;
            }
        }

        // Detect single-character operators
        if (single_char_operators.count(ch)) {
            tokenCount++;
            std::cout << "Operator: " << ch << "\n";
            continue;
        }

        // Detect keywords and identifiers
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

        // Detect numbers (integer and floating-point)
        if (std::isdigit(ch)) {
            token += ch;
            bool isFloat = false;
            while (i + 1 < code.length() && (std::isdigit(code[i + 1]) || code[i + 1] == '.')) {
                if (code[i + 1] == '.') {
                    if (isFloat) break; // Malformed number
                    isFloat = true;
                }
                token += code[++i];
            }
            tokenCount++;
            std::cout << (isFloat ? "Floating-point number: " : "Integer: ") << token << "\n";
            token = "";
            continue;
        }

        // Detect delimiters
        if (delimiters.count(ch)) {
            tokenCount++;
            std::cout << "Delimiter: " << ch << "\n";
            continue;
        }

        // Handle string literals
        if (ch == '"') {
            token += ch;
            while (i + 1 < code.length() && code[i + 1] != '"') {
                token += code[++i];
            }
            if (i + 1 < code.length() && code[i + 1] == '"') {
                token += code[++i];
            }
            tokenCount++;
            std::cout << "String literal: " << token << "\n";
            token = "";
            continue;
        }

        // Handle character literals
        if (ch == '\'') {
            token += ch;
            while (i + 1 < code.length() && code[i + 1] != '\'') {
                token += code[++i];
            }
            if (i + 1 < code.length() && code[i + 1] == '\'') {
                token += code[++i];
            }
            tokenCount++;
            std::cout << "Character literal: " << token << "\n";
            token = "";
            continue;
        }

        // Handle invalid characters
        std::cout << "Invalid character: " << ch << "\n";
    }

    std::cout << "Total tokens: " << tokenCount << "\n";
}