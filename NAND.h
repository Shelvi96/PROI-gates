#ifndef NAND_H
#define NAND_H
#include "Gate.h"

class NAND : public Gate {
	public:
		NAND(int id0);
		bool computeVal() override;

	protected:

	private:

};

#endif