/**
* This class provides the full implementation
* for city spaces 
*
**/
#include <stdlib.h>
#include <stdio.h>
#include "Property.h"
#define MAX_HOUSES 5
class City : public Property
{
	private:
		//The number of houses built on a space
		int houses;
		//The various rent rates
		float* rent_prices;
		char format[6];
		
	public:
		City(char* string, char code, float* arr) : Property(string, code)
		{
			houses = 0; 
			rent_prices = arr;
		}

		City() : Property(){}
		~City(){printf("Free memory\n");}

		
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
		* Prints the rates associated with a city space
		**/
		void printRentInfo()
		{
			printf("Rent Rates\n");
			printf("Basic: %-6s\n", getFormat(*rent_prices));
			/**Printing done as such due to undefined behaviour in C
			   with respect to printf and multiple calls to the same function**/
			int offset = 1;

			for(offset; offset < 5; offset++)
				printf("If %d House(s) owned: %-6s\n",offset, getFormat(*(rent_prices + offset)));

			printf("If Hotel owned:\t%-6s\n",getFormat(*(rent_prices + offset)));
				
		}

		/**
		* Updates the rent of the city space
		* @param owned - the number of city spaces of the same group owned 
		**/
		void rentChanges(int owned)
		{
			int lands = (int) (getCode() % 10);
			setRent((owned / lands + 1) * (*rent_prices));
			printf("New rent: %s\n", getFormat(getRent()));
		}


};
