#ifndef False_H
#define False_H
#include "Gate.h"

class False : public Gate {
	public:
		False();
		bool computeVal() override;
		void changeOutput(Gate* g);
		void setOutput(Gate* output0) override;

	protected:
		
	private:
};

#endif