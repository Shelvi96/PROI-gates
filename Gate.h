#ifndef Gate_H
#define Gate_H
#include <iostream>
#include <exception>

class Gate {
	public:
		Gate(int id0, std::string name0);
		virtual ~Gate();
		
		virtual void setInput(Gate* g1, Gate* g2 = nullptr);
		virtual void setOutput(Gate* g = nullptr);
		virtual bool computeVal();

		void changeInput1(Gate* g);
		void changeInput2(Gate* g);
		virtual void changeOutput(Gate* g);

		bool isOutput();
		void remove();
		void print(int lvl);

	protected:
		int id;
		std::string name;

		Gate* input1;
		Gate* input2;
		Gate* output;

	private:

};

struct Feedback : public std::exception {
   const char * msg () const throw () {
      return "Sprzężenie zwrotne niedozwolone! Podlaczanie nie powiodlo sie.";
   }
};

struct AlreadyUsed: public std::exception {
   const char * msg () const throw () {
      return "Ta bramka ma już wykorzystane wyjście! Podlaczanie nie powiodlo sie.";
   }
};

struct GateInUse : public std::exception {
   const char * msg () const throw () {
      return "Wyjscie tej bramki jest używana! Odlaczanie nie powiodlo sie.";
   }
};

struct OutputAssignmentError : public std::exception {
   const char * msg () const throw () {
      return "Na wyjscie bramki nie mozna ustawic prawdy i falszu! Podlaczanie nie powiodlo sie.";
   }
};

#endif
