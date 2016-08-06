/**
* This class provides the base for all spaces on the Monopoly board
**/
#include <stdlib.h>
#include <stdio.h>
#ifndef LandingSpace_H
#define LandingSpace_H
#define MIN_VALUE 0.00000001
class Player;
class LandingSpace
{

	private:
		char* name;
		char format[6];
		
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
		* Returns the String representation of a monetary number
		* @param amount - the monetary number
		* @return - its String representation
		**/
		char* getFormat(float amount)
		{
			char symbol;
			int thousand_number = amount / 1000000 < 1;
			float result = thousand_number ? amount / 1000 : amount / 1000000;
			symbol = thousand_number ? 'K' : 'M';
			int isInt = result - (int)(result)   < MIN_VALUE;
			!thousand_number && !isInt ? sprintf(format, "$%0.3f%c", result, symbol) : sprintf(format, "$%.0f%c", result, symbol);
			return format; 
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
