/**
* This file contains the implementation of the following classes:
* - Jail
**/
#include <stdio.h>
#include "Jail.h"
#include "Player.h"

int Jail::execute(Player* plyr)
{
	char* msg = plyr->getJail() ? "In jail" : "Just visiting";
	printf("Git test\n");
	setName(msg);
	printLanded();
	return 10;
}
