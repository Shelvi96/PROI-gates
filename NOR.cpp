#include "NOR.h"

NOR::NOR(int id0) : Gate(id0, "NOR") {}

void NOR::computeOutput() {
	if (input1 != nullptr && input2 != nullptr)
		val = !(input1->getOutput() || input2->getOutput());
}
