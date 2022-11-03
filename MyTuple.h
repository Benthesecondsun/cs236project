#ifndef CS236PROJECT_MYTUPLE_H
#define CS236PROJECT_MYTUPLE_H

#include <string>
#include <vector>

using namespace std;

class MyTuple {
private:
    vector<string> rowValues;

public:
    bool operator<(const MyTuple &rhs) const;

    bool operator>(const MyTuple &rhs) const;

    bool operator<=(const MyTuple &rhs) const;

    bool operator>=(const MyTuple &rhs) const;

    string CheckTuple(int column) {return rowValues.at(column);}
    void SetTuple(string newAttribute) {rowValues.push_back(newAttribute);}
};


#endif //CS236PROJECT_MYTUPLE_H
