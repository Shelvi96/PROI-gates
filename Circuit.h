#ifndef Circiut_H
#define Circuit_H
#include <map>
#include "Gate.h"
#include "NOT.h"
#include "AND.h"
#include "NAND.h"
#include "OR.h"
#include "NOR.h"
#include "XOR.h"
#include "True.h"
#include "False.h"

class Circuit {
	public:
		Circuit();
		~Circuit();
		void addGate(std::string name, int input1, int input2 = 0);
		void removeGate(int gateID);
		bool computeOutput(int gateID);
		void printCircuit();

	protected:

	private:
		int id;
		std::map<int, Gate*> gates;
};

struct OutOfBound : public std::exception {
   const char * msg () const throw () {
      return "Bramka o podanym indeksie nie istnieje!";
   }
};

struct GateDoesNotExist : public std::exception {
   const char * msg () const throw () {
      return "Bramka o podanej nazwie nie istnieje!";
   }
};

#endif
