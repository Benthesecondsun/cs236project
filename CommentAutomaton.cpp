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
    if (index == input.size()) {SetFail(); return;}
    if (input[index] == '|') {
        index++;
        inputRead++;
        S3(input);
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}

void CommentAutomaton::S2(const std::string& input) {
    if (index == input.size()) {SetFail(); return;}
    if (input[index] != '\n') {
        index++;
        inputRead++;
        S2(input);
    }
    else {
        newLines++;
        index++;
        inputRead++;
    }
}
void CommentAutomaton::S3(const std::string& input) {
    if (index == input.size()) {SetFail(); return;}
    if (input[index] == '|') {
        index++;
        inputRead++;
        S4(input);
    }
    else if (input[index] == '\n') {
        newLines++;
        inputRead++;
        index++;
        S3(input);
    }
    else {
        inputRead++;
        index++;
        S3(input);
    }
}
void CommentAutomaton::S4(const std::string& input) {
    if (index == input.size()) {SetFail(); return;}
    if (input[index] == '#') {
        index++;
        inputRead++;
    }
    else if (input[index] == '\n'){
        newLines++;
        index++;
        inputRead++;
        S3(input);
    }
    else {
        index++;
        inputRead++;
        S3(input);
    }
}
