//
// Created by jaden on 9/16/2021.
//

#include "EofAutomaton.h"

void EofAutomaton::S0(const std::string& input) {
    if (input[index] == '\n') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}