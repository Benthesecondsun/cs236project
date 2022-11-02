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


};


#endif //CS236PROJECT_MYTUPLE_H
