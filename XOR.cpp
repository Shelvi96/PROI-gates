#include "XOR.h"

XOR::XOR(int id0) : Gate(id0, "XOR") {}

bool XOR::computeVal() {
	return (input1->computeVal() + input2->computeVal())%2;
}
