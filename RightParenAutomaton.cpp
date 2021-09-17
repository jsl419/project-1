//
// Created by jaden on 9/16/2021.
//

#include "RightParenAutomaton.h"

void RightParenAutomaton::S0(const std::string& input) {
    if (input[index] == ')') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}