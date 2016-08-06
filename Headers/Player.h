/**
* This class provides the prototype for a Monopoly player
**/
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
		//The number rolled
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
			jailState = 0;
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

		/**
		* Moves the player based on the roll of dice
		* @param ptr- pointer to Die object
		* @return - 1 if the player does not roll again. 0 otherwise
		**/
		int move(Die* ptr);

		/**
		* Player rolls for a double while in jail
		* @param ptr- pointer to Die object
		* @return - 
		**/
		int rollDouble(Die* ptr);

		/**
		* Moves player to a new position
		* @param new_position - the position on the board
		**/
		void moveToPosition(int new_position)
		{
			turn += position > new_position && !jailState;
			position = new_position;
			collectGO();
		}

		/**
		* Forces player to pay debt when landing on owned property
		* @param owner - the owner of the property
		* @param amount - the amount owed
		**/
		void payOwed(Player* owner, float amount);

		/**
		* Determines whether player owns properties or not
		* @return - the number of owned properties
		**/
		int hasProperty()
		{
			return owned;
		}	
		/**
		* Determines whether player owns properties in a specific group
		* @param index - the group in question
		* @return - 0 if the player does not. Any other int otherwise
		**/
		int hasGroup(int index)
		{
			return properties[index] != NULL;
		}

		/**
		* Prints a list of the player's owned properties
		**/
		void printOwned();
		/**
		* Sets jail state of player
		* @param cond - the jail state
		**/
		void setJail(int cond)
		{
			jailState = cond;
		}
		/**
		* Deducts specific amount from cash reserves
		* @param amount - the amount to be deducted
		**/
		void deduct(float amount)
		{
			cash -= amount;
		}
		/**
		* Adds specific amount from cash reserves
		* @param amount - the amount to be added
		**/
		void add(float amount)
		{
			cash += amount;
		}
		/**
		* Payment between two players
		* @param amount - the amount to be payed
		* @param receive - the creditor
		* @param give - the debtor
		**/
		void cashSwap(Player* receive, Player* give, float amount)
		{
			give->deduct(amount);
			receive->add(amount);			

		}
		/**
		* Returns position of player on board
		* @return - the position of the player
		**/
		int getPosition()
		{
			return position;
		}
		/**
		* Returns number of times player has passed GO
		* @return - the number of times player has passed GO
		**/
		int getTurn()
		{
			return turn;
		}
		/**
		* Returns the player's most recent dice roll
		* @return - the player's most recent dice roll
		**/
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
		/**
		* Adds a property to list of owned properties
		* @param ptr - the property
		* @param price - the purchase price
		* @precondition - the player has enough money to make purchase
		* @postcondition 
		**/
		void addProperty(Property* ptr, float price);

		char* getName()
		{
			return name;
		}


		
};
