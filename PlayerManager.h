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
		std::map< std::string, int> stringMap;

		void increment(int offset)
		{
			index = (index + offset) % size;
		}

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

		void scanListed(int** arr, int size);

		Player** searchPlayer();
		
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

		void endTurn();
		void startTurn();
		void build();
		void deal();

		int reNegotiate()
		{
			printf("Press 0 for counter-offer. Press 1 to end negotiations\n");
			char c;
			while((c = getchar()) != '0' && c != '1');
			getchar();
			return (int) (c - '0');			

		}

		void completeDeal()
		{
			printf("Swap stuff\n");
		}	
	
		int inRange(int i)
		{
			return i > -1 && i < size;
		}

		void addPlayer(Player* plyr)
		{
			players[index] = plyr;
			increment(1);
		}

		int getRunning()
		{
			return running;
		}

};
