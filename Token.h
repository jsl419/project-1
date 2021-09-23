#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    ENDOFFILE,
    UNDEFINED,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    COLON,
};

class Token
{
public:
    Token(TokenType type, std::string description, int line);
    // TODO: add other needed methods
    std::string TokenToString(TokenType type);
    int lineNumb = 0;
    TokenType typeToken = TokenType::UNDEFINED;
    std::string desc = "";
};

#endif // TOKEN_H

