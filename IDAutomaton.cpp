//
// Created by jaden on 9/16/2021.
//

#include "IDAutomaton.h"

void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if (isalpha(input[index]) || isdigit(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
}