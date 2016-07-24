#include <stdio.h>
#include <stdlib.h>
#define JAIL 10
#define GO_TO_JAIL 30
#define SIZE 10
class Die;
class Property;
class Group;

class Player
{

	private:
		int position;
		float cash;
		int roll;
		int jailState;
		Group** properties;
		int owned;
		int turn;
		int prevTurn;
		int consecutive_doubles;
		int jail_rolls;
		char* name;

		void collectGO()
		{
			cash =  turn - prevTurn == 1 ? cash + 2000000 : cash;
			prevTurn = turn;
		}

	public:

		Player(char* str)
		{
			cash = 15000000;
			jailState = false;
			position = 0;
			turn = 0;
			prevTurn = 0;
			consecutive_doubles = 0;
			owned = 0;
			jail_rolls = 0;

			properties = (Group**) malloc(SIZE * sizeof(Group*));
			int i = 0;
			for(i; i < SIZE; i++)
				properties[i] = NULL;
			name = str;
		}

		~Player(){}

		int move(Die* ptr);
		int rollDouble(Die* ptr);

		void moveToPosition(int new_position)
		{
			turn += position > new_position && !jailState;
			position = new_position;
			collectGO();
		}

		void payOwed(Player* owner, float amount);

		

		int hasProperty()
		{
			return owned;
		}	

		int hasGroup(int index)
		{
			return properties[index] != NULL;
		}

		void printOwned();

		void setJail(int cond)
		{
			jailState = cond;
		}

		void deduct(float amount)
		{
			cash -= amount;
		}

		void add(float amount)
		{
			cash += amount;
		}

		void cashSwap(Player* receive, Player* give, float amount)
		{
			give->deduct(amount);
			receive->add(amount);			

		}

		int getPosition()
		{
			return position;
		}

		int getTurn()
		{
			return turn;
		}

		int getRoll()
		{
			return roll;
		}

		int getJail()
		{
			return jailState;
		}

		float getCash()
		{
			return cash;
		}

		void addProperty(Property* ptr, float price);

		char* getName()
		{
			return name;
		}


		
};
