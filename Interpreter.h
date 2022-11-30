#ifndef CS236PROJECT_INTERPRETER_H
#define CS236PROJECT_INTERPRETER_H
#include "Database.h"
#include "DatalogProgram.h"
#include <iostream>

using namespace std;

class Interpreter {
private:
    DatalogProgram program;
    Database database;

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
