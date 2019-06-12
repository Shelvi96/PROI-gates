#include "NAND.h"

NAND::NAND(int id0) : Gate(id0, "NAND") {}

bool NAND::computeVal() {
	return !(input1->computeVal() && input2->computeVal());
}
