#include "AND.h"

AND::AND(int id0) : Gate(id0, "AND") {}

void AND::computeOutput() {
	if (input1 != nullptr && input2 != nullptr) {
		std::cerr << "ANDESSUNIAA" << std::endl;
		val = input1->getOutput() && input2->getOutput();
	}
}
