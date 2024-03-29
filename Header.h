#ifndef CS236PROJECT_HEADER_H
#define CS236PROJECT_HEADER_H
#include <string>
#include <vector>

using namespace std;

class Header {
private:
    vector<string> columnNames;

public:
    Header() = default;
    ~Header() = default;
    void SetHeader(string newAttribute);
    Header GetNewHeader(vector<int> newColumns) {
        Header newHeader;
        for (unsigned int i = 0; i < newColumns.size(); ++i) {
            newHeader.SetHeader(columnNames.at(newColumns.at(i)));
        }
        return newHeader;
    }
    string GetHeader(int index) {return columnNames.at(index);}
    bool isEmpty() {return columnNames.empty();}
    bool operator==(const Header &rhs) const {
        return columnNames == rhs.columnNames;
    }

    bool operator!=(const Header &rhs) const {
        return !(rhs == *this);
    }
    vector<string> RetrieveHeader() {return columnNames;}
};


#endif //CS236PROJECT_HEADER_H
