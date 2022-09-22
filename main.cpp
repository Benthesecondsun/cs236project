#include "Lexer.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype> // This gives us the isspace() function also gives isalpha() and isalnum()
using namespace std;

int main(int argc, char** argv) {

    ifstream bringIn;
    bringIn.open(argv[1]);
    if (bringIn.fail())
    {
        cerr << "Failed to open input file." << endl;
        exit(1);
    }
    string input( (std::istreambuf_iterator<char>(bringIn) ), (std::istreambuf_iterator<char>()) );

    Lexer* lexer = new Lexer();
    lexer->Run(input);
    cout << lexer->lexerToString() << endl;
    delete lexer;
    return 0;

}