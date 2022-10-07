#include "Parser.h"


Parser::Parser(vector<Token*> inTokens) {
    tokens = inTokens;
    removeComments();
}
Parser::~Parser() {}
/*                                                          ---------------------- _||_ --
                                                            --RemoveComments------ \  / --
                                                            ----------------------  \/  --
*/
void Parser::removeComments() {
    vector<Token*> tempTokens;
    int lineNum = 0;
    for (unsigned int i = 0; i < tokens.size(); i++) {
        if (tokens.at(i)->getType() == TokenType::COMMENT) {}
        else {
            tempTokens.push_back(tokens.at(i));
            lineNum++;
        }
    }
    tokens = tempTokens;
}
/*                                                          ---------------------- _||_ --
                                                            --checkSyntax--------- \  / --
                                                            ----------------------  \/  --
*/
void Parser::checkSyntax() {
if (tokens.at(0)->getType() != TokenType::SCHEMES) { throw tokens.at(0)->toString();}
else if (tokens.at(1)->getType() != TokenType::COLON) { throw tokens.at(1)->toString();}
tokenNum = 2;
manySchemes(); // checked through all the schemes
if (tokens.at(tokenNum)->getType() != TokenType::FACTS) {throw tokens.at(tokenNum)->toString();}
tokenNum++;
if (tokens.at(tokenNum)->getType() != TokenType::COLON) {throw tokens.at(tokenNum)->toString();}
tokenNum++;
if (tokens.at(tokenNum)->getType() != TokenType::RULES) {manyFacts();} // check through all the facts
if (tokens.at(tokenNum)->getType() != TokenType::RULES) {throw tokens.at(tokenNum)->toString();}
tokenNum++;
if (tokens.at(tokenNum)->getType() != TokenType::COLON) {throw tokens.at(tokenNum)->toString();}
tokenNum++;
if (tokens.at(tokenNum)->getType() != TokenType::QUERIES) {manyRules();} // check through all the rules
if (tokens.at(tokenNum)->getType() != TokenType::QUERIES) {throw tokens.at(tokenNum)->toString();}
tokenNum++;
if (tokens.at(tokenNum)->getType() != TokenType::COLON) {throw tokens.at(tokenNum)->toString();}
tokenNum++;
manyQueries();// check through all the queries

}
/*                                                          ---------------------- _||_ --
                                                            --Check the Schemes--- \  / --
                                                            ----------------------  \/  --
*/
void Parser::manySchemes() {
    if (tokens.at(tokenNum)->getType() == TokenType::ID) {
        name = tokens.at(tokenNum)->getDesc();
        tokenNum++;
        if (tokens.at(tokenNum)->getType() != TokenType::LEFT_PAREN) {throw tokens.at(tokenNum)->toString();}
        inParen += tokens.at(tokenNum)->getDesc();
        tokenNum++;
        manyVariables();
    }
    else { throw tokens.at(tokenNum)->toString();}
}

void Parser::manyVariables() {
    if (tokens.at(tokenNum)->getType() == TokenType::ID) {
        inParen += tokens.at(tokenNum)->getDesc();
        tokenNum++;
        TokenType testToken = tokens.at(tokenNum)->getType();
        if (tokens.at(tokenNum)->getType() == TokenType::COMMA) {
            inParen += tokens.at(tokenNum)->getDesc();
            tokenNum++;
            manyVariables();
        }
        else if (tokens.at(tokenNum)->getType() == TokenType::RIGHT_PAREN) {
            inParen += tokens.at(tokenNum)->getDesc();
            tokenNum++;
            program.addScheme(name, inParen);
            name = "";
            inParen = "";
            if (tokens.at(tokenNum)->getType() == TokenType::ID) {
                manySchemes();
            }
        }
        else {throw tokens.at(tokenNum)->toString();}

    }
    else { throw tokens.at(tokenNum)->toString();}
}
/*                                                          ---------------------- _||_ --
                                                            --Check the Facts----- \  / --
                                                            ----------------------  \/  --
*/
void Parser::manyFacts() {
    if (tokens.at(tokenNum)->getType() == TokenType::ID) {
        name = tokens.at(tokenNum)->getDesc();
        tokenNum++;
        if (tokens.at(tokenNum)->getType() != TokenType::LEFT_PAREN) {throw tokens.at(tokenNum)->toString();}
        inParen += tokens.at(tokenNum)->getDesc();
        tokenNum++;
        manyStrings();
    }
    else { throw tokens.at(tokenNum)->toString();}
}

