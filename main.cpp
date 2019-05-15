#include <bits/stdc++.h>
#include "Circuit.h"

using namespace std;

void initTest () {
	Circuit c1;
	c1.addGate("AND", 1, 0);
	// cout << "VAL AND: " << c1.computeOutput(2) << endl;
	c1.addGate("OR", 1, 0);
	// cout << "VAL OR: " << c1.computeOutput(3) << endl;
	c1.printCircuit();
	cout << "**************************************************" << endl;
	c1.addGate("XOR", 2, 3);
	c1.printCircuit();
	cout << "**************************************************" << endl;
	c1.addGate("OR", 0, 0);
	c1.printCircuit();
	cout << "**************************************************" << endl;
	c1.removeGate(4);
	c1.printCircuit();
	cout << "VAL OR: " << c1.computeOutput(3) << endl;

	cerr << "Init tests OK!" << endl;
}

int main () {
	initTest();

	return 0;
}
