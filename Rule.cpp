#include "Rule.h"
Rule::Rule(Predicate* inHead, vector<Predicate*> copyVec) {
    Head = new Predicate(inHead->getID(),inHead->getParams());
}

Rule::~Rule() {}

string Rule::toString() {}