#include "lexer.h"
#include <string>
#include <iostream>
#include "token.h"
#include <cctype>

Lexer::Lexer(std::string source_code) {
    source = source_code;
    keywords["if"] = TokenType::IF;
    keywords["else"] = TokenType::ELSE;
    keywords["print"] = TokenType::PRINT;
    keywords["let"] = TokenType::LET;
    keywords["func"] = TokenType::FUNC;
    keywords["return"] = TokenType::RETURN;
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
std::vector<Token> Lexer::tokenize(){
    while (!isAtEnd()) {
        start = current;
        char c = advance();
        switch (c){
            case ' ':
            case '\r':
            case '\t':
                break;
            case '\n':
                line++;
                break;
            case '+':
                tokens.push_back({TokenType::PLUS, "+", line});
                break;
            case ';':
                tokens.push_back({TokenType::SEMICOLON, ";", line});
                break;
            case '=':
                if (peek() == '=') {
                    advance();
                    tokens.push_back({TokenType::EQUALS, "==", line});
                } else {
                    tokens.push_back({TokenType::ASSIGN, "=", line});
                }
                break;
            default:
                if (std::isdigit(c)){
                    number();
                }
                else if (std::isalpha(c)){
                    identifier();
                }
                else {
                    std::cout << "Unexpected character: " << c << " at line " << line << "\n";
                }
                break;
        }
    }
    return tokens;
}

void Lexer::number(){
    while (std::isdigit(peek())) {
        advance();
    }
    int length = current - start;
    std::string text = source.substr(start, length);
    tokens.push_back({TokenType::NUMBER, text,line});
}

void Lexer::identifier(){
    while (std::isalnum(peek())){
        advance();
    }
    int length = current - start;
    std::string text = source.substr(start, length);
    TokenType type = TokenType::IDENTIFIER;
    if (keywords.find(text) != keywords.end()) {
        type = keywords[text];
    }
    tokens.push_back({type, text, line});
}