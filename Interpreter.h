#ifndef CS236PROJECT_INTERPRETER_H
#define CS236PROJECT_INTERPRETER_H
#include "Database.h"
#include "DatalogProgram.h"
using namespace std;

class Interpreter {
private:
    DatalogProgram program;
    Database database;

public:
    Interpreter() = default;
    ~Interpreter() = default;
    Interpreter(DatalogProgram program) {this->program = program;}
    void InterpretSchemes();
    void InterpretFacts();
    void InterpretQueries();








};


#endif //CS236PROJECT_INTERPRETER_H
