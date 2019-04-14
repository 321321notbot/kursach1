#include <iostream>
#include "Satellitephone.h"


void Satellitephone::writeToFile(ostream &file) {
	file << "Satellitephone" << endl;
	Device::writeToFile(file);
}

void Satellitephone::readFromFile(istream &file) {
	Device::readFromFile(file);
}
istream &operator >> (istream &in, Satellitephone &sc) {
	in >> static_cast<Device &>(sc);
	return in;
}
ostream &operator<<(ostream &os, const Satellitephone &sc) {
	os << "Satellitephone - " << static_cast<const Device &>(sc);
	return os;
}

void Satellitephone::toConsole() {
	cout << *this;
}
string Satellitephone::getFilename() {
	return "Satellitephone.txt";
}



