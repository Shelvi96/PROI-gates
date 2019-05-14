#ifndef Gate_H
#define Gate_H
#include <iostream>
#include <exception>

class Gate {
	public:
		Gate(int id0, std::string name0);
		virtual ~Gate();
		bool isUsed();
		bool isActive();
		virtual bool computeVal();
		void setInput(Gate* input1, Gate* input2);
		virtual void setOutput(Gate* output = nullptr);
		virtual void disconnect();
		void print(int lvl);

	protected:
		int id;
		bool active;
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

#endif
