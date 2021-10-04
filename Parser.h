//
// Created by jaden on 10/3/2021.
//

#ifndef PROJECT_1_PARSER_H
#define PROJECT_1_PARSER_H
#include "prj1/Lexer.h"
#include <vector>

class Parser {
    void Run(Lexer lexer);
    void createParser();
std::vector<TokenType> parseList;
std::vector<TokenType> lexerList;
    Parser();
    ~Parser();
    void LexerToTokentypeList(Lexer lexer);
};


#endif //PROJECT_1_PARSER_H
