//
// Created by jaden on 10/3/2021.
//

#ifndef PROJECT_1_PARSER_H
#define PROJECT_1_PARSER_H
#include "prj1/Lexer.h"
#include <vector>

class Parser {

public:

    void Run(Lexer* lexer);
    void S0();
    void S1();
    void S2();
    void S3();
    void S4();
    bool SIDList();
    bool SStringList();
    bool SHeadPredicate();
    bool SPredicateList();
    bool SParamList();
    void createParser();
    std::vector<TokenType> parseList;
    std::vector<TokenType> lexerList;
    Parser();
    ~Parser();
    void LexerToTokentypeList(Lexer* lexer);
    bool properGrammar = true;
};


#endif //PROJECT_1_PARSER_H
