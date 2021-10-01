#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "CommentAutomaton.h"
#include "FactsAutomaton.h"
#include "LeftParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "QueriesAutomaton.h"
#include "RightParenAutomaton.h"
#include "RulesAutomaton.h"
#include "SchemesAutomaton.h"
#include "StringAutomaton.h"
#include "IDAutomaton.h"
#include "AddAutomaton.h"
#include <iostream>
#include "Token.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    automata.clear();
    tokens.clear();

}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new IDAutomaton());
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;
    Automaton *maxAutomata = automata.at(0);
    while (input.size() > 0) {
        while (std::isspace(input[0])) {
            if (input[0] == '\n'){
                lineNumber++;
            }
            input.erase(input.begin());
            if(input.size() <= 1){
                Token *newToken = new Token(TokenType::ENDOFFILE , "" , lineNumber);
                tokens.push_back(newToken);
                return;
            }
        }
        int maxRead = 0;
        maxAutomata = automata.at(0);
        for (unsigned int i = 0; i < automata.size(); i++) {
            int read = automata.at(i)->Start(input);
            if (read > maxRead) {
                maxRead = read;
                maxAutomata = automata.at(i);
            }
        }
        if(maxRead >= (int) input.size()){
            Token *newToken = new Token(TokenType::UNDEFINED, input.substr(0,maxRead) , lineNumber);
            lineNumber += maxAutomata->NewLinesRead();
            tokens.push_back(newToken);
        }
        else if (maxRead > 0) {
            Token *newToken = maxAutomata->CreateToken(input.substr(0,maxRead) , lineNumber);
            lineNumber += maxAutomata->NewLinesRead();
            tokens.push_back(newToken);
        } else {
            maxRead = 1;
            std::string undef;
            undef.push_back(input.at(0));
            Token *newToken = new Token(TokenType::UNDEFINED , undef , lineNumber);
            tokens.push_back(newToken);
        }
        input.erase(0, maxRead);
    }
}
std::string Lexer::LexerToString(){
    std::string output = "";
        for (unsigned int i = 0; i < tokens.size(); i++) {
            output += "(" + tokens.at(i)->TokenToString(tokens.at(i)->typeToken) + ",\"" + tokens.at(i)->desc + "\"," +
                    std::to_string(tokens.at(i)->lineNumb) + ")\n";
        }
        output += "Total Tokens = " + std::to_string(tokens.size());
    return output;
};