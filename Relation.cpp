#include "Relation.h"


string Relation::ToString() {
    string outString = "";
    if (!columnNames.isEmpty()) {
        for (auto theTuple: tuples) {
            outString += "  ";
            for (int i = 0; i < theTuple.size(); ++i) {
                outString += columnNames.GetHeader(i) + "=" + theTuple.ToString(i);
                if (i != theTuple.size() - 1) { outString += ", "; }
            }
            outString += "\n";
        }
    }
    return outString;
}

Relation Relation::select1(int columnIndex, string value) {
    Relation newRelation;
    //newRelation.SetNewHeader(this->columnNames);
    for (MyTuple Tuple:tuples) {
        if (Tuple.CheckTuple(columnIndex) == value) {newRelation.AddTuple(Tuple);}
    }
    return newRelation;
}

Relation Relation::select2(int columnIndex1, int columnIndex2) {
    Relation newRelation;
    //newRelation.SetNewHeader(this->columnNames);
    for (MyTuple Tuple:tuples) {
        if (Tuple.CheckTuple(columnIndex1) == Tuple.CheckTuple(columnIndex2)) {newRelation.AddTuple(Tuple);}
    }
    return newRelation;
}

Relation Relation::project(vector<int> columnsToProject) {
    Relation newRelation;
    vector<MyTuple> newTuples;
    Header newHeader = columnNames.GetNewHeader(columnsToProject);
    for (MyTuple tuple: tuples) {
        MyTuple aNewTuple;
        newTuples.push_back(aNewTuple);
    }
    for (unsigned int i = 0; i < columnsToProject.size(); ++i) {
        int tupleNum = 0;
        for (MyTuple tuple: tuples) {
            newTuples.at(tupleNum).SetTuple(tuple.CheckTuple(columnsToProject.at(i)));
            tupleNum++;
        }
    }
    // setting newrelation header to newrelation's tuples
    newRelation.SetNewHeader(newHeader);
    for (unsigned int i = 0; i < newTuples.size(); ++i) {
        newRelation.AddTuple(newTuples.at(i));
    }
    return newRelation;
}

Relation Relation::rename(vector<string> newColumnNames) {
    Relation newRelation;
    newRelation.tuples = this->tuples;
    newRelation.columnNames = this->columnNames;
    Header newHeader;
    for (unsigned int i = 0; i < newColumnNames.size(); ++i) {
        newHeader.SetHeader(newColumnNames.at(i));
    }
    newRelation.SetNewHeader(newHeader);
    return newRelation;
}

Relation Relation::join(Relation relationToJoinWith) {
    Relation newRelation;
    newRelation.SetNewHeader(this->columnNames);
    for (string strings: relationToJoinWith.columnNames.RetrieveHeader()) {
        newRelation.columnNames.SetHeader(strings);
    }
    // Just completed adding the headers together
    vector<MyTuple> headersToCombine;
    vector<int> avoidTheseBetaColumns;
    int alphaIndex = 0;
    for (string alphaHeaders:this->columnNames.RetrieveHeader()) {
        int betaIndex = 0;
        for (string betaHeaders:relationToJoinWith.columnNames.RetrieveHeader()) {
            MyTuple newTuple;
            if (alphaHeaders == betaHeaders) {
                newTuple.SetTuple(to_string(alphaIndex));
                newTuple.SetTuple(to_string(betaIndex));
                headersToCombine.push_back(newTuple);
                avoidTheseBetaColumns.push_back(betaIndex);
                break;
            }else {
                betaIndex++;
            }
        }
        alphaIndex++;
    }
    if (!headersToCombine.empty()) { //code to combine tuples
        for (MyTuple alphaTuples:this->tuples) {
            for (MyTuple betaTuples:relationToJoinWith.tuples) {
                int matchedHeaders = 0;
                for (MyTuple headerTuples:headersToCombine) {
                    if (alphaTuples.CheckTuple(stoi(headerTuples.CheckTuple(0))) == betaTuples.CheckTuple(stoi(headerTuples.CheckTuple(1)))) {++matchedHeaders;}
                }
                if (matchedHeaders == headersToCombine.size()) {
                    MyTuple newTuple = alphaTuples;
                    bool avoid = false;
                    for (unsigned int i = 0; i < betaTuples.getRowValues().size(); i++) {
                        for (int avoidNums:avoidTheseBetaColumns) {
                            if (i == avoidNums) {avoid = true;}
                        }
                        if (avoid == false) {
                            newTuple.SetTuple(betaTuples.getRowValues().at(i));
                        }
                        avoid = false;
                    }
                    newRelation.AddTuple(newTuple);
                }
            }
        }
    }
    else {
        vector<MyTuple> newTuples;
        MyTuple newTuple;
        for (MyTuple alphaTuples:this->tuples) {
            newTuple = alphaTuples;
            for (MyTuple betaTuples:relationToJoinWith.tuples) {
                for (int j = 0; j < betaTuples.size(); ++j) {
                    newTuple.SetTuple(betaTuples.CheckTuple(j));
                }
                newTuples.push_back(newTuple);
                newTuple = alphaTuples;
            }
            for (MyTuple tuplesToAdd:newTuples) {
                newRelation.AddTuple(tuplesToAdd);
            }

        }

    }
    return newRelation;
}

Relation Relation::myUnion(Relation relationToUnionWith) {
    Relation newRelation;
    string outString;
    for (MyTuple newTuple:relationToUnionWith.tuples) {
        if(this->tuples.insert(newTuple).second) {
            numTuples++;
            outString += "  ";
            for (int i = 0; i < newTuple.size(); ++i) {
                outString += columnNames.GetHeader(i) + "=" + newTuple.ToString(i);
                if (i != newTuple.size() - 1) { outString += ", "; }
            }
            outString += "\n";
        }
    }
    cout << outString;

    return newRelation;
}
