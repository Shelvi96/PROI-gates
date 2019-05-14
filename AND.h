#ifndef AND_H
#define AND_H
#include "Gate.h"

class AND : public Gate {
	public:
		AND(int id0);
		bool computeVal() override;

	protected:

	private:

};

#endif