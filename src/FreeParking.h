#include <stdio.h>
#include "LandingSpace.h"

class FreeParking : public LandingSpace
{
	public:
		FreeParking(char* str) : LandingSpace(str){}
		FreeParking() : LandingSpace() {}
		~FreeParking(){}

		void printLanded()
		{
			printf("You landed on Free Parking\n");
		}

		int execute(Player* plyr)
		{
			printLanded();
			return 20;
		}



};
