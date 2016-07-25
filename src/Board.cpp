/**
* This file contains the implementation of the following classes:
* - Board
**/
#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
#include "RandomCardImp.h"
#include "PropertyChildren.h"
#include "CardTypes.h"
#include "Names.h"

void Board::shuffleDecks()
{
	chanceDeck->shuffle();
	communityDeck->shuffle();
}

void Board::createDecks()
{
	chanceDeck = new RandomCardDeck();
	communityDeck = new RandomCardDeck();
}

void Board::assignRandomCardPositions()
{
	RandomSpace* chance = new RandomSpace(chanceDeck, "Chance");
	elements[7] = chance;
	elements[22] = chance;
	elements[36] = chance;

	RandomSpace* community = new RandomSpace(communityDeck, "Community Chest");
	elements[17] = community;
	elements[33] = community;
	elements[2] = community;
}

void Board::readCities()
{
	elements[0] = new GO("GO");
	elements[12] = new Service("Cellphone Service", 'f');
	elements[28] = new Service("Internet Service", 'f');
	elements[20] = new FreeParking("Free Parking");
	elements[10] = new Jail();

	fp = fopen(CITIES_LINK, "r");

	if(fp == NULL)
		exit(1);

	int i = 0;int index; float purchase; 

	for(i; i < 22; i++)
	{
		char* string = (char*) malloc(40*sizeof(char));
		char c;int j = 0; 
		float* tmp = (float*) malloc(6 * sizeof(float));
		while((c = fgetc(fp)) != '\t')
			string[j++] = c;
		string[j] = '\0';int code; 
		fscanf(fp, "%d", &code);
		fscanf(fp, "%d%f%f%f%f%f%f%f\n", &index, tmp, tmp + 1, tmp + 2, 
					tmp + 3, tmp + 4, tmp + 5, &purchase);

		City* city = new City(string, (char)code, tmp);
		city->setPurchasePrice(purchase);
		city->setRent(tmp[0]);
		elements[index] = city; 
	}
	fclose(fp);
}

void Board::readAirports()
{
	fp = fopen(AIRPORT_LINK, "r");
	int i = 0;int index;
	for(i; i < 4; i++)
	{
		char* string = (char*) malloc(40*sizeof(char));
		char c;int j = 0;
		while((c = fgetc(fp)) != '\t')
			string[j++] = c;
		string[j] = '\0';int code;
		fscanf(fp, "%d\n", &code);
		Airport* airport = new Airport(string, (char)code);
		fscanf(fp, "%d\n", &index);
		elements[index] = airport;
		
	}
	fclose(fp);

}

void Board::readChance()
{
	fp = fopen(CHANCE_LINK, "r");
	if(fp == NULL)
		exit(1);
	int i = 0;int index;
	for(i; i < 3; i++)
	{
		char* string = (char*) malloc(100*sizeof(char));
		if(string == NULL)
			exit(1);
		char c;int j = 0;

		while((c = fgetc(fp)) != '\t')
			string[j++] = c;

		string[j] = '\0';
		fscanf(fp, "%d\n", &index);
		RandomCard* card  = new AdvanceCard (string, index);
		chanceDeck->insert(card);
	}
	fclose(fp);

}

void Board::readCommunityChest()
{
	fp = fopen(COMMUNITY_LINK, "r");
	if(fp == NULL)
		exit(1);
	int i = 0;int index;
	for(i; i < 3; i++)
	{
		char* string = (char*) malloc(100*sizeof(char));
		if(string == NULL)
			exit(1);
		char c;int j = 0;

		while((c = fgetc(fp)) != '\t')
			string[j++] = c;

		string[j] = '\0';
		fscanf(fp, "%d\n", &index);
		RandomCard* card  = new AdvanceCard (string, index);
		communityDeck->insert(card);
	}
	fclose(fp);
}

void Board::readNearest()
{
	char* string = "Advance to the nearest airport";
	chanceDeck->insert(new NearestCard(string));
	communityDeck->insert(new NearestCard(string));
}






