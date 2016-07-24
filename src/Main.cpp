#include <stdio.h>
#include <stdlib.h>
#include "Player.h"
#include "PlayerManager.h"
#include "Board.h"

void main()
{

	Player player1("Bob");
	Player player2("Bill");
	Board board;
	PlayerManager manager (2, &board);
	manager.addPlayer(&player1);
	manager.addPlayer(&player2);
	
	
	while(manager.getRunning())
	{
		manager.startTurn();
		//board->executeOptions(currPlayer, currPlayer->getPosition());
		manager.endTurn();
	}


}
