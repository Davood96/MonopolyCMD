#include <stdlib.h>
#include <stdio.h>
#include "RandomCard.h"

class Player;
class AdvanceCard : public RandomCard
{
	private:
		int new_position;

	public:
		AdvanceCard(char* text, int pos) : RandomCard(text)
		{
			new_position = pos;
		}

		AdvanceCard() : RandomCard(){}
		~AdvanceCard(){}
		

		void modify(Player* plyr);
		
			
		

};
