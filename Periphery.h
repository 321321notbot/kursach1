#ifndef TP_PERIPHERY_H
#define TP_PERIPHERY_H

#include <ostream>
#include "Device.h"

class Periphery {
private:
    static Periphery *periphery;

    int size;
    Device **devices;

    Periphery();
public:

    Periphery(const Periphery&) = delete;
    Periphery& operator=(Periphery&) = delete;

    Periphery& add(Device &device);
    Periphery& remove(int index);

    static Periphery* getInstance() {
        if(!periphery)
            periphery = new Periphery();
        return periphery;
    }

    int getSize() const;
    Device **getDevices() const;

    void writeToFile();
    void readFromFile();

    friend std::ostream &operator<<(std::ostream &os, const Periphery &periphery);

    ~Periphery();
};


#endif //TP_PERIPHERY_H
