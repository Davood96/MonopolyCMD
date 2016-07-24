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

		void executeOptions(Player* plyr, int index)
		{
			int pos = elements[index]->execute(plyr);
			if(pos - index != 0)
				elements[pos]->execute(plyr);
			
		}


};


