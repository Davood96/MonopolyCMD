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
