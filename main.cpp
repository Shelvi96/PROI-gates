/*
	TODO:
		read/write file
*/
#include <bits/stdc++.h>
#include "Circuit.h"
#include "Exceptions.h"

using namespace std;

void initTest () {
	Circuit c1;
	c1.printCircuit();
	cerr << "Dodaje AND: " << endl;
	c1.addGate("AND", 1, 0);
	c1.printCircuit();
	cerr << "Dodaje AND do drugiego wejscia ANDa" << endl;
	c1.addGate(2, 2, "AND");
	c1.printCircuit();
	cerr << "Usuwam AND ze srodka" << endl;
	c1.removeGate(3);
	c1.printCircuit();
	cerr << "Usuwam ostatni AND" << endl;
	c1.removeGate(2);
	c1.printCircuit();

	cerr << "Init tests OK!" << endl;
}

void printHelp() {
	cout << "Symulator obwodow logicznych." << endl;
	cout << "Aby wczytac dane z pliku napisz 'wczytaj [nazwa-pliku]'" << endl;
	cout << "Aby zapisac dane do pliku napisz 'zapisz [nazwa-pliku]'" << endl;
	cout << "Aby dodac nowa bramke napisz 'dodaj'" << endl;
	cout << "Aby usunac istniejaca bramke napisz 'usun [id-bramki]'" << endl;
	cout << "Aby zmienic wartosc logiczna na wejsciu bramki napisz 'zmien [id-bramki] [numer-wejscia(1 lub 2)] [wartosc-logiczna]'" << endl;
	cout << "Aby wyswietlic stworzony obwod napisz 'pokaz'" << endl;
	cout << "Aby obliczyc wartosc na wyjsciu bramki napisz 'oblicz [id-bramki]" << endl;
	cout << "Aby wyswietlic ponownie ten komunikat napisz 'pomoc'" << endl;
	cout << "Aby zakonczyc napisz 'zakoncz'" << endl;
}

int main () {
	// initTest();

	Circuit c;
	string instruction;
	bool isFinished = false;

	printHelp();

	while (!isFinished) {
		// clear buffer!!!!!!!!!
		cin >> instruction;
		if (instruction == "zakoncz") {
			isFinished = true;
		}
		else if (instruction == "pomoc") {
			printHelp();
		}
		else if (instruction == "wczytaj") {
			string fileName;
			cin >> fileName;
			ifstream* file = new ifstream(fileName);
			cout << "Wczytuje plik " << fileName << "..." << endl;
			c.readFromFile(file);
			file->close();
			cout << "Wczytano." << endl;
		}
		else if (instruction == "zapisz") {
			string fileName;
			cin >> fileName;
			ofstream* file = new ofstream(fileName);
			// file->open(fileName, ios::out | ios::trunc);
			cout << "Zapisuje do pliku " << fileName << "..." << endl;
			c.saveToFile(file);
			file->close();
			cout << "Zapisano." << endl;
		}
		else if (instruction == "dodaj") {
			cout << "Aby dodac nowa, osobna bramke, wpisz 'nowa [nazwa-bramki]'." << endl;
			cout << "Aby podlaczyc bramke do juz istniejacej, wpisz 'istniejaca [id-bramki] [numer-podlaczenia] [nazwa-bramki]'" << endl;
			cout << "Podlaczenia sa numerowane nastepujaco: 0 - output; 1,2 - input" << endl;
			string details;
			cin >> details;
			if (details == "nowa") { // creating new, not connected gate
				string gateName;
				cin >> gateName;
				try {
					c.addGate(gateName);
					cout << "Dodano bramke." << endl;
				}
				catch (const myexception& ex) {
					cout << "REEE" << endl;
					cout << ex.msg() << endl;
				}
			}
			else if (details == "istniejaca") { // connecting to another gate
				int id, connectionNum;
				string gateName;
				cin >> id >> connectionNum >> gateName;
				if (connectionNum == 0) { // connecting to its output
					try {
						c.addGate(id, gateName);
						cout << "Dodano bramke." << endl;
					}
					catch (const myexception& ex) {
						cout << ex.msg() << endl;
					}
				}
				else if (connectionNum == 1 || connectionNum == 2) { // connecting to one of its inputs
					try {
						c.addGate(id, connectionNum, gateName);
						cout << "Dodano bramke." << endl;
					}
					catch (const myexception& ex) {
						cout << ex.msg() << endl;
					}
				}
				else {
					cout << "Niepoprawna instrukcja! Sprobuj jeszcze raz." << endl;
				}
			}
			else {
				cout << "Niepoprawna instrukcja! Sprobuj jeszcze raz." << endl;
			}
		}
		else if (instruction == "usun") {
			int id;
			cin >> id;
			try {
				c.removeGate(id);
				cout << "Usunieto bramke." << endl;
			}
			catch (const myexception& ex) {
				cout << ex.msg() << endl;
			}
		}
		else if (instruction == "zmien") {
			int id, input;
			bool val;
			cin >> id >> input >> val;
			try {
				c.setInputValue(id, input, val);
			}
			catch (const myexception& ex) {
				cout << ex.msg() << endl;
			}
		}
		else if (instruction == "pokaz") {
			c.printCircuit();
		}
		else if (instruction == "oblicz") {
			int id;
			cin >> id;
			try {
				cout << c.computeOutput(id) << endl;
			}
			catch (const myexception& ex) {
				cout << ex.msg() << endl;
			}
		}
		else {
			cout << "Niepoprawna instrukcja! Sprobuj jeszcze raz." << endl;
		}
	}

	return 0;
}
