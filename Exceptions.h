#ifndef Exceptions_H
#define Exceptions_H

struct myexception : public std::exception{
	virtual const char * msg () const throw () {return "WYJATEK!!!!";}
};

struct Feedback : public myexception {
   const char * msg () const throw () {
      return "Sprzężenie zwrotne niedozwolone! Podlaczanie nie powiodlo sie.";
   }
};

struct AlreadyUsed: public myexception {
   const char * msg () const throw () {
      return "Ta bramka ma już wykorzystane wyjście! Podlaczanie nie powiodlo sie.";
   }
};

struct GateInUse : public myexception {
   const char * msg () const throw () {
      return "Wyjscie tej bramki jest używana! Odlaczanie nie powiodlo sie.";
   }
};

struct OutputAssignmentError : public myexception {
   const char * msg () const throw () {
      return "Na wyjscie bramki nie mozna ustawic prawdy i falszu! Podlaczanie nie powiodlo sie.";
   }
};

struct OutOfBound : public myexception {
   const char * msg () const throw () {
      return "Bramka o podanym indeksie nie istnieje!";
   }
};

struct GateDoesNotExist : public myexception {
   const char * msg () const throw () {
      return "Bramka o podanej nazwie nie istnieje!";
   }
};

#endif
