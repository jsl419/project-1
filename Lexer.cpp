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
#include "EofAutomaton.h"
#include "IDAutomaton.h"
#include "UndefinedAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens'
    automata.clear();
    tokens.clear();

}

void Lexer::CreateAutomata() {
    automata.push_back(new UndefinedAutomaton());
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new EofAutomaton());
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;
    Automaton *maxAutomata = automata.at(0);
    while (input.size() > 0) {
        while (std::isspace(input[0])) {
            input.erase(0);
        }
        int maxRead = 0;
        maxAutomata = automata.at(0);
        for (int i = 0; i < automata.size(); i++) {
            if (maxAutomata->Start(input) > maxRead) {
                maxRead = maxAutomata->Start(input);
                maxAutomata = automata.at(i);
            }
        }
        if (maxRead > 0) {
            Token *newToken = maxAutomata->CreateToken(input , maxAutomata->NewLinesRead());
            newToken->lineNumb = maxAutomata->NewLinesRead();
            tokens.push_back(newToken);
        } else {
            maxRead = 1;
            Token *newToken = automata.at(0)->CreateToken(std::to_string(input[0]),1);
            tokens.push_back(newToken);
        }
        input.erase(0, maxRead);
    }
    maxAutomata = automata.at(15);
    Token *newToken = maxAutomata->CreateToken("",1);
    tokens.push_back(newToken);
}