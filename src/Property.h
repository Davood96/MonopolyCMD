#ifndef Property_H
#define Property_H
#include <stdlib.h>
#include <stdio.h>
#include "LandingSpace.h"
#define MIN_VALUE 0.00000001
#define YES 'Y'
#define NO 'N'
#define GROUPS 10

class Property : public LandingSpace
{

	private:
		float rent;
		float purchase_price;
		Player* owner;
		char format[6];
		int morgated;
		//Must be a char. Have no idea why
		char groupCode;

		void purchase(Player* plyr);
		void payRent(Player* plyr, int roll);
		inline void purchaseDialog(Player* plyr);
		int getOwned(int index);

	public:
		Property(char* string, char code) : LandingSpace(string)
		{ 
			owner = NULL; 
			groupCode = code;
			
		}

		Property() : LandingSpace(){}
		~Property(){printf("Free memory\n");}

		static const char* group_labels[GROUPS];

		int isOwned(Player* plyr)
		{
			return owner != NULL && plyr != owner;
		}

		float getRent()
		{
			return rent;
		}

		float getPrice()
		{
			return purchase_price;
		}

		void setPurchasePrice(float amount)
		{
			purchase_price = amount;
		}

		void setRent(float amount)
		{
			rent = amount;
		}

		void setOwner(Player* ptr)
		{
			owner = ptr;
		}

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

		char getCode()
		{
			return groupCode;
		}

		int execute(Player* plyr);
		virtual void printRentInfo() = 0;

		virtual float calculateOwed(int rolls) = 0;
		

		void printPurchaseInfo()
		{
			printf("Price = %s\n", getFormat(getPrice()));
		}

		void printColorGroup()
		{
			printf("Group : %s\n", group_labels[(int) groupCode / 10 - 1]);
		}

		virtual void rentChanges(int owned) = 0;
	
};
#endif
