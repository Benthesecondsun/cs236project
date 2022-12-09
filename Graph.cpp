//
// Created by bgm98 on 12/8/2022.
//

#include "Graph.h"

bool Graph::operator==(const Graph &rhs) const {
    return Rules == rhs.Rules;
}

bool Graph::operator!=(const Graph &rhs) const {
    return !(rhs == *this);
}

vector<node> Graph::SetNodesLeftID(vector<string> inNodeIDs) {
    vector<node> newNodes;
    for (string IDs:inNodeIDs) {
        node newNode;
        newNode.SetHeadID(IDs);
        newNodes.push_back(newNode);
    }
    return newNodes;
}

void Graph::CreateAdjacencyList() {
    adjacencyList = SetNodesLeftID(SetRuleNumOnLeft());
    int currentNode = 0;
    for (node eachRule:rulesAsNodes) {
        vector<string> rightSideDependents;
        for (string RightSideID:eachRule.GetrightSideIDs()) {
            // needs to go through every left sideID of rules and find all that match the leftID
            for (string matchingLeftSides:GetRightSideStringsMatchingLeftID(RightSideID)) {
                rightSideDependents.push_back(matchingLeftSides);// pushes
            }
        }
        adjacencyList.at(currentNode).SetRightSideIDs(rightSideDependents);
        currentNode++;
    }
}

void Graph::CreateReverseList() {
    reverseList = SetNodesLeftID(SetRuleNumOnLeft());
    int currentNode = 0;
    for (node eachRule:rulesAsNodes) {
        vector<string> leftSideDependents;
        string stringToMatch = eachRule.GetHeadID();
        for (string matchingRightSides:GetLeftSideStringsMatchingRightID(stringToMatch)) {
            leftSideDependents.push_back(matchingRightSides);// pushes
        }
        reverseList.at(currentNode).SetRightSideIDs(leftSideDependents);
        currentNode++;
    }
}

void Graph::GetRuleLeftSideIDs() {
    for (Rule* eachRule: Rules) {
        Predicate* PredPTR = eachRule->GetHead();
        RuleLeftSideIDs.push_back(PredPTR->getID());
    }

}

void Graph::CreateRulesAsNodes() {
    GetRuleLeftSideIDs();
    rulesAsNodes = SetNodesLeftID(RuleLeftSideIDs);
    int ruleNumCounter = 0;
    for (Rule* eachRule: Rules) {
        for(Predicate* rightSideIDs: eachRule->GetBody()) {
            rulesAsNodes.at(ruleNumCounter).AddRightSideID(rightSideIDs->getID());
        }
        ruleNumCounter++;
    }

}

vector<string> Graph::SetRuleNumOnLeft() {
    vector<string> RuleNumsOnLeft;
    for (unsigned int i = 0; i < Rules.size(); ++i) {
        RuleNumsOnLeft.push_back("R" + to_string(i));
    }

    return RuleNumsOnLeft;
}

vector<string> Graph::GetRightSideStringsMatchingLeftID(string matchThisID) {
    vector<string> matchedRules;
    int RuleCounter = 0;
    for (node aRule:rulesAsNodes) {
        if (matchThisID == aRule.GetHeadID()) {matchedRules.push_back("R"+ to_string(RuleCounter));}
        RuleCounter++;
    }
    return matchedRules;
}

vector<string> Graph::GetLeftSideStringsMatchingRightID(string matchThisID) {
    vector<string> matchedRules;
    int RuleCounter = 0;
    for (node aRule: rulesAsNodes) {
        for (string RightSideID: aRule.GetrightSideIDs()) {
            if (matchThisID == RightSideID) { matchedRules.push_back("R" + to_string(RuleCounter)); }

        }
        RuleCounter++;
    }
    return matchedRules;
}