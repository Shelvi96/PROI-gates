#ifndef OR_H
#define OR_H
#include "Gate.h"

class OR : public Gate {
	public:
		OR(int id0);
		void computeOutput() override;

	protected:

	private:

};

#endif
