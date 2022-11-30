#include "Database.h"

void Database::AddRelation(Relation NewRelation) {
    relations.insert({NewRelation.GetName(),NewRelation});
};

Relation* Database::GetRelation(string relationName) {

    map<string, Relation> :: iterator itr = relations.find(relationName);
    return &itr->second;
}

int Database::TotalTuples() {
    int numTuples = 0;
    for (auto x : relations)
    {
        numTuples+= x.second.GetNumTuples();
    }
    return numTuples;
}
