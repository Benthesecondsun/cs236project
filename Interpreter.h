#ifndef CS236PROJECT_INTERPRETER_H
#define CS236PROJECT_INTERPRETER_H
#include "Database.h"
#include "DatalogProgram.h"
#include <iostream>
#include "Graph.h"

using namespace std;

class Interpreter {
private:
    DatalogProgram program;
    Database database;
    vector <string> allPossibleRuleIDs;
public:
    int numPasses = 1;
    Interpreter() = default;
    ~Interpreter() = default;
    Interpreter(DatalogProgram program) {this->program = program;}
    void InterpretSchemes();
    void InterpretFacts();
    void InterpretQueries();
    void InterpretRules();







};


#endif //CS236PROJECT_INTERPRETER_H
