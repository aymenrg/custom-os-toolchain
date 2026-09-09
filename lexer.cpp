#include "lexer.h"
#include <string>

Lexer::Lexer(std::string source_code) {
    source = source_code;
}

bool Lexer::isAtEnd() {
    return current >= source.length();
}
char Lexer::advance() {
    char c = source[current];
    current++;
    return c;
}
char Lexer::peek() {
    if (isAtEnd()) {
        return '\0'; 
    }
    return source[current];
}

char Lexer::peekNext() {
    if (current + 1 >= source.length()) {
        return '\0';
    }
    return source[current + 1];
}