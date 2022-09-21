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

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
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
    //automata.push_back(new IdAutomaton());
    //automata.push_back(new StringAutomaton());
    //automata.push_back(new CommentAutomaton());
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;
    // While there are more characters to tokenize
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton *maxAutomaton = automata.at(0);

        // TODO: you need to handle whitespace inbetween tokens
        while (input[0] == ' ') { input.erase(0,1);}
        while (input[0] == '\n') { input.erase(0,1); lineNumber++;}
        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for (int i = 0; i < automata.size(); i++) {
            int inputRead = automata.at(i)->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata.at(i);
            }
        }

        // Here is the "Max" part of the algorithm

        if (maxRead > 0) {
                Token* newToken = maxAutomaton->CreateToken(input,lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                tokens.push_back(newToken);
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
                maxRead = 1;
                char TESTCHAR = input[0];
                string toString(1,input[0]);
                Token* newToken =  new Token(TokenType::UNDEFINED, toString, lineNumber);
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
    string outstring = "";
    for (int i = 0; i < tokens.size(); i++) {
        outstring += tokens.at(i)->toString() + "\n";
    }
    return outstring;
}