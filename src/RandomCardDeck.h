/**
* This class provides a prototype for both
* Chance and Community Chest decks
**/
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

		/**
		* Shuffles the deck
		**/
		void shuffle();

		/**
		* Adds a card to the deck
		* @param ptr - the card to be added
		**/
		void insert(node* ptr)
		{
			insertAtHead(ptr);
		}

		
};
