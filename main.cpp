#include <bits/stdc++.h>
#include "Circuit.h"

using namespace std;

void initTest () {
	Circuit c1;
	c1.addGate("AND", 1, 0);
	cout << "VAL AND: " << c1.computeOutput(2) << endl;
	c1.addGate("OR", 1, 0);
	cout << "VAL OR: " << c1.computeOutput(3) << endl;
	c1.addGate("XOR", 2, 3);
	c1.addGate("OR", 1, 0);
	cout << "V1" << endl;
	c1.printCircuit();
	c1.disconnectGate(4);
	cout << "V2" << endl;
	c1.addGate("NOR", 1, 4);
	c1.printCircuit();
	cout << "VAL NOR: " << c1.computeOutput(6) << endl;

	cerr << "Init tests OK!" << endl;
}

int main () {
	initTest();

	return 0;
}
