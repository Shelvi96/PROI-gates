#include <bits/stdc++.h>
#include "False.h"

False::False() : Gate(0, "False") {}

bool False::computeVal() {
	return false;
}

void False::changeOutput(Gate* g) {
	output = nullptr;
	g = g;
}

void False::setOutput(Gate* output0) { output0 = output0; }