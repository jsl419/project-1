#include <iostream>
#include "Lexer.h"
#include <fstream>

int main(int argc, char** argv) {
    std::ifstream in(argv[1]);
    if (!in) { std::cerr << "Unable to open " << argv[1] << " for input"; return 2; }
    std::string input = "";
    while(!in.eof()){
        std::string line;
        getline(in,line);
        input += line + (in.eof() ? "" : "\n");;
    }
    Lexer* lexer = new Lexer();
    lexer->Run(input);
    std::cout << lexer->LexerToString();
    delete lexer;

    return 0;
}