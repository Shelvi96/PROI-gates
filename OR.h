#ifndef OR_H
#define OR_H
#include "Gate.h"

class OR : public Gate {
	public:
		OR(int id0);
		bool computeVal() override;

	protected:

	private:

};

#endif
