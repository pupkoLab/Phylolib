#ifndef ___GAIN_LOSS_ALPH
#define ___GAIN_LOSS_ALPH

#include "alphabet.h"
#include "errorMsg.h"

class gainLossAlphabet : public alphabet {
public:
	explicit gainLossAlphabet(); 
	virtual ~gainLossAlphabet() {}
	virtual alphabet* clone() const { return new gainLossAlphabet(*this); }
	ALPHACHAR unknown() const  {return 2;}
	ALPHACHAR gap() const  {return 3;} // 
	ALPHACHAR size() const {return 2;} // presence or absence only
	size_t stringSize() const {return 1;} // one letter code.
	ALPHACHAR relations(const ALPHACHAR charInSeq, const ALPHACHAR charToCheck) const;
	ALPHACHAR fromChar(const string& str, const size_t pos) const;
	size_t fromChar(const char s) const;
	string fromInt(const ALPHACHAR in_id) const;
	vector<ALPHACHAR> fromString(const string& str) const;
	bool isSpecific(const ALPHACHAR id) const {return (id>=0 && id < static_cast<int>(size()));}

};

#endif
