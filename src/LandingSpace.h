#include <stdlib.h>
#include <stdio.h>
#ifndef LandingSpace_H
#define LandingSpace_H

class Player;
class LandingSpace
{

	private:
		char* name;
		
	public:
		LandingSpace(char* string)
		{
			name = string;
		}

		LandingSpace(){}
		~LandingSpace(){}

		char* getName()
		{
			return name;
		}

		void setName(char* str)
		{
			name = str;
		}

		void printLanded()
		{
			printf("You landed on %s\n", getName());
		}

		virtual int execute(Player* plyr) = 0;
		
		

};
#endif
