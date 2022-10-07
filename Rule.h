#ifndef CS236PROJECT_RULE_H
#define CS236PROJECT_RULE_H
#include <string>
#include <vector>
#include "Predicate.h"
using namespace std;

class Rule {
private:
    Predicate* Head;
    //vector<Predicate*> body;
public:
    Rule(Predicate* inHead, vector<Predicate*> copyVec);
    ~Rule();
    string toString();
};


#endif //CS236PROJECT_RULE_H
