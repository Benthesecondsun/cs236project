#include "Database.h"

void Database::AddRelation(Relation NewRelation) {
    relations.insert({NewRelation.GetName(),NewRelation});
};