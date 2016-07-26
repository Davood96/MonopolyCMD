/**
* This class provides a template for a 
* managing client that acts as the intermediate
* between the game and the players
**/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#define DEFAULT_SIZE 3

class Player;
class Die;
class Board;
using namespace std;
class PlayerManager
{
	private:
		Player** players;
		Player* currPlayer;
		Board* board;
		int index;
		int size;
		int running;
		int offset;
		Die* die;
		void newDie();

		//Used for user input detection
		std::map< std::string, int> stringMap;

		//Increments index to point to the next player
		// If offset is 0, player rolls again
		void increment(int offset)
		{
			index = (index + offset) % size;
		}

		//Read user input
		int readAction()
		{
			char buffer[10];
			fgets(buffer, 10, stdin);
			int sz = strlen(buffer);
			buffer[sz - 1] = '\0';
			return stringMap.find(std::string(buffer))->second;
		}

		void negotiate(Player** dealer, Player** receiver);
		
		inline void play();

		int inRange(int i)
		{
			return i > -1 && i < size;
		}

		void scanListed(int** arr, int size);

		Player** searchPlayer();
		
		//Mathing input to possible entries
		inline void runCase(int input)
		{
			while(input != 1)
			{
				switch(input)
				{
					case 2:
					build();
					break;

					case 3:
					deal();
					break;
					
					default:
					printf("Please try again\n");
					break;
				}
				input = readAction();
			}
		}

	public:
		PlayerManager()
		{
			players = (Player**) malloc(DEFAULT_SIZE * sizeof(Player*));
			index = 0;
			size = DEFAULT_SIZE;
			newDie();
		}

		PlayerManager(int amount, Board* ptr)
		{
			players = (Player**) malloc(amount * sizeof(Player*));
			board = ptr;
			index = 0;
			size = amount;
			stringMap[std::string("")] = 1;
			stringMap[std::string("B")] = 2;
			stringMap[std::string("D")] = 3;
			running = 1;
			int i = 0;
			newDie();
		}
		/**
		* Ends the current player's turn
		**/
		void endTurn();
		/**
		* Begins the current player's turn
		**/
		void startTurn();
		/**
		* Build house(s) or hotel(s) on properties
		**/
		void build();
		/**
		* Initiate a deal between two players
		**/
		void deal();
		/**
		* Responds to the current offer
		* @return - 0 for a counter-offer. 1 to terminate negotiations
		**/
		int reNegotiate()
		{
			printf("Press 0 for counter-offer. Press 1 to end negotiations\n");
			char c;
			while((c = getchar()) != '0' && c != '1');
			getchar();
			return (int) (c - '0');			

		}
		/**
		* Carries out the terms specified in the deal
		**/
		void completeDeal()
		{
			printf("Swap stuff\n");
		}	
	
		
		/**
		* Adds a player to the game
		* @param plyr - the player to be added
		**/
		void addPlayer(Player* plyr)
		{
			players[index] = plyr;
			increment(1);
		}
		/**
		* Returns whether the game is running or not
		* @return - 1 if running. 0 otherwise
		**/
		int getRunning()
		{
			return running;
		}

};
