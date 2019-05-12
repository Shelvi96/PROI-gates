#ifndef XOR_H
#define XOR_H
#include "Gate.h"

class XOR : public Gate {
	public:
		XOR(int id0);
		void computeOutput() override;

	protected:

	private:

};

#endif