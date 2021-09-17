#include <iostream>
#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    typeToken = type;
    desc = description;
    lineNumb = line;
    std::cout << "(" << std::to_string(static_cast<double>(type)) << ",\"" << description << "\"," << line << ")" <<std::endl;

    // TODO: initialize all member variables (COMMA,",",1)
}
