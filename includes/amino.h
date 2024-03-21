// $Id: amino.h 1901 2007-03-15 13:21:06Z nimrodru $

#ifndef ____AMINO
#define ____AMINO

#include "definitions.h"
#include "errorMsg.h"
#include "alphabet.h"
#include "geneticCodeHolder.h"
// #include "codon.h"


//utility of amino acid
// class aminoUtility {
// public:

// 	static vector<int> codonOf(const int a, codon &cod); //returns vector of codons that code to a under a specific genetic code.
	
// };

//based on the amino-acid list found in http://www.dur.ac.uk/~dbl0www/Bioinformatics/aminoacids.htm
class amino : public alphabet {
public:
	explicit amino();
	virtual ~amino() {}
	virtual alphabet* clone() const { return new amino(*this); }
	ALPHACHAR unknown() const  {return 22;}
	ALPHACHAR gap() const  {return 23;}
	ALPHACHAR size() const {return 20;}
	size_t stringSize() const {return 1;} // one letter code.
	ALPHACHAR relations(const ALPHACHAR charInSeq, const ALPHACHAR charToCheck) const;
	ALPHACHAR fromChar(const string& str, const size_t pos) const;
	ALPHACHAR fromChar(const char s) const;
	string fromInt(const ALPHACHAR in_id) const;
	vector<ALPHACHAR> fromString(const string& str) const;
	// "specific" here is not unknown, nor ambiguity, nor gap (for example, for nucleotides it will true for A,C,G, or T).
	bool isSpecific(const ALPHACHAR id) const {return (id>=0 && id < size());}

private:
	ALPHACHAR relations_internal(const ALPHACHAR charInSeq, const ALPHACHAR charToCheck) const;
	// VVint _relation;
	std::vector<std::vector<ALPHACHAR>> _relation;
};//end of class

#endif


