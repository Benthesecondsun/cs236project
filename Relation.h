#ifndef CS236PROJECT_RELATION_H
#define CS236PROJECT_RELATION_H
#include <string>
#include <vector>
#include "Header.h"
#include "MyTuple.h"
#include <set>

using namespace std;

class Relation {
private:
    string name;
    Header columnNames;
    set <MyTuple> tuples;
    int numTuples = 0;
public:
    Relation() = default;
    ~Relation() = default;
    Relation(string name, Header columnNames) {
        this->name = name;
        this->columnNames = columnNames;
    }
    string GetName() {return name;}
    int GetNumTuples() {return numTuples;}
    void SetNewHeader(Header newHeader) { columnNames = newHeader;}
    void AddTuple(MyTuple newTuple) {tuples.insert(newTuple); numTuples++;}
    Relation select1(int columnIndex, string value);
    Relation select2(int columnIndex1, int columnIndex2);
    Relation project(vector<int> columnsToProject);
    Relation rename(vector<string> newColumnNames);
    void SetName(string name) {this->name = name;}
    string ToString();
    bool IsEmpty() { return tuples.empty();}
    Header GetHeader() {return columnNames;}








};


#endif //CS236PROJECT_RELATION_H
