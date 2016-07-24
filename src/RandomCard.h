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

		virtual void modify(Player* plyr) = 0;
		
		void printText()
		{
			printf("%s\n", getData());
		}
	
};
#endif

