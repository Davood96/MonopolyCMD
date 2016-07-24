#include <stdio.h>
#include "LandingSpace.h"

class GO : public LandingSpace
{
	public:
		GO(char* str) : LandingSpace(str){}
		GO() : LandingSpace() {}
		~GO(){}

		void printLanded()
		{
			printf("You landed on GO\n");
		}

		int execute(Player* plyr)
		{
			printLanded();
			return 0;
		}



};
