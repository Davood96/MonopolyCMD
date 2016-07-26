/**
* This class provides the full implementation
* for airport spaces 
*
**/
#include <stdlib.h>
#include <stdio.h>
#include "Property.h"
#define BASE_RATE 250000
class Airport : public Property
{
	public:
		Airport(char* string, char code) : Property(string, code)
		{
			setPurchasePrice(2000000);
			setRent(BASE_RATE);
		}

		Airport() : Property(){}
		~Airport(){}

		/**
		* Prints the rates associated with an airport space
		**/
		void printRentInfo()
		{
			float rent = BASE_RATE/1000;
			
			printf("If one airport owned -> rent = $%.0fK\n",rent);
			printf("If two airports owned -> rent = $%.0fK\n",rent * 2);
			printf("If three airports owned -> rent = $%.0fM\n",rent * 4 / 1000);
			printf("If four airports owned -> rent = $%.0fM\n",rent * 8 / 1000);
		}

		/**
		* Calculates the amount owed by a player when landing
		* on an airport space
		* @param rolls - the number rolled by the player
		* @return - the amount owed
		*
		**/
		float calculateOwed(int rolls)
		{
			return getRent();
		}

		/**
		* Updates the rent of the airport space
		* @param owned - the number of airports owned 
		**/
		void rentChanges(int owned)
		{
			//Rent = 2^(number of owned airports - 1) * BASE_RATE
			int operand = 1 << --owned;
			setRent(BASE_RATE * operand);
			printf("New rent: %f\n", getRent());
		}


};
