#ifndef CS236PROJECT_DATABASE_H
#define CS236PROJECT_DATABASE_H
#include "Relation.h"
#include <map>

using namespace std;

class Database {
private:
    map <string, Relation> relations;
public:
    void AddRelation(Relation NewRelation);
    Relation* GetRelation(string relationName);
    Relation GetRelationCopy(string relationName);
    int TotalTuples();
};


#endif //CS236PROJECT_DATABASE_H
