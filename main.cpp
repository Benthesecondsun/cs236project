#include "Lexer.h"
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
    //string input( (std::istreambuf_iterator<char>(bringIn) ), (std::istreambuf_iterator<char>()) );
    string input, line;
    while (getline(bringIn, line)) {
        input += line + "\n";
    }
    Lexer* lexer = new Lexer();
    lexer->Run(input);
    cout << lexer->lexerToString();
    delete lexer;
    return 0;
}