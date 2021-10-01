//
// Created by jaden on 9/16/2021.
//

#include "StringAutomaton.h"
void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if (input[index] == '\'') {
        if (index + 1 <= input.size()) {
            inputRead++;
            index++;
            S2(input);
        }
    } else if (input[index] == '\n') {
        inputRead++;
        newLines++;
        index++;
        if (index + 1 > input.size()) {
            return;
            //for end of file stuff
        }
        S1(input);
    } else {
            inputRead++;
            index++;
            S1(input);
    }
}
void StringAutomaton::S2(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
}