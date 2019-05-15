#include <bits/stdc++.h>
#include "True.h"

True::True() : Gate(1, "True") {}

bool True::computeVal() {
	return true;
}

void True::changeOutput(Gate* g) {
	output = nullptr;
	g = g;
}

void True::setOutput(Gate* output0) { output0 = output0; }