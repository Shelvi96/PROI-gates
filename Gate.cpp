#include "Gate.h"

Gate::Gate(int id0, std::string name0) : id(id0), active(false), name(name0), input1(nullptr), input2(nullptr), output(nullptr) {}

Gate::~Gate() {}

bool Gate::isUsed() {
	return output != nullptr;
}

bool Gate::isActive() {
	return active;
}

bool Gate::computeVal() {
	return false;
}

void Gate::setInput(Gate* input01, Gate* input02) {
	if (this == input01 || this == input02)
		throw Feedback();

	if (input01->isUsed() || input02->isUsed())
		throw AlreadyUsed();

	input01->setOutput(this);
	input1 = input01;
	input02->setOutput(this);
	input2 = input02;

	active = true;
}

void Gate::setOutput(Gate* output0) {
	output = output0;
}

void Gate::disconnect() {
	if (output != nullptr)
		throw GateInUse();

	input1->setOutput();	
	input2->setOutput();
	input1 = nullptr;
	input2 = nullptr;

	active = false;
}

void Gate::print(int lvl) {
	for (int i = 0; i < lvl; ++i)
		std::cout << '\t';
	std::cout << name << " " << id << std::endl;
	if (input1 != nullptr)
		input1->print(lvl+1);
	if (input2 != nullptr)
		input2->print(lvl+1);
}