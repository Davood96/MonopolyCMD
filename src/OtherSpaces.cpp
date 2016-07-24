#include <stdio.h>
#include "Jail.h"
#include "Player.h"

int Jail::execute(Player* plyr)
{
	char* msg = plyr->getJail() ? "In jail" : "Just visiting";
	setName(msg);
	printLanded();
	return 10;
}
