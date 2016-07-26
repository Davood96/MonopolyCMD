/**
* This file contains the implementation of the following classes:
* - PlayerManager
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Die.h"
#include "../Headers/Board.h"
#include "../Headers/PlayerManager.h"
#include "../Headers/Player.h"

Player** PlayerManager::searchPlayer()
{
	int i;

	while(scanf("%d", &i) < 0 && !inRange(i))
		printf("Please try again\n");

	char* otherPlayer = players[i - 1] -> getName();

	printf("%s selected\n", otherPlayer); 	
	//Clear buffer
	getchar();

	return &players[i - 1];

}

void PlayerManager::scanListed(int** arr, int size)
{
	int index = 0;
	int input;
	scanf("%d", &input);
	while(input)
	{
		if(size - index < 1)
		{
			size *= 2;
			(*arr) = (int*) realloc(*arr, size);
		}

		input--;

		unsigned int group = input >> 4;
		unsigned int position = input << 28;
		position = position >> 28;
		//check if currPlayer has property before adding
		//(*arr)[index++] = input;
		printf("Group %d Pos %d %d\n", group, position, input);
		scanf("%d", &input);
	}


}

void PlayerManager::negotiate(Player** dealer, Player** receiver)
{	
	int end = 0;
	while( !end )
	{
		printf("Dealer - %s Receiver - %s\n", (*dealer)->getName(), (*receiver)->getName());
		int* tmp = (int*) malloc(2 * sizeof(int));

		if((*dealer)->hasProperty())
		{
			(*dealer)->printOwned();
			printf("Select the properties by their property number:\n");
			scanListed(&tmp, 2);
		}

		printf("Cash offer\nDoes %s accept: Y/N?\n", (*receiver)->getName());
		char c;
		while((c = getchar()) != 'Y' && c != 'N');
		getchar();

		if((end = (c == 'Y')))
			completeDeal();
		else if(!(end = reNegotiate()))
		{
			Player** placeHolder = dealer;
			dealer = receiver;
			receiver = placeHolder;
		}
		
		free(tmp);
	}
}

void PlayerManager::deal()
{
	Player** dealer = &currPlayer;
	Player** receiver;

	printf("%s would like to make a trade. Enter the player number to select the desired player:\n", currPlayer->getName());
	int i = (index + 1) % size;

	for(i; i != index; i = (i + 1) % size)
		printf("Player %d- %s\t", i + 1, players[i]->getName());

	printf("\n");
	receiver = searchPlayer();
	negotiate(dealer, receiver);
	
}

void PlayerManager::build()
{
	printf("%s would like to build\n", currPlayer->getName());
}

void PlayerManager::endTurn()
{
	printf("Options:\nPress Enter to end turn\tPress B to buy houses\tPress D to make a deal\n");
	int val =  readAction();
	runCase(val);
	increment(offset);
	printf("%d ", offset);
}

inline void PlayerManager::play()
{
	currPlayer = players[index];
	offset = currPlayer->getJail() ?  currPlayer->rollDouble(die) : currPlayer->move(die);
	board->executeOptions(currPlayer, currPlayer->getPosition());
}


void PlayerManager::startTurn()
{
	currPlayer = players[index];
	printf("It is now %s's turn\n\n", players[index]->getName());
	printf("Options:\nPress Enter to roll\tPress B to buy houses\tPress D to make a deal\n");
	int val =  readAction();
	runCase(val);
	play();
}

void PlayerManager::newDie()
{
	die = new Die();
}

