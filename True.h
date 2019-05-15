#ifndef True_H
#define True_H
#include "Gate.h"

class True : public Gate {
	public:
		True();
		bool computeVal() override;
		void changeOutput(Gate* g);
		void setOutput(Gate* output0) override;

	protected:
		
	private:
};

#endif
