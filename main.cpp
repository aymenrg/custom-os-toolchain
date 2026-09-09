#include <iostream>
#include "lexer.h"
#include "fuel.h"

int main(){
    std::string source_code = loadFile("source.txt");
    std::cout << "File loaded successfully.\n";

    Lexer myLexer(source_code);

    std::cout << "Testing:\n";

    std::cout << "Char 1: " << myLexer.advance() << "\n";
    std::cout << "Char 2: " << myLexer.advance() << "\n";
    std::cout << "Char 3: " << myLexer.advance() << "\n";

    return 0;
}