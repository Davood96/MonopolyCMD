#include <stdio.h>
#include "LandingSpace.h"

class Jail : public LandingSpace
{
	public:
		Jail(char* str) : LandingSpace(str){}
		Jail() : LandingSpace() {}
		~Jail(){}

		void printLanded()
		{
			printf("%s\n", getName());
		}
		

		int execute(Player* plyr);
		
			
		



};
