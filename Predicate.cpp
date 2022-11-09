#include "Predicate.h"
Predicate::Predicate(string inID, string inParams) {
    ID = inID;
    params.push_back(new Parameter(inParams));
}

Predicate::~Predicate() {
    for (auto & Parameter : params) {
        delete Parameter;
    }
}
void Predicate::setID(string inID) {
    ID = inID;
}

void Predicate::setVector(string inParams) {
    params.push_back(new Parameter(inParams));
}

void Predicate::resetID() {
    ID = "";
}


void Predicate::resetVector() {
    for (unsigned int i = 0; i < params.size(); ++i) {
        delete params.at(i);
    }
}


string Predicate::getID() {
    return ID;
}

vector<Parameter*> Predicate::getParams() {
    return params;
}


string Predicate::toString() {
    string outString = ID + "(";
    for (unsigned int i = 0; i < params.size(); i++) {
        outString += params.at(i)->toString();
        if (i != params.size() - 1) {outString += ", ";}
    }
    outString += ")?";
    return outString;
}