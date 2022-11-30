#include "Interpreter.h"

void Interpreter::InterpretSchemes(){
    Relation newRelation;

    for (Predicate* scheme:program.GetSchemes()) {
        newRelation.SetName(scheme->getID());

        for (Parameter* parameter: scheme->getParams()) {
            Header newHeader;
            for (string string1:parameter->GetStringParams()) {
                newHeader.SetHeader(string1);
            }
            newRelation.SetNewHeader(newHeader);
            database.AddRelation(newRelation);
        }

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

void Interpreter::InterpretRules() { // CHANGE ME
    Relation* relationPtr;
    int preRulesNumTuples = 0;
    preRulesNumTuples = database.TotalTuples();
    //string outString;
    for (Rule* rules:program.GetRules()) { // INSIDE RULES
        Relation finalRelation;
        int isFirstBodyPred = 0;
        for (Predicate* bodyPredicates:rules->GetBody()) { // for every Predicate* in the queries vector
            //outString += query->toString() + " ";
            relationPtr = database.GetRelation(bodyPredicates->getID());
            for (Parameter* parameter: bodyPredicates->getParams()) { // for every parameter in the params vector
                vector <string> seenVariables;
                vector <int> indexOfSeenVariables;
                int indexNumber = 0;
                Relation tempRelation = *relationPtr;
                bool newVar = true;
                for (string string1:parameter->GetStringParams()) { // for each string in the each param vector
                    if (string1.at(0) == '\'') { // do select 1
                        tempRelation = relationPtr->select1(indexNumber, string1);
                        relationPtr = &tempRelation;
                    }
                    else {  // this means it is a variable
                        if (seenVariables.empty()) {seenVariables.push_back(string1);indexOfSeenVariables.push_back(indexNumber);}
                        else {
                            for (unsigned int i = 0; i < seenVariables.size(); ++i) {
                                if (seenVariables.at(i) == string1) { // do select 2
                                    tempRelation = relationPtr->select2(indexOfSeenVariables.at(i), indexNumber);
                                    relationPtr = &tempRelation;
                                    newVar = false;
                                }
                            }
                            if (newVar == true) {seenVariables.push_back(string1); indexOfSeenVariables.push_back(indexNumber);}
                            newVar = true;
                        }
                    }
                    indexNumber++;
                }
                if (!tempRelation.IsEmpty()) {
                    //outString += "Yes(" + to_string(tempRelation.GetNumTuples()) + ")\n";
                    Header newHeader;
                    if (!seenVariables.empty()) {
                        for (unsigned int i = 0; i < seenVariables.size(); ++i) {
                            newHeader.SetHeader(seenVariables.at(i));
                        }
                        tempRelation.SetNewHeader(newHeader);
                        tempRelation = tempRelation.project(indexOfSeenVariables);
                        tempRelation.rename(seenVariables);
                        if (isFirstBodyPred == 0) {finalRelation = tempRelation;}
                        else {finalRelation = finalRelation.join(tempRelation);}

                    }
                    //outString += tempRelation.ToString();
                    //cout << outString;
                    //outString = "";
                    tempRelation = *relationPtr;

                }
                else {
                    //outString += "No\n";
                    //cout << outString;
                    //outString = "";
                }
            }
            ++isFirstBodyPred;
        }
                                                                         // Mess with the head now.
        Relation headRelation;
        vector<int> columnsToProject;
        vector<MyTuple> headersToCombine;
        int alphaIndex = 0;
        vector<Parameter*> headPtr = rules->GetHead()->getParams();
        Header headersOfTheHead;
        for (Parameter* parameter: headPtr) {
            for (string alphaHeaders: parameter->GetStringParams()) {
                int betaIndex = 0;
                for (string betaHeaders: finalRelation.GetHeader().RetrieveHeader()) {
                    MyTuple newTuple;
                    if (alphaHeaders == betaHeaders) {
                        newTuple.SetTuple(to_string(alphaIndex));
                        newTuple.SetTuple(to_string(betaIndex));
                        headersToCombine.push_back(newTuple);
                        columnsToProject.push_back(betaIndex);
                        break;
                    } else {
                        betaIndex++;
                    }
                }
                alphaIndex++;
            }
        }
        finalRelation = finalRelation.project(columnsToProject);
        finalRelation.SetName(rules->GetHead()->getID());
        relationPtr = database.GetRelation(finalRelation.GetName());
        finalRelation = finalRelation.rename(relationPtr->GetHeader().RetrieveHeader());
        cout << rules->toString() + ".\n";
        relationPtr->myUnion(finalRelation);
        //run database tuple counter.
    }

    int postRulesNumTuples = 0;
    postRulesNumTuples = database.TotalTuples();
    if (postRulesNumTuples != preRulesNumTuples) {InterpretRules(); ++numPasses;} // Rerun till total tuples doesnt change

}

void Interpreter::InterpretQueries(){
    Relation* relationPtr;
    string outString;
    outString += "\nQuery Evaluation\n";
    for (Predicate* query:program.GetQueries()) { // for every Predicate* in the queries vector
        outString += query->toString() + "? ";
        relationPtr = database.GetRelation(query->getID());
        for (Parameter* parameter: query->getParams()) { // for every parameter in the params vector
            vector <string> seenVariables;
            vector <int> indexOfSeenVariables;
            int indexNumber = 0;
            Relation tempRelation = *relationPtr;
            bool newVar = true;
            for (string string1:parameter->GetStringParams()) { // for each string in the each param vector
                if (string1.at(0) == '\'') { // do select 1
                    tempRelation = relationPtr->select1(indexNumber, string1);
                    relationPtr = &tempRelation;
                }
                else {  // this means it is a variable
                    if (seenVariables.empty()) {seenVariables.push_back(string1);indexOfSeenVariables.push_back(indexNumber);}
                    else {
                        for (unsigned int i = 0; i < seenVariables.size(); ++i) {
                            if (seenVariables.at(i) == string1) { // do select 2
                                tempRelation = relationPtr->select2(indexOfSeenVariables.at(i), indexNumber);
                                relationPtr = &tempRelation;
                                newVar = false;
                            }
                        }
                        if (newVar == true) {seenVariables.push_back(string1); indexOfSeenVariables.push_back(indexNumber);}
                        newVar = true;
                    }
                }
                indexNumber++;
            }
            if (!tempRelation.IsEmpty()) {
                outString += "Yes(" + to_string(tempRelation.GetNumTuples()) + ")\n";
                if (!seenVariables.empty()) {
                    relationPtr = database.GetRelation(query->getID());
                    tempRelation.SetNewHeader(relationPtr->GetHeader());
                    tempRelation = tempRelation.project(indexOfSeenVariables);
                    tempRelation = tempRelation.rename(seenVariables);
                }
                outString += tempRelation.ToString();
                cout << outString;
                outString = "";
                tempRelation = *relationPtr;
            }
            else {
                outString += "No\n";
                cout << outString;
                outString = "";
            }
        }
        // This is where I need to update my cout
        //cout << outString;

    }
}