/**
* This class provides the base for all spaces on the Monopoly board
**/
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

		/**
		* Returns the name of the space
		* @return - the name of the space
		**/
		char* getName()
		{
			return name;
		}

		/**
		* Prints a message when a player lands on the space
		**/
		void printLanded()
		{
			printf("You landed on %s\n", getName());
		}

		/**
		* Run a sequecence of instructions when a player lands
		* This is defined relative to the type of space
		* @param plyr - the player who has landed
		* @return - the position on the board
		**/
		virtual int execute(Player* plyr) = 0;
		
		

};
#endif
