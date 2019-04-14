#include <iostream>
#include <fstream>

#include "Periphery.h"
#include "Satellitephone.h"
#include "Smartphone.h"
#include "homephone.h"

using namespace std;

const string FILENAME = "text.txt";

void printMenu() {
    cout << "0 - выход" << endl;
    cout << "1 - добавить устройство" << endl;
    cout << "2 - удалить устройство" << endl;
    cout << "3 - записать в файл" << endl;
    cout << "4 - прочитать из файла" << endl;
    cout << "5 - вывод устройств на экран" << endl;
}

int main() {

    setlocale(LC_ALL, "Russian");

    Periphery *perephery = Periphery::getInstance();

    bool isRunning = true;
    int mode;
    while (isRunning) {
        printMenu();
        cin >> mode;
        switch(mode) {
            case 0:
                isRunning = false;
                break;
            case 1:
                cout << "Выберите что хотите добавить" << endl;
                cout << "1 - смартфорн, 2 - домашний тлф, 3 - спутниковый тлф" << endl;
                int selected;
                cin >> selected;
                if (selected == 1) {
                    Smartphone *p = new Smartphone();
                    cin >> *p;
                    Periphery::getInstance()->add(*p);
                }
				if (selected == 2) {
                    homephone *gp = new homephone();
                    cin >> *gp;
                    Periphery::getInstance()->add(*gp);
                }
                if (selected == 3) {
                    Satellitephone *sc = new Satellitephone();
                    cin >> *sc;
                    Periphery::getInstance()->add(*sc);
                }
               
                break;
            case 2:
                cout << "Введите индекс удаляемого устройства" << endl;
                int removed;
                cin >> removed;
                Periphery::getInstance()->remove(removed);
                break;
            case 3:
                try {
                    Periphery::getInstance()->writeToFile();
                } catch (exception e) {
                    cout << "Не удается записать в файл" << e.what();
                }
                break;
            case 4:
                try {
                    Periphery::getInstance()->readFromFile();
                } catch (exception e) {
                    cout << "Не удается прочитать файл" << e.what();
                }
                break;
            case 5:
                cout << *Periphery::getInstance();
                break;

        }

    }

    return 0;
}