#ifndef AND_H
#define AND_H
#include "Gate.h"

class AND : public Gate {
	public:
		AND(int id0);
		void computeOutput() override;

	protected:

	private:

};

#endif