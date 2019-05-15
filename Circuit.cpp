#include "Circuit.h"

Circuit::Circuit() : id(2) {
	gates[0] = new False();
	gates[1] = new True();
}

Circuit::~Circuit() {
	for (auto& it: gates) {
		delete it.second;
	}
}

void Circuit::addGate(std::string name, int input1, int input2) {
	if (gates.find(input1) == gates.end() || gates.find(input2) == gates.end())
		throw OutOfBound();

	if (name == "NOT") {
		NOT* gate = new NOT(gates.size());
		gate->setInput(gates[input1]);
		gates[id++] = gate;
	}
	else if(name == "AND") {
		AND* gate = new AND(gates.size());
		gate->setInput(gates[input1], gates[input2]);
		gates[id++] = gate;
	}
	else if(name == "NAND") {
		NAND* gate = new NAND(gates.size());
		gate->setInput(gates[input1], gates[input2]);
		gates[id++] = gate;
	}
	else if(name == "OR") {
		OR* gate = new OR(gates.size());
		gate->setInput(gates[input1], gates[input2]);
		gates[id++] = gate;
	}
	else if(name == "NOR") {
		NOR* gate = new NOR(gates.size());
		gate->setInput(gates[input1], gates[input2]);
		gates[id++] = gate;
	}
	else if(name == "XOR") {
		XOR* gate = new XOR(gates.size());
		gate->setInput(gates[input1], gates[input2]);
		gates[id++] = gate;
	}
	else
		throw GateDoesNotExist();
}

void Circuit::removeGate(int gateID) {
	if (gateID < 2 || gates.find(gateID) == gates.end())
		throw OutOfBound();

	try {
		gates[gateID]->remove();
		delete gates[gateID];
		gates.erase(gateID);
	}
	catch (std::exception ex) {
		throw ex;
	}
}

bool Circuit::computeOutput(int gateID) {
	if (gateID < 0 || gateID >= (int)gates.size())
		throw OutOfBound();
	
	return gates[gateID]->computeVal();
}

void Circuit::printCircuit() {
	std::map<int, Gate*>::iterator it=gates.begin(); it++; it++;
	for (; it!=gates.end(); ++it) {
		if (!(*it).second->isOutput())
			(*it).second->print(0);
	}
}
