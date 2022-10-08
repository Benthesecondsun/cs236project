#ifndef CS236PROJECT_PREDICATE_H
#define CS236PROJECT_PREDICATE_H
#include "Parameter.h"
#include <string>
#include <vector>
#include <set>

using namespace std;


class Predicate {
private:
    string ID;
    vector<Parameter*> params;
public:
    Predicate(string inID, string inParams);
    Predicate() {};
    ~Predicate();
    void setID(string inID);
    void setVector(string inParams);
    void resetID();
    void resetVector();
    string getID();
    vector<Parameter*> getParams();

    string toString();
};


#endif //CS236PROJECT_PREDICATE_H
