#include "NOT.h"

NOT::NOT(int id0) : Gate(id0, "NOT") {}

bool NOT::computeVal() {
	return !input1->computeVal();
}
