//
// Created by jaden on 9/16/2021.
//

#ifndef PROJECT_1_LEFTPARENAUTOMATON_H
#define PROJECT_1_LEFTPARENAUTOMATON_H

#include "Automaton.h"

class LeftParenAutomaton : public Automaton {
public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT_1_LEFTPARENAUTOMATON_H
