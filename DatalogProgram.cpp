#include "DatalogProgram.h"
DatalogProgram::DatalogProgram() {
    numSchemes = 0;
    numFacts = 0;
    numRules = 0;
    numQueries = 0;
}

DatalogProgram::~DatalogProgram() {}

void DatalogProgram::addScheme(string inID, string inParams) {
    numSchemes++;
    schemes.push_back(new Predicate(inID, inParams));
}

void DatalogProgram::addFact(string inID, string inParams) {
    numFacts++;
    facts.push_back(new Predicate(inID, inParams));
}

void DatalogProgram::addRule(Predicate* head, vector<Predicate*> paraVec) {
    numRules++;
    rules.push_back(new Rule(head, paraVec));
}

void DatalogProgram::addQuery(string inID, string inParams) {
    numQueries++;
    queries.push_back(new Predicate(inID, inParams));
}

void DatalogProgram::setDomain(std::string in) {
    domains.insert(in);
}


string DatalogProgram::tostring() {
    string outString = "";
    outString += "Schemes(" + to_string(numSchemes) + "):\n";
    for (unsigned int i = 0; i < schemes.size(); i++) {
        outString += "  " + schemes.at(i)->toString() + "\n";
    }
    outString += "Facts(" + to_string(numFacts) + "):\n";
    for (unsigned int i = 0; i < facts.size(); i++) {
        outString += "  " + facts.at(i)->toString() + ".\n";
    }
    outString += "Rules(" + to_string(numRules) + "):\n";
    for (unsigned int i = 0; i < rules.size(); i++) {
        outString += "  " + rules.at(i)->toString() + ".\n";
    }
    outString += "Queries(" + to_string(numQueries) + "):\n";
    for (unsigned int i = 0; i < queries.size(); i++) {
        outString += "  " + queries.at(i)->toString() + "?\n";
    }
    outString += "Domain(" + to_string(domains.size()) + "):\n  ";
    set<string>::iterator itr;
        for (itr = domains.begin(); itr != domains.end(); itr++) {
            outString +=  *itr;
            if (itr != domains.end()) {outString +=  "\n  ";}
        }
    return outString;
}