#include "Circuit.h"

Circuit::Circuit() {
	gates.push_back(new False());
	gates.push_back(new True());
}

Circuit::~Circuit() {
	for (auto it: gates) {
		delete it;
	}
}

void Circuit::addGate(std::string name, int input1, int input2) {
	if (input1 < 0 || input1 >= (int)gates.size() || input2 < 0 || input2 >= (int)gates.size())
		throw OutOfBound();

	if (name == "NOT") {
		NOT* gate = new NOT(gates.size());
		gate->setInput(gates[input1]);
		gates.push_back(gate);
	}
	else if(name == "AND") {
		AND* gate = new AND(gates.size());
		gate->setInput(gates[input1], gates[input2]);
		gates.push_back(gate);
	}
	else if(name == "NAND") {
		NAND* gate = new NAND(gates.size());
		gate->setInput(gates[input1], gates[input2]);
		gates.push_back(gate);
	}
	else if(name == "OR") {
		OR* gate = new OR(gates.size());
		gate->setInput(gates[input1], gates[input2]);
		gates.push_back(gate);
	}
	else if(name == "NOR") {
		NOR* gate = new NOR(gates.size());
		gate->setInput(gates[input1], gates[input2]);
		gates.push_back(gate);
	}
	else if(name == "XOR") {
		XOR* gate = new XOR(gates.size());
		gate->setInput(gates[input1], gates[input2]);
		gates.push_back(gate);
	}
	else
		throw GateDoesNotExist();
}

void Circuit::disconnectGate(int gateID) {
	try {
		gates[gateID]->disconnect();
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
	for (auto it: gates) {
		if (!it->isUsed())
			it->print(0);
	}
}
