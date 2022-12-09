#ifndef CS236PROJECT_GRAPH_H
#define CS236PROJECT_GRAPH_H
#include <vector>
#include "Rule.h"
#include "node.h"
using namespace std;

class Graph {
private:

   vector<Rule*> Rules;
   vector<node> rulesAsNodes;
   vector<node> adjacencyList;
   vector<node> reverseList;
   vector<string> RuleLeftSideIDs;
public:
    bool operator==(const Graph &rhs) const;

    bool operator!=(const Graph &rhs) const;
    void SetRules(vector<Rule*> newRules) {this->Rules = newRules;}
    vector<node> SetNodesLeftID(vector<string> allPossibleNodeIDs);
    void CreateAdjacencyList(); // this will have rules tha
    void CreateReverseList();
    void GetRuleLeftSideIDs();
    void CreateRulesAsNodes();
    vector<string> SetRuleNumOnLeft();
    vector<string> GetRightSideStringsMatchingLeftID(string matchThisID);
    vector<string> GetLeftSideStringsMatchingRightID(string matchThisID);
};


#endif //CS236PROJECT_GRAPH_H
