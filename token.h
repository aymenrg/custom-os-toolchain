#pragma once
#include <string>

enum class TokenType {
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    BANG, BANG_EQUAL,
    ASSIGN, EQUALS,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    IDENTIFIER, STRING, NUMBER,

    PRINT, LET, IF, ELSE, FUNC, RETURN,

    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string lexeme;
    int line;
};