void Parser::manyStrings() {
    if (tokens.at(tokenNum)->getType() == TokenType::STRING) {
        inParen += tokens.at(tokenNum)->getDesc();
        program.setDomain((tokens.at(tokenNum)->getDesc()));
        tokenNum++;
        TokenType testToken = tokens.at(tokenNum)->getType();
        if (tokens.at(tokenNum)->getType() == TokenType::COMMA) {
            inParen += tokens.at(tokenNum)->getDesc();
            tokenNum++;
            manyStrings();
        }
        else if (tokens.at(tokenNum)->getType() == TokenType::RIGHT_PAREN) {
            inParen += tokens.at(tokenNum)->getDesc();
            tokenNum++;
            if (tokens.at(tokenNum)->getType() == TokenType::PERIOD) {
                tokenNum++;
                program.addFact(name, inParen);
                name = "";
                inParen = "";
                if (tokens.at(tokenNum)->getType() == TokenType::ID) {manyFacts();}
            }
            else {throw tokens.at(tokenNum)->toString();}

        }
        else {throw tokens.at(tokenNum)->toString();}

    }
    else { throw tokens.at(tokenNum)->toString();}
}
/*                                                          ---------------------- _||_ --
                                                            --Check the Rules----- \  / --
                                                            ----------------------  \/  --
*/
void Parser::manyRules() { // get initial ID and (
    if (tokens.at(tokenNum)->getType() == TokenType::ID) {
        tokenNum++;
        TokenType testToken = tokens.at(tokenNum)->getType(); // DELETEME
        if (tokens.at(tokenNum)->getType() != TokenType::LEFT_PAREN) {throw tokens.at(tokenNum)->toString();}
        tokenNum++;
        findHead();
            if (tokens.at(tokenNum)->getType() == TokenType::ID) {
                tokenNum++;
                if (tokens.at(tokenNum)->getType() != TokenType::LEFT_PAREN) {throw tokens.at(tokenNum)->toString();}
                tokenNum++;
                findBody();
            }
            else { throw tokens.at(tokenNum)->toString();}
    }
    else { throw tokens.at(tokenNum)->toString();}
}

void Parser::findHead() {
    if (tokens.at(tokenNum)->getType() == TokenType::ID) {
        tokenNum++;
        TokenType testToken = tokens.at(tokenNum)->getType(); // DELETEME
        if (tokens.at(tokenNum)->getType() == TokenType::COMMA) {
            tokenNum++;
            findHead(); // This goes until it hits the )
        }// KEEP GOING FROM HERE< NOT DONE
        else if (tokens.at(tokenNum)->getType() == TokenType::RIGHT_PAREN) {
            tokenNum++;
            if (tokens.at(tokenNum)->getType() == TokenType::COLON_DASH) {
                tokenNum++;
            }
            else {throw tokens.at(tokenNum)->toString();}
        }
        else {throw tokens.at(tokenNum)->toString();}

    }
    else { throw tokens.at(tokenNum)->toString();}
}

