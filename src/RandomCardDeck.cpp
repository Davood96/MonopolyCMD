#include <stdlib.h>
#include <stdio.h>
#include "../Headers/RandomCardDeck.h"
#include "../Headers/RandomCard.h"
#include "../Headers/Player.h"
#include "../Headers/CardTypes.h"

void RandomCardDeck::shuffle()
{
	int times = generate();
	DNode<char*>* start = getFirst();DNode<char*>* second;
	int i = 0; int j = 0;
	for(i; i < times; i++)
	{	
		j = 0;
		for(j; j < CARDS - 1; j++)
			start = swap(start, start->getNext());
		start = getFirst();
		
	}
}

int RandomCardDeck::drawCard(Player* plyr)
{
	RandomCard* card = (RandomCard*) removeAtHead();
	card->printText();
	card->modify(plyr);
	insertAtTail(card);
	return plyr->getPosition();
}

void AdvanceCard::modify(Player* plyr)
{
	plyr->moveToPosition(new_position);
}

void NearestCard::modify(Player* plyr)
{
	int position = plyr->getPosition();
	int new_position = (position / 5) % 7;
	int factor = new_position % 2 < 1 ? 1: 2;
	new_position = (new_position + factor) * 5; 
	plyr->moveToPosition(new_position);
}
