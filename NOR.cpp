#include "NOR.h"

NOR::NOR(int id0) : Gate(id0, "NOR") {}

bool NOR::computeVal() {
	return !(input1->computeVal() || input2->computeVal());
}
