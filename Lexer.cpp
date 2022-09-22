#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "Left_ParenAutomaton.h"
#include "Right_ParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IdAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    for (unsigned int i = 0; i < automata.size(); i++) {
        delete automata.at(i);
        }
    for (unsigned int i = 0; i < tokens.size(); i++) {
        delete tokens.at(i);
    }
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new Q_MarkAutomaton());
    automata.push_back(new Left_ParenAutomaton());
    automata.push_back(new Right_ParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;
    // While there are more characters to tokenize
    while (input.size() > 0) {
        //if (input.size() == 1) {break;}
        int maxRead = 0;
        Automaton *maxAutomaton = automata.at(0);

        // TODO: you need to handle whitespace inbetween tokens
        while (input[0] == ' '|input[0] == '\t'|input[0] == '\n') {
            if (input[0] == ' ') {input.erase(0,1);}
            else if (input[0] == '\t') {input.erase(0,1);}
            else if (input[0] == '\n') {input.erase(0,1); lineNumber++;}
        }
        if (input.size() == 1| input.empty()) {break;}
        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for (unsigned int i = 0; i < automata.size(); i++) {
            int inputRead = automata.at(i)->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata.at(i);
            }
        }

        // Here is the "Max" part of the algorithm

        if (maxRead > 0) {
                if (maxAutomaton == automata.at(14)) {
                    if (automata.at(14)->GetFail() == true){
                        Token* newToken =  new Token(TokenType::UNDEFINED, input.substr(0,maxRead), lineNumber);
                        lineNumber += maxAutomaton->NewLinesRead();
                        tokens.push_back(newToken);
                    }
                    else {
                        Token* newToken = maxAutomaton->CreateToken(input.substr(0,maxRead),lineNumber);
                        lineNumber += maxAutomaton->NewLinesRead();
                        tokens.push_back(newToken);
                    }
                }
                else if (maxAutomaton == automata.at(15)) {
                    if (automata.at(15)->GetFail() == true){
                        Token* newToken =  new Token(TokenType::UNDEFINED, input.substr(0,maxRead), lineNumber);
                        lineNumber += maxAutomaton->NewLinesRead();
                        tokens.push_back(newToken);
                    }
                    else {
                        Token* newToken = maxAutomaton->CreateToken(input.substr(0,maxRead),lineNumber);
                        lineNumber += maxAutomaton->NewLinesRead();
                        tokens.push_back(newToken);
                    }
                }
                else {
                    Token *newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
                    lineNumber += maxAutomaton->NewLinesRead();
                    tokens.push_back(newToken);
                }
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
                maxRead = 1;
                char TESTCHAR = input[0];
                string toString(1,input[0]);
                Token* newToken =  new Token(TokenType::UNDEFINED, input.substr(0, maxRead), lineNumber);
                tokens.push_back(newToken);
        }
        // Update `input` by removing characters read to create Token
        input.erase(0,maxRead);
    }
    Token* EOFToken = new Token(TokenType::EOF_TYPE, "", lineNumber);
    tokens.push_back(EOFToken);

}

string Lexer::lexerToString()
{
    string outString = "";
    for (unsigned int i = 0; i < tokens.size(); i++) {
        outString += tokens.at(i)->toString() + "\n";
    }
    outString += "Total Tokens = " + to_string(tokens.size());
    return outString;
}