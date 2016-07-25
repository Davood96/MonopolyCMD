/**
* This class provides the prototype
* for the Monopoly board
*
**/

#include <stdlib.h>
#include <stdio.h>
#include "LandingSpace.h"

class Player;
class RandomCardDeck;
class Board
{
	private:
		LandingSpace* elements[40];
		FILE* fp;
		RandomCardDeck* chanceDeck;
		RandomCardDeck* communityDeck;

		void readCities();
		void readAirports();
		void readChance();
		void readCommunityChest();
		void readNearest();
		void createDecks();
		void assignRandomCardPositions();
		void shuffleDecks();

	public:
		Board()
		{
			readCities();
			readAirports();

			createDecks();
			
			readChance();
			readCommunityChest();
			readNearest();
			
			assignRandomCardPositions();
			shuffleDecks();

		}


		~Board(){};
		
		/**
		* Instructs a LandingSpace's execute() routine to run
		* when a player lands
		* @param plyr - The player who has just rolled
		* @param index - the player's position on the board
		*
		**/
		void executeOptions(Player* plyr, int index)
		{
			int pos = elements[index]->execute(plyr);
			//This occurs in the event an AdvanceCard is drawn in the line above
			if(pos - index)
				elements[pos]->execute(plyr);
			
		}


};


