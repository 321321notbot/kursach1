#include <iostream>
#include "Smartphone.h"

void Smartphone::writeToFile(ostream &file) {
	file << "Smartphone" << endl;
	Device::writeToFile(file);
}

void Smartphone::readFromFile(istream &file) {
	Device::readFromFile(file);
}

istream &operator >> (istream &in, Smartphone &p) {
	in >> static_cast<Device &>(p);
	return in;
}

ostream &operator<<(ostream &os, const Smartphone &p) {
	os << "Smartphone - " << static_cast<const Device &>(p);
	return os;
}

void Smartphone::toConsole() {
	cout << *this;
}

string Smartphone::getFilename() {
	return "Smartphone.txt";
}

