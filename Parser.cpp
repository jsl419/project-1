//
// Created by jaden on 10/3/2021.
//

#include "Parser.h"

void Parser::createParser() {
    parseList.push_back(TokenType::ENDOFFILE);
    parseList.push_back(TokenType::querylist);
    parseList.push_back(TokenType::COLON);
    parseList.push_back(TokenType::QUERIES);
    parseList.push_back(TokenType::rulelist);
    parseList.push_back(TokenType::COLON);
    parseList.push_back(TokenType::RULES);
    parseList.push_back(TokenType::factlist);
    parseList.push_back(TokenType::COLON);
    parseList.push_back(TokenType::FACTS);
    parseList.push_back(TokenType::schemelist);
    parseList.push_back(TokenType::COLON);
    parseList.push_back(TokenType::SCHEMES);
}

void Parser::Run(Lexer* lexer) {
    LexerToTokentypeList(lexer);
}
void Parser::S0() {
    if ((parseList.size() > 0) && (lexerList.size() > 0)) {
        if (parseList.at(parseList.size() - 1) == lexerList.at(0)) {
            parseList.pop_back();
            lexerList.erase(lexerList.begin());
            S0();
        } else if (parseList.at(parseList.size() - 1) == TokenType::schemelist) {
            parseList.pop_back();
            S1();
        } else if (parseList.at(parseList.size() - 1) == TokenType::factlist) {
            parseList.pop_back();
            S2();
        } else if (parseList.at(parseList.size() - 1) == TokenType::rulelist) {
            parseList.pop_back();
            S3();
        } else if (parseList.at(parseList.size() - 1) == TokenType::querylist) {
            parseList.pop_back();
            S4();
        } else {
            properGrammar = false;
            return;
        }
    }
    else properGrammar = false;
}
void Parser::S1() {
    if (lexerList.at(0) == TokenType::ID) {
        lexerList.erase(lexerList.begin());
        if(lexerList.at(0) == TokenType::LEFT_PAREN){
            lexerList.erase(lexerList.begin());
            if(lexerList.at(0) == TokenType::ID){
                lexerList.erase(lexerList.begin());
                if(SIDList()){
                    if(lexerList.at(0) == TokenType::RIGHT_PAREN){
                        lexerList.erase(lexerList.begin());
                        S1();
                    }else {
                        properGrammar = false;
                        return;
                    }
                } else{
                    properGrammar = false;
                    return;
                }
            }
        } else {
            properGrammar = false;
            return;
        }
    } else{
        S0();
    }
}
void Parser::S2() { //fact list
    if (lexerList.at(0) == TokenType::ID) {
        lexerList.erase(lexerList.begin());
        if(lexerList.at(0) == TokenType::LEFT_PAREN){
            lexerList.erase(lexerList.begin());
            if(lexerList.at(0) == TokenType::STRING){
                lexerList.erase(lexerList.begin());
                if(SStringList()){
                    if(lexerList.at(0) == TokenType::RIGHT_PAREN){
                        lexerList.erase(lexerList.begin());
                        S2();
                    }else {
                        properGrammar = false;
                        return;
                    }
                } else{
                    properGrammar = false;
                    return;
                }
            }
        } else {
            properGrammar = false;
            return;
        }
    } else{
        S0();
    }
}
void Parser::S3() {//rulelist
    if (SHeadPredicate()) {
        if(lexerList.at(0) == TokenType::COLON_DASH){
            lexerList.erase(lexerList.begin());
            if(SPredicateList()){
                    if(lexerList.at(0) == TokenType::PERIOD){
                        lexerList.erase(lexerList.begin());
                        S3();
                    }else {
                        properGrammar = false;
                        return;
                    }
            } else{
                properGrammar = false;
                return;
            }
        } else {
            properGrammar = false;
            return;
        }
    } else{
        S0();
    }
}
void Parser::S4() {

}
bool Parser::SIDList() {
    if (lexerList.at(0) == TokenType::COMMA) {
        lexerList.erase(lexerList.begin());
        if(lexerList.at(0) == TokenType::ID){
            lexerList.erase(lexerList.begin());
            if(SIDList()){
                return true;
            }else{
                return false;
            }
        } else {
            return false;
        }
    } else{
        return true;
    }
}
bool Parser::SStringList() {
    if (lexerList.at(0) == TokenType::COMMA) {
        lexerList.erase(lexerList.begin());
        if(lexerList.at(0) == TokenType::STRING){
            lexerList.erase(lexerList.begin());
            if(SStringList()){
                return true;
            }else{
                return false;
            }
        } else {
            return false;
        }
    } else{
        return true;
    }
}
bool Parser::SHeadPredicate() {
    if (lexerList.at(0) == TokenType::ID) {
        lexerList.erase(lexerList.begin());
        if (lexerList.at(0) == TokenType::LEFT_PAREN) {
            lexerList.erase(lexerList.begin());
            if (lexerList.at(0) == TokenType::ID) {
                lexerList.erase(lexerList.begin());
                if (SIDList()) {
                    if(lexerList.at(0) == TokenType::RIGHT_PAREN){
                        lexerList.erase(lexerList.begin());
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    return true;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    }else {
        return false;
    }
}
bool Parser::SPredicateList() {
    if (lexerList.at(0) == TokenType::ID) {
        lexerList.erase(lexerList.begin());
        if(lexerList.at(0) == TokenType::LEFT_PAREN){
            lexerList.erase(lexerList.begin());
            if(SParamList()){
                return true;
            }else{
                return false;
            }
        } else {
            return false;
        }
    } else{
        return true;
    }
}
bool Parser::SParamList() {

}
/*
    while((parseList.size() > 0) && (lexerList.size() > 0)){
        if(parseList.at(parseList.size()-1) == lexerList.at(0)){
            parseList.pop_back();
            lexerList.erase(lexerList.begin());
        }else if (parseList.at(parseList.size()-1) == TokenType::scheme){
            parseList.pop_back();
            if(lexerList.at(0) == TokenType::ID){
                parseList.push_back(TokenType::RIGHT_PAREN);
                parseList.push_back(TokenType::idlist);
                parseList.push_back(TokenType::ID);
                parseList.push_back(TokenType::LEFT_PAREN);
                parseList.push_back(TokenType::ID);
            } else{
                return;
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::query){
            parseList.pop_back();
            if(lexerList.at(0) == TokenType::ID){
                parseList.push_back(TokenType::Q_MARK);
                parseList.push_back(TokenType::predicate);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::fact){
            parseList.pop_back();
            if(lexerList.at(0) == TokenType::ID) {
                parseList.push_back(TokenType::PERIOD);
                parseList.push_back(TokenType::RIGHT_PAREN);
                parseList.push_back(TokenType::stringlist);
                parseList.push_back(TokenType::STRING);
                parseList.push_back(TokenType::LEFT_PAREN);
                parseList.push_back(TokenType::ID);
            } else{
                return;
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::rule){
            parseList.pop_back();
            if(lexerList.at(0) == TokenType::ID) {
                parseList.push_back(TokenType::PERIOD);
                parseList.push_back(TokenType::predicatelist);
                parseList.push_back(TokenType::predicate);
                parseList.push_back(TokenType::COLON_DASH);
                parseList.push_back(TokenType::headPredicate);
            } else{
                return;
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::schemelist){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::ID) {
                parseList.push_back(TokenType::schemelist);
                parseList.push_back(TokenType::scheme);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::factlist){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::ID) {
                parseList.push_back(TokenType::factlist);
                parseList.push_back(TokenType::fact);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::rulelist){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::ID) {
                parseList.push_back(TokenType::rulelist);
                parseList.push_back(TokenType::rule);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::querylist){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::ID) {
                parseList.push_back(TokenType::querylist);
                parseList.push_back(TokenType::query);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::headPredicate){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::ID) {
                parseList.push_back(TokenType::RIGHT_PAREN);
                parseList.push_back(TokenType::idlist);
                parseList.push_back(TokenType::ID);
                parseList.push_back(TokenType::LEFT_PAREN);
                parseList.push_back(TokenType::ID);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::predicate){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::ID) {
                parseList.push_back(TokenType::RIGHT_PAREN);
                parseList.push_back(TokenType::parameterlist);
                parseList.push_back(TokenType::parameter);
                parseList.push_back(TokenType::LEFT_PAREN);
                parseList.push_back(TokenType::ID);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::predicatelist){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::COMMA) {
                parseList.push_back(TokenType::predicatelist);
                parseList.push_back(TokenType::predicate);
                parseList.push_back(TokenType::COMMA);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::parameterlist){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::COMMA) {
                parseList.push_back(TokenType::parameterlist);
                parseList.push_back(TokenType::parameter);
                parseList.push_back(TokenType::COMMA);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::stringlist){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::COMMA) {
                parseList.push_back(TokenType::stringlist);
                parseList.push_back(TokenType::STRING);
                parseList.push_back(TokenType::COMMA);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::idlist){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::COMMA) {
                parseList.push_back(TokenType::idlist);
                parseList.push_back(TokenType::ID);
                parseList.push_back(TokenType::COMMA);
            }
        }else if (parseList.at(parseList.size()-1) == TokenType::parameter){
            parseList.pop_back();
            if (lexerList.at(0) == TokenType::ID) {
                parseList.push_back(TokenType::ID);
            } else if (lexerList.at(0) == TokenType::STRING){
                parseList.push_back(TokenType::STRING);
            }
        }else{
            return;
        }
    }
    */
Parser::Parser(){
        createParser();
}
Parser::~Parser() {
    lexerList.clear();
    parseList.clear();
}

void Parser::LexerToTokentypeList(Lexer* lexer) {
    for (unsigned int i = 0; i < lexer->tokens.size(); ++i) {
        lexerList.push_back(lexer->tokens.at(i)->typeToken);
    }
}