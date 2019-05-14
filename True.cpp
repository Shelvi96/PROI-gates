#include <bits/stdc++.h>
#include "True.h"

True::True() : Gate(1, "True") {
	active = false;
}

bool True::computeVal() {
	return true;
}

void True::setOutput(Gate* output0) { output0 = output0; }