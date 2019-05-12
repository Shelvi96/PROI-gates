#ifndef Gate_H
#define Gate_H
#include <iostream>

class Gate {
	public:
		Gate(int id, std::string name);
		virtual void computeOutput();
		void setInput(Gate* input1, Gate* input2);
		bool getOutput();
		virtual ~Gate();

	protected:
		int id;
		bool val;
		std::string name;
		Gate* input1;
		Gate* input2;

	private:
		
};

#endif
