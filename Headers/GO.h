#include <stdio.h>
#include "LandingSpace.h"

class GO : public LandingSpace
{
	public:
		GO(char* str) : LandingSpace(str){}
		GO() : LandingSpace() {}
		~GO(){}

		int execute(Player* plyr)
		{
			printLanded();
			return 0;
		}



};
