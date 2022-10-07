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
    void split(string in);

};


#endif //CS236PROJECT_PARAMETER_H
