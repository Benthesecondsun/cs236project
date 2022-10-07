#include "Lexer.h"
#include "Parser.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    ifstream bringIn;
    bringIn.open(argv[1]);
    if (bringIn.fail())
    {
        cerr << "Failed to open input file." << endl;
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

    try {
        myParser->checkSyntax();
        cout << endl << "Success!" << endl;
        cout << myParser->parserToString();// DELETEME THIS IS FOR TESTING
    }
    catch(string e) {cout << endl << "Failure!" << endl << "  " << e << endl;}

    /*                                                           ---------------------- _||_ --
                                                                 --Clean Up All New---- \  / --
                                                                 ----------------------  \/  --
    */
    delete lexer;
    delete myParser;

    return 0;
}