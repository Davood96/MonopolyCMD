/**
* This class provides implementation of Free Parking
**/
#include <stdio.h>
#include "LandingSpace.h"
#define SPACE 20
class FreeParking : public LandingSpace
{
	public:
		FreeParking(char* str) : LandingSpace(str){}
		FreeParking() : LandingSpace() {}
		~FreeParking(){}

		int execute(Player* plyr)
		{
			printLanded();
			return SPACE;
		}



};
