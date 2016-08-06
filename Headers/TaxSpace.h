#include "LandingSpace.h"

class LuxuryTax : public LandingSpace
{
	public:
		LuxuryTax(char* str) : LandingSpace(str){}
		LuxuryTax(){}
		~LuxuryTax(){}

		int execute(Player* plyr);

};

class IncomeTax : public LandingSpace
{
	public:
		IncomeTax(char* str) : LandingSpace(str){}
		IncomeTax(){}
		~IncomeTax(){}

		int execute(Player* plyr);
		

};

