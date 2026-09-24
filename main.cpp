#include <iostream>
#include "lexer.h"
#include "fuel.h"
#include "token.h"
#include <string>
#include <vector>


std::string loadFile(std::string filename);

std::string typeToString(TokenType type) {
    switch (type) {                                   
        case TokenType::PLUS: return "PLUS";          
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::ASSIGN: return "ASSIGN";      
        case TokenType::EQUALS: return "EQUALS";      
        case TokenType::END_OF_FILE: return "EOF";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::IF: return "IF";
        case TokenType::ELSE: return "ELSE";
        case TokenType::PRINT: return "PRINT";
        case TokenType::LET: return "LET";
        case TokenType::FUNC: return "FUNC";
        case TokenType::RETURN: return "RETURN";    
        default: return "UNKNOWN";                    
    }
}

int main(){
    std::string source_code = loadFile("source.txt");
    std::cout << "File loaded successfully.\n";

    Lexer myLexer(source_code);
    std::vector<Token> finished_tokens = myLexer.tokenize();

    std::cout << "Testing Dictionary:\n";

    for (int i = 0; i < finished_tokens.size(); i++) {      
        
        Token t = finished_tokens[i];                         
        
        std::cout << "Line " << t.line << " | "               
                  << typeToString(t.type)                     
                  << " ('" << t.lexeme << "')\n";             
    }

    return 0;
}