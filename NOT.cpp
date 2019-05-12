#include "NOT.h"

NOT::NOT(int id0) : Gate(id0, "NOT") {}

void NOT::computeOutput() {
	if (input1 != nullptr)
		val = !input1->getOutput();
}
