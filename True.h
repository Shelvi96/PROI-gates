#ifndef True_H
#define True_H
#include "Gate.h"

class True : public Gate {
	public:
		True();
		bool computeVal() override;
		void setOutput(Gate* output0) override;

	protected:
		// void setOutput(Gate* output0) override;
		
	private:
};

#endif
