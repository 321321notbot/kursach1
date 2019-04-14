#ifndef TP_homephone_H
#define TP_homephone_H


#include "Device.h"

class homephone : public Device {
public:
    void writeToFile(ostream &file) override;
    void readFromFile(istream &file) override;

    string getFilename() override;

    void toConsole() override;

    friend ostream &operator<<(ostream &os, const homephone &gp);
    friend istream &operator>>(istream &in, homephone &gp);
};


#endif //TP_homephone_H
