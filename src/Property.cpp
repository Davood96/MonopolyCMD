/**
* This file contains the implementation of the following classes:
* - Property
**/
#include "../Headers/Property.h"
#include "../Headers/Player.h"
#include <stdio.h>


const char* Property::group_labels[GROUPS] = {"BROWN", "LIGHT BLUE", "PINK", 
					"ORANGE", "RED", "YELLOW", "GREEN", 
					"DARK BLUE", "AIRPORT", "SERVICE"};

int Property::execute(Player* plyr)
{
	printLanded();
	printColorGroup();
	printRentInfo();
	printf("You have this much: %s\n",getFormat(plyr->getCash()));

	if(isOwned() && owner != plyr)
		payRent(plyr, plyr->getRoll());
	else if(owner == NULL)
		purchase(plyr);

	return plyr->getPosition();
}

void Property::purchase(Player* plyr)
{	
	!plyr->getTurn() ? printf("Buy after passing round once\n\n") : purchaseDialog(plyr);  
}

inline void Property::purchaseDialog(Player* plyr)
{
	if(plyr->hasProperty())
		plyr->printOwned();

	printf("Would you like to purchase: Y or N ?\n");
	char c;
	while((c = getchar()) != YES && c != NO);
	if(c == YES){
		plyr->addProperty(this, purchase_price); owner = plyr;}
	while(getchar() != '\n');

}

void Property::payRent(Player* plyr, int roll)
{
	printf("Pay the man\n"); float owed = calculateOwed(roll);
	plyr->payOwed(owner, owed);
	printf("%s now has: %s \n", plyr->getName(), getFormat(plyr->getCash()));
	printf("%s now has: %s \n", owner->getName(), getFormat(owner->getCash()));
}
