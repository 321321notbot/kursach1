#pragma once
#include "PhoneType.hpp"
using namespace std;

class Phone {//pattern Singletone
private:
	PhoneType *pt;
    Phone(PhoneType* type):pt(type) {}
    Phone( const Phone&);  
    Phone& operator=( Phone& );
public:
	//вывод
	void print (ostream& out){ pt->print(out);} 
    static Phone& getInstance(PhoneType *type) {
        static Phone  instance(type);
        return instance;
    }    
}; 