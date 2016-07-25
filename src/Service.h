/**
* This class provides a template for a Service space
**/
#include <stdlib.h>
#include <stdio.h>
#include "Property.h"
#define RATE_1 40000
#define RATE_2 100000

class Service : public Property
{
	public:
		Service(char* str, char code) : Property(str, code)
		{
			setPurchasePrice(1500000);
			setRent(RATE_1);
		}

		Service() : Property(){}

		~Service(){}


		void printRentInfo()
		{
			printf("Rent is $40,000 * dice_roll if one service owned, $100,000 * dice_roll if both owned\n");
		}		

		float calculateOwed(int roll)
		{
			printf("Service version\n");
			return getRent() * roll;
		}

		void rentChanges(int owned)
		{
			int lands = (int) (getCode() % 10);
			setRent(owned / lands < 1 ? RATE_1 : RATE_2);
			printf("New rent: %s\n", getFormat(getRent()));
		}


};
