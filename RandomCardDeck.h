#include <stdlib.h>
#include <stdio.h>
#include "Deck.h"

class Player;
class RandomCard;
typedef DNode<char*> node;
class RandomCardDeck : public Deck<char*>
{
	
	public:
		RandomCardDeck() : Deck<char*>(){}

		~RandomCardDeck(){}

		int drawCard(Player* plyr);

		void shuffle();

		void insert(node* ptr)
		{
			insertAtHead(ptr);
		}

		
};
