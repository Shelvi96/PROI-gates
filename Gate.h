#ifndef Gate_H
#define Gate_H
#include <iostream>
#include "Exceptions.h"

class Gate {
	public:
		Gate(int id0, std::string name0);
		virtual ~Gate();
		
		void setInput(Gate* g1, Gate* g2 = nullptr);
		virtual void setOutput(Gate* g = nullptr);
		virtual bool computeVal();

		void changeInput1(Gate* g);
		Gate* getInput1();
		void changeInput2(Gate* g);
		Gate* getInput2();
		virtual void changeOutput(Gate* g);

		int getID();
		std::string getName();
		bool isOutput();
		void remove(Gate* gFalse);
		void print(int lvl);

	protected:
		int id;
		std::string name;

		Gate* input1;
		Gate* input2;
		Gate* output;

	private:

};

#endif
