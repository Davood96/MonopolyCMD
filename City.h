#include <stdlib.h>
#include <stdio.h>
#include "Property.h"
#define MAX_HOUSES 5
class City : public Property
{
	private:
		int houses;
		float* rent_prices;
		char format[6];
		
	public:
		City(char* string, char code) : Property(string, code){houses = 0; rent_prices = (float*) malloc(6 * sizeof(float));}
		City() : Property(){}
		~City(){printf("Free memory\n");}

		float* getPrices()
		{
			return rent_prices;
		}
		
		float calculateOwed(int rolls)
		{
			return getRent();
		}

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

		void rentChanges(int owned)
		{
			int lands = (int) (getCode() % 10);
			setRent((owned / lands + 1) * (*rent_prices));
			printf("New rent: %s\n", getFormat(getRent()));
		}


};
