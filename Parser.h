#ifndef CS236PROJECT_PARSER_H
#define CS236PROJECT_PARSER_H
#include "Token.h"
#include "DatalogProgram.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Parser {
private:
    DatalogProgram program;
    string line;
    vector<Token*> tokens;
    int tokenNum;
    string inParen, name;
    //Predicate holder;
    //vector<Predicate*> predVec;
public:
    Parser(vector<Token*> inTokens);
    ~Parser();
    void removeComments();
    void checkSyntax();
    void manySchemes();
    void manyVariables();
    void manyFacts();
    void manyStrings();
    void manyRules();
    void findHead(Predicate* newPred);
    void findBody(Predicate* newPred, vector<Predicate*> newVec);
    void manyQueries();
    void manyTests();

    string parserToString();

};


#endif //CS236PROJECT_PARSER_H
