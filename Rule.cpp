#include "Rule.h"
Rule::Rule(Predicate* header, vector<Predicate*> theBody) {
    head = header;
    body = theBody;
}


string Rule::toString() {
    string outString = head->toString() + " :- ";
    for (unsigned int i = 0; i < body.size(); ++i) {
        outString += body.at(i)->toString();
        if (i != body.size()-1) {outString += ",";}
        else {}
    }
    return outString;
}