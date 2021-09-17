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