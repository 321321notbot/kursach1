#pragma once
#include <string>
#include <iostream>

namespace std{

	class PhoneType{//типы телефонов
	protected:
		bool isGPS;
		bool is4G;
		bool isKeyboard;
		bool isSencore;
		int year;
		int memory;
		string color;
		string wifi;
		string camera;
		string screen;
		string typeName;
		string creator;
		string connectionType;
	public:
		bool& IsGPS(){ return isGPS;}
		bool& Is4G(){ return is4G;};
		bool& IsKeyboard(){ return isKeyboard;}
		bool& IsSencore(){ return isSencore;}
		int& Year(){ return year;}
		int& Memory(){ return memory;}
		string& Color(){ return color;}
		string& Wifi(){ return wifi;}
		string& Camera(){ return camera;}
		string& Screen(){ return screen;}
		string& TypeName(){ return typeName;}
		string& Creator(){ return creator;}
		string& ConnectionType(){ return connectionType;}
		//вывод в поток вывода
		void print (ostream& out){
			out << "["<< typeName << "]" <<
				   "\nGPS: " << boolalpha << isGPS <<
				   "\n4G: " << boolalpha << isGPS	<< 
				   "\nKeyboard: " << boolalpha << isKeyboard <<
				   "\nSensore: " << boolalpha << isSencore <<
				   "\nYear: " << year <<
				   "\nMemory: " << memory << 
				   "\nColor: " << color <<
				   "\nWIFI: " << wifi <<
				   "\nCamera: " << camera <<
				   "\nScreen: " << screen <<
				   "\nCreator: " << creator <<
				   "\nConnectionType: " << connectionType;
		}
	};
	
	//смартфон
	class Smartphone: public PhoneType{
	public:
		Smartphone(){
		isGPS = true;
		is4G = true;
		isKeyboard = true;
		isSencore = true;
		year = 2018;
		memory = 64;
		color = "red";
		wifi = "801.1";
		camera = "13mp";
		screen = "5.6";
		typeName = "Smartphone";
		creator = "Samsung";
		connectionType = "8001.1";
		}
	};

	//домашний
	class HomePhone: public PhoneType{
	public:
		HomePhone(){
		isGPS = false;
		is4G = false;
		isKeyboard = true;
		isSencore = false;
		year = 2012;
		memory = 0;
		color = "green";
		wifi = "0.0";
		camera = "0mp";
		screen = "1.3";
		typeName = "HomePhone";
		creator = "Simens";
		connectionType = "802.1";
		}
	};

	//спутниковый
	class SattelitPhone: public PhoneType{
	public:
		SattelitPhone(){
		isGPS = true;
		is4G = true;
		isKeyboard = true;
		isSencore = false;
		year = 2011;
		memory = 32;
		color = "blue";
		wifi = "8011.3";
		camera = "12mp";
		screen = "8.9";
		typeName = "SattelitPhone";
		creator = "TLink";
		connectionType = "8011.1";
		}
	};

}