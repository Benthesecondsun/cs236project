#ifndef CS236PROJECT_NODE_H
#define CS236PROJECT_NODE_H
#include <string>
#include <vector>
using namespace std;

class node {
private:
        string leftSideID;
        vector<string> rightSideIDs;

public:
    void SetHeadID(string ID) {this->leftSideID = ID;}
    void AddRightSideID(string ID) {rightSideIDs.push_back(ID);}
    vector<string> GetrightSideIDs() {return rightSideIDs;}
    string GetHeadID() {return leftSideID;}
    void SetRightSideIDs(vector<string> newRightSideIDs) {rightSideIDs = newRightSideIDs;}
};


#endif //CS236PROJECT_NODE_H
