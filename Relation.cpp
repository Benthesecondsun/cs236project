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