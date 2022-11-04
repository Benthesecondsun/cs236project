#include "Interpreter.h"

void Interpreter::InterpretSchemes(){
    Relation newRelation;
    Header newHeader;
    for (Predicate* scheme:program.GetSchemes()) {
        newRelation.SetName(scheme->getID());

        for (Parameter* parameter: scheme->getParams()) {
            for (string string1:parameter->GetStringParams()) {
                newHeader.SetHeader(string1);
            }

        }
        newRelation.SetNewHeader(newHeader);
        database.AddRelation(newRelation);
    }
}
void Interpreter::InterpretFacts(){

    Relation* relationPtr;
    for (Predicate* facts:program.GetFacts()) {
        for (Parameter* parameter: facts->getParams()) {
            MyTuple tuple;
            for (string string1:parameter->GetStringParams()) {
                tuple.SetTuple(string1);
            }
            relationPtr = database.GetRelation(facts->getID());
            relationPtr->AddTuple(tuple);
        }

    }
}
void Interpreter::InterpretQueries(){

}