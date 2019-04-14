#include <iostream>
#include <fstream>

#include "Periphery.h"

#include "Smartphone.h"
#include "Satellitephone.h"
#include "homephone.h"

using namespace std;

Periphery* Periphery::periphery = nullptr;

Periphery::Periphery() {
    size = 0;
    devices = new Device*[size];
}

Periphery::~Periphery() {
    size = 0;
    delete []devices;
}

std::ostream &operator<<(std::ostream &os, const Periphery &periphery) {
    os << "Всего: " << periphery.size << endl;
    for (int i = 0; i < periphery.size; ++i) {
        periphery.devices[i]->toConsole();
        cout << endl;
    }
    return os;
}

int Periphery::getSize() const {
    return size;
}


Device **Periphery::getDevices() const {
    return devices;
}

Periphery &Periphery::add(Device &device) {
    this->size++;
    Device **copy = new Device*[this->size - 1];
    for (int i = 0; i < this->size - 1; ++i) {
        copy[i] = this->devices[i];
    }
    this->devices = new Device*[this->size];
    for (int j = 0; j < this->size - 1; ++j) {
        this->devices[j] = copy[j];
    }
    this->devices[size - 1] = &device;
    return *this;
}

Periphery &Periphery::remove(int index) {
    if (index < 0 || index >= this->size) {
        cout << "oshibka" << endl;
    } else {
        int k = 0;
        Device **copy = new Device*[this->size-1];
        for (int i = 0; i < this->size; ++i) {
            if (i != index) {
                copy[k] = this->devices[i];
                k++;
            }
        }
        this->size--;
        this->devices = new Device*[this->size];
        for (int j = 0; j < this->size; ++j) {
            this->devices[j] = copy[j];
        }
    }
    return *this;
}

void Periphery::writeToFile() {
    const string files[] = {
            "Satellitephone.txt", "Smartphone.txt", "homephone.txt"
    };
    const int length = 3;
    for (int j = 0; j < 3; ++j) {
        ofstream file;
        int count = 0;
        file.open(files[j], ios_base::out);
        for (int i = 0; i < size; ++i) {
            if (devices[i]->getFilename() == files[j]) {
                count++;
            }
        }
        file << count << endl;
        for (int i = 0; i < size; ++i) {
            if (devices[i]->getFilename() == files[j]) {
                devices[i]->writeToFile(file);
                file << endl;
            }
        }
        file.close();
    }
}

void Periphery::readFromFile() {
    const string files[] = {
             "Satellitephone.txt", "Smartphone.txt", "homephone.txt"
    };
    for (int j = 0; j < 3; ++j) {
        ifstream is;
        is.open(files[j], ios_base::in);
        int size;
        is >> size;
        for (int i = 0; i < size; ++i) {
           string currentDevice;
           is >> currentDevice;
           
           if (currentDevice == "Smartphone") {
               Smartphone *p = new Smartphone();
               p->readFromFile(is);
               this->add(*p);
           }
           if (currentDevice == "Satellitephone") {
               Satellitephone *sc = new Satellitephone();
               sc->readFromFile(is);
               this->add(*sc);
           }
           if (currentDevice == "homephone") {
               homephone *gp = new homephone();
               gp->readFromFile(is);
               this->add(*gp);
           }
        }
        is.close();
    }
}
