#include "NOT.h"

NOT::NOT(int id0) : Gate(id0, "NOT") {}

bool NOT::computeVal() {
	return !input1->computeVal();
}

void NOT::setInput(Gate* input01) {
	if (this == input01)
		throw Feedback();

	if (input01->isUsed())
		throw AlreadyUsed();

	input1 = input01;
	input01->setOutput(this);
	input2 = nullptr;

	active = true;
}

void NOT::disconnect() {
	std::cerr << "NOT DISCONNECT" << std::endl;
	if (output != nullptr)
		throw GateInUse();

	input1->setOutput();	

	active = false;
}