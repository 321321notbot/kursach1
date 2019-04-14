#include <iostream>
#include "homephone.h"

void homephone::writeToFile(ostream &file) {
    file << "homephone" << endl;
    Device::writeToFile(file);
}

void homephone::readFromFile(istream &file) {
    Device::readFromFile(file);
}

istream &operator>>(istream &in, homephone &gp) {
    in >> static_cast<Device &>(gp);
    return in;
}

ostream &operator<<(ostream &os, const homephone &gp) {
    os << "homephone - " << static_cast<const Device &>(gp);
    return os;
}

void homephone::toConsole() {
    cout << *this;
}

string homephone::getFilename() {
    return "homephone.txt";
}
