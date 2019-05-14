#include <bits/stdc++.h>
#include "False.h"

False::False() : Gate(0, "False") {
	active = false;
}

bool False::computeVal() {
	return false;
}

void False::setOutput(Gate* output0) { output0 = output0; }