#pragma once
#include <string>
#include <vector>
#include "token.h"
#include <unordered_map>

class Lexer {
private:
    std::string source;
    int start = 0;
    int current = 0;
    int line = 1;
    std::vector<Token> tokens;
    std::unordered_map<std::string, TokenType> keywords;
    void number();
    void identifier();

public:
    Lexer(std::string source_code);
    std::vector<Token> tokenize();
    bool isAtEnd();
    char advance();
    char peek();
    char peekNext();
};