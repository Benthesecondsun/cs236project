#include "MyTuple.h"

bool MyTuple::operator<(const MyTuple &rhs) const {
    return rowValues < rhs.rowValues;
}

bool MyTuple::operator>(const MyTuple &rhs) const {
    return rhs < *this;
}

bool MyTuple::operator<=(const MyTuple &rhs) const {
    return !(rhs < *this);
}

bool MyTuple::operator>=(const MyTuple &rhs) const {
    return !(*this < rhs);
}

bool MyTuple::operator==(const MyTuple &rhs) const {
    return rowValues == rhs.rowValues;
}

bool MyTuple::operator!=(const MyTuple &rhs) const {
    return !(rhs == *this);
}
