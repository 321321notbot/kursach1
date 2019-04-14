#ifndef TP_Smartphone_H
#define TP_Smartphone_H



#include "Device.h"

class Smartphone : public Device {
public:
	void writeToFile(ostream &file) override;
	void readFromFile(istream &file) override;

	string getFilename() override;

	void toConsole() override;

	friend ostream &operator<<(ostream &os, const Smartphone &p);
	friend istream &operator >> (istream &in, Smartphone &p);
};


#endif //TP_Smartphone_H
