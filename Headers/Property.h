/**
* This class provides base for Property spaces
* (Spaces that represent purchasable properties)
**/
#ifndef Property_H
#define Property_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "LandingSpace.h"
#define YES 'Y'
#define NO 'N'
#define GROUPS 10

class Property : public LandingSpace
{

	private:
		float rent;
		float purchase_price;
		Player* owner;
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

		Property() : LandingSpace(){owner = NULL;}
		~Property(){printf("Free memory\n");}

		/**
		* Holds the labels for the groups that each property
		* belongs to 
		**/
		static const char* group_labels[GROUPS];
		
		/**
		* Returns whether the property is owned
		* @return - 0 if it is available for purchase. Any other int otherwise
		**/
		int isOwned()
		{
			return owner != NULL;
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
		

		char getCode()
		{
			return groupCode;
		}

		int execute(Player* plyr);

		virtual void printRentInfo() = 0;

		virtual float calculateOwed(int rolls) = 0;
		
		virtual void rentChanges(int owned) = 0;

		/**
		* Prints the purchase price of a property
		**/
		void printPurchaseInfo()
		{
			printf("Price = %s\n", getFormat(getPrice()));
		}
		/**
		* Prints the color group of a property
		**/
		void printColorGroup()
		{
			printf("Group : %s\n", group_labels[(int) groupCode / 10 - 1]);
		}
		
	
};
#endif
