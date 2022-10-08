#ifndef CS236PROJECT_DATALOGPROGRAM_H
#define CS236PROJECT_DATALOGPROGRAM_H
#include "Predicate.h"
#include "Rule.h"
#include <vector>
#include <set>

using namespace std;

class DatalogProgram {
private:
    int numSchemes;
    int numFacts;
    int numRules;
    int numQueries;
    vector<Predicate*> schemes;
    vector<Predicate*> facts;
    vector<Rule*> rules;
    vector<Predicate*> queries;
    set<string> domains;
public:
    DatalogProgram();
    ~DatalogProgram();
    void addScheme(string inID, string inParams);
    void addFact(string inID, string inParams);
    void addRule(Predicate* head, vector<Predicate*> paraVec);
    void addQuery(string inID, string inParams);
    string tostring();
    void setDomain(string in);
};


#endif //CS236PROJECT_DATALOGPROGRAM_H
