#include "Parameter.h"

Parameter::Parameter(string in) {
    numParams = 0;
    //eachParam.push_back(in);
    //in.erase(std::remove(in.begin(), in.end(), ' '), in.end());
    in.erase(std::remove(in.begin(), in.end(), '('), in.end());
    in.erase(std::remove(in.begin(), in.end(), ')'), in.end());
    split(in.substr(0,in.size()));
}

Parameter::~Parameter() {}

void Parameter::split(string in) {
    int counter = 0;
    string outString = "";
    while (in.at(counter) != ',') {
        outString += in.at(counter);
        counter++;
        if (counter == in.size()) {
            eachParam.push_back(outString);
            numParams++;
            return;
        }
    }
    eachParam.push_back(outString);
    numParams++;
    split(in.substr(counter + 1,in.size()));
}


string Parameter::toString() {
    string outString = "";
    for (unsigned int i = 0; i < eachParam.size(); i++) {
        outString += eachParam.at(i);
        if (i != eachParam.size() - 1) {outString += ",";}
    }
    return outString;
}