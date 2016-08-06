/**
* This file contains the implementation of the following classes:
* - Jail
* - TaxSpace : Income tax, Luxury Tax
**/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../Headers/Jail.h"
#include "../Headers/TaxSpace.h"
#include "../Headers/Player.h"
#define LUXURY_AMNT 1000000
#define INCOME_AMNT 2000000
#define LUXURY_SPCE 38
#define INCOME_SPCE 4

using namespace std;

int Jail::execute(Player* plyr)
{
	char* msg = plyr->getJail() ? "In jail" : "Just visiting";
	printf("%s\n", msg);
	return 10;
}


int LuxuryTax::execute(Player* plyr)
{
	printLanded();
	plyr->deduct(LUXURY_AMNT);
	return LUXURY_SPCE;
}


int IncomeTax::execute(Player* plyr)
{
	printLanded();
	std::cout << "You currently have "<< getFormat(plyr->getCash()) << "\n" <<"Press 1 for 10% , 0 for $2M\n";
	char c;
	while((c = getchar()) != '1' && c != '0');
	getchar();
	float amount = ((int) c < 1) ? INCOME_AMNT : plyr->getCash() / 10;
	plyr->deduct(amount);			
	return INCOME_SPCE;

}








