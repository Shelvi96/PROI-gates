#include "Gate.h"

Gate::Gate(int id0, std::string name0) : id(id0), name(name0), input1(nullptr), input2(nullptr), output(nullptr) {}

Gate::~Gate() { }

bool Gate::computeVal() {
	return false;
}

void Gate::changeInput1(Gate* g) {
	input1 = g;
}
Gate* Gate::getInput1() {
	return input1;
}
void Gate::changeInput2(Gate* g) {
	input2 = g;
}
Gate* Gate::getInput2() {
	return input2;
}
void Gate::changeOutput(Gate* g) {
	output = g;
}

void Gate::setInput(Gate* g1, Gate* g2) {
	if (this == g1 || this == g2)
		throw Feedback();
	if (g1->output != nullptr || (g2 != nullptr && g2->output != nullptr)) {
		throw AlreadyUsed();
	}
	if (input1 != nullptr && input1->name != "True" && input1->name != "False")
		throw AlreadyUsed();
	if (input2 != nullptr && input2->name != "True" && input2->name != "False")
		throw AlreadyUsed();

	input1 = g1;
	g1->changeOutput(this);
	if (g2 != nullptr) {
		input2 = g2;
		g2->changeOutput(this);
	}
}

void Gate::setOutput(Gate* g) {
	if (g->name == "True" || g->name == "False")
		throw OutputAssignmentError();
	if (g == this)
		throw Feedback();
	if (g->input1 != nullptr && g->input2 != nullptr)
		throw AlreadyUsed();

	output = g;
	if (g->input1 == nullptr)
		g->changeInput1(this);
	else
		g->changeInput2(this);
}

int Gate::getID() {
	return id;
}

std::string Gate::getName() {
	return name;
}

bool Gate::isOutput() {
	return output != nullptr;	
}

void Gate::remove(Gate* gFalse) {
	if (output != nullptr && ((input1 != nullptr && input1->getID() > 2) ||
		(input2 != nullptr && input2->getID() > 2)))
		throw GateInUse();

	if (output == nullptr) {
		if (input1 != nullptr)
			input1->output = nullptr;
		if (input2 != nullptr)
			input2->output = nullptr;
	}
	if (output != nullptr && input1 != nullptr && (input1->name == "False" || input1->name == "True")) {
		if (output->input1 != nullptr && output->input1 == this)
			output->input1 = gFalse;
	}
	if (output != nullptr && input2 != nullptr && (input2->name == "False" || input2->name == "True")) {
		if (output->input2 != nullptr && output->input2 == this)
			output->input2 = gFalse;	
	}
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
