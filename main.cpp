#include <bits/stdc++.h>
#include "AND.h"
#include "OR.h"
#include "True.h"
#include "False.h"

using namespace std;

int main () {
	AND bramka1 = AND(0);
	cout << "AND: " << bramka1.getOutput() << endl;
	bramka1.setInput(new True, new False);
	cout << "AND: " << bramka1.getOutput() << endl;

	OR bramka2 = OR(1);
	cout << "OR: " << bramka2.getOutput() << endl;
	bramka2.setInput(new True, new True);
	cout << "OR: " << bramka2.getOutput() << endl;

	cout << "COMBO!" << endl;
	AND bramka3 = AND(2);
	bramka3.setInput(&bramka1, &bramka2);
	cout << bramka3.getOutput() << endl;

	return 0;
}