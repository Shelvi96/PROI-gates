#include "XOR.h"

XOR::XOR(int id0) : Gate(id0, "XOR") {}

void XOR::computeOutput() {
	if (input1 != nullptr && input2 != nullptr)
		val = (input1->getOutput() + input2->getOutput())%2;
}
