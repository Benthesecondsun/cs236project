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

}
void Interpreter::InterpretQueries(){

}