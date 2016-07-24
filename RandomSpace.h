#ifndef RandomSpace_H
#define RandomSpace_H
#include <stdlib.h>
#include <stdio.h>
#include "LandingSpace.h"

class Player;
class RandomCardDeck;
class RandomSpace : public LandingSpace 
{
	private:
		RandomCardDeck* deck;

	public:
		RandomSpace() : LandingSpace(){}

		RandomSpace(RandomCardDeck* ptr, char* str) : LandingSpace(str)
		{
			deck = ptr;
		}		

		int execute(Player* plyr)
		{
			printLanded();
			return deck->drawCard(plyr);
		}
};
#endif
