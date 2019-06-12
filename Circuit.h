#ifndef Circiut_H
#define Circuit_H
#include <map>
#include <bits/stdc++.h>
#include "Exceptions.h"
#include "Gate.h"
#include "NOT.h"
#include "AND.h"
#include "NAND.h"
#include "OR.h"
#include "NOR.h"
#include "XOR.h"
#include "True.h"
#include "False.h"

class Circuit {
	public:
		Circuit();
		~Circuit();
		void addGate(std::string name, int input1 = 0, int input2 = 0);
		void addGate(int id0, int input, std::string name2);
		void addGate(int id0, std::string name);
		void setInputValue(int id, int input, bool val);
		void removeGate(int gateID);
		bool computeOutput(int gateID);
		void printCircuit();
		void saveToFile(std::ofstream* file);
		void readFromFile(std::ifstream* file);

	protected:

	private:
		int id;
		std::map<int, Gate*> gates;
		Gate* makeGate(std::string name, int id, int input1 ,int input2);
		void save(int gateID, std::ofstream* file);
		void read(int parentID, std::ifstream* file);
};

#endif
