/**
* This class provides the prototype
* for cards that force the player to 
* advance to specific location
*
**/
#include <stdlib.h>
#include <stdio.h>
#include "RandomCard.h"

class Player;
class AdvanceCard : public RandomCard
{
	private:
		// The location directed to by the card
		int new_position;

	public:
		AdvanceCard(char* text, int pos) : RandomCard(text)
		{
			new_position = pos;
		}

		AdvanceCard() : RandomCard(){}
		~AdvanceCard(){}
		
		/**
		* Moves the player to the described location
		* @param plyr - The player who must move to the location
		*
		**/
		void modify(Player* plyr);
		
			
};
