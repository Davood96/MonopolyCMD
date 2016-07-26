/**
* This class provides the prototype for cards
* that move the player to the nearest airport or service
**/
#include <stdlib.h>
#include <stdio.h>
#include "RandomCard.h"

class Player;
class NearestCard : public RandomCard
{
	public:
		NearestCard(char* text) : RandomCard(text){}
		NearestCard() : RandomCard(){}
		~NearestCard(){}

		void modify(Player* plyr);
		
		

};
