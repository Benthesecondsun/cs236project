#include "Relation.h"


string Relation::ToString() {
    string outString = "";
    for (auto& string:tuples) {
        
    }
    return outString;
}

Relation Relation::select1(int columnIndex, string value) {
    Relation newRelation; // CHANGE ME
    for (MyTuple Tuple:tuples) {
        if (Tuple.CheckTuple(columnIndex) == value) {newRelation.AddTuple(Tuple);}
    }
    return newRelation;
}

Relation Relation::select2(int columnIndex1, int columnIndex2) {
    Relation newRelation;
    for (MyTuple Tuple:tuples) {
        if (Tuple.CheckTuple(columnIndex1) == Tuple.CheckTuple(columnIndex2)) {newRelation.AddTuple(Tuple);}
    }
    return newRelation;
}

Relation Relation::project(vector<int> columnsToProject) {
    Relation newRelation;
    vector<MyTuple> newTuples;
    Header newHeader = columnNames.GetHeader(columnsToProject);
    for (MyTuple tuple: tuples) {
        MyTuple aNewTuple;
        newTuples.push_back(aNewTuple);
    }
    for (unsigned int i = 0; i < columnsToProject.size(); ++i) {
        for (MyTuple tuple: tuples) {
            newTuples.at(i).SetTuple(tuple.CheckTuple(columnsToProject.at(i)));
        }
    }
    // setting newrelation header to newrelation's tuples
    newRelation.SetHeader(newHeader);
    for (int i = 0; i < newTuples.size(); ++i) {
        newRelation.AddTuple(newTuples.at(i));
    }
    return newRelation;
}

Relation Relation::rename(vector<string> newColumnNames) {
    Relation newRelation;
    newRelation.tuples = this->tuples;
    newRelation.columnNames = this->columnNames;
    Header newHeader;
    for (int i = 0; i < newColumnNames.size(); ++i) {
        newHeader.SetHeader(newColumnNames.at(i));
    }
    newRelation.SetHeader(newHeader);
    return newRelation;
}