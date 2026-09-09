#pragma once
#include <string>

class Lexer {
private:
    std::string source;
    int start = 0;
    int current = 0;
    int line = 1;

public:
    Lexer(std::string source_code);
    bool isAtEnd();
    char advance();
    char peek();
    char peekNext();
};