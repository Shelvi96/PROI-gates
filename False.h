#ifndef False_H
#define False_H
#include "Gate.h"

class False : public Gate {
	public:
		False();
		bool computeVal() override;
		void setOutput(Gate* output0) override;

	protected:
		// void setOutput(Gate* output0) override;
		
	private:
};

#endif