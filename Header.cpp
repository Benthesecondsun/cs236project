#include "Header.h"
void Header::SetHeader(string newAttribute) {
    bool headerAlreadyExists = false;
    for (unsigned int i = 0; i < columnNames.size(); ++i) {
        if (columnNames.at(i) == newAttribute) {headerAlreadyExists = true;}
    }
    if (!headerAlreadyExists) {columnNames.push_back(newAttribute);}

}