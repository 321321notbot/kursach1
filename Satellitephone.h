#ifndef TP_Satellitephone_H
#define TP_Satellitephone_H


#include "Device.h"

class Satellitephone : public Device {
public:
	void writeToFile(ostream &file) override;
	void readFromFile(istream &file) override;

	string getFilename() override;

	void toConsole() override;

	friend ostream &operator<<(ostream &os, const Satellitephone &sc);
	friend istream &operator >> (istream &in, Satellitephone &sc);
};




#endif //TP_Satellitephone_H
