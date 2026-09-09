#include <iostream>
#include <fstream>
#include "fuel.h"

std::string loadFile(std::string filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << "\n";
        exit(1);
    }

    std::string source_code = "";
    std::string line;
    while (std::getline(file, line)) {
        source_code += line + "\n";
    }
    file.close();
    return source_code;
}



