#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
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
    ENDOFFILE,
    UNDEFINED
};

class Token
{
private:
    TokenType typeToken = TokenType::UNDEFINED;
    std::string desc = "";
public:
    Token(TokenType type, std::string description, int line);
    // TODO: add other needed methods
    int lineNumb = 0;
};

#endif // TOKEN_H

