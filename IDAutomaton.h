//
// Created by jaden on 9/16/2021.
//

#ifndef PROJECT_1_IDAUTOMATON_H
#define PROJECT_1_IDAUTOMATON_H

#include "Automaton.h"
class IDAutomaton : public Automaton {
    //isalpha() isnumb()

private:
    void S1(const std::string& input);

public:
    IDAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor
    void S0(const std::string& input);

};


#endif //PROJECT_1_IDAUTOMATON_H
