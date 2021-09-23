#include <iostream>
#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    typeToken = type;
    desc = description;
    lineNumb = line;

    // TODO: initialize all member variables (COMMA,",",1)
}

std::string Token::TokenToString(TokenType type) {
    double stringVal = static_cast<double>(type);
    std::string TokenString;
    if(stringVal == 0.0){
        TokenString = "ENDOFFILE";
    } else if(stringVal == 1.0) {
        TokenString = "UNDEFINED";
    }else if(stringVal == 2.0){
        TokenString = "COLON_DASH";
    }else if(stringVal == 3.0){
        TokenString = "COMMA";
    }else if(stringVal == 4.0){
        TokenString = "PERIOD";
    }else if(stringVal == 5.0){
        TokenString = "Q_MARK";
    }else if(stringVal == 6.0){
        TokenString = "LEFT_PAREN";
    }else if(stringVal == 7.0){
        TokenString = "RIGHT_PAREN";
    }else if(stringVal == 8.0){
        TokenString = "MULTIPLY";
    }else if(stringVal == 9.0){
        TokenString = "ADD";
    }else if(stringVal == 10.0){
        TokenString = "SCHEMES";
    }else if(stringVal == 11.0){
        TokenString = "FACTS";
    }else if(stringVal == 12.0){
        TokenString = "RULES";
    }else if(stringVal == 13.0){
        TokenString = "QUERIES";
    }else if(stringVal == 14.0){
        TokenString = "ID";
    }else if(stringVal == 15.0){
        TokenString = "STRING";
    }else if(stringVal == 16.0){
        TokenString = "COMMENT";
    }else if(stringVal == 17.0){
        TokenString = "COLON";
    }
    return TokenString;
}