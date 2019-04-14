#ifndef TP_DEVICE_H
#define TP_DEVICE_H

#include <string>
#include <ostream>

using namespace std;

class Device {
private:
    
    int memory;
	int year;
	int sizeScreen;
	bool isgps;
	bool is4g;
	bool isSensore;
	bool isKeyBoard;
	string screen;
    string color;
	string producer;
	string wifi;
	string typeConnection;
public:

    virtual void writeToFile(ostream &file);
    virtual void readFromFile(istream &file);
    virtual string getFilename() = 0;

    Device(const string &producer, int memory,bool isgps,bool is4g, const string &color,
		const string &screen,int year,bool isSensore,bool isKeyBoard,const string &wifi,int sizeScreen,const string &typeConnection);

    const string &getproducer() const;
	void setproducer(const string &producer);


    virtual ~Device();

    int getmemory() const;
	void setmemory(int memory);

	int getsizeScreen() const;
	void setsizeScreen(int sizeScreen);

	bool getisgps() const;
	void setisgps(bool isgps);

	bool getis4g() const;
	void setis4g(bool is4g);

	bool getisKeyBoard() const;
	void setisKeyBoard(bool isKeyBoard);

	bool getisSensore() const;
	void setisSensore(bool isSensore);

	const string &getColor() const;
	void setColor(const string &color);

	const string &gettypeConnection() const;
	void settypeConnection(const string &typeConnection);

	const string &getwifi() const;
	void setwifi(const string &wifi);

	const string &getScreen() const;
	void setScreen(const string &screen);

	int getYear() const;
	void setYear(int year);

   

    virtual void toConsole();

    friend ostream &operator<<(ostream &os, const Device &device);
    friend istream &operator>>(istream &in, Device &device);

    Device();

};


#endif //TP_DEVICE_H
