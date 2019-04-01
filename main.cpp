#include "Phone.hpp"
#include <fstream>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	 cout << "1.read from console\n2.read from file\n";
	 int a; cin >> a;
	 cout << "1.write in console\n2.write in file\n";
	 int b; cin >> b;
	 ofstream out("save.txt");
	 if(a == 1){
		 cout << "1.smartphone\n2.SattelitPhone\n3.HomePhone\n";
		 cin >> a;
		 if(a == 1){
			Phone& p = Phone::getInstance(new Smartphone);
			p.print(b == 1 ? cout : out);
		 }
		 else if(a == 2){
		    Phone& p = Phone::getInstance(new SattelitPhone);
			p.print(b == 1 ? cout : out);
		 }
		 else if(a == 3){
		    Phone& p = Phone::getInstance(new HomePhone);
			p.print(b == 1 ? cout : out);
		 }
	 }
	 else{
		string tmp;
		ifstream in("save.txt");
		in >> tmp;
		if(tmp == "[Smartphone]"){
			Phone& p = Phone::getInstance(new Smartphone);
			p.print(b == 1 ? cout : out);
		 }
		 else if(tmp == "[SattelitPhone]"){
		    Phone& p = Phone::getInstance(new SattelitPhone);
			p.print(b == 1 ? cout : out);
		 }
		 else if(tmp == "[HomePhone]"){
		    Phone& p = Phone::getInstance(new HomePhone);
			p.print(b == 1 ? cout : out);
		 }
	 }
	 system("pause>>void");
}