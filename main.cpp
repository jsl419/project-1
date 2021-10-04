#include <iostream>
#include "prj1/Lexer.h"
#include "Parser.h"
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
    Parser* parser = new Parser();
    parser->Run(lexer);
    delete lexer;
    delete parser;

    return 0;
}