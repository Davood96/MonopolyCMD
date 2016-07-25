/**
* This file contains the implementation of the following classes:
* - Player
* - Group
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
#include "Die.h"
#include "Property.h"
#include "Group.h"


void Player::payOwed(Player* owner, float amount)
{
	cashSwap(owner, this, amount);
	//More complex stuff to come

}

int Player::rollDouble(Die* ptr)
{
	int roll_1 = ptr->roll();
	int roll_2 = ptr->roll();
	int snake_eyes = roll_1 == roll_2;
	printf("You rolled a %d and a %d\n", roll_1, roll_2);
	setJail( !snake_eyes && jail_rolls < 2);

	if(!jailState && !snake_eyes)
		cash -= 1000000;
	else if(snake_eyes)
	{
		moveToPosition(position + 2 * roll_1);
		roll = 2 * roll_1;
	}

	jail_rolls = jailState ? jail_rolls + 1 : 0;

	return 1;
}

void Player::printOwned()
{
	printf("You have the following properties:");
	int i = 0;
	Group* grp;
	for(i; i < 10; i++)
	{
		if(hasGroup(i))
		{
			grp = properties[i];
			int size = grp->getSize();
			printf("\n%d %s(s) - ", size, Property::group_labels[i]);
			int j = 0;
			for(j; j < size; j++)
				printf("Property %d : %s\n", (i << 4) + j + 1 , (grp->getProperty(j))->getName() );	
		}	
	}
	printf("\n");
}


void Player::addProperty(Property* ptr, float price)
{
	cash -= price;
	int code = (int)(ptr->getCode());
	int index = code / 10 - 1;	

	if(properties[index] == NULL)
		properties[index] = new Group(code % 10);
	
	properties[index]->add(ptr);
		
	printf("%s now owns %s\n\n", name, ptr->getName());
	owned++;
}

void Group::add(Property* ptr)
{
	arr[size++] = ptr;
	int i = 0;

	if(capacity - size < 1)
	{
		for(i;i < size; i++)
			arr[i]->rentChanges(size);
	}
}

int Player::move(Die* ptr)
{
	printf("MAKe\n");
	int roll_1 = ptr->roll();
	int roll_2 = ptr->roll();
	int snake_eyes = roll_1 == roll_2;
	consecutive_doubles = snake_eyes ? consecutive_doubles + 1 : 0;
	setJail(position + roll_1 + roll_2 == GO_TO_JAIL || consecutive_doubles > 2);
	printf("You rolled a %d and a %d\n", roll_1, roll_2);

	if(!jailState)
	{
		roll = roll_1 + roll_2;
		turn += (position + roll > 39);
		position = (position + roll) % 40;
		collectGO();
		return !snake_eyes;
	}
	
	consecutive_doubles = 0;
	moveToPosition(JAIL);
	
	return jailState;

}
