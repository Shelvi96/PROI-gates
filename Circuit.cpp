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

Gate* Circuit::makeGate(std::string name, int id0, int input1 ,int input2) { // utility function to create new gate based on required name and inputs/output
	Gate* gate;
	if (name == "NOT") {
		gate = new NOT(id0);
		gate->setInput(gates[input1]);
	}
	else if(name == "AND") {
		gate = new AND(id0);
		gate->setInput(gates[input1], gates[input2]);
	}
	else if(name == "NAND") {
		gate = new NAND(id0);
		gate->setInput(gates[input1], gates[input2]);
	}
	else if(name == "OR") {
		gate = new OR(id0);
		gate->setInput(gates[input1], gates[input2]);
	}
	else if(name == "NOR") {
		gate = new NOR(id0);
		gate->setInput(gates[input1], gates[input2]);
	}
	else if(name == "XOR") {
		gate = new XOR(id0);
		gate->setInput(gates[input1], gates[input2]);
	}
	else
		throw GateDoesNotExist();
	return gate;
}

void Circuit::addGate(std::string name, int input1, int input2) { // creating new gate, not connected to any other gate
	if (gates.find(input1) == gates.end() || gates.find(input2) == gates.end())
		throw OutOfBound();

	Gate* gate = makeGate(name, (--gates.end())->second->getID() + 1, input1, input2);
	gates[gate->getID()] = gate;
}

void Circuit::addGate(int id0, int input, std::string name) { // connecting to given input of id0 gate
	if (id0 < 2 || gates.find(id0) == gates.end())
		throw OutOfBound();
	if (input == 2 && gates[id0]->getName() == "NOT")
		throw GateInUse();

	int in1 = gates[id0]->getInput1()->getID();
	int in2;
	if (gates[id0]->getName() != "NOT")
		in2 = gates[id0]->getInput2()->getID();
	else in2 = 100;

	if ((input == 1 && in1 > 2) || (input == 2 && in2 > 2))
		throw AlreadyUsed();

	Gate* gate = makeGate(name, (--gates.end())->second->getID() + 1, 0, 0);

	gates[gate->getID()] = gate;
	gate->changeOutput(gates[id0]);

	if (input == 1) {
		gates[id0]->changeInput1(gate);
	}
	if (input == 2) {
		gates[id0]->changeInput2(gate);
	}
}

void Circuit::addGate(int id0, std::string name) { // connecting to output of id0 gate
	if (gates.find(id0) == gates.end())
		throw OutOfBound();

	Gate* gate = makeGate(name, (--gates.end())->second->getID() + 1, id0, 0);
	gates[gate->getID()] = gate;
}

void Circuit::setInputValue(int id0, int input, bool val) {
	if (gates.find(id0) == gates.end())
		throw OutOfBound();

	if (input == 1 && gates[id0]->getInput1()->getID() < 2) {
		gates[id0]->changeInput1(gates[(int)val]);
	}
	if (input == 2 && gates[id0]->getInput2()->getID() < 2) {
		gates[id0]->changeInput2(gates[(int)val]);
	}
}

void Circuit::removeGate(int gateID) {
	if (gateID < 2 || gates.find(gateID) == gates.end())
		throw OutOfBound();

	gates[gateID]->remove(gates[0]);

	delete gates[gateID];
	gates.erase(gateID);
}

bool Circuit::computeOutput(int gateID) {
	if (gateID < 2 || gates.find(gateID) == gates.end())
		throw OutOfBound();
	
	return gates[gateID]->computeVal();
}

void Circuit::printCircuit() {
	if (gates.size() == 2) {
		std::cout << "Obwod pusty!" << std::endl;
		return;
	}
	std::map<int, Gate*>::iterator it=gates.begin(); it++; it++;
	for (; it!=gates.end(); ++it) {
		if (!(*it).second->isOutput())
			(*it).second->print(0);
	}
}

void Circuit::save(int gateID, std::ofstream* file) {
	Gate* gate = gates[gateID];
	*file << gate->getName();
	if (gate->getInput1() != nullptr) {
		*file << " ( ";
		save(gate->getInput1()->getID(), file);
		*file << " , ";
		if (gate->getInput2() != nullptr)
			save(gate->getInput2()->getID(), file);
		else
			save(0, file);
		*file << " ) ";
	}
}

void Circuit::saveToFile(std::ofstream* file) {
	auto it = gates.begin();
	std::advance(it,2);
	Gate* g = (*it).second;
	save(g->getID(), file);
}

void Circuit::read(int parentID, std::ifstream* file) {
	std::string data;
	*file >> data;
	if (data == "(") {
		*file >> data;
		if (data != "True" && data != "False") {
			addGate(parentID, 1, data);
			read(parentID+1, file);
		}
		else if (data == "True") {
			setInputValue(parentID, 1, true);
		}
	}
	*file >> data;
	if (data == ",") {
		*file >> data;
		if (data != "True" && data != "False") {
			addGate(parentID, 2, data);
			read(parentID+1, file);
		}
		else if (data == "True") {
			setInputValue(parentID, 2, true);
		}
	}
	*file >> data;
}

void Circuit::readFromFile(std::ifstream* file) {
	std::string data;
	*file >> data;
	addGate(data);
	read(2, file);
}