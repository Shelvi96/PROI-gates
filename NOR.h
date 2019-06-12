#ifndef NOR_H
#define NOR_H
#include "Gate.h"

class NOR : public Gate {
	public:
		NOR(int id0);
		bool computeVal() override;

	protected:

	private:

};

#endif