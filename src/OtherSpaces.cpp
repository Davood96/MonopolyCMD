/**
* This file contains the implementation of the following classes:
* - Jail
**/
#include <stdio.h>
#include "../Headers/Jail.h"
#include "../Headers/Player.h"

int Jail::execute(Player* plyr)
{
	char* msg = plyr->getJail() ? "In jail" : "Just visiting";
	printf("%s\n", msg);
	return 10;
}
