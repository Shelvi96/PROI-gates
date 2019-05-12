#include <bits/stdc++.h>
#include "NOT.h"
#include "AND.h"
#include "NAND.h"
#include "OR.h"
#include "NOR.h"
#include "XOR.h"
#include "True.h"
#include "False.h"

using namespace std;

void initTest () {
	True* inTrue = new True;
	False* inFalse = new False;

	NOT bramkaNOT = NOT(-1);
	bramkaNOT.setInput(inFalse, nullptr);
	assert(bramkaNOT.getOutput() == 1);
	bramkaNOT.setInput(inTrue, nullptr);
	assert(bramkaNOT.getOutput() == 0);

	AND bramkaAND = AND(-1);
	bramkaAND.setInput(inFalse, inFalse);
	assert(bramkaAND.getOutput() == 0);
	bramkaAND.setInput(inFalse, inTrue);
	assert(bramkaAND.getOutput() == 0);
	bramkaAND.setInput(inTrue, inFalse);
	assert(bramkaAND.getOutput() == 0);
	bramkaAND.setInput(inTrue, inTrue);
	assert(bramkaAND.getOutput() == 1);

	NAND bramkaNAND = NAND(-1);
	bramkaNAND.setInput(inFalse, inFalse);
	assert(bramkaNAND.getOutput() == 1);
	bramkaNAND.setInput(inFalse, inTrue);
	assert(bramkaNAND.getOutput() == 1);
	bramkaNAND.setInput(inTrue, inFalse);
	assert(bramkaNAND.getOutput() == 1);
	bramkaNAND.setInput(inTrue, inTrue);
	assert(bramkaNAND.getOutput() == 0);

	OR bramkaOR = OR(-1);
	bramkaOR.setInput(inFalse, inFalse);
	assert(bramkaOR.getOutput() == 0);
	bramkaOR.setInput(inFalse, inTrue);
	assert(bramkaOR.getOutput() == 1);
	bramkaOR.setInput(inTrue, inFalse);
	assert(bramkaOR.getOutput() == 1);
	bramkaOR.setInput(inTrue, inTrue);
	assert(bramkaOR.getOutput() == 1);

	NOR bramkaNOR = NOR(-1);
	bramkaNOR.setInput(inFalse, inFalse);
	assert(bramkaNOR.getOutput() == 1);
	bramkaNOR.setInput(inFalse, inTrue);
	assert(bramkaNOR.getOutput() == 0);
	bramkaNOR.setInput(inTrue, inFalse);
	assert(bramkaNOR.getOutput() == 0);
	bramkaNOR.setInput(inTrue, inTrue);
	assert(bramkaNOR.getOutput() == 0);

	XOR bramkaXOR = XOR(-1);
	bramkaXOR.setInput(inFalse, inFalse);
	assert(bramkaXOR.getOutput() == 0);
	bramkaXOR.setInput(inFalse, inTrue);
	assert(bramkaXOR.getOutput() == 1);
	bramkaXOR.setInput(inTrue, inFalse);
	assert(bramkaXOR.getOutput() == 1);
	bramkaXOR.setInput(inTrue, inTrue);
	assert(bramkaXOR.getOutput() == 0);

	delete inTrue;
	delete inFalse;

	cerr << "Init tests OK!" << endl;
}

int main () {
	initTest();

	return 0;
}
