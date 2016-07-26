/**
* This class provides a base for Chance
* and Community Chest cards
**/
#ifndef Chance_H
#define Chance_H
#include <stdlib.h>
#include <stdio.h>
#include "DNode.h"

class RandomCard : public DNode<char*>
{
	public:
		RandomCard(char* string) : DNode<char*>(string){}
		
		RandomCard() : DNode<char*>() {}

		~RandomCard(){}

		/**
		* Makes a change to the player depending on the type of card
		* @param plyr - the player who has drawn the card
		**/
		virtual void modify(Player* plyr) = 0;
		
		/**
		* Prints the card text
		**/
		void printText()
		{
			printf("%s\n", getData());
		}
	
};
#endif

