#include "OR.h"

OR::OR(int id0) : Gate(id0, "OR") {}

bool OR::computeVal() {
	return input1->computeVal() || input2->computeVal();
}
