#include "AND.h"

AND::AND(int id0) : Gate(id0, "AND") {}

bool AND::computeVal() {
	return input1->computeVal() && input2->computeVal();
}
