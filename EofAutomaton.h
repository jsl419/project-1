//
// Created by jaden on 9/16/2021.
//

#ifndef PROJECT_1_EOFAUTOMATON_H
#define PROJECT_1_EOFAUTOMATON_H

#include "Automaton.h"

class EofAutomaton  : public Automaton{
        public:
        EofAutomaton() : Automaton(TokenType::ENDOFFILE) {}  // Call the base constructor
        void S0(const std::string& input);
};


#endif //PROJECT_1_EOFAUTOMATON_H