void Parser::findBody() {
    if (tokens.at(tokenNum)->getType() == TokenType::ID) {
        tokenNum++;
        TokenType testToken = tokens.at(tokenNum)->getType(); // DELETEME
        if (tokens.at(tokenNum)->getType() == TokenType::COMMA) {
            tokenNum++;
            findBody(); // This goes until it hits the )
        }// KEEP GOING FROM HERE< NOT DONE
        else if (tokens.at(tokenNum)->getType() == TokenType::RIGHT_PAREN) {
            tokenNum++;
            TokenType testToken = tokens.at(tokenNum)->getType(); // DELETEME
            if (tokens.at(tokenNum)->getType() == TokenType::PERIOD) {
                tokenNum++;
                if (tokens.at(tokenNum)->getType() == TokenType::ID) {manyRules();}
            }
            else if (tokens.at(tokenNum)->getType() == TokenType::COMMA) {
                tokenNum++;
                if (tokens.at(tokenNum)->getType() == TokenType::ID) {
                    tokenNum++;
                    if (tokens.at(tokenNum)->getType() != TokenType::LEFT_PAREN) {throw tokens.at(tokenNum)->toString();}
                    tokenNum++;
                    findBody();
                }
                else { throw tokens.at(tokenNum)->toString();} // if it is adding multiples it will repeat the body.
            }
            else {throw tokens.at(tokenNum)->toString();}
        }
        else {throw tokens.at(tokenNum)->toString();}

    }
    else if (tokens.at(tokenNum)->getType() == TokenType::STRING) {
        tokenNum++;
        TokenType testToken = tokens.at(tokenNum)->getType(); // DELETEME
        if (tokens.at(tokenNum)->getType() == TokenType::COMMA) {
            tokenNum++;
            findBody(); // This goes until it hits the )
        }// KEEP GOING FROM HERE< NOT DONE
        else if (tokens.at(tokenNum)->getType() == TokenType::RIGHT_PAREN) {
            tokenNum++;
            if (tokens.at(tokenNum)->getType() == TokenType::PERIOD) {
                tokenNum++;
                if (tokens.at(tokenNum)->getType() == TokenType::ID) {manyRules();}
            }
            else {throw tokens.at(tokenNum)->toString();}
        }
        else {throw tokens.at(tokenNum)->toString();}

    }
    else { throw tokens.at(tokenNum)->toString();}
}
/*                                                          ---------------------- _||_ --
                                                            --Check the Queries--- \  / --
                                                            ----------------------  \/  --
*/
void Parser::manyQueries() {
    if (tokens.at(tokenNum)->getType() == TokenType::ID) {
        name = tokens.at(tokenNum)->getDesc();
        tokenNum++;
        if (tokens.at(tokenNum)->getType() != TokenType::LEFT_PAREN) {throw tokens.at(tokenNum)->toString();}
        inParen += tokens.at(tokenNum)->getDesc();
        tokenNum++;
        manyTests();
    }
    else { throw tokens.at(tokenNum)->toString();}
}

void Parser::manyTests() {
    if (tokens.at(tokenNum)->getType() == TokenType::STRING) {
        inParen += tokens.at(tokenNum)->getDesc();
        tokenNum++;
        TokenType testToken = tokens.at(tokenNum)->getType();
        if (tokens.at(tokenNum)->getType() == TokenType::COMMA) {
            inParen += tokens.at(tokenNum)->getDesc();
            tokenNum++;
            manyTests();
        }
        else if (tokens.at(tokenNum)->getType() == TokenType::RIGHT_PAREN) {
            inParen += tokens.at(tokenNum)->getDesc();
            tokenNum++;
            TokenType testToken = tokens.at(tokenNum)->getType();
            if (tokens.at(tokenNum)->getType() == TokenType::Q_MARK) {
                tokenNum++;
                program.addQuery(name, inParen);
                name = "";
                inParen = "";
                if (tokens.at(tokenNum)->getType() == TokenType::ID) {manyQueries();}
            }
            else {throw tokens.at(tokenNum)->toString();}

        }
        else {throw tokens.at(tokenNum)->toString();}

    }
    else if (tokens.at(tokenNum)->getType() == TokenType::ID) {
        inParen += tokens.at(tokenNum)->getDesc();
        tokenNum++;
        TokenType testToken = tokens.at(tokenNum)->getType();
        if (tokens.at(tokenNum)->getType() == TokenType::COMMA) {
            inParen += tokens.at(tokenNum)->getDesc();tokenNum++;
            manyTests();
        }
        else if (tokens.at(tokenNum)->getType() == TokenType::RIGHT_PAREN) {
            inParen += tokens.at(tokenNum)->getDesc();
            tokenNum++;
            TokenType testToken = tokens.at(tokenNum)->getType();
            if (tokens.at(tokenNum)->getType() == TokenType::Q_MARK) {
                tokenNum++;
                program.addQuery(name, inParen);
                name = "";
                inParen = "";
                TokenType testToken = tokens.at(tokenNum)->getType();
                if (tokens.at(tokenNum)->getType() == TokenType::ID) {manyQueries();}
            }
            else {throw tokens.at(tokenNum)->toString();}

        }
        else {throw tokens.at(tokenNum)->toString();}

    }
    else { throw tokens.at(tokenNum)->toString();}
}

/*                                                          ---------------------- _||_ --
                                                            --toString------------ \  / --
                                                            ----------------------  \/  --
*/
string Parser::parserToString()
{
    return program.tostring();
    /*call the datalog tostring
            which called the pridicate tostring for each
                            which called prints the id and calls the perameter tostring
                    predicate to string
            call the queires tostring
     */
}