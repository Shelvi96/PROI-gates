#include "OR.h"

OR::OR(int id0) : Gate(id0, "OR") {}

void OR::computeOutput() {
	if (input1 != nullptr && input2 != nullptr)
		val = input1->getOutput() || input2->getOutput();
}