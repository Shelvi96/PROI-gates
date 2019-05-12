#include "NAND.h"

NAND::NAND(int id0) : Gate(id0, "NAND") {}

void NAND::computeOutput() {
	if (input1 != nullptr && input2 != nullptr)
		val = !(input1->getOutput() && input2->getOutput());
}
