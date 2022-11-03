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
    void SetHeader(string newAttribute) {columnNames.push_back(newAttribute);}
    Header GetHeader(vector<int> newColumns) {
        Header newHeader;
        for (int i = 0; i < newColumns.size(); ++i) {
            newHeader.SetHeader(columnNames.at(newColumns.at(i)));
        }
        return newHeader;
    }

    bool operator==(const Header &rhs) const {
        return columnNames == rhs.columnNames;
    }

    bool operator!=(const Header &rhs) const {
        return !(rhs == *this);
    }
};


#endif //CS236PROJECT_HEADER_H
