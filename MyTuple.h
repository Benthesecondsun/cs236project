#ifndef CS236PROJECT_MYTUPLE_H
#define CS236PROJECT_MYTUPLE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MyTuple {
private:
    vector<string> rowValues;
    int numTupleElements = 0;
public:
    bool operator<(const MyTuple &rhs) const;

    bool operator>(const MyTuple &rhs) const;

    bool operator<=(const MyTuple &rhs) const;

    bool operator==(const MyTuple &rhs) const;

    bool operator!=(const MyTuple &rhs) const;

    bool operator>=(const MyTuple &rhs) const;
    vector<string> getRowValues() {return rowValues;}
    string CheckTuple(int column) {return rowValues.at(column);}
    void SetTuple(string newAttribute) {rowValues.push_back(newAttribute); numTupleElements++;}
    string ToString(int index) {
        return rowValues.at(index);
    }
    string ToString();
    int size() {return numTupleElements;}
};


#endif //CS236PROJECT_MYTUPLE_H
