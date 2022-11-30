#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    ifstream bringIn;
    bringIn.open(argv[1]);
    if (bringIn.fail())
    {
        cerr << "Failed to open input file." << "\n";
        exit(1);
    }
    string input, line;
    while (getline(bringIn, line)) {
        input += line + "\n";
    }
    /*                                                           ---------------------- _||_ --
                                                                 --Run The Lexer------- \  / --
                                                                 ----------------------  \/  --
    */
    Lexer* lexer = new Lexer();
    lexer->Run(input);
    /*                                                           ---------------------- _||_ --
                                                                 --Run The Parser------ \  / --
                                                                 ----------------------  \/  --
    */
    vector<Token*> inToken = lexer->outLexTokens();
    Parser* myParser = new Parser(inToken);
    string interpreterInput; // use this to get the parser's data to the interpreter.
    try {
        myParser->checkSyntax();
        //cout << "Success!" << "\n";
        //cout << myParser->parserToString();
    }
    catch(string e) {cout << "Failure!\n" << "  " << e << "\n";}
    /*                                                           ---------------------- _||_ --
                                                                 --Run The Interpreter- \  / --
                                                                 ----------------------  \/  --
    */
    Interpreter* myInterpreter = new Interpreter(myParser->GetDatalogProgram());
    myInterpreter->InterpretSchemes();
    myInterpreter->InterpretFacts();
    cout << "Rule Evaluation\n";
    myInterpreter->InterpretRules();
    cout << "\nSchemes populated after " << to_string(myInterpreter->numPasses) << " passes through the Rules.\n";
    myInterpreter->InterpretQueries();
    /*                                                           ---------------------- _||_ --
                                                                 --Clean Up All New---- \  / --
                                                                 ----------------------  \/  --
    */
    delete lexer;
    delete myParser;
    delete myInterpreter;

    return 0;
}