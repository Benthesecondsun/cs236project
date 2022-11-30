#ifndef CS236PROJECT_RULE_H
#define CS236PROJECT_RULE_H
#include <string>
#include <vector>
#include "Predicate.h"
using namespace std;

class Rule {
private:
    Predicate* head;
    vector<Predicate*> body;
public:
    Rule(Predicate* header, vector<Predicate*> theBody);
    ~Rule() {}
    string toString();
    vector<Predicate*> GetBody() {return body;}
    Predicate* GetHead() {return head;}
};


#endif //CS236PROJECT_RULE_H
