#ifndef NOT_H
#define NOT_H
#include "Gate.h"

class NOT : public Gate {
	public:
		NOT(int id0);
		void computeOutput() override;

	protected:

	private:

};

#endif