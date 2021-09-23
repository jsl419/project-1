//
// Created by jaden on 9/16/2021.
//

#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] != '\n'){
        inputRead++;
        index++;
        S2Line(input);
    }
    else {

        Serr();
    }
}

void CommentAutomaton::S2(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else if (index + 1 > input.size()){
        Serr();
    } else {

        inputRead++;
        index++;
        S2(input);
    }
}

void CommentAutomaton::S3(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}

void CommentAutomaton::S2Line(const std::string& input) {
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S2Line(input);
    }
}