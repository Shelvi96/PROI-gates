#include "Gate.h"

Gate::Gate(int id0, std::string name0) : id(id0), name(name0), input1(nullptr), input2(nullptr), output(nullptr) {}

Gate::~Gate() { }

bool Gate::computeVal() {
	return false;
}

void Gate::changeInput1(Gate* g) {
	input1 = g;
}
void Gate::changeInput2(Gate* g) {
	input2 = g;
}
void Gate::changeOutput(Gate* g) {
	output = g;
}

void Gate::setInput(Gate* g1, Gate* g2) {
	if (this == g1 || this == g2)
		throw Feedback();
	if (g1->output != nullptr || g2->output != nullptr) {
		throw AlreadyUsed();
	}
	if (input1 != nullptr && input1->name != "True" && input1->name != "False")
		throw AlreadyUsed();
	if (input2 != nullptr && input2->name != "True" && input2->name != "False")
		throw AlreadyUsed();

	input1 = g1;
	g1->changeOutput(this);
	input2 = g2;
	g2->changeOutput(this);
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

bool Gate::isOutput() {
	return output != nullptr;	
}

void Gate::remove() {
	if (output != nullptr)
		throw GateInUse();
	input1->output = nullptr;
	input2->output = nullptr;
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
