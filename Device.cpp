#include <iostream>

#include "Device.h"

using namespace std;

const string &Device::getproducer() const {
    return producer;
}

void Device::setproducer(const string &producer) {
    Device::producer = producer;
}

const string &Device::gettypeConnection() const {
	return typeConnection;
}

void Device::settypeConnection(const string &typeConnection) {
	Device::typeConnection = typeConnection;
}


int Device::getmemory() const {
    return memory;
}

void Device::setmemory(int memory) {
    Device::memory = memory;
}
int Device::getsizeScreen() const {
	return sizeScreen;
}

void Device::setsizeScreen(int sizeScreen) {
	Device::sizeScreen = sizeScreen;
}
bool Device::getisgps() const {
	return isgps;
}

void Device::setisgps(bool isgps) {
	Device::isgps = isgps;
}

bool Device::getisSensore() const {
	return isSensore;
}

void Device::setisSensore(bool isSensore) {
	Device::isSensore = isSensore;
}

bool Device::getisKeyBoard() const {
	return isKeyBoard;
}

void Device::setisKeyBoard(bool isKeyBoard) {
	Device::isKeyBoard = isKeyBoard;
}

const string &Device::getColor() const {
    return color;
}

void Device::setColor(const string &color) {
    Device::color = color;
}

bool Device::getis4g() const {
	return is4g;
}
void Device::setis4g(bool is4g) {
	Device::is4g = is4g;
}


const string &Device::getScreen() const {
	return screen;
}

void Device::setScreen(const string &screen) {
	Device::screen = screen;
}
const string &Device::getwifi() const {
	return wifi;
}

void Device::setwifi(const string &wifi) {
	Device::wifi = wifi;
}
int Device::getYear() const {
	return year;
}

void Device::setYear(int year) {
	Device::year = year;
}

Device::~Device() {
    color = "";
    producer = "";
    memory = 0;
    color = "";
    isgps = 0;
	is4g = 0;
	screen = "";
	year = 0;
	isSensore = 0;
	isKeyBoard = 0;
	wifi = "";
	sizeScreen = 0;
	typeConnection = "";
}


Device::Device(const string &producer, int memory, bool isgps,bool is4g, const string &color,const string &screen,int year,bool isSensore,bool isKeyBoard,const string &wifi,int sizeScreen,const string &typeConnection)
        : producer(producer), memory(memory), isgps(isgps), is4g(is4g), color(color), screen(screen),year(year),isSensore(isSensore), isKeyBoard(isKeyBoard), wifi(wifi),
	sizeScreen(sizeScreen), typeConnection(typeConnection){}

ostream &operator<<(ostream &os, const Device &device) {
    os << "izgotovitel': " << device.producer << " memory: " << device.memory <<" isGps?: " << device.isgps << " is4G?: " << device.is4g 
		<< " color: " << device.color << " screen: " << device.screen << " year: " << device.year
		<< " is Sensore?: " << device.isSensore << " is KeyBoard?: " << device.isKeyBoard << " type wifi connection?: " << device.wifi << " size Screen: " 
		<< device.sizeScreen << " type Connection: " << device.typeConnection;
    return os;
}

void Device::writeToFile(ostream &file) {
	file << producer << endl << memory << endl << isgps << endl << is4g << endl << color << endl << screen << endl << year << endl << isSensore << endl
		<< isKeyBoard << endl << wifi << endl << sizeScreen << endl << typeConnection << endl;
}

void Device::readFromFile(istream &file) {
    string producer;
    file >> producer;
    int memory;
    file >> memory;
	bool isgps;
	file >> isgps;
	bool is4g;
	file >> is4g;
    string color;
    file >> color;
	string screen;
	file >> screen;
	int year;
	file >> year;
	bool isSensore;
	file >> isSensore;
	bool isKeyBoard;
	file >> isKeyBoard;
	string wifi;
	file >> wifi;
	int sizeScreen;
	file >> sizeScreen;
	string typeConnection;
	file >> typeConnection;
    this->producer = producer;
    this->memory = memory;
	this->isgps = isgps;
	this->is4g = is4g;
    this->color = color;
	this->screen = screen;
	this->year = year;
	this->isSensore = isSensore;
	this->isKeyBoard = isKeyBoard;
	this->wifi = wifi;
	this->sizeScreen;
	this->typeConnection;
}

istream &operator>>(istream &in, Device &device) {
    cout << "vvedite izgotovitelya" << endl;
    string producer;
    in >> producer;
    cout << "vvedite memory GB" << endl;
    int memory;
    in >> memory;
	cout << "is GPS?" << endl;
	bool isgps;
	in >> isgps;
	cout << "is 4G?" << endl;
	bool is4g;
	in >> is4g;
    cout << "vvedite color" << endl;
    string color;
    in >> color;
	cout << "vvedite type screen" << endl;
	string screen;
	in >> screen;
	cout << "god izgotovleniya" << endl;
	int year;
	in >> year;
	cout << "est' li sensor?" << endl;
	bool isSensore;
	in >> isSensore;
	cout << "est' li klaviatura?" << endl;
	bool isKeyBoard;
	in >> isKeyBoard;
	cout << "type wifi connection?" << endl;
	string wifi;
	in >> wifi;
	cout << "sizeScreen" << endl;
	int sizeScreen;
	in >> sizeScreen;
	cout << "type soedinenia" << endl;
	string typeConnection;
	in >> typeConnection;

    device.producer = producer;
    device.memory = memory;
	device.isgps = isgps;
	device.is4g = is4g;
	device.color = color;
	device.screen = screen;
	device.year = year;
	device.isSensore = isSensore;
	device.isKeyBoard = isKeyBoard;
	device.wifi = wifi;
	device.sizeScreen=sizeScreen;
	device.typeConnection=typeConnection;
    return in;
}

Device::Device() {}

void Device::toConsole() {
    cout << *this;
}
