#include "Gate.h"

Gate::Gate(int id0, std::string name0) : id(id0), val(true), name(name0), input1(nullptr), input2(nullptr) {}

Gate::~Gate() {}

void Gate::computeOutput() {}

void Gate::setInput(Gate* input01, Gate* input02) {
	input1 = input01;
	input2 = input02;
}

bool Gate::getOutput() {
	computeOutput();
	return val;
}
