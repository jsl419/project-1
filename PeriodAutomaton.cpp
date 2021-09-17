//
// Created by jaden on 9/16/2021.
//

#include "PeriodAutomaton.h"
void PeriodAutomaton::S0(const std::string& input) {
    if (input[index] == '.') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}