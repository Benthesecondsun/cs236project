#ifndef CS236PROJECT_PARAMETER_H
#define CS236PROJECT_PARAMETER_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Parameter {
private:


public:
    vector <string> eachParam;
    Parameter(string in);
    ~Parameter();
    int numParams;
    string toString();
    string singleToString(int index) {return eachParam.at(index);}
    void split(string in);
    vector <string> GetStringParams() {return eachParam;}

};


#endif //CS236PROJECT_PARAMETER_H
