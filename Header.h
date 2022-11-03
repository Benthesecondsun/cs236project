#ifndef CS236PROJECT_HEADER_H
#define CS236PROJECT_HEADER_H
#include <string>
#include <vector>

using namespace std;

class Header {
private:
    vector<string> columnNames;

public:
    void SetHeader(string newAttribute) {columnNames.push_back(newAttribute);}
    Header GetHeader(vector<int> newColumns) {
        Header newHeader;
        for (int i = 0; i < newColumns.size(); ++i) {
            newHeader.SetHeader(columnNames.at(newColumns.at(i)));
        }
        return newHeader;
    }

};


#endif //CS236PROJECT_HEADER_H
