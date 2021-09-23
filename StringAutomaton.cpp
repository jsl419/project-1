//
// Created by jaden on 9/16/2021.
//

#include "StringAutomaton.h"
#include <iostream>
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
        inputRead++;
        index++;
        S3(input);
    }
    else if(input[index] != '\n'){
        if (index+1 > input.size()){
            Serr();
        } else {
            inputRead++;
            index++;
            S1(input);
        }
    }
    else {
        Serr();
    }
}

void StringAutomaton::S2(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S3(input);
    }
    else if(input[index] != '\n'){
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S3(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
